

#ifndef _manejo_leds_rgb_h    /* Guard against multiple inclusion */
#define _manejo_leds_rgb_h


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <time.h>

#include "../freeRTOS/include/FreeRTOS.h"
#include "../freeRTOS/include/semphr.h"

// *****************************************************************************

/** 
  @Description
   "led" indica cuál fue el LED modificado (de 1 a 8).
    ? ?color? indica el color a encender en el LED:
    ? 0 es blanco
    ? 1 es rojo
    ? 2 es azul
    ? 3 es verde
    ? 4 es negro (Apagado)
    ? "time" es el momento en el que se modificó el estado del LED.
 */
typedef struct {
    uint8_t led;
    uint8_t color;
    struct tm time;
} app_register_t;

typedef struct {
    int numeroLed;
    int color;
} queueStruct;

extern SemaphoreHandle_t xSemaphoreMutex;

extern QueueHandle_t xQueueComandos;

bool ledValido(int numLed);

bool colorValido(int colorNum);

bool rgbValido(int numRgb);

char* ultimoLedModificado();

void apagarLeds();

void setLEDRGBComun(int ledNum, int colorNum);

void setLEDRGBPorColor(int ledNum, int valoresRGB[]);

void consumirComandosQueue( void *params );


#endif 

/* *****************************************************************************
 End of File
 */
