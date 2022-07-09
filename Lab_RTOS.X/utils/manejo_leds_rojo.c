
#include "../mcc_generated_files/pin_manager.h"
#include "manejo_leds_rojo.h"
#include "../freeRTOS/include/FreeRTOS.h"


#define tiempo_prendido 400
#define tiempo_apagado 800

/*void startLEDA() {
    statusLEDA.startValue = tmr2_cnt_get();
    statusLEDA.state = UT_TMR_DELAY_INIT;
    LED_A_SetHigh();
}*/

void manejoLedsRojos(void *params) {
    for (;;) {
        vTaskDelay(pdMS_TO_TICKS(tiempo_prendido));
        LED_A_SetLow();
        vTaskDelay(pdMS_TO_TICKS(tiempo_apagado));
        LED_A_SetHigh();
    }

    /*if (statusLEDA.state == UT_TMR_DELAY_INIT) {
        if (UT_delayms(tiempo_prendido, statusLEDA.startValue)) {
            //contador de interrupciones
            statusLEDA.startValue = tmr2_cnt_get();
            //Setear estado apagado
            statusLEDA.state = UT_TMR_DELAY_WAIT;
            //apagar led
            LED_A_SetLow();
        }
    } else if (statusLEDA.state == UT_TMR_DELAY_WAIT) {
        if (UT_delayms(tiempo_apagado, statusLEDA.startValue)) {
            //contador de interrupciones
            statusLEDA.startValue = tmr2_cnt_get();
            //setear estado prendido
            statusLEDA.state = UT_TMR_DELAY_INIT;
            //prender led
            LED_A_SetHigh();
        }
    }*/
}