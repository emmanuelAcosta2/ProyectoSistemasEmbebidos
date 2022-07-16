#include "utils.h"
#include "mostrarPuntaje.h"
#include "utils/manejo_leds_rgb.h"

void mostrarPuntaje(void *params) {
    for (;;) {
        bool entrar = true;
        if (terminoJuego && !empezarJuego && entrar) {
            int puntaje2 = puntaje;
            int bolasPurple = cantidadLedsColor(puntaje2, 50);
            puntaje2 = puntaje2 % 50;
            int bolasCyan = cantidadLedsColor(puntaje2, 20);
            puntaje2 = puntaje2 % 20;
            int bolasBlancas = cantidadLedsColor(puntaje2, 10);
            puntaje2 = puntaje2 % 10;
            int bolasRojas = cantidadLedsColor(puntaje2, 5);
            puntaje2 = puntaje2 % 5;
            int bolasAzules = cantidadLedsColor(puntaje2, 2);
            puntaje2 = puntaje2 % 2;
            int bolasVerdes = cantidadLedsColor(puntaje2, 1);
            puntaje2 = puntaje2 % 1;

            int leds[8] = {0, 0, 0, 0, 0, 0, 0, 0};
            int numeroLed = 1;
            for (int i = 0; i < bolasPurple; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 5);
                    numeroLed++;
                }
            }
            for (int i = 0; i < bolasCyan; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 6);
                    numeroLed++;
                }
            }
            for (int i = 0; i < bolasBlancas; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 0);
                    numeroLed++;
                }
            }
            for (int i = 0; i < bolasRojas; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 1);
                    numeroLed++;
                }
            }
            for (int i = 0; i < bolasAzules; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 2);
                    numeroLed++;
                }
            }
            for (int i = 0; i < bolasVerdes; i++) {
                if (numeroLed <= 8) {
                    setLEDRGBComun(numeroLed, 3);
                    numeroLed++;
                }
            }
            entrar = false;
        }
        if(terminoJuego && !empezarJuego){
            entrar = true;
        }
    }

}

int cantidadLedsColor(int puntaje, int divisor) {
    int devolucion = puntaje / divisor;
    return devolucion;
}