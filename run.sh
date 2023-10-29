#!/usr/bin/bash
#
# This run script will build with Ninja and clang++,
# and therefore should only be used if you wish to use
# those two in tandem. If not, build using CMake for whatever
# way you wish.

mkdir -p build
cd build
export CC=clang
export CXX=clang++
cmake -GNinja .. && ninja neptune && ./neptune
