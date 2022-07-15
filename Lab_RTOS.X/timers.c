#include "./freeRTOS/include/FreeRTOS.h"
#include "./freeRTOS/include/timers.h"
#include "./FreeRTOSConfig.h"
#include "utils.h"
#include "sonidos.h"
#include <stdbool.h>

int tiempoRojo;
int milisegundosEnemigo;
bool terminoJuego;
int *tiempoPointer;
int puntaje;
TimerHandle_t xTimer;

void sumarPuntaje(void *params) {

    for (;;) {
        if (!terminoJuego) {
            if (estadoBoton1.bandera) {
                if (!terminoJuego) {
                    puntaje += 5;
                    vTaskDelay(pdMS_TO_TICKS(1000));
                } 
            } else {
                puntaje = 0;
                terminoJuego = false;
                milisegundosEnemigo = 1500;
                tiempoRojo = 0;
            }
        }
    }
}

void callbackTimers(TimerHandle_t xTimer) {

    int* tiempoRojoPointer = (int*) pvTimerGetTimerID(xTimer);



    if ((tiempoRojo) < 150) {
        tiempoRojo = tiempoRojo + 10;
        milisegundosEnemigo = milisegundosEnemigo - 100;
        sonidoAumentarVelocidad();
    } 




    //xTimerStop(xTimer, 0);

}

void crearTimers(void *params) {

    //Crear el timer
    xTimer = xTimerCreate
            (/* Just a text name, not used by the RTOS
                     kernel. */
            "Timer",
            /* The timer period in ticks, must be
            greater than 0. */
            pdMS_TO_TICKS(1000),
            /* The timers will auto-reload themselves
            when they expire. */
            pdTRUE,
            /* Aca iria el bloque de memoria creado con malloc que contiene el struct con el numero de led y el color */
            (void *) tiempoPointer,
            /* Each timer calls the same callback when
            it expires. */
            callbackTimers
            );

    if (xTimerStart(xTimer, 0) != pdPASS) {
        /* The timer could not be set into the Active
        state. */
    }
    xTimerStop(xTimer, 0);
    vTaskDelete(NULL);
}

