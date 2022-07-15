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
 */
/* ************************************************************************** */

#ifndef _SONIDOS_H    /* Guard against multiple inclusion */
#define _SONIDOS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */




/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    void sonidoInicio();
    void sonidoPerderSuperarHS();
    void sonidoPerderSinSuperarHS();
    void sonidoAumentarVelocidad();
    void tareaSonidos(void *params);
    void UT_delay(int n);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
