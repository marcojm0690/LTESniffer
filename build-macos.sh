#!/usr/bin/env bash
# Build LTESniffer natively on macOS (Apple silicon), no VM.
# Needs: brew install cmake pkg-config uhd fftw boost glib libconfig mbedtls@3
set -euo pipefail
cd "$(dirname "$0")"
B=build-mac
mkdir -p $B

# CMake 4's ExternalProject download is broken for these old sub-projects, and
# srsRAN needs macOS patches, so fetch/patch the sources ourselves.
[ -d $B/srsRAN-src ] || {
  git clone --depth 1 https://github.com/ShaoPaoLao/srsRAN2.git $B/srsRAN-src
  git -C $B/srsRAN-src apply "$PWD/external/patches/srsran-macos.patch"
}

export PKG_CONFIG_PATH="/opt/homebrew/opt/mbedtls@3/lib/pkgconfig:${PKG_CONFIG_PATH:-}"
cd $B
cmake .. -DCMAKE_BUILD_TYPE=Release -DENABLE_BLADERF=OFF -DENABLE_SOAPYSDR=OFF -DENABLE_GUI=OFF \
  -DENABLE_SRSUE=OFF -DENABLE_SRSENB=OFF -DENABLE_SRSEPC=OFF \
  -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DCMAKE_PREFIX_PATH=/opt/homebrew
make -j"$(sysctl -n hw.ncpu)"
echo "Built: $PWD/src/LTESniffer"
