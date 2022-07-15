#include <stdio.h>

#include "buttons.h"
#include "freeRTOS/include/FreeRTOS.h"

void boton1_isr(void) {
    printf("%d",2);
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();

}

void boton2_isr(void) {
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();


}