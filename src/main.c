#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_log.h"
#include <nrfx_log.h>
#include <libraries/log/nrf_log_ctrl.h>
#include <libraries/log/nrf_log_default_backends.h>
#include "bsp.h"
#include "nrf.h"
#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "system_nrf52.h"
#include "nrf_delay.h"
#include "sdk_config.h"

#define ENABLE_SWD 1

static const uint8_t leds_list[LEDS_NUMBER] = { 9, 7, LED_3, LED_4 };

int main(void)
{

	NRF_LOG_INIT((void*)0);
    NRF_LOG_DEFAULT_BACKENDS_INIT();
    /* Configure LED-pins as outputs. */
    
    LEDS_CONFIGURE(LEDS_MASK);
    while (true)
    {
    	 NRF_LOG_PROCESS();
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            LEDS_INVERT(1 << leds_list[i]);
           
            nrf_delay_ms(500);
        }
        
        NRF_LOG_INFO("testing print CMAKE\n");
        NRF_LOG_FLUSH();
    }
}
// https://devzone.nordicsemi.com/f/nordic-q-a/20314/error-jlinkarm-dll-reported-an-error-try-again
// https://github.com/JF002/nrf52-baseproject
// https://github.com/Polidea/cmake-nRF5x