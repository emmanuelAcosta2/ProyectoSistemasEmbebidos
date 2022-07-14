/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 * Archivo para la lectura del acelerometro, se definiran estructuras y metodos utiles para 
 * trabajar con tareas y actualizar valores.
 */
/* ************************************************************************** */

#ifndef _LECTURA_H    /* Guard against multiple inclusion */
#define _LECTURA_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "framework/Accelerometer/Accelerometer.h"


/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef  EXTERN
#define  EXTERN  extern
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */




    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */


    extern Accel_t accel;

    typedef struct {
        double_t posicion_x;
        double_t posicion_y;
        double_t vector_r;
        double_t angulo;
        double_t vInicialX;
        double_t vInicialY;
        double_t vFinalX;
        double_t vFinalY;
        int ledActual;
    } pelota;

    EXTERN pelota structCoordenadas;
    //Funcion para calcular coordenadas polares

    
    
    void getCoordenadaPolar();

    void calcularOctante();

    void calcularPosicionXY();

    //

    void leerValoresAcelerometro(void *params);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
