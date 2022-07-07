#include <linux/refcount.h>
#include <linux/bitmap.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/acpi.h>
#include <linux/sched.h>
#include <linux/ktime.h>
#include <linux/scatterlist.h>
#include <linux/vgaarb.h>
#include <linux/i2c.h>
#include <linux/acpi.h>
#include <linux/plist.h>

#ifdef CONFIG_DEBUG_PI_LIST
static void plist_check_head(struct plist_head *head)
{
        if (!plist_head_empty(head))
                plist_check_list(&plist_first(head)->prio_list);
        plist_check_list(&head->node_list);
}
#else
# define plist_check_head(h)    do { } while (0)
#endif

void plist_add(struct plist_node *node, struct plist_head *head)
{
        struct plist_node *first, *iter, *prev = NULL;
        struct list_head *node_next = &head->node_list;

        plist_check_head(head);
        WARN_ON(!plist_node_empty(node));
        WARN_ON(!list_empty(&node->prio_list));

        if (plist_head_empty(head))
                goto ins_node;

        first = iter = plist_first(head);

        do {
                if (node->prio < iter->prio) {
                        node_next = &iter->node_list;
                        break;
                }

                prev = iter;
                iter = list_entry(iter->prio_list.next,
                                struct plist_node, prio_list);
        } while (iter != first);

        if (!prev || prev->prio != node->prio)
                list_add_tail(&node->prio_list, &iter->prio_list);
ins_node:
        list_add_tail(&node->node_list, node_next);

        plist_check_head(head);
}
EXPORT_SYMBOL(plist_add);

void plist_del(struct plist_node *node, struct plist_head *head)
{
        plist_check_head(head);

        if (!list_empty(&node->prio_list)) {
                if (node->node_list.next != &head->node_list) {
                        struct plist_node *next;

                        next = list_entry(node->node_list.next,
                                        struct plist_node, node_list);

                        /* add the next plist_node into prio_list */
                        if (list_empty(&next->prio_list))
                                list_add(&next->prio_list, &node->prio_list);
                }
                list_del_init(&node->prio_list);
        }

        list_del_init(&node->node_list);

        plist_check_head(head);
}
EXPORT_SYMBOL(plist_del);

#if !defined(CPTCFG_VGA_CONSOLE)
int vga_remove_vgacon(struct pci_dev *pdev)
{
        return 0;
}
#elif !defined(CPTCFG_DUMMY_CONSOLE)
int vga_remove_vgacon(struct pci_dev *pdev)
{
        return -ENODEV;
}
#else
int vga_remove_vgacon(struct pci_dev *pdev)
{
        int ret = 0;

        if (pdev != vga_default)
                return 0;
        vgaarb_info(&pdev->dev, "deactivate vga console\n");

        console_lock();
        if (con_is_bound(&vga_con))
                ret = do_take_over_console(&dummy_con, 0,
                                           MAX_NR_CONSOLES - 1, 1);
        if (ret == 0) {
                ret = do_unregister_con_driver(&vga_con);

                /* Ignore "already unregistered". */
                if (ret == -ENODEV)
                        ret = 0;
        }
        console_unlock();

        return ret;
}
#endif

static int sg_dma_page_count(struct scatterlist *sg)
{
        return PAGE_ALIGN(sg->offset + sg_dma_len(sg)) >> PAGE_SHIFT;
}

bool __sg_page_iter_dma_next(struct sg_dma_page_iter *dma_iter)
{
        struct sg_page_iter *piter = &dma_iter->base;

        if (!piter->__nents || !piter->sg)
                return false;

        piter->sg_pgoffset += piter->__pg_advance;
        piter->__pg_advance = 1;

        while (piter->sg_pgoffset >= sg_dma_page_count(piter->sg)) {
                piter->sg_pgoffset -= sg_dma_page_count(piter->sg);
                piter->sg = sg_next(piter->sg);
                if (!--piter->__nents || !piter->sg)
                        return false;
        }

        return true;
}
