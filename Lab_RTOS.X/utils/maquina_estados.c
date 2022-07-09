#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../mcc_generated_files/rtcc.h"

#include "../freeRTOS/include/FreeRTOS.h"
#include "../freeRTOS/include/timers.h"
#include "../FreeRTOSConfig.h"
#include "manejoUSB.h"
#include "manejo_leds_rgb.h"
#include "WS2812.h"

#include "fecha_hora.h"

#include "mensajes.h"
#include "maquina_estados.h"



#define MENU_MAX 1            // Indican el rango posible de opciones
#define MENU_MIN 5            // que puede ingresar el usuario en el menú
// principal.

#define MAX_SEGUNDOS 120
#define MIN_SEGUNDOS 0


int estado = 0; // Almacena el estado actual de la máquina
bool accionEnviada = false; // Se envió una instrucción?

int ledNumTemp; // Variables auxiliares para el control de los
int valoresRGB[3]; // LED RGB.
int colorRGB;
int tiempoComando;

typedef enum {
    ESTADO_INICIAL = 0,
    INGRESAR_ANIO = 11,
    INGRESAR_MES = 12,
    INGRESAR_DIA = 13,
    INGRESAR_HORA = 14,
    INGRESAR_MINUTO = 15,
    FINALIZAR_CONFIG_FECHA = 16,
    MOSTRAR_FECHA = 21,
    EDITAR_LEDS = 31,
    INGRESAR_COLOR = 32,
    INGRESAR_TIEMPO = 33,
    FINALIZAR_EDICION = 34,
    INGRESAR_LED_RGB = 41,
    INGRESAR_ROJO = 42,
    INGRESAR_VERDE = 43,
    INGRESAR_AZUL = 44,
    FINALIZAR_CONFIG_RGB = 45,
    MOSTRAR_FECHA_ULTIMO_LED = 51


} ESTADOS_MAQ;

ESTADOS_MAQ enum_estados;

/**
 * Pone en buffer una acción para enviar a PC.
 * @param accion accion a enviar
 * @return 
 */
bool enviarAccion(char accion[]) {
    if (accionEnviada) {
        return false;
    } else {
        strcpy(buffer, accion);
        accionEnviada = true;
        setDatosPendientes();
        return true;
    }
}

/**
 * Pone en buffer una alerta
 * @param alerta
 */
void alerta(char alerta[]) {
    strcpy(buffer, alerta);
    setDatosPendientes();
}

void cambiarEstado(int estadoSiguiente) {
    estado = estadoSiguiente;
    accionEnviada = false;
}

void cambiarColor(char inst[], int estado, int rgb) {
    enviarAccion(inst);

    if (banderaEntradaPC()) {
        if (rgbValido(obtenerValorPC())) {
            valoresRGB[rgb] = obtenerValorPC();
            cambiarEstado(estado);
        } else {
            alerta(RGB_COLOR);
        }
        limpiarBanderaPC();
    }
}

void enviarTiempoActual() {
    char tiempo[20];

    RTCC_TimeGet(&tiempo_temp);

    strftime(tiempo, sizeof (tiempo), "%x - %X", &tiempo_temp);

    sprintf(buffer, "%s %s %s", FECHA_ACTUAL, tiempo, CONTINUAR);

    setDatosPendientes();
}

void estadoInicial() {
    if (banderaEntradaPC()) {
        if (!enviarAccion(MENU)) {
            if (MENU_MAX <= obtenerValorPC() && obtenerValorPC() <= MENU_MIN) {
                //Los estados van por decimas.
                cambiarEstado(obtenerValorPC() * 10 + 1);
            } else {
                alerta(MENU_ERROR);
            }
        }
        limpiarBanderaPC();
    }
}

/**
 * Ingreso de año, cada parte del menú se subdivide en decimas, por lo cual de 11 a 19 será uno, de 21 a 29 otro etc...
 */
void ingresarAnio11() {
    enviarAccion(ANIO);

    if (banderaEntradaPC()) {
        if (anioValido(obtenerValorPC())) {
            tiempo_temp.tm_year = obtenerValorPC() - 1900;
            cambiarEstado(12);
        } else {
            alerta(ANIO_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingresarMes12() {
    enviarAccion(MES);

    if (banderaEntradaPC()) {
        if (mesValido(obtenerValorPC())) {
            tiempo_temp.tm_mon = obtenerValorPC() - 1;
            cambiarEstado(13);
        } else {
            alerta(MES_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingresarDia13() {
    enviarAccion(DIA);

    if (banderaEntradaPC()) {
        if (diaValido(obtenerValorPC())) {
            tiempo_temp.tm_mday = obtenerValorPC();
            cambiarEstado(14);
        } else {
            alerta(DIA_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingresarHoras14() {
    enviarAccion(HORA);

    if (banderaEntradaPC()) {
        if (horaValida(obtenerValorPC())) {
            tiempo_temp.tm_hour = obtenerValorPC();
            cambiarEstado(15);
        } else {
            alerta(HORA_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingresarMinuto15() {
    enviarAccion(MINUTO);

    if (banderaEntradaPC()) {
        if (minutoValido(obtenerValorPC())) {
            tiempo_temp.tm_min = obtenerValorPC();
            RTCC_TimeSet(&tiempo_temp);
            cambiarEstado(16);
        } else {
            alerta(MINUTO_ERROR);
        }
        limpiarBanderaPC();
    }
}

void finalizarConfiguracion16() {
    enviarAccion(FECHA_FIN);
    cambiarEstado(0);
}

void mostrarFechaYHora21() {
    enviarTiempoActual();
    cambiarEstado(0);
}

void editarLeds31() {
    enviarAccion(LED);

    if (banderaEntradaPC()) {
        if (ledValido(obtenerValorPC())) {
            ledNumTemp = obtenerValorPC();
            cambiarEstado(32);
        } else {
            alerta(LED_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingreseColor32() {
    enviarAccion(COLOR);

    if (banderaEntradaPC()) {
        if (colorValido(obtenerValorPC())) {
            colorRGB = obtenerValorPC();
            cambiarEstado(INGRESAR_TIEMPO);
        } else {
            alerta(COLOR_ERROR);
        }
        limpiarBanderaPC();
    }
}

bool segundosValidos(int tiempo) {
    if (tiempo >= MIN_SEGUNDOS && tiempo <= MAX_SEGUNDOS) {
        return true;
    }
    return false;
}

void vTimerCallback(TimerHandle_t xTimer) {
    queueStruct* valorQueueStruct;

    valorQueueStruct = (queueStruct*) pvTimerGetTimerID(xTimer);
    //meter en la queue
    //TOMAR SEMAFORO
    //TOMAR SEMAFORO
    //  if (xSemaphoreMutex != NULL) {
    /* See if we can obtain the semaphore.  If the semaphore is not
    available wait 10 ticks to see if it becomes free. */
    //       if (xSemaphoreTake(xSemaphoreMutex, (TickType_t) 10) == pdTRUE) {
    //Quitar del queue
    //PONER COMANDO EN EL QUEUE

    if (xQueueComandos != 0) {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if (xQueueSendToBack(xQueueComandos,
                (void *) &valorQueueStruct,
                (TickType_t) 10) != pdPASS) {
            /* Failed to post the message, even after 10 ticks. */
        }
        free(valorQueueStruct);
    }
    //         xSemaphoreGive(xSemaphoreMutex);
    //   } else {
    /* We could not obtain the semaphore and can therefore not access
    the shared resource safely. */
    // }
    // }
    //PONER COMANDO EN EL QUEUE

    //LIBERAR SEMAFORO
    //setLEDRGBComun((*valorQueueStruct).numeroLed, (*valorQueueStruct).color);
    xTimerStop(xTimer, 0);

    //free(valorQueueStruct);
}

void ingreseTiempo33() {
    enviarAccion(INGRESAR_TIEMPO_COMANDO);

    if (banderaEntradaPC()) {
        if (segundosValidos(obtenerValorPC())) {
            tiempoComando = obtenerValorPC();
            //Crear bloque de memoria
            queueStruct* ptr;
            ptr = (queueStruct*) malloc(sizeof (queueStruct));
            //Crear y agregar al struct el numero de led y el numero de color
            //queueStruct numeroLedYColor;
            (*ptr).color = colorRGB;
            (*ptr).numeroLed = ledNumTemp;
            if (tiempoComando == 0) {
                //PONER DIRECTAMENTE EN EL QUEUE

                //TOMAR SEMAFORO
                if (xSemaphoreMutex != NULL) {
                    /* See if we can obtain the semaphore.  If the semaphore is not
                    available wait 10 ticks to see if it becomes free. */
                    if (xSemaphoreTake(xSemaphoreMutex, (TickType_t) 10) == pdTRUE) {
                        //Quitar del queue
                        //PONER COMANDO EN EL QUEUE

                        if (xQueueComandos != 0) {
                            /* Send an unsigned long.  Wait for 10 ticks for space to become
                            available if necessary. */
                            if (xQueueSendToBack(xQueueComandos,
                                    (void *) &ptr,
                                    (TickType_t) 10) != pdPASS) {
                                /* Failed to post the message, even after 10 ticks. */
                            }
                            free(ptr);
                        }
                        xSemaphoreGive(xSemaphoreMutex);
                    } else {
                        /* We could not obtain the semaphore and can therefore not access
                        the shared resource safely. */
                    }
                }


                //LIBERAR SEMAFORO
            } else {

                //Crear el timer
                TimerHandle_t xTimer;
                xTimer = xTimerCreate
                        (/* Just a text name, not used by the RTOS
                     kernel. */
                        "Timer",
                        /* The timer period in ticks, must be
                        greater than 0. */
                        pdMS_TO_TICKS(tiempoComando * 1000),
                        /* The timers will auto-reload themselves
                        when they expire. */
                        pdFALSE,
                        /* Aca iria el bloque de memoria creado con malloc que contiene el struct con el numero de led y el color */
                        (void *) ptr,
                        /* Each timer calls the same callback when
                        it expires. */
                        vTimerCallback
                        );

                if (xTimerStart(xTimer, 0) != pdPASS) {
                    /* The timer could not be set into the Active
                    state. */
                }
            }


            cambiarEstado(34);
        } else {
            alerta(CMD_TIEMPO_INCORRECTO);
        }
        limpiarBanderaPC();
    }
}

void finalizarEdicion34() {
    enviarAccion(LED_FIN);
    cambiarEstado(0);
}

void ingresarLed41() {
    enviarAccion(LED);

    if (banderaEntradaPC()) {
        if (ledValido(obtenerValorPC())) {
            ledNumTemp = obtenerValorPC();
            cambiarEstado(42);
        } else {
            alerta(LED_ERROR);
        }
        limpiarBanderaPC();
    }
}

void ingresarRojo42() {
    cambiarColor(COLOR_ROJO, 43, 0);
}

void ingresarVerde43() {
    cambiarColor(COLOR_VERDE, 44, 1);
}

void ingresarAzul44() {
    cambiarColor(COLOR_AZUL, 45, 2);
}

void finalizarConfiguracion45() {
    enviarAccion(LED_FIN);
    cambiarEstado(0);
}

void mostrarFechaHora51() {
    char output[150];

    char *info_LED = ultimoLedModificado();

    strcpy(output, info_LED);

    strcat(output, CONTINUAR);
    enviarAccion(output);
    cambiarEstado(0);
}

void maquina_estados(void *params) {
    for (;;) {
        switch (estado) {
            case ESTADO_INICIAL:
                estadoInicial();
                break;

            case INGRESAR_ANIO:
                ingresarAnio11();
                break;

            case INGRESAR_MES:
                ingresarMes12();
                break;

            case INGRESAR_DIA:
                ingresarDia13();
                break;

            case INGRESAR_HORA:
                ingresarHoras14();
                break;

            case INGRESAR_MINUTO:
                ingresarMinuto15();
                break;

            case FINALIZAR_CONFIG_FECHA:
                finalizarConfiguracion16();
                break;


            case MOSTRAR_FECHA:
                mostrarFechaYHora21();
                break;


            case EDITAR_LEDS:
                editarLeds31();
                break;

            case INGRESAR_COLOR:
                ingreseColor32();
                break;
            case INGRESAR_TIEMPO:
                ingreseTiempo33();
                break;
            case FINALIZAR_EDICION:
                finalizarEdicion34();
                break;


            case INGRESAR_LED_RGB:
                ingresarLed41();
                break;

            case INGRESAR_ROJO:
                ingresarRojo42();
                break;

            case INGRESAR_VERDE:
                ingresarVerde43();
                break;

            case INGRESAR_AZUL:
                ingresarAzul44();
                break;

            case FINALIZAR_CONFIG_RGB:
                finalizarConfiguracion45();
                break;


            case MOSTRAR_FECHA_ULTIMO_LED:
                mostrarFechaHora51();
                break;


            default:
                break;
        }
    }
}