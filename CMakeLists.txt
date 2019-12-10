 ##############################################################################
# CMAKE CONFIGURATION
##############################################################################
cmake_minimum_required(VERSION 3.15)

project(nrf52-cmake C ASM)

# set build type = Debug mode
set(CMAKE_BUILD_TYPE Debug)

message("\n" "=========================================")
message("Project: ${PROJECT_NAME} ")
message("=========================================")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

# You must set these variables with your own path
set(NRF_TARGET 						"nrf52"											)	# nrf51 or nrf52
set(ARM_NONE_EABI_TOOLCHAIN_PATH 	"/opt/SEGGER/gcc-arm-none-eabi-9-2019-q4-major"	) 	# Path to root folder 
set(NRF5_SDK_PATH 					"/opt/SEGGER/nRF5SDK"							)	# Path to root folder
set(NRFJPROG 						"/opt/SEGGER/Toolchain/nrfjprog/nrfjprog"		)	# Path to .bin file
#set(MERGE_HEX 						"/opt/SEGGER/Toolchain/mergehex/mergehex"		)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include("${CMAKE_CURRENT_LIST_DIR}/cmake/nRF5x.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/arm-gcc-toolchain.cmake")

##############################################################################
# nRF5x setup
##############################################################################
nRF5x_setup()
nRF5x_addAppScheduler()
nRF5x_addAppFIFO()
nRF5x_addAppTimer()
nRF5x_addAppUART()
nRF5x_addAppButton()
nRF5x_addBSP(TRUE FALSE FALSE)
nRF5x_addBLEGATT()
nRF5x_addBLEService(ble_bas)

add_definitions(-DCONFIG_GPIO_AS_PINRESET)

##############################################################################
# INCLUDE CONFIG FILE: sdk_config.h
##############################################################################
include_directories("${CMAKE_SOURCE_DIR}/config")

##############################################################################
# ERASE BOARD AND FLASH SOFTDEVICE
##############################################################################
add_custom_target(FLASH_ERASE ALL
        COMMAND ${NRFJPROG} --family ${NRF_TARGET} --eraseall
        COMMENT "erasing flashing"
        )

# adds target for erasing and flashing the board with a softdevice
add_custom_target(FLASH_SOFTDEVICE ALL
        COMMAND ${NRFJPROG} --program ${SOFTDEVICE_PATH} -f ${NRF_TARGET} --sectorerase --log
        COMMAND sleep 0.5s
        COMMAND ${NRFJPROG} --reset -f ${NRF_TARGET}
        COMMENT "flashing SoftDevice"
        ) 

##############################################################################
# SOURCE CODE
##############################################################################
list(APPEND SOURCE_FILES "src/main.c")

##############################################################################
# EXECUTABLES
##############################################################################
nRF5x_addExecutable(${PROJECT_NAME} "${SOURCE_FILES}")

##############################################################################
# .hex, .map and .bin file 
##############################################################################
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} ${PROJECT_NAME}.out
        COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.out "${PROJECT_NAME}.bin"
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.out "${PROJECT_NAME}.hex"
        COMMENT "post build steps for ${PROJECT_NAME}")

##############################################################################
# FLASHING PROGRAM TO BOARD 
##############################################################################
add_custom_target("FLASH_${PROJECT_NAME}" ALL
        DEPENDS ${PROJECT_NAME}
        COMMAND ${NRFJPROG} --program ${PROJECT_NAME}.hex -f ${NRF_TARGET} --sectorerase
        COMMAND sleep 0.5s
        COMMAND ${NRFJPROG} --reset -f ${NRF_TARGET}
        COMMENT "flashing ${PROJECT_NAME}.hex"
        )

message("=========================================")
message("Project: ${PROJECT_NAME} COMPILED WITH CMAKE " ${CMAKE_VERSION})
message("=========================================")
