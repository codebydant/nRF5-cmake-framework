cmake_minimum_required(VERSION 3.15)

project(nrf52-cmake-example C CXX ASM)

# You must set this variables with your own path
set(NRF_TARGET "nrf52")
set(ARM_NONE_EABI_TOOLCHAIN_PATH "/home/imar-itt/Downloads/gcc-arm-none-eabi-9-2019-q4-major")
set(NRF5_SDK_PATH "/home/imar-itt/Downloads/nRF5SDK160098a08e2")
set(NRFJPROG "/home/imar-itt/Downloads/tool/nRF-Command-Line-Tools_10_5_0_Linux-amd64/nrfjprog/nrfjprog")

include("cmake/CMake_nRF5x.cmake")

# define some variables for this project
include(${DIR_OF_nRF5x_CMAKE}/arm-gcc-toolchain.cmake)

nRF5x_setup()
add_definitions(-DCONFIG_GPIO_AS_PINRESET)

# define include libraries 
include_directories(
        "${NRF5_SDK_PATH}/components/libraries/bsp"
        "${NRF5_SDK_PATH}/components/libraries/button"
        .
)
	
list(APPEND SDK_SOURCE_FILES  
        "${NRF5_SDK_PATH}/components/libraries/bsp"
        "${NRF5_SDK_PATH}/components/libraries/button"
)

# source file
#list(APPEND SOURCE_FILES "src/main.c")
list(APPEND SOURCE_FILES "src/main.cpp")

# create executable file
nRF5x_addExecutable(${PROJECT_NAME} "${SOURCE_FILES}")
