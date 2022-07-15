


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
#include "utils.h"
#define tiempo_prendido 400
#define tiempo_apagado 800
#define tiempo_dormir 0.1
#define tamano_circulo 1
#define angulo_base 45
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)
#define  EXTERN  

Accel_t accel;
Accel_t *accelPointer;

EXTERN pelota structCoordenadas;


void getCoordenadaPolar() {
    //Se accede con el punto porque es la variable en si
    //Si y es negativo, entonces el angulo es el mismo
    structCoordenadas.vector_r = sqrt(pow((structCoordenadas.posicion_x), 2) + pow((structCoordenadas.posicion_y), 2));



    //    if(structCoordenadas.angulo > 0){

    //  }else{

    //}
    if (fabs(structCoordenadas.vector_r) > fabs(tamano_circulo)) {
        structCoordenadas.vector_r = tamano_circulo;
        //structCoordenadas.posicion_x = tamano_circulo * cos(structCoordenadas.angulo);
        if (structCoordenadas.vector_r > 0) {
            /*if(structCoordenadas.posicion_x < 0){
                structCoordenadas.posicion_x = -1*sqrt(pow(structCoordenadas.vector_r, 2) - pow(structCoordenadas.posicion_y, 2));
            }else{
                structCoordenadas.posicion_x = sqrt(pow(structCoordenadas.vector_r, 2) - pow(structCoordenadas.posicion_y, 2));
            }
            if(structCoordenadas.posicion_y < 0){
                structCoordenadas.posicion_y = -1*sqrt(pow(structCoordenadas.vector_r, 2) - pow(structCoordenadas.posicion_x, 2));
            }else{
                structCoordenadas.posicion_y = sqrt(pow(structCoordenadas.vector_r, 2) - pow(structCoordenadas.posicion_x, 2));
            }*/
            structCoordenadas.posicion_x = 0;
            structCoordenadas.posicion_y = 0;


        }

        // v2 = x2 + y2 -Z v2 - y2 = x2
        //structCoordenadas.posicion_y = tamano_circulo * sin(structCoordenadas.angulo);
        structCoordenadas.vFinalX = 0;
        structCoordenadas.vFinalY = 0;
        structCoordenadas.vInicialX = 0;
        structCoordenadas.vInicialY = 0;
    }
    if (accel.Accel_X > 0 && structCoordenadas.posicion_y >= 0) {
        structCoordenadas.angulo = atan2(structCoordenadas.posicion_y, structCoordenadas.posicion_x);
    } else if (accel.Accel_X == 0 && structCoordenadas.posicion_y > 0) {
        structCoordenadas.angulo = M_PI / 2;
    } else if (accel.Accel_X < 0) {
        structCoordenadas.angulo = atan2(structCoordenadas.posicion_y, accel.Accel_X) + M_PI;
    } else if (accel.Accel_X == 0 && structCoordenadas.posicion_y < 0) {
        structCoordenadas.angulo = (3 * M_PI) / 2;
    } else if (accel.Accel_X > 0 && structCoordenadas.posicion_y < 0) {
        structCoordenadas.angulo = atan2(structCoordenadas.posicion_y, accel.Accel_X) + (2 * M_PI);
    }

    structCoordenadas.angulo = radToDeg(structCoordenadas.angulo);

}

void calcularOctante() {

    double_t angulo = structCoordenadas.angulo;
    if (semaforoStructCoordenadas != NULL) {

        if (xSemaphoreTake(semaforoStructCoordenadas, (TickType_t) 10) == pdTRUE) {

            /*bool entrarAlBloque = true;
            if (accel.Accel_Y >= 0 && structCoordenadas.posicion_y <= 0
                    || accel.Accel_Y <= 0 && structCoordenadas.posicion_y >= 0) {
                entrarAlBloque = false;
            }
            if (accel.Accel_X >= 0 && structCoordenadas.posicion_x <= 0
                    || accel.Accel_X <= 0 && structCoordenadas.posicion_x >= 0) {
                entrarAlBloque = false;
            }
             
            
             
             * octante actual y lo actualizamos cada vez que entramos.. 
             * Para calcular la distancia, tengo el octante actual de la pelota blanca
             * tenemos que tener guardado la correspondencia octante -> led...

            if (entrarAlBloque) {*/
            //apagarLeds();
            if (structCoordenadas.posicion_x > 0 && structCoordenadas.posicion_y > 0 && (structCoordenadas.posicion_x > structCoordenadas.posicion_y)) {
                //OCTANTE 1
                structCoordenadas.ledActual = 3;
                structCoordenadas.octanteActualBlanca = 1;
                setLEDRGBBlanca(3, 0);
            } else if (structCoordenadas.posicion_x > 0 && structCoordenadas.posicion_y > 0 && (structCoordenadas.posicion_x < structCoordenadas.posicion_y)) {
                //Octante2
                structCoordenadas.octanteActualBlanca = 2;
                structCoordenadas.ledActual = 2;
                setLEDRGBBlanca(2, 0);
            } else if (structCoordenadas.posicion_x < 0 && structCoordenadas.posicion_y > 0 && (fabs(structCoordenadas.posicion_x) < structCoordenadas.posicion_y)) {
                //Octante 3
                structCoordenadas.octanteActualBlanca = 3;
                structCoordenadas.ledActual = 1;
                setLEDRGBBlanca(1, 0);
            } else if (structCoordenadas.posicion_x < 0 && structCoordenadas.posicion_y > 0 && (fabs(structCoordenadas.posicion_x) > structCoordenadas.posicion_y)) {
                //Octante 4
                structCoordenadas.octanteActualBlanca = 4;
                structCoordenadas.ledActual = 4;
                setLEDRGBBlanca(4, 0);
            } else if (structCoordenadas.posicion_x < 0 && structCoordenadas.posicion_y < 0 && (fabs(structCoordenadas.posicion_x) > fabs(structCoordenadas.posicion_y))) {
                //Octante 5
                structCoordenadas.octanteActualBlanca = 5;
                structCoordenadas.ledActual = 6;
                setLEDRGBBlanca(6, 0);
            } else if (structCoordenadas.posicion_x < 0 && structCoordenadas.posicion_y < 0 && (fabs(structCoordenadas.posicion_x) < fabs(structCoordenadas.posicion_y))) {
                //Octante 6
                structCoordenadas.octanteActualBlanca = 6;
                structCoordenadas.ledActual = 7;
                setLEDRGBBlanca(7, 0);
            } else if (structCoordenadas.posicion_x > 0 && structCoordenadas.posicion_y < 0 && (structCoordenadas.posicion_x < fabs(structCoordenadas.posicion_y))) {
                //Octante 7
                structCoordenadas.octanteActualBlanca = 7;
                structCoordenadas.ledActual = 8;
                setLEDRGBBlanca(8, 0);
            } else if (structCoordenadas.posicion_x > 0 && structCoordenadas.posicion_y < 0 && (fabs(structCoordenadas.posicion_x) > fabs(structCoordenadas.posicion_y))) {
                //Octante 8
                structCoordenadas.octanteActualBlanca = 8;
                structCoordenadas.ledActual = 5;
                setLEDRGBBlanca(5, 0);
                // }
            }/*else{
                //Placa horizontal
                setLEDRGBComun(structCoordenadas.ledActual, 0);
            }*/
            xSemaphoreGive(semaforoStructCoordenadas);
        } else {

        }
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

    structCoordenadas.posicion_x = structCoordenadas.posicion_x + structCoordenadas.vInicialX * tiempo_dormir + ((1 / 2)*(accel.Accel_X * (pow(tiempo_dormir, 2))));
    structCoordenadas.posicion_y = structCoordenadas.posicion_y + structCoordenadas.vInicialY * tiempo_dormir + ((1 / 2)*(accel.Accel_Y * (pow(tiempo_dormir, 2))));


    structCoordenadas.vector_r = sqrt(pow(structCoordenadas.posicion_x, 2) + pow(structCoordenadas.posicion_y, 2));

    //reasignacion de vinicial
    structCoordenadas.vInicialX = structCoordenadas.vFinalX;
    structCoordenadas.vInicialY = structCoordenadas.vFinalY;

    //calculo de posicion



}

void calcularAnguloDesdeAceleracion() {

    if (accel.Accel_X < 0 && accel.Accel_Y < 0) {
        structCoordenadas.angulo = atan2(accel.Accel_Y, accel.Accel_X) - M_PI;
    } else if (accel.Accel_X == 0 && accel.Accel_Y < 0) {
        structCoordenadas.angulo = -M_PI / 2;
    } else if (accel.Accel_X > 0) {
        structCoordenadas.angulo = atan2(accel.Accel_Y, accel.Accel_X);
    } else if (accel.Accel_X == 0 && accel.Accel_Y > 0) {
        structCoordenadas.angulo = (M_PI) / 2;
    } else if (accel.Accel_X < 0 && accel.Accel_Y >= 0) {
        structCoordenadas.angulo = atan2(accel.Accel_Y, accel.Accel_X) + (M_PI);
    }
    structCoordenadas.angulo = radToDeg(structCoordenadas.angulo);



}

void leerValoresAcelerometro(void *params) {
    structCoordenadas.ledActual = 1;

    TickType_t timeToSleep = pdMS_TO_TICKS(10);

    //cargo valores iniciales de x e y.
    structCoordenadas.posicion_x = 0;
    structCoordenadas.posicion_y = 0;
    structCoordenadas.vInicialX = 0;
    structCoordenadas.vInicialY = 0;

    accelPointer = &accel;



    for (;;) {
        if (estadoBoton1.bandera) {
            if (!ACCEL_GetAccel(accelPointer)) {
                return;
            }
            //Umbral 0.7 para el acelerometro.
            /*if (accel.Accel_X < 0.4 && accel.Accel_X > -0.4) {
                accel.Accel_X = 0;
            }
            if (accel.Accel_Y < 0.4 && accel.Accel_Y > -0.4) {
                accel.Accel_Y = 0;
            }*/
            calcularPosicionXY();
            getCoordenadaPolar();
            //calcularAnguloDesdeAceleracion();
            calcularOctante();
            //anda a dormir
            vTaskDelay(timeToSleep);
        }
    }


}