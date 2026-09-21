/*
 * Force-included on macOS (see CMakeLists.txt). glibc's headers transitively
 * pull in the <endian.h> helpers that srsRAN uses without including them.
 */
#pragma once

#ifdef __APPLE__
#ifdef __cplusplus
// srsRAN includes <complex.h> from inside extern "C" blocks; libc++ then pulls
// <complex> in with C linkage. Having it included first avoids that.
#include <complex>
#endif
#include <libkern/OSByteOrder.h>

#ifndef htole16
#define htole16(x) OSSwapHostToLittleInt16(x)
#define le16toh(x) OSSwapLittleToHostInt16(x)
#define htole32(x) OSSwapHostToLittleInt32(x)
#define le32toh(x) OSSwapLittleToHostInt32(x)
#define htole64(x) OSSwapHostToLittleInt64(x)
#define le64toh(x) OSSwapLittleToHostInt64(x)
#define htobe16(x) OSSwapHostToBigInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)
#define htobe32(x) OSSwapHostToBigInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)
#define htobe64(x) OSSwapHostToBigInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
#endif
#endif
