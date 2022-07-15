#include "reiniciarValores.h"
#include "enemigo.h"
#include "lectura.h"
#include "utils.h"

void reiniciarValores(void *params) {
    for (;;) {
        if (estadoBoton1.reiniciar) {
            milisegundosEnemigo = 1500;
            enemigo.octanteEnemigo = octanteEnemigoInicial();
            tiempoRojo = 0;
            estadoBoton1.timers = true;
            estadoBoton1.reiniciar = false;
            structCoordenadas.posicion_x = 0;
            structCoordenadas.posicion_y = 0;
            structCoordenadas.vInicialX = 0;
            structCoordenadas.vInicialY = 0;
            structCoordenadas.vFinalX = 0;
            structCoordenadas.vFinalX = 0;
            //structCoordenadas.octanteActualBlanca = 1;
            structCoordenadas.vector_r = 0;
        }
    }
}