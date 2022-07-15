#include "./freeRTOS/include/FreeRTOS.h"
#include "./freeRTOS/include/timers.h"
#include "./FreeRTOSConfig.h"
#include "utils.h"
#include "sonidos.h"

int tiempoRojo;
int milisegundosEnemigo;
int *tiempoPointer;

void callbackTimers(TimerHandle_t xTimer) {

    int* tiempoRojoPointer = (int*) pvTimerGetTimerID(xTimer);


    
    if ((tiempoRojo) < 150) {
        tiempoRojo = tiempoRojo + 10;
        milisegundosEnemigo = milisegundosEnemigo - 100;
        sonidoAumentarVelocidad();
    } else {
        vTaskDelete(NULL);
    }




    xTimerStop(xTimer, 0);

}

void crearTimers(void *params) {
    
    milisegundosEnemigo = 1500;

    //Debe haber un struct que tenga el tiempo

    for (int i = 1; i <= 15; i++) {
        //Crear el timer
        TimerHandle_t xTimer;
        xTimer = xTimerCreate
                (/* Just a text name, not used by the RTOS
                     kernel. */
                "Timer",
                /* The timer period in ticks, must be
                greater than 0. */
                pdMS_TO_TICKS(10000),
                /* The timers will auto-reload themselves
                when they expire. */
                pdFALSE,
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
        vTaskDelay(10000);

    }


    for (;;);
}

