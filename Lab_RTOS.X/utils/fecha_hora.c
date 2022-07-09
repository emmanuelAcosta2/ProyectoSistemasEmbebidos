
#include <stdbool.h>
#include <time.h>

#include "fecha_hora.h"

struct tm tiempo_temp;   

/**
 * Valida que la hora est� entre 0 y 23.
 * @param hora
 * @return 
 */
bool horaValida(int hora){
    return MIN_HORA <= hora && hora <= MAX_HORA;
}

/**
 * Valida que el minuto est� entre 0 y 59
 * @param minuto
 * @return 
 */
bool minutoValido(int minuto){
    return MIN_MINUTO <= minuto && minuto <= MAX_MINUTO;
}

/**
 * Valida que el mes est� entre 0 y 12
 * @param mes
 * @return 
 */
bool mesValido(int mes){
    return MIN_MES <= mes && mes <=MAX_MES;
}

/**
 * Valida que el d�a est� entre 1 y 31.
 * @param dia
 * @return 
 */
bool diaValido(int dia){
    return MIN_DIA <= dia && dia <= MAX_DIA;
}

/**
 * Valida que el a�o est� entre el 1900 y 2030
 * @param anio
 * @return 
 */
bool anioValido(int anio) {
    return MIN_ANIO <= anio && anio <= MAX_ANIO;
}






