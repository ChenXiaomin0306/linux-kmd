/*
 * include/linux/idr.h
 * 
 * 2002-10-18  written by Jim Houston jim.houston@ccur.com
 *	Copyright (C) 2002 by Concurrent Computer Corporation
 *	Distributed under the GNU GPL license version 2.
 *
 * Small id to pointer translation service avoiding fixed sized
 * tables.
 */

#ifndef __BACKPORT_LINUX_IDR_H__
#define __BACKPORT_LINUX_IDR_H__

#include_next <linux/idr.h>

#define idr_init_base LINUX_BACKPORT(idr_init_base)
static inline void backport_idr_init_base(struct idr *idr, int base)
{
    idr_init(idr);
}


#endif /* __BACKPORT_LINUX_IDR_H__ */
