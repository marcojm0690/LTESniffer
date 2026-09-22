/*
 * <linux/udp.h> shim for macOS: struct udphdr with the Linux field names
 * (macOS's <netinet/udp.h> names them uh_sport, uh_dport, ...).
 */
#pragma once

#include <stdint.h>

struct udphdr {
  uint16_t source;
  uint16_t dest;
  uint16_t len;
  uint16_t check;
};
