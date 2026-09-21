/*
 * Minimal netinet/sctp.h shim for macOS.
 *
 * macOS has no kernel SCTP or libsctp. srsRAN's network_utils only needs these
 * declarations to compile; SCTP is used for S1AP (eNB/EPC), which LTESniffer
 * never runs. Any attempt to actually use SCTP at runtime fails with
 * EPROTONOSUPPORT.
 */
#pragma once

#include <cerrno>
#include <cstdint>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#ifndef SOL_SCTP
#define SOL_SCTP IPPROTO_SCTP
#endif

#define SCTP_RTOINFO 0
#define SCTP_INITMSG 2
#define SCTP_EVENTS 11

typedef int sctp_assoc_t;

struct sctp_sndrcvinfo {
  uint16_t     sinfo_stream;
  uint16_t     sinfo_ssn;
  uint16_t     sinfo_flags;
  uint32_t     sinfo_ppid;
  uint32_t     sinfo_context;
  uint32_t     sinfo_timetolive;
  uint32_t     sinfo_tsn;
  uint32_t     sinfo_cumtsn;
  sctp_assoc_t sinfo_assoc_id;
};

struct sctp_event_subscribe {
  uint8_t sctp_data_io_event;
  uint8_t sctp_association_event;
  uint8_t sctp_address_event;
  uint8_t sctp_send_failure_event;
  uint8_t sctp_peer_error_event;
  uint8_t sctp_shutdown_event;
  uint8_t sctp_partial_delivery_event;
  uint8_t sctp_adaptation_layer_event;
  uint8_t sctp_authentication_event;
  uint8_t sctp_sender_dry_event;
};

struct sctp_rtoinfo {
  sctp_assoc_t srto_assoc_id;
  uint32_t     srto_initial;
  uint32_t     srto_max;
  uint32_t     srto_min;
};

struct sctp_initmsg {
  uint16_t sinit_num_ostreams;
  uint16_t sinit_max_instreams;
  uint16_t sinit_max_attempts;
  uint16_t sinit_max_init_timeo;
};

static inline int sctp_recvmsg(int, void*, size_t, struct sockaddr*, socklen_t*, struct sctp_sndrcvinfo*, int*)
{
  errno = EPROTONOSUPPORT;
  return -1;
}
