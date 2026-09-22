/*
 * <linux/ip.h> shim for macOS: struct iphdr with Linux's field names/layout.
 * srsenb/srsepc cast raw wire bytes directly onto this struct, so the layout
 * must match glibc's exactly, not just provide equivalent fields (macOS's
 * own <netinet/ip.h> struct ip uses different names *and* a different
 * bit-order convention). This is the little-endian bitfield layout glibc
 * uses on LE architectures (incl. Apple Silicon).
 */
#pragma once

#include <stdint.h>

struct iphdr {
  uint8_t  ihl : 4;
  uint8_t  version : 4;
  uint8_t  tos;
  uint16_t tot_len;
  uint16_t id;
  uint16_t frag_off;
  uint8_t  ttl;
  uint8_t  protocol;
  uint16_t check;
  uint32_t saddr;
  uint32_t daddr;
  /* options start here */
};
