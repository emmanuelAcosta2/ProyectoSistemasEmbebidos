/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.167.0
        Device            :  PIC32MM0256GPM064
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.35
 */

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */

/* Kernel includes. */
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"




#include "mcc_generated_files/usb/usb_device_cdc.h"
#include "mcc_generated_files/tmr2.h"
#include "utils/tmr_aux_cnt.h"
#include "utils/manejo_leds_rojo.h"
#include "utils/manejo_leds_rgb.h"
#include "utils/maquina_estados.h"
#include "utils/manejoUSB.h"
#include "mcc_generated_files/rtcc.h"
#include "framework/Accelerometer/Accelerometer.h"
#include "lectura.h"
#include "utils.h"
#include "enemigo.h"
#include "sonidos.h"
#include "timers.h"
#include "buttons.h"
#include "reiniciarValores.h"
#include "mostrarPuntaje.h"
#include "./mcc_generated_files/memory/flash_demo.h"
#include "escribirMemoria.h"

void blinkLED(void *p_param);
//wait x number of seconds

int main(void) {
    // initialize the device
    empezarJuego = false;
    terminoJuego = true;
    estadoBoton1.seReinicio = true;
    puntaje = readWord();
    SYSTEM_Initialize();
    BUZ_CTRL_SetDigitalOutput();
    semaforoStructCoordenadas = xSemaphoreCreateMutex();
    semaforoArrayLedsYSend = xSemaphoreCreateMutex();
    semaforoStructEnemigo = xSemaphoreCreateMutex();
    //readMemory();

    //Inicializar los botones
    BTN1_SetDigitalInput();
    BTN2_SetDigitalInput();

    BTN1_SetInterruptHandler(boton1_isr);
    BTN2_SetInterruptHandler(boton2_isr);
    TMR2_SetInterruptHandler(timer2_isr);

   
    //Wait for accel init. If false repeat.
    while (!ACCEL_init()) {

    }
    
    

    TaskHandle_t xHandleLeerValores = NULL;
    TaskHandle_t xHandleMoverEnemigo = NULL;
    TaskHandle_t xHandleCrearTimers = NULL;
    TaskHandle_t xHandleSumarPuntaje = NULL;

    //El boton S2, se apreta en dos ocasiones
    //1-Cuando queres resetear
    //2-Cuando queres resetear al HS.


    xTaskCreate(leerValoresAcelerometro, "leerValores", configMINIMAL_STACK_SIZE * 10, NULL, tskIDLE_PRIORITY + 1, &xHandleLeerValores);
    xTaskCreate(moverEnemigo, "moverEnemigo", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY * 10 + 1, &xHandleMoverEnemigo);
    xTaskCreate(crearTimers, "timers", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xHandleCrearTimers);
    xTaskCreate(sumarPuntaje, "sumarPuntajes", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xHandleSumarPuntaje);
    xTaskCreate(reiniciarValores, "reiniciarValores", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(mostrarPuntaje, "mostrarPuntajes", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    //xTaskCreate(escribirMemoria, "escribirMemoria", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    /* Finally start the scheduler. */
    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following line
    will never be reached.  If the following line does execute, then there was
    insufficient FreeRTOS heap memory available for the idle and/or timer tasks
    to be created.  See the memory management section on the FreeRTOS web site
    for more details. */
    for (;;);


}

void blinkLED(void *p_param) {
    // Add your code here
}

void vApplicationMallocFailedHook(void) {
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for (;;);
}

/*-----------------------------------------------------------*/

void vApplicationIdleHook(void) {
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    (void) pcTaskName;
    (void) pxTask;

    /* Run time task stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook	function is 
    called if a task stack overflow is detected.  Note the system/interrupt
    stack is not checked. */
    taskDISABLE_INTERRUPTS();
    for (;;);
}

/*-----------------------------------------------------------*/

void vApplicationTickHook(void) {
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()). */
}

/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

void vAssertCalled(const char * pcFile, unsigned long ulLine) {
    volatile unsigned long ul = 0;

    (void) pcFile;
    (void) ulLine;

    __asm volatile( "di");
    {
        /* Set ul to a non-zero value using the debugger to step out of this
        function. */
        while (ul == 0) {
            portNOP();
        }
    }
    __asm volatile( "ei");
}

/**
 End of File
 */

