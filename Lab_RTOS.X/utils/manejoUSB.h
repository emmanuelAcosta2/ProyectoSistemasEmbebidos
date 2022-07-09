
#ifndef _manejo_usb_
#define _manejo_usb_


#define BUFFER_SIZE 500


extern char buffer[];

int obtenerValorPC();

bool banderaEntradaPC();

void limpiarBanderaPC();

void setDatosPendientes();

void manejadorUSB(void *params);
#endif