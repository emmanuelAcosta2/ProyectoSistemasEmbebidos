
#include "mcc_generated_files/pin_manager.h"
#include "sonidos.h"

void UT_delay(int n) {

    while (n > 0) {
        n--;
    }
}

void sonidoInicio() {
    int var = 5;
    while (var >= 0) {
        var--;
        int i = 200;
        while (i != 0) {
            i--;
            UT_delay(1000);
            BUZ_CTRL_Toggle();
        }
        UT_delay(100);
    }
}

void sonidoPerderSuperarHS() {
    int i = 50;
    while (i != 0) {
        i--;
        UT_delay(20000);
        BUZ_CTRL_Toggle();
    }
    i = 70;
    while (i != 0) {
        i--;
        UT_delay(15000);
        BUZ_CTRL_Toggle();
    }
    i = 100;
    while (i != 0) {
        i--;
        UT_delay(12500);
        BUZ_CTRL_Toggle();
    }
    i = 200;
    while (i != 0) {
        i--;
        UT_delay(10000);
        BUZ_CTRL_Toggle();
    }
    i = 300;
    while (i != 0) {
        i--;
        UT_delay(7500);
        BUZ_CTRL_Toggle();
    }
    i = 750;
    while (i != 0) {
        i--;
        UT_delay(5000);
        BUZ_CTRL_Toggle();
    }
    i = 70;
    while (i != 0) {
        i--;
        UT_delay(15000);
        BUZ_CTRL_Toggle();
    }
    i = 70;
    while (i != 0) {
        i--;
        UT_delay(15000);
        BUZ_CTRL_Toggle();
    }
    i = 750;
    while (i != 0) {
        i--;
        UT_delay(5000);
        BUZ_CTRL_Toggle();
    }
}

void sonidoPerderSinSuperarHS() {
    int var = 10;
    while (var >= 0) {
        var--;
        int i = 200;
        while (i != 0) {
            i--;
            UT_delay(1000);
            BUZ_CTRL_Toggle();
        }
        i = 100;
        while (i != 0) {
            i--;
            UT_delay(5000);
            BUZ_CTRL_Toggle();
        }
        UT_delay(100);
    }
}

void sonidoAumentarVelocidad() {
    int i = 200;
    while (i != 0) {
        i--;
        UT_delay(2000);
        BUZ_CTRL_Toggle();
    }
}

void tareaSonidos(void *params) {

}
/*void UT_delay(int n){
        
}*/