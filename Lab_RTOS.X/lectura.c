


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
#define tiempo_dormir 100
#define tamano_circulo 25
#define angulo_base 45
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

pelota structCoordenadas;

Accel_t accel;
Accel_t *accelPointer;

void getCoordenadaPolar() {
    //Se accede con el punto porque es la variable en si
    //Si y es negativo, entonces el angulo es el mismo
    structCoordenadas.vector_r = sqrt(pow((structCoordenadas.posicion_x), 2) + pow((structCoordenadas.posicion_y), 2));
    structCoordenadas.angulo = atan2(structCoordenadas.posicion_y, structCoordenadas.posicion_x);


    //    if(structCoordenadas.angulo > 0){
    float anguloRad = structCoordenadas.angulo;
    structCoordenadas.angulo = radToDeg(structCoordenadas.angulo);
    //  }else{

    //}
    if (structCoordenadas.vector_r > tamano_circulo) {
        structCoordenadas.vector_r = tamano_circulo;
        structCoordenadas.posicion_x = tamano_circulo * cos(structCoordenadas.angulo);
        structCoordenadas.posicion_y = tamano_circulo * sin(structCoordenadas.angulo);
        structCoordenadas.vFinalX = 0;
        structCoordenadas.vFinalY = 0;
        structCoordenadas.vInicialX = 0;
        structCoordenadas.vInicialY = 0;
    }


}

void calcularOctante() {
    apagarLeds();
    double_t angulo = structCoordenadas.angulo;
    double_t PI = M_PI;
    if (angulo > 0 && angulo < (180.0/4)) {
        //OCTANTE 1
        setLEDRGBComun(1, 0);
    } else if (angulo > (180.0 / 4) && angulo < (180.0/2)) {
        //Octante2
        setLEDRGBComun(2, 0);
    } else if (angulo > (180.0 / 2) && angulo < ((3 * 180.0) / 4)) {
        //Octante 3
        setLEDRGBComun(3, 0);
    } else if (angulo > ((3 * 180.0) / 4) && angulo < 180.0) {
        //Octante 4
        setLEDRGBComun(4, 0);
    } else if (angulo > -180.0 && angulo < ((-3 * 180.0) / 4)) {
        //Octante 5
        setLEDRGBComun(5, 0);
    } else if (angulo > ((-3 * 180.0) / 4) && angulo < ((-180.0) / 2)) {
        //Octante 6
        setLEDRGBComun(6, 0);
    } else if (angulo > ((-180.0) / 2) && angulo < ((-180.0) / 4)) {
        //Octante 7
        setLEDRGBComun(7, 0);
    } else if (angulo > ((-180.0) / 4) && angulo < 0) {
        //Octante 8
        setLEDRGBComun(8, 0);
    }
    

}

void calcularPosicionXY() {


    //v(t)=v0+at,

    //calculo de la velocidad

    structCoordenadas.vFinalX = structCoordenadas.vInicialX + accel.Accel_X*tiempo_dormir;
    structCoordenadas.vFinalY = structCoordenadas.vInicialY + accel.Accel_Y*tiempo_dormir;
         
    //structCoordenadas.posicion_x = structCoordenadas.posicion_x + structCoordenadas.vFinalX*tiempo_dormir;
    //structCoordenadas.posicion_y = structCoordenadas.posicion_y + structCoordenadas.vFinalY*tiempo_dormir;

    //x(t)=x0+ v0t +1/2(at2),

    structCoordenadas.posicion_x = structCoordenadas.posicion_x + structCoordenadas.vInicialX * tiempo_dormir + ((1 / 2)*(accel.Accel_X * (pow(tiempo_dormir,2))));
    structCoordenadas.posicion_y = structCoordenadas.posicion_y + structCoordenadas.vInicialY * tiempo_dormir + ((1 / 2)*(accel.Accel_Y * (pow(tiempo_dormir,2))));


    //reasignacion de vinicial
    structCoordenadas.vInicialX = structCoordenadas.vFinalX;
    structCoordenadas.vInicialY = structCoordenadas.vFinalY;

    //calculo de posicion



}

void leerValoresAcelerometro(void *params) {

    TickType_t timeToSleep = pdMS_TO_TICKS(100);

    //cargo valores iniciales de x e y.
    structCoordenadas.posicion_x = -2;
    structCoordenadas.posicion_y = -1;
    structCoordenadas.vInicialX = 0;
    structCoordenadas.vInicialY = 0;
    
    accelPointer = &accel;



    for (;;) {
        
        if(!ACCEL_GetAccel(accelPointer)){
            return;
        }
        calcularPosicionXY();
        getCoordenadaPolar();
        calcularOctante();
        //anda a dormir
        vTaskDelay(timeToSleep);
    }


}