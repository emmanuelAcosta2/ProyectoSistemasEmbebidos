
#ifndef _ENEMIGO_H    /* Guard against multiple inclusion */
#define _ENEMIGO_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#define EXTERN extern

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    
    
        typedef struct {
        
            uint8_t octanteEnemigo;
            uint8_t octanteBlanco;
            
    } enemigoStruct;

    EXTERN enemigoStruct enemigo;
    
    
    void moverEnemigo(void *params);
    
    //calcular el camino mas corto
    int *  caminoMasCorto();
    
    void prenderLedEnemigo(int octante,int octanteBlanca);
    
    void obtenerOctanteBlanca();
    
    int octanteEnemigoInicial();
    
    //Obtener el octante de la pelota blanca
    
    //definir la tarea que se duerma cada vez menos tiempo...
    
    //dentro de esta tarea cada vez que pase determinado tiempo debería sonar el buzzer
    
    //
    
    
    
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
