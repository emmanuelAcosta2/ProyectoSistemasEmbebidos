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

#ifndef _TIMERS_H    /* Guard against multiple inclusion */
#define _TIMERS_H

#include "freeRTOS/include/timers.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    extern int *tiempoPointer;
    void sumarPuntaje(void *params);
    void crearTimers(void *params);
    void callbackTimers(TimerHandle_t xTimer);
    





    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
