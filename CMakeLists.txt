 ##############################################################################
# CMAKE CONFIGURATION
##############################################################################
cmake_minimum_required(VERSION 3.15)

project(nrf52-cmake C CXX ASM)

# set build type = Debug mode
set(CMAKE_BUILD_TYPE Release)

message("\n" "=========================================")
message("Project: ${PROJECT_NAME} ")
message("=========================================")
set(NRF_TARGET "nrf52")
set(NRF_SDH_BLE_ENABLED 1)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_STANDARD 99)

# You must set these variables with your own path
set(ARM_NONE_EABI_TOOLCHAIN_PATH "/opt/SEGGER/GNU_Arm_Embedded_Toolchain") 	   # Path to root folder 
set(NRF5_SDK_PATH "/opt/SEGGER/nRF5SDK")									   # Path to root folder
set(NRFJPROG "/opt/SEGGER/NRFJPROG/nrfjprog/nrfjprog")						   # Path to .bin file

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include("${CMAKE_CURRENT_LIST_DIR}/cmake/nRF5x.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/arm-gcc-toolchain.cmake")

##############################################################################
# MACROS
##############################################################################
nRF5x_setup()
add_definitions(-DCONFIG_GPIO_AS_PINRESET)

##############################################################################
# CONFIG FILE: sdk_config.h
##############################################################################
include_directories("${CMAKE_SOURCE_DIR}/config")

##############################################################################
# SOURCE CODE
##############################################################################
#list(APPEND SOURCE_FILES "src/main.c")
list(APPEND SOURCE_FILES "src/main.cpp")

##############################################################################
# EXECUTABLES
##############################################################################
nRF5x_addExecutable(${PROJECT_NAME} "${SOURCE_FILES}")

message("=========================================")
message("Project: ${PROJECT_NAME} COMPILED WITH CMAKE " ${CMAKE_VERSION})
message("=========================================")
