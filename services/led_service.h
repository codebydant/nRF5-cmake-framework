/*
 * The MIT License (MIT)
 * Copyright (c) 2018 Novel Bits
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#ifndef LED_SERVICE_H
#define LED_SERVICE_H

#include "ble.h"
#include "ble_srv_common.h"
#include "boards.h"
#include "nrf_sdh_ble.h"
#include <stdint.h>

/**@brief   Macro for defining a ble_led_service instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */

#define BLE_LED_SERVICE_BLE_OBSERVER_PRIO 2

#define BLE_LED_SERVICE_DEF(_name)                                                                                                                                                                                                                       \
    static ble_led_service_t _name;                                                                                                                                                                                                                      \
    NRF_SDH_BLE_OBSERVER(_name##_obs, BLE_LED_SERVICE_BLE_OBSERVER_PRIO, ble_led_service_on_ble_evt, &_name)

// LED service:                     E54B0001-67F5-479E-8711-B3B99198CE6C
//   LED 2 characteristic:   E54B0002-67F5-479E-8711-B3B99198CE6C

// The bytes are stored in little-endian format, meaning the
// Least Significant Byte is stored first
// (reversed from the order they're displayed as)

// Base UUID: E54B0000-67F5-479E-8711-B3B99198CE6C
#define BLE_UUID_LED_SERVICE_BASE_UUID                                                                                                                                                                                                                   \
    { 0x6C, 0xCE, 0x98, 0x91, 0xB9, 0xB3, 0x11, 0x87, 0x9E, 0x47, 0xF5, 0x67, 0x00, 0x00, 0x4B, 0xE5 }

// Service & characteristics UUIDs
#define BLE_UUID_LED_SERVICE_UUID 0x0001
#define BLE_UUID_LED_2_CHAR_UUID 0x0002

// Forward declaration of the custom_service_t type.
typedef struct ble_led_service_s ble_led_service_t;

typedef void (*ble_led_service_led_write_handler_t)(uint16_t conn_handle, ble_led_service_t *p_led_service, uint8_t new_state);

/** @brief LED Service init structure. This structure contains all options and data needed for
 *        initialization of the service.*/
typedef struct { ble_led_service_led_write_handler_t led_write_handler; /**< Event handler to be called when the LED Characteristic is written. */ } ble_led_service_init_t;

/**@brief LED Service structure.
 *        This contains various status information
 *        for the service.
 */
typedef struct ble_led_service_s {
    uint16_t conn_handle;
    uint16_t service_handle;
    uint8_t uuid_type;
    ble_gatts_char_handles_t led_2_char_handles;
    ble_led_service_led_write_handler_t led_write_handler;

} ble_led_service_t;

// Function Declarations

/**@brief Function for initializing the LED Service.
 *
 * @param[out]  p_led_service  LED Service structure. This structure will have to be supplied by
 *                                the application. It will be initialized by this function, and will later
 *                                be used to identify this particular service instance.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_led_service_init(ble_led_service_t *p_led_service, const ble_led_service_init_t *p_led_service_init);

/**@brief Function for handling the application's BLE stack events.
 *
 * @details This function handles all events from the BLE stack that are of interest to the LED Service.
 *
 * @param[in] p_ble_evt  Event received from the BLE stack.
 * @param[in] p_context  LED Service structure.
 */
void ble_led_service_on_ble_evt(ble_evt_t const *p_ble_evt, void *p_context);

#endif /* LED_SERVICE_H */