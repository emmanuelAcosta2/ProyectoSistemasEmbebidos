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
#include "./freeRTOS/include/semphr.h"
#include <stdbool.h>
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
#ifndef  EXTERN
#define  EXTERN  extern
#endif




    extern SemaphoreHandle_t semaforoStructCoordenadas;
    extern SemaphoreHandle_t semaforoArrayLedsYSend;
    extern SemaphoreHandle_t semaforoStructEnemigo;

    EXTERN int milisegundosEnemigo;
    EXTERN int tiempoRojo;
    EXTERN bool terminoJuego;
    EXTERN int puntaje;
    

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
