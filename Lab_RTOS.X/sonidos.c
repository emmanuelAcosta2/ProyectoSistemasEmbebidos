
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
    int i = 5;
    while (i != 0) {
        i--;
        UT_delay(2000);
        BUZ_CTRL_Toggle();
    }
    i = 7;
    while (i != 0) {
        i--;
        UT_delay(1500);
        BUZ_CTRL_Toggle();
    }
    i = 10;
    while (i != 0) {
        i--;
        UT_delay(1250);
        BUZ_CTRL_Toggle();
    }
    i = 20;
    while (i != 0) {
        i--;
        UT_delay(1000);
        BUZ_CTRL_Toggle();
    }
    i = 30;
    while (i != 0) {
        i--;
        UT_delay(750);
        BUZ_CTRL_Toggle();
    }
    i = 70;
    while (i != 0) {
        i--;
        UT_delay(500);
        BUZ_CTRL_Toggle();
    }
    i = 7;
    while (i != 0) {
        i--;
        UT_delay(1500);
        BUZ_CTRL_Toggle();
    }
    i = 7;
    while (i != 0) {
        i--;
        UT_delay(1500);
        BUZ_CTRL_Toggle();
    }
    i = 75;
    while (i != 0) {
        i--;
        UT_delay(500);
        BUZ_CTRL_Toggle();
    }
}

void sonidoPerderSinSuperarHS() {
    //int var = 3;
    //while (var >= 0) {
    //  var--;
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
    //}
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