/*
 * <linux/if.h> shim for macOS. Nothing here is actually used on macOS: the
 * only real Linux TUN setup code (struct ifreq's ifr_ifrn union, IFF_TUN,
 * TUNSETIFF) lives behind #ifdef __APPLE__/#else guards in srsepc's gtpu.cc,
 * which take the utun_compat.h path instead on macOS. This just needs to
 * exist so the unconditional #include at the top of those files resolves.
 */
#pragma once
