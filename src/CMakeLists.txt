cmake_minimum_required(VERSION 3.12)

project(nrf52-cmake C CXX ASM)

# define some variables just for this example to determine file locations
set(NRF_PROJECT_NAME ${PROJECT_NAME})
#set(NRF_BOARD pca10040)
#set(NRF_SOFTDEVICE s132)

#nRF5x_toolchainSetup()
include(${DIR_OF_nRF5x_CMAKE}/arm-gcc-toolchain.cmake)
nRF5x_setup()



add_definitions(-DCONFIG_GPIO_AS_PINRESET)

#include_directories(/home/imar-itt/Downloads/nRF5SDK160098a08e2/config/nrf52810/config)
include_directories(./)
include_directories(
        "${NRF5_SDK_PATH}/components/libraries/bsp"
        "${NRF5_SDK_PATH}/components/libraries/button"
)
	
list(APPEND SDK_SOURCE_FILES
        #"${NRF5_SDK_PATH}/<library source file path>"
        "${NRF5_SDK_PATH}/components/libraries/bsp"
        "${NRF5_SDK_PATH}/components/libraries/button"
)
#list(APPEND SOURCE_FILES main.c)
list(APPEND SOURCE_FILES main.cpp)

nRF5x_addExecutable(${PROJECT_NAME} "${SOURCE_FILES}")