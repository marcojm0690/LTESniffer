/*
 * <linux/if_tun.h> shim for macOS. See linux/if.h in this same directory —
 * same reasoning: the real TUNSETIFF/IFF_TUN Linux TUN setup is behind
 * #ifdef __APPLE__ guards and never compiled here; this just needs to exist.
 */
#pragma once
