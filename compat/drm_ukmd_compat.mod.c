#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xf8cdd757, "module_layout" },
	{ 0xf4b9b193, "kmalloc_caches" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x1ed8b599, "__x86_indirect_thunk_r8" },
	{ 0x6cfc5f3c, "driver_register" },
	{ 0x2f4ce417, "debugfs_create_dir" },
	{ 0x58388972, "pv_lock_ops" },
	{ 0xb15021a8, "pm_generic_restore" },
	{ 0x46a5e192, "single_open" },
	{ 0x9337cd0, "__wake_up_locked_key" },
	{ 0x8c88fc, "dev_printk" },
	{ 0x61704c0d, "single_release" },
	{ 0x708a5d77, "seq_puts" },
	{ 0x420ecfe3, "seq_printf" },
	{ 0xad27f361, "__warn_printk" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x9b7fe4d4, "__dynamic_pr_debug" },
	{ 0xc29957c3, "__x86_indirect_thunk_rcx" },
	{ 0x87b8798d, "sg_next" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0xa6093a32, "mutex_unlock" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x501d615e, "debugfs_create_file" },
	{ 0xb348a850, "ex_handler_refcount" },
	{ 0x4668b613, "debugfs_remove_recursive" },
	{ 0x98600ced, "seq_read" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x87c2b160, "pm_generic_freeze" },
	{ 0xfb578fc5, "memset" },
	{ 0x3812050a, "_raw_spin_unlock_irqrestore" },
	{ 0x9202ba1c, "current_task" },
	{ 0x4a928de6, "mutex_lock_interruptible" },
	{ 0x9a76f11f, "__mutex_init" },
	{ 0x27e1a049, "printk" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x86090068, "driver_unregister" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x9166fada, "strncpy" },
	{ 0x2ec05d33, "ww_mutex_lock" },
	{ 0x5792f848, "strlcpy" },
	{ 0x41aed6e7, "mutex_lock" },
	{ 0x87471dc5, "bus_find_device" },
	{ 0x41482d8b, "strndup_user" },
	{ 0x5813db4b, "fput" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x4ea5d10, "ksize" },
	{ 0x62749cff, "pm_generic_suspend" },
	{ 0xae10a194, "pm_generic_runtime_suspend" },
	{ 0x3fca107d, "module_put" },
	{ 0x97ab9ad3, "pv_irq_ops" },
	{ 0xb601be4c, "__x86_indirect_thunk_rdx" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x47941711, "_raw_spin_lock_irq" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x2fe76b0c, "pm_generic_resume" },
	{ 0x47ad95b8, "pm_generic_runtime_resume" },
	{ 0xc00d5473, "wake_up_process" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf86c8d03, "kmem_cache_alloc_trace" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0x51760917, "_raw_spin_lock_irqsave" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8297b0ac, "device_for_each_child" },
	{ 0x525a244e, "seq_lseek" },
	{ 0x348df88b, "pm_generic_poweroff" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfdabfe7a, "fd_install" },
	{ 0xcfb5871c, "irq_work_queue" },
	{ 0x14aa0311, "ww_mutex_unlock" },
	{ 0x46dcd35, "pm_generic_thaw" },
	{ 0x6e314ecb, "fget" },
	{ 0x51742fb6, "device_unregister" },
	{ 0x28318305, "snprintf" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x92cc83fa, "ww_mutex_lock_interruptible" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6c6f0f93, "anon_inode_getfile" },
	{ 0xb840d099, "try_module_get" },
	{ 0x85f5e2aa, "krealloc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "532BC08B39BFF6F01109D95");
MODULE_INFO(rhelversion, "8.6");
