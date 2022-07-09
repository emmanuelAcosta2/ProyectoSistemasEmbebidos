

#include <stdbool.h>
#include <stdio.h>

#include "delay.h"
#include "tmr_aux_cnt.h"


ut_tmrDelay_t statusLEDA;

/**
 * 
 * @param timeMS (cantidad de tiempo que necesitamos que demore el delay)
 * @param tmr_initial 
 * @return 
 */
bool UT_delayms(uint16_t timeMS, uint16_t tmr_initial) {
    uint16_t currentTime = tmr2_cnt_get();

    if (currentTime < tmr_initial) { // Overflow TMR2
        return ((65535 - tmr_initial) + currentTime) > timeMS;
    } else {
        return (currentTime - tmr_initial) > timeMS;
    }
}
