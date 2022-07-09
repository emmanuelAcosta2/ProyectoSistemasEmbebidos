
#include "tmr_aux_cnt.h"

/**
 * Devuelve el valor del contador auxiliar
 * @return 
 */

uint16_t tmr2_cnt;

uint16_t tmr2_cnt_get(void) {
    return tmr2_cnt;
}

/**
 * Aumenta en una unidad el valor del contador. 
 */
void tmr2_cnt_inc(void){
    tmr2_cnt++;
}
