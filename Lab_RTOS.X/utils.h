/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef UTILS_H    /* Guard against multiple inclusion */
#define UTILS_H

#include "./freeRTOS/include/FreeRTOS.h"

#include "./freeRTOS/include/FreeRTOS.h"
#include "./freeRTOS/include/semphr.h"
#include "./freeRTOS/include/timers.h"
#include <stdbool.h>
#include <stdint.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
#ifndef  EXTERN
#define  EXTERN  extern
#endif

    typedef struct {
        uint16_t timer_inicial;
        bool debounce;
        bool bandera;
        bool reiniciar;
        bool timers;
    } estadoBoton;
    EXTERN estadoBoton estadoBoton1;
    EXTERN estadoBoton estadoBoton2;

    EXTERN TimerHandle_t xTimer;

    extern SemaphoreHandle_t semaforoStructCoordenadas;
    extern SemaphoreHandle_t semaforoArrayLedsYSend;
    extern SemaphoreHandle_t semaforoStructEnemigo;

    EXTERN int milisegundosEnemigo;
    EXTERN int tiempoRojo;
    EXTERN bool terminoJuego;
    EXTERN int puntaje;
    EXTERN bool empezarJuego;


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
