
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../mcc_generated_files/usb/usb_device_cdc.h"
#include "manejoUSB.h"
#include "manejo_leds_rgb.h"

char buffer[BUFFER_SIZE];
bool pendienteEnviar = false; // Flag que indica si hay datos en espera de
// ser enviados.
uint8_t numBytes; // Cantidad de bytes recibidos 

bool valorRecibido = false; // Flag que indica si se recibieron datos

int enteroRecibido; // Valor entero del dato recibido 

/**
 * Retorna el valor del dato recibido desde el hercules.
 */
int obtenerValorPC() {
    return enteroRecibido;
}

/**
 * Retorna verdadero si se recibieron datos desde el hercules.
 */
bool banderaEntradaPC() {
    return valorRecibido;
}

/**
 * Limpia la Flag que se usa para saber si se recibieron datos desde el hercules.
 */
void limpiarBanderaPC() {
    valorRecibido = false;
}

/**
 * Setea la Flag en aviso que hay datos para ser enviados al pc.
 */
void setDatosPendientes() {
    pendienteEnviar = true;
}

void manejadorUSB(void *params) {
    for (;;) {
        if ((USBGetDeviceState() < CONFIGURED_STATE) ||
                (USBIsDeviceSuspended() == true)) {

        } else {
            CDCTxService();


            if (USBUSARTIsTxTrfReady()) {

                // Recibir datos
                if (!pendienteEnviar) {
                    memset(buffer, 0, sizeof (buffer));
                    // Se limpia cualquier basura que haya en el buffer

                    numBytes = getsUSBUSART(buffer, sizeof (buffer));
                    if (numBytes > 0) {
                        sscanf(buffer, "%d", &enteroRecibido);
                        valorRecibido = true;
                        //return;
                    }
                }

                // Enviar datos
                if (pendienteEnviar) {
                    putsUSBUSART(buffer);
                    pendienteEnviar = false;
                }
            }
        }
    }
}