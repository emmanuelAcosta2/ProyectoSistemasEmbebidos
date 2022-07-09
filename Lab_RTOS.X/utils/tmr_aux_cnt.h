#ifndef _tmr_aux_H  
#define _tmr_aux_H

#include <stdint.h>



extern uint16_t tmr2_cnt;

uint16_t tmr2_cnt_get(void);

void tmr2_cnt_inc(void);

#endif
