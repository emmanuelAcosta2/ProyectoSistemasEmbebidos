

#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#include "WS2812.h"
#include "../mcc_generated_files/rtcc.h"
#include "manejo_leds_rgb.h"
#include "mensajes.h"
#include "../utils.h"
#include "../enemigo.h"

#define CANTIDAD_LEDS 8            

#define MIN_COLOR 0             //Colores posibles a elegir
#define MAX_COLOR 4             

#define MIN_RGBVAL 0            // Valores posibles para rgb
#define MAX_RGBVAL 255          

ws2812_t arrayLed[CANTIDAD_LEDS]; // Conjunto de los LED RGB de la placa

app_register_t ultimoLedModificadoAppRegister; // Ultimo led modificado
EXTERN enemigoStruct enemigo;
char valoresUtimoLed[150]; // String con los valores del ultimo led modificado

SemaphoreHandle_t semaforoStructCoordenadas;
SemaphoreHandle_t semaforoArrayLedsYSend;
QueueHandle_t xQueueComandos;

int mapearEnemigo(int octante) {
    switch (octante) {
        case 1:
            return 3;

        case 2:
            return 2;

        case 3:
            return 1;

        case 4:
            return 4;

        case 5:
            return 6;

        case 6:
            return 7;

        case 7:
            return 8;

        case 8:
            return 5;

    }

}

/**
 * Correspondencia entre el led ingresado y el led de la placa
 * @param led
 * @return 
 */
int mapearLeds(int led) {
    switch (led) {
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 7;
        case 8:
            return 6;
    }
}

/**
 * Correspondencia entre color ingresado y las constantes
 * @param colorNum
 * @return 
 */
ws2812_t obtenerColor(int colorNum) {
    switch (colorNum) {
        case 0:
            return WHITE;
        case 1:
            return RED;
        case 2:
            return BLUE;
        case 3:
            return GREEN;
        case 4:
            return OFF;
        case 5:
            return PURPLE;
        case 6:
            return CYAN;
    }
}

/**
 * El led es valido
 * @param led
 * @return Verdadero si es v?lido, falso de lo contrario.
 */
bool ledValido(int led) {
    return 1 <= led && led <= CANTIDAD_LEDS;
}

/**
 * Indica color valido
 * @param color
 * @return Verdadero si es v?lido, falso de lo contrario.
 */
bool colorValido(int color) {
    return MIN_COLOR <= color && color <= MAX_COLOR;
}

/**
 * Indica valor RGB valido.
 * @param valor
 * @return Verdadero si es v?lido, falso de lo contrario.
 */
bool rgbValido(int valor) {
    return MIN_RGBVAL <= valor && valor <= MAX_RGBVAL;
}

/**
 * @return Puntero al string con la info del ulitmo led modificado
 */
char* ultimoLedModificado() {
    char fechaInfo[22];
    //Formatear el tiempo representado en la estructura de acuerdo al formato pasado como "%d/%m/%Y - %X"
    strftime(fechaInfo, sizeof (fechaInfo), FORMATO_FECHA, &(ultimoLedModificadoAppRegister.time));

    //Enviar informacion formateada a valoresUtimoLed.
    sprintf(valoresUtimoLed, FECHA_ULTIMA_MODIFICACION,
            ultimoLedModificadoAppRegister.led, ultimoLedModificadoAppRegister.color, fechaInfo);
    return valoresUtimoLed;
}

/**
 * Apaga leds sin alterar la info del ultime led modificado. (lastLEDModified).
 */
void apagarLeds() {
    int i;
    //recorrer el array de leds y asignarle el color OFF.
    for (i = 0; i < CANTIDAD_LEDS; i++) {
        arrayLed[i] = OFF;
    }
    //usar libreria
    WS2812_send(arrayLed, CANTIDAD_LEDS);
}

/**
 * Para cada LED se le asigna un color 1 a 1 desde el numero de color predefinido.
 * @param ledNum
 * @param colorNum
 */
void setLEDRGBBlanca(int ledNum, int colorNum) {
    if (semaforoArrayLedsYSend != NULL) {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait 10 ticks to see if it becomes free. */
        if (xSemaphoreTake(semaforoArrayLedsYSend, (TickType_t) 10) == pdTRUE) {
            int i;
            //recorrer el array de leds y asignarle el color OFF.
            for (i = 0; i < CANTIDAD_LEDS; i++) {
                /*if(i == enemigo.octanteEnemigo){
                    continue;
                }*/
                arrayLed[i] = OFF;


            }
            arrayLed[mapearLeds(mapearEnemigo(enemigo.octanteEnemigo))] = obtenerColor(1);
            arrayLed[mapearLeds(ledNum)] = obtenerColor(colorNum);
            WS2812_send(arrayLed, CANTIDAD_LEDS);


            // Actualiza los datos del ?ltimo LED modificado
            ultimoLedModificadoAppRegister.led = ledNum;
            ultimoLedModificadoAppRegister.color = colorNum;
            RTCC_TimeGet(&ultimoLedModificadoAppRegister.time);
            xSemaphoreGive(semaforoArrayLedsYSend);
        } else {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }
    // Establece el color del LED indicado, sin modificar el estado de los otros
    // LED.

}

void setLEDRGBComun(int ledNum, int colorNum) {

    /* See if we can obtain the semaphore.  If the semaphore is not
    available wait 10 ticks to see if it becomes free. */

    int i;
    arrayLed[mapearLeds(ledNum)] = obtenerColor(colorNum);
    WS2812_send(arrayLed, CANTIDAD_LEDS);


    // Actualiza los datos del ?ltimo LED modificado
    ultimoLedModificadoAppRegister.led = ledNum;
    ultimoLedModificadoAppRegister.color = colorNum;
    RTCC_TimeGet(&ultimoLedModificadoAppRegister.time);


}

void setLEDRGBEnemigo(int ledNum, int colorNum, int milisegundosEnemigo) {
    if (semaforoArrayLedsYSend != NULL) {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait 10 ticks to see if it becomes free. */
        if (xSemaphoreTake(semaforoArrayLedsYSend, (TickType_t) 10) == pdTRUE) {
            int i;
            //recorrer el array de leds y asignarle el color OFF.
            for (i = 0; i < CANTIDAD_LEDS; i++) {
                //if (i == colorNum) {
                //    arrayLed[i] = OFF;
                //}
            }
            arrayLed[mapearLeds(ledNum)] = obtenerColor(colorNum);
            WS2812_send(arrayLed, CANTIDAD_LEDS);
            xSemaphoreGive(semaforoArrayLedsYSend);
            vTaskDelay(pdMS_TO_TICKS(milisegundosEnemigo));

            // Actualiza los datos del ?ltimo LED modificado
            ultimoLedModificadoAppRegister.led = ledNum;
            ultimoLedModificadoAppRegister.color = colorNum;
            RTCC_TimeGet(&ultimoLedModificadoAppRegister.time);

        } else {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }
    // Establece el color del LED indicado, sin modificar el estado de los otros
    // LED.

}

/**
 * Consume los comandos del queue
 * @param pvParameters
 */
void consumirComandosQueue(void *params) {
    //xQueueComandos = xQueueCreate(20, sizeof ( queueStruct));
    //SemaphoreMutex = xSemaphoreCreateMutex();
    for (;;) {
        //TOMAR SEMAFORO DEL QUEUE
        //if (xSemaphoreMutex != NULL) {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait 10 ticks to see if it becomes free. */
        //  if (xSemaphoreTake(xSemaphoreMutex, (TickType_t) 10) == pdTRUE) {
        //Quitar del queue
        if (xQueueComandos != NULL) {
            queueStruct* ptr;
            /* Receive a message from the created queue to hold complex struct AMessage
            structure.  Block for 10 ticks if a message is not immediately available.
            The value is read into a struct AMessage variable, so after calling
            xQueueReceive() xRxedStructure will hold a copy of xMessage. */
            if (xQueueReceive(xQueueComandos,
                    (&ptr),
                    (TickType_t) 10) == pdPASS) {
                //LLAMAR AL SETEO DEL LED
                setLEDRGBBlanca((*ptr).numeroLed, (*ptr).color);
            }
        }
        //LIBERAR SEMAFORO DEL QUEUE
        //    xSemaphoreGive(xSemaphoreMutex);
        //} else {
        //    /* We could not obtain the semaphore and can therefore not access
        //   the shared resource safely. */
        //}
    }
}





