#ifndef _delay_H    /* Guard against multiple inclusion */
#define _delay_H
#include <stdint.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */



typedef enum {
    UT_TMR_DELAY_INIT, 
    UT_TMR_DELAY_WAIT
} UT_TMR_DELAY_STATE;

typedef struct {
    uint16_t startValue;
    UT_TMR_DELAY_STATE state;
} ut_tmrDelay_t;

extern ut_tmrDelay_t statusLEDA;
extern ut_tmrDelay_t statusBTN2;


bool UT_delayms(uint16_t timeMS, uint16_t tmr_initial);


#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
