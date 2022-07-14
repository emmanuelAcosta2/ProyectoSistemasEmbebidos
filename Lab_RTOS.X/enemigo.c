


#include "enemigo.h"
#include "utils.h"
#include "lectura.h"
#include "task.h"
#include <stdlib.h>
#include "utils/manejo_leds_rgb.h"
#define EXTERN

EXTERN enemigoStruct enemigo;

int octanteEnemigoInicial() {
    int octante = 5;
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
    for (;;) {
        caminoMasCorto();
    }

}

void obtenerOctanteBlanca() {
    if (xSemaphoreMutex != NULL) {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait 10 ticks to see if it becomes free. */
        if (xSemaphoreTake(xSemaphoreMutex, (TickType_t) 10) == pdTRUE) {

            enemigo.octanteBlanco = structCoordenadas.ledActual;

            xSemaphoreGive(xSemaphoreMutex);
        } else {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }
}

void prenderLedEnemigo(int octante) {
    setLEDRGBComun(octante, 1);
}

/**
 * El enemigo va solo por la circunferencia
 * @return 
 */
int * caminoMasCorto() {
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
            if (enemigo.octanteEnemigo == 0) {
                enemigo.octanteEnemigo = 8;
            }
            enemigo.octanteEnemigo--;
            prenderLedEnemigo(enemigo.octanteEnemigo);
            obtenerOctanteBlanca();
            if (octanteBlanca != enemigo.octanteBlanco) {
                break;
            }
            //aplico delay
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    } else {
        int octanteBlanca = enemigo.octanteBlanco;
        for (int i = 0; i < distancia; i++) {
            if (enemigo.octanteEnemigo == 9) {
                enemigo.octanteEnemigo = 1;
            }
            enemigo.octanteEnemigo++;
            prenderLedEnemigo(enemigo.octanteEnemigo);
            obtenerOctanteBlanca();
            if (octanteBlanca != enemigo.octanteBlanco) {
                break;
            }
            //aplico delay
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }





}