/* Copyright (c) 2014, ENEA Software AB
 * Copyright (c) 2014, Nokia
 * All rights reserved.
 *
 * SPDX-License-Identifier:	BSD-3-Clause
 */

#ifndef __OFP_TYPES_H__
#define __OFP_TYPES_H__

#include <stdint.h>
#include "ofp_queue.h"

#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

/**
 * Result of processing a packet. Indicates what, if anything, the
 * caller should do with the packet.
 */
enum ofp_return_code {
	/**
	 * The caller may continue processing the packet, and should
	 * eventually free it.
	 */
	OFP_PKT_CONTINUE = 0,
	/**
	 * The packet has been processed and may already have been
	 * freed. The caller should not use the packet any further and
	 * should not free it.
	 */
	OFP_PKT_PROCESSED,
	/**
	 * The packet is dropped. The caller should free the packet.
	 */
	OFP_PKT_DROP
};

struct ofp_nh_entry {
	uint32_t flags;
	uint32_t gw;
	uint16_t port;
	uint16_t vlan;
	uint32_t arp_ent_idx;
};

struct pkt6_entry;
OFP_SLIST_HEAD(pkt6_list, pkt6_entry);

struct ofp_nh6_entry {
	uint32_t flags;
	uint8_t  gw[16];
	uint16_t port;
	uint16_t vlan;
	uint8_t  mac[6];
	struct pkt6_list pkt6_hold;
};

#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif /* __OFP_TYPES_H__ */
