#ifndef _respuestas_H_
#define _respuestas_H_


#define CONTINUAR "\n> Aprete una tecla.\n"


#define MENU "\n ¡Seleccione un item! \n"\
                    "1: Configurar fecha y hora\n"\
                    "2: Mostrar fecha y hora\n"\
                    "3: Configurar LED RGB - colores primarios\n"\
                    "4: Configurar LED RGB PRO - colores personalizados \n"\
                    "5: Visualizar datos del ultimo LED RGB alterado\n"
        
#define MENU_ERROR "\nError | Valor invalido. Ingresar valor del 1 a 5\n"

#define ANIO "\n> Ingresar el año\n"
#define ANIO_ERROR "\n> Error | Valor invalido. Ingresar valor del 1900 a 2030\n"

#define MES "\n> Ingresar un mes de 1 a 12\n"
#define MES_ERROR "\n> Error | Valor invalido. Ingresar valor del 1 a 12\n"

#define DIA "\n> Ingresar un día de 1 a 31\n"
#define DIA_ERROR "\n> Error | Valor invalido\n"
#define DIA_ERROR_MES_30 "\n> Error | El mes indicado tiene 30 dias\n" 

#define HORA "\n> Ingresar una hora de 00 a 23\n"
#define HORA_ERROR "\n> Error | Valor invalido. Ingresar valor del 00 a 23\n"

#define MINUTO "\n> Ingresar minutos de 0 a 59\n"
#define MINUTO_ERROR "\n> Error | Valor invalido. Ingresar valor del 0 a 59\n"

#define FECHA_FIN "\n> Se modifico la fecha y hora correctamente.\n"\
                      "> Presionar cualquier tecla para continuar.\n"


#define FECHA_ACTUAL "\n> La fecha y hora del PIC es: "


#define LED "\n> Ingresar LED a modificar de 1 a 8\n"
#define LED_ERROR "\n> Error | Valor invalido. Ingresar valor del 1 a 8\n"

#define COLOR "\n> Ingresar color deseado:\n"\
                       " 0: Blanco\n"\
                       " 1: Rojo\n"\
                       " 2: Azul\n"\
                       " 3: Verde\n"\
                       " 4: Apagado\n"
                       
#define COLOR_ERROR "\n> Error | Valor invalido. Ingresar valor del 0 a 4\n"

#define COLOR_ROJO "\n> Ingresar valor de rojo. De 0 a 255\n"
#define COLOR_VERDE "\n> Ingresar valor de verde. De 0 a 255\n"
#define COLOR_AZUL "\n> Ingresar valor de azul. De 0 a 255\n"
#define RGB_COLOR "\n> Error | Valor invalido. Ingresar valor del 0 a 255\n"

#define LED_FIN "\n> El LED seleccionado fue modificado.\n"\
                      "> Presionar cualquier tecla para continuar.\n"

#define INGRESAR_TIEMPO_COMANDO "\n> Ingrese un tiempo entre 0 y 120 para demorar el comando!"

#define CMD_TIEMPO_INCORRECTO "\n> El tiempo debe estar entre 0 y 120."

#define FECHA_ULTIMA_MODIFICACION "\n> Ultima modificación fue al led: %d. Su color es: %d. Fecha: %s."

#define FORMATO_FECHA "%d/%m/%Y - %X"

#endif