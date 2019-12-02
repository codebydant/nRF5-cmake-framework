cmake_minimum_required(VERSION 3.15)
project(nrf52-cmake-example C CXX ASM)

set(NRF_TARGET "nrf52")
set(ARM_NONE_EABI_TOOLCHAIN_PATH "/home/imar-itt/Downloads/gcc-arm-none-eabi-9-2019-q4-major")
set(NRF5_SDK_PATH "/home/imar-itt/Downloads/nRF5SDK160098a08e2")
set(NRFJPROG "/home/imar-itt/Downloads/tool/nRF-Command-Line-Tools_10_5_0_Linux-amd64/nrfjprog/nrfjprog")

 # if (NOT ARM_NONE_EABI_TOOLCHAIN_PATH)
#   message(FATAL_ERROR "The path to the toolchain (arm-non-eabi) must be specified on the command line (add -DARM_NONE_EABI_TOOLCHAIN_PATH=<path>")
# endif ()

# if (NOT NRF5_SDK_PATH)
#   message(FATAL_ERROR "The path to the NRF52 SDK must be specified on the command line (add -DNRF52_SDK_PATH=<path>")
# endif ()

# if (NOT NRFJPROG)
#   message(FATAL_ERROR "the path to the tool nrfjprog must be specified on the command line (add -DNRFJPROG=<path>")
# endif ()

include("cmake/CMake_nRF5x.cmake")
add_subdirectory(src)
