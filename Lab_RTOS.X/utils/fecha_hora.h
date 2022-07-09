

#ifndef _fecha_hora_H_    /* Guard against multiple inclusion */
#define _fecha_hora_H_


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#define MIN_ANIO 1900
#define MAX_ANIO 2030

#define MIN_MES 1
#define MAX_MES 12

#define MIN_DIA 1
#define MAX_DIA 31

#define MIN_HORA 00
#define MAX_HORA 23

#define MIN_MINUTO 0
#define MAX_MINUTO 59


extern struct tm tiempo_temp;

bool anioValido(int anio);

bool mesValido(int mes);

bool diaValido(int dia);

bool horaValida(int hora);

bool minutoValido(int minuto);

#endif 
