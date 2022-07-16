


#include "enemigo.h"
#include "utils.h"
#include "lectura.h"
#include "task.h"
#include <stdlib.h>
#include "utils/manejo_leds_rgb.h"
#include "sonidos.h"
#include "timers.h"
#include "escribirMemoria.h"
#include "mcc_generated_files/memory/flash_demo.h"
#define EXTERN

EXTERN enemigoStruct enemigo;
SemaphoreHandle_t semaforoStructEnemigo;

int octanteEnemigoInicial() {
    int octante = structCoordenadas.octanteActualBlanca;
    int numero;
    srand(time(NULL));
    do {
        numero = (rand() % 8) + 1;
    } while (numero == octante);

    return numero;
}

void moverEnemigo(void *params) {
    enemigo.octanteEnemigo = octanteEnemigoInicial();
    //Buscar camino más corto

    //delay que dice cuanto tiempo pasa entre que salta de un octante al otro...
    //El enemigo inicia en un lugar x, distinto de donde inicia el blanco
    //Un determinado tiempo despues (1s)
    int vueltas = 0;
    for (;;) {
        if (!terminoJuego) {
            if (estadoBoton1.bandera) {
                vueltas++;
                if (vueltas == 10) {
                    vueltas = 0;
                }

                caminoMasCorto(vueltas);

            } else {
                enemigo.octanteEnemigo = octanteEnemigoInicial();
                vueltas = 0;
            }
        }
    }

}

void obtenerOctanteBlanca() {
    if (semaforoStructCoordenadas != NULL) {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait 10 ticks to see if it becomes free. */
        if (xSemaphoreTake(semaforoStructCoordenadas, (TickType_t) 10) == pdTRUE) {

            enemigo.octanteBlanco = structCoordenadas.octanteActualBlanca;

            xSemaphoreGive(semaforoStructCoordenadas);
        } else {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }
}

void prenderLedEnemigo(int octante, int octanteBlanca) {
    switch (octante) {
        case 1:
            setLEDRGBEnemigo(3, 1, milisegundosEnemigo);
            break;
        case 2:
            setLEDRGBEnemigo(2, 1, milisegundosEnemigo);
            break;
        case 3:
            setLEDRGBEnemigo(1, 1, milisegundosEnemigo);
            break;
        case 4:
            setLEDRGBEnemigo(4, 1, milisegundosEnemigo);
            break;
        case 5:
            setLEDRGBEnemigo(6, 1, milisegundosEnemigo);
            break;
        case 6:
            setLEDRGBEnemigo(7, 1, milisegundosEnemigo);
            break;
        case 7:
            setLEDRGBEnemigo(8, 1, milisegundosEnemigo);
            break;
        case 8:
            setLEDRGBEnemigo(5, 1, milisegundosEnemigo);
            break;
    }

}

/**
 * El enemigo va solo por la circunferencia
 * @return 
 */
int * caminoMasCorto(int tiempoEnMilis) {
    //obtener la pelota blanca

    obtenerOctanteBlanca();

    //vamos a tener octantes, dependiendo del octante donde esté la pelota blanca
    //tenemos que calcular cual es el camino mas corto
    //En si sería por ejemplo si la pelota blanca esta en el 3 y el enemigo esta en el 5.
    // ver por qué lado llega más rapido
    //Tener cuidado porque debe ser una cola circular en este caso
    //si está en el 2 la blanca y en el 7 la enemiga
    // debería ir por el 8.
    //es decir si enemigo - blanca > 4... debe ir por la vuelta inversa
    // enemigo - blanca
    // Si resultado < 0
    // 5 - 8 = -3 
    // 1 - 8 = -7
    // 6 7 8
    // 5 - 2 = -3
    // 5 + |-3| = 8

    // si | enemigo - blanca | > 4

    // |2 - 7| = 5
    // |3 - 7| = 4
    // |1 - 8| = 7
    // 1 - 8 | 2 - 8
    // 1 - 7 | 2 - 7
    // 1 - 6 | 2 - 6
    // 1 - 5 | 2 - 5
    // 1 - 4
    // 1 - 3
    // 1 - 2
    // 1 - 1


    int distancia = abs(enemigo.octanteEnemigo - enemigo.octanteBlanco);
    if (distancia > 4) {
        //Siempre que sea positivo se pasa ese valor a prender el led
        //Si es negativo invierto y sumo 
        //suponete que el enemigo esta en el 1 y tenemos que ir hasta el 7
        // el primer led que prendemos leugo de tanto tiempo es el 8, si nosotros decrementador, ese contador
        // va a pasar a 0 por que 1 - 0 = 0, entonces cuando lleguemos a 0, ponemos el contador en 8
        // y ahi seguimos decrementando hasta que sea igual a la blanca
        // es que en cada paso tenemos que consultar donde esta la blanca,
        // porque si no sigue en ese lugar tenemos que irnos a otro lado y volver a calcular
        int octanteBlanca = enemigo.octanteBlanco;
        for (int i = 0; i < distancia; i++) {
            // i = 0, 4... octanteEnemigo es 4


            if ((enemigo.octanteEnemigo) != octanteBlanca) {
                if (enemigo.octanteEnemigo != 1) {
                    --enemigo.octanteEnemigo;
                } else {
                    enemigo.octanteEnemigo = 8;
                }

                prenderLedEnemigo(enemigo.octanteEnemigo, octanteBlanca);
            }
            //enemigo.octanteEnemigo--;

            //Si son distintos...


            obtenerOctanteBlanca();
            //Si obtenemos de nuevo la octante blanca y no esta en el mismo lugar tenemos que volver a calcular.
            if (octanteBlanca != enemigo.octanteBlanco) {
                break;
            }
            //aplico delay

        }
    } else {

        int octanteBlanca = enemigo.octanteBlanco;
        if (distancia == 0) {
            //uint32_t valorMemoria = leerMemoria();
            //WordWriteExample();
            //escribirMemoria();
            //apagarLeds();
            //vTaskDelay(pdMS_TO_TICKS(1000));
            terminoJuego = true;
            empezarJuego = false;
            sonidoPerderSinSuperarHS();
            xTimerStop(xTimer,0);
            prenderLedEnemigo(enemigo.octanteEnemigo, octanteBlanca);
        }
        for (int i = 0; i < distancia; i++) {
            /*if (enemigo.octanteEnemigo == 8) {
                enemigo.octanteEnemigo = 1;
            }*/
            if ((enemigo.octanteEnemigo) != octanteBlanca) {
                if (enemigo.octanteEnemigo > enemigo.octanteBlanco) {
                    --enemigo.octanteEnemigo;
                } else if (enemigo.octanteEnemigo < enemigo.octanteBlanco) {
                    if (enemigo.octanteEnemigo == 8) {
                        enemigo.octanteEnemigo = 1;
                    } else {
                        ++enemigo.octanteEnemigo;
                    }
                }
                prenderLedEnemigo((enemigo.octanteEnemigo), octanteBlanca);
            }
            //enemigo.octanteEnemigo++;
            //prenderLedEnemigo(enemigo.octanteEnemigo);
            obtenerOctanteBlanca();
            if (octanteBlanca != enemigo.octanteBlanco) {
                break;
            }
            //aplico delay

        }
    }





}