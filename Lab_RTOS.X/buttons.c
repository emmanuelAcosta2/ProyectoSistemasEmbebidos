#include <stdio.h>
#include "utils.h"
#include "buttons.h"
#include "utils/delay.h"
#include "freeRTOS/include/FreeRTOS.h"
#include "enemigo.h"
#include "timers.h"
#include "lectura.h"
#define DELAYDEBOUNCE 50

bool empezarJuego;
estadoBoton estadoBoton1;
estadoBoton estadoBoton2;

void timer2_isr(void) {
    tmr2_cnt_inc();
}

void boton1_isr(void) {
    //Si se apreto y todavia no se solto
    //conta cuanto tiempo va...
    if (estadoBoton1.debounce) { // Control anti-rebotes del bot?n 2
        if (UT_delayms(DELAYDEBOUNCE, estadoBoton1.timer_inicial)) {
            estadoBoton1.debounce = false;
        }
    }



    xTimerStartFromISR(xTimer,0);
    xTimerResetFromISR(xTimer,pdMS_TO_TICKS(1000));

    estadoBoton1.bandera = true;
    milisegundosEnemigo = 1500;
    tiempoRojo = 0;
    puntaje = 0;
    empezarJuego = true;
    terminoJuego = false;
    structCoordenadas.posicion_x = 0;
    structCoordenadas.posicion_y = 0;
    enemigo.octanteEnemigo = octanteEnemigoInicial();
    estadoBoton1.reiniciar = true;


}

void boton2_isr(void) {

    
    
}

void BTN1_reset(void) {

}

void BTN2_reset(void) {

}