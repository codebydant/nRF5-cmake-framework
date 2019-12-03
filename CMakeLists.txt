##############################################################################
# CMAKE CONFIGURATION
##############################################################################
cmake_minimum_required(VERSION 3.15)
project(nrf52-cmake C CXX ASM)

# set build type = Debug mode
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

message("\n" "=========================================")
message("Project: ${PROJECT_NAME} ")
message("=========================================")

##############################################################################
# VARIABLES TO SET BY DEVELOPER
##############################################################################
set(NRF_TARGET "nrf52")														   # set nrf51 or nrf52
set(ARM_NONE_EABI_TOOLCHAIN_PATH "/opt/SEGGER/GNU_Arm_Embedded_Toolchain") 	   # Path to root folder 
set(NRF5_SDK_PATH "/opt/SEGGER/nRF5SDK")									   # Path to root folder
set(NRFJPROG "/opt/SEGGER/NRFJPROG/nrfjprog/nrfjprog")						   # Path to .bin file

include("${CMAKE_CURRENT_LIST_DIR}/cmake/nRF5x.cmake")						   # nRF5x library headers 
include("${CMAKE_CURRENT_LIST_DIR}/cmake/arm-gcc-toolchain.cmake")

##############################################################################
# nRF5 MACRO FUNCTION
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
list(APPEND SOURCE_FILES "src/main.c")
#list(APPEND SOURCE_FILES "src/main.cpp")

##############################################################################
# EXECUTABLES
##############################################################################
nRF5x_addExecutable(${PROJECT_NAME} "${SOURCE_FILES}")

message("=========================================")
message("Project: ${PROJECT_NAME} COMPILED WITH CMAKE " ${CMAKE_VERSION})
message("=========================================")
