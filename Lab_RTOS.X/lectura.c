


/**
 archivo encargado de leer la aceleracion y transformarlo en un struct
 */


#include "lectura.h"
#include "framework/Accelerometer/Accelerometer.h"
#include "mcc_generated_files/pin_manager.h"
#include "./freeRTOS/include/FreeRTOS.h"
#include "utils/delay.h"
#include <math.h>
#include "utils/manejo_leds_rgb.h"
#include "task.h"
#define tiempo_prendido 400
#define tiempo_apagado 800

coordenada structCoordenadas;

Accel_t accel;

void getCoordenadaPolar() {
    //Se accede con el punto porque es la variable en si
    //Si y es negativo, entonces el angulo es el mismo
    structCoordenadas.vector_r = sqrt(pow((structCoordenadas.posicion_x), 2) + pow((structCoordenadas.posicion_y), 2));
    structCoordenadas.angulo = atan2(structCoordenadas.posicion_y, structCoordenadas.posicion_x);

}

void calcularOctante() {
    double_t angulo = structCoordenadas.angulo;
    if (angulo > 0 && angulo < M_PI / 4) {
        //OCTANTE 1
        setLEDRGBComun(1,0);
    } else if (angulo > M_PI / 4 && angulo < M_PI / 2) {
        //Octante2
        setLEDRGBComun(2,0);
    } else if (angulo > M_PI / 2 && angulo < 3 * M_PI / 4) {
        //Octante 3
        setLEDRGBComun(3,0);
    } else if (angulo > 3 * M_PI / 4 && angulo < M_PI) {
        //Octante 4
        setLEDRGBComun(4,0);
    } else if (angulo > -M_PI && angulo < (-3 * M_PI) / 4) {
        //Octante 5
        setLEDRGBComun(5,0);
    } else if (angulo > (-3 * M_PI) / 4 && angulo < (-M_PI) / 2) {
        //Octante 6
        setLEDRGBComun(6,0);
    } else if (angulo > (-M_PI) / 2 && angulo < (-M_PI) / 4) {
        //Octante 7
        setLEDRGBComun(7,0);
    } else if (angulo > (-M_PI) / 4 && angulo < 0) {
        //Octante 8
        setLEDRGBComun(8,0);
    }
}

void leerValoresAcelerometro(void *params) {
    
    TickType_t timeToSleep = pdMS_TO_TICKS(100);

    //cargo valores iniciales de x e y.
    structCoordenadas.posicion_x = -2;
    structCoordenadas.posicion_y = -1;



    for (;;) {

        ACCEL_GetAccel(&accel);
        getCoordenadaPolar(); 
        calcularOctante();
        
        //anda a dormir
        vTaskDelay(timeToSleep);
    }


}