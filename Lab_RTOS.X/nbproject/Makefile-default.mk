#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=freeRTOS/croutine.c freeRTOS/event_groups.c freeRTOS/list.c freeRTOS/queue.c freeRTOS/tasks.c freeRTOS/timers.c freeRTOS/portable/MemMang/heap_4.c freeRTOS/portable/MPLAB/PIC32MM/port.c freeRTOS/portable/MPLAB/PIC32MM/port_asm.S mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/exceptions.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/rtcc.c mcc_generated_files/tmr2.c utils/delay.c utils/fecha_hora.c utils/manejoUSB.c utils/manejo_leds_rgb.c utils/manejo_leds_rojo.c utils/maquina_estados.c utils/tmr_aux_cnt.c utils/WS2812.c main.c mcc_generated_files/spi1.c mcc_generated_files/usb/usb_device_events.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device_cdc.c ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/freeRTOS/croutine.o ${OBJECTDIR}/freeRTOS/event_groups.o ${OBJECTDIR}/freeRTOS/list.o ${OBJECTDIR}/freeRTOS/queue.o ${OBJECTDIR}/freeRTOS/tasks.o ${OBJECTDIR}/freeRTOS/timers.o ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/rtcc.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/utils/delay.o ${OBJECTDIR}/utils/fecha_hora.o ${OBJECTDIR}/utils/manejoUSB.o ${OBJECTDIR}/utils/manejo_leds_rgb.o ${OBJECTDIR}/utils/manejo_leds_rojo.o ${OBJECTDIR}/utils/maquina_estados.o ${OBJECTDIR}/utils/tmr_aux_cnt.o ${OBJECTDIR}/utils/WS2812.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o ${OBJECTDIR}/_ext/1098631528/LIS3DH.o ${OBJECTDIR}/_ext/995403417/Accelerometer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/freeRTOS/croutine.o.d ${OBJECTDIR}/freeRTOS/event_groups.o.d ${OBJECTDIR}/freeRTOS/list.o.d ${OBJECTDIR}/freeRTOS/queue.o.d ${OBJECTDIR}/freeRTOS/tasks.o.d ${OBJECTDIR}/freeRTOS/timers.o.d ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o.d ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o.d ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/exceptions.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/rtcc.o.d ${OBJECTDIR}/mcc_generated_files/tmr2.o.d ${OBJECTDIR}/utils/delay.o.d ${OBJECTDIR}/utils/fecha_hora.o.d ${OBJECTDIR}/utils/manejoUSB.o.d ${OBJECTDIR}/utils/manejo_leds_rgb.o.d ${OBJECTDIR}/utils/manejo_leds_rojo.o.d ${OBJECTDIR}/utils/maquina_estados.o.d ${OBJECTDIR}/utils/tmr_aux_cnt.o.d ${OBJECTDIR}/utils/WS2812.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o.d ${OBJECTDIR}/_ext/1098631528/LIS3DH.o.d ${OBJECTDIR}/_ext/995403417/Accelerometer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/freeRTOS/croutine.o ${OBJECTDIR}/freeRTOS/event_groups.o ${OBJECTDIR}/freeRTOS/list.o ${OBJECTDIR}/freeRTOS/queue.o ${OBJECTDIR}/freeRTOS/tasks.o ${OBJECTDIR}/freeRTOS/timers.o ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/rtcc.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/utils/delay.o ${OBJECTDIR}/utils/fecha_hora.o ${OBJECTDIR}/utils/manejoUSB.o ${OBJECTDIR}/utils/manejo_leds_rgb.o ${OBJECTDIR}/utils/manejo_leds_rojo.o ${OBJECTDIR}/utils/maquina_estados.o ${OBJECTDIR}/utils/tmr_aux_cnt.o ${OBJECTDIR}/utils/WS2812.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o ${OBJECTDIR}/_ext/1098631528/LIS3DH.o ${OBJECTDIR}/_ext/995403417/Accelerometer.o

# Source Files
SOURCEFILES=freeRTOS/croutine.c freeRTOS/event_groups.c freeRTOS/list.c freeRTOS/queue.c freeRTOS/tasks.c freeRTOS/timers.c freeRTOS/portable/MemMang/heap_4.c freeRTOS/portable/MPLAB/PIC32MM/port.c freeRTOS/portable/MPLAB/PIC32MM/port_asm.S mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/exceptions.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/rtcc.c mcc_generated_files/tmr2.c utils/delay.c utils/fecha_hora.c utils/manejoUSB.c utils/manejo_leds_rgb.c utils/manejo_leds_rojo.c utils/maquina_estados.c utils/tmr_aux_cnt.c utils/WS2812.c main.c mcc_generated_files/spi1.c mcc_generated_files/usb/usb_device_events.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device_cdc.c ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MM0256GPM064
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o: freeRTOS/portable/MPLAB/PIC32MM/port_asm.S  .generated_files/flags/default/17ccdd859683f32b507de18c387b97363ddb8025 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.ok ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d"  -o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o freeRTOS/portable/MPLAB/PIC32MM/port_asm.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d" "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o: freeRTOS/portable/MPLAB/PIC32MM/port_asm.S  .generated_files/flags/default/996dc690a9c9cca745cc8a699ce4a6511070b8bb .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.ok ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d"  -o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o freeRTOS/portable/MPLAB/PIC32MM/port_asm.S  -DXPRJ_default=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.asm.d",--gdwarf-2 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.d" "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/freeRTOS/croutine.o: freeRTOS/croutine.c  .generated_files/flags/default/bb85e6199dcdac10ca253ff9ab810cfdf88e64e7 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/croutine.o.d" -o ${OBJECTDIR}/freeRTOS/croutine.o freeRTOS/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/event_groups.o: freeRTOS/event_groups.c  .generated_files/flags/default/4c4c024d007746688d03b0d1efb085e6f08df64b .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/event_groups.o.d" -o ${OBJECTDIR}/freeRTOS/event_groups.o freeRTOS/event_groups.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/list.o: freeRTOS/list.c  .generated_files/flags/default/71dfa1d3f34d2a91541b103f373252f8a2dc434e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/list.o.d" -o ${OBJECTDIR}/freeRTOS/list.o freeRTOS/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/queue.o: freeRTOS/queue.c  .generated_files/flags/default/8957ab46ce177ba8a9eee4623fffd8985e9f51e7 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/queue.o.d" -o ${OBJECTDIR}/freeRTOS/queue.o freeRTOS/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/tasks.o: freeRTOS/tasks.c  .generated_files/flags/default/44b01d4900d0dec336c0cedd241fe8503c70decf .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/tasks.o.d" -o ${OBJECTDIR}/freeRTOS/tasks.o freeRTOS/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/timers.o: freeRTOS/timers.c  .generated_files/flags/default/d6f5f5485d2f0f27663c5e3d3660544a2be53c8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/timers.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/timers.o.d" -o ${OBJECTDIR}/freeRTOS/timers.o freeRTOS/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o: freeRTOS/portable/MemMang/heap_4.c  .generated_files/flags/default/c3f7f620419758d955411782e8df51dc3c229e96 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MemMang" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o.d" -o ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o freeRTOS/portable/MemMang/heap_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o: freeRTOS/portable/MPLAB/PIC32MM/port.c  .generated_files/flags/default/debc51c76131ca1ec738fe976bc4859935635ebd .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o.d" -o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o freeRTOS/portable/MPLAB/PIC32MM/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/92aebc44be5b626b4d2bb65153e66319501292c0 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/72c14a0ddb6fdc14e5482936b6d8201b91ff861e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/flags/default/627ea88b619f29c0b718c294b11b59b70a8a6802 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/66d741da5001e6ef60ebe4fd6fff1f41fc7ed6c4 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/64362e138060d5f54088ac3ffad167ba9bd622eb .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/c8d485ea0d3a0977eea7da46373bcb6b5ab05bf8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/rtcc.o: mcc_generated_files/rtcc.c  .generated_files/flags/default/6129967dce5886f4d135d04a7a3258d938d4ac59 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/rtcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/rtcc.o mcc_generated_files/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/default/ca96af86f0169691fa0bba9e06d1fca26b1a6c4c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d" -o ${OBJECTDIR}/mcc_generated_files/tmr2.o mcc_generated_files/tmr2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/delay.o: utils/delay.c  .generated_files/flags/default/fe8dd5e8ff625957d5e1bb41b95368efe5988a8b .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/delay.o.d 
	@${RM} ${OBJECTDIR}/utils/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/delay.o.d" -o ${OBJECTDIR}/utils/delay.o utils/delay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/fecha_hora.o: utils/fecha_hora.c  .generated_files/flags/default/a9af380d0bced6064df0e52c511a1bfa61eff9aa .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/fecha_hora.o.d 
	@${RM} ${OBJECTDIR}/utils/fecha_hora.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/fecha_hora.o.d" -o ${OBJECTDIR}/utils/fecha_hora.o utils/fecha_hora.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejoUSB.o: utils/manejoUSB.c  .generated_files/flags/default/9ca25ae8a9cd5f3321fbf0c7066c03c296c0302b .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejoUSB.o.d 
	@${RM} ${OBJECTDIR}/utils/manejoUSB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejoUSB.o.d" -o ${OBJECTDIR}/utils/manejoUSB.o utils/manejoUSB.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejo_leds_rgb.o: utils/manejo_leds_rgb.c  .generated_files/flags/default/f76125059ce36c70d3d84a64849240ed4fc53654 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejo_leds_rgb.o.d" -o ${OBJECTDIR}/utils/manejo_leds_rgb.o utils/manejo_leds_rgb.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejo_leds_rojo.o: utils/manejo_leds_rojo.c  .generated_files/flags/default/196228e9c45c67f6b7b3a5654c59eb356082e086 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rojo.o.d 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rojo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejo_leds_rojo.o.d" -o ${OBJECTDIR}/utils/manejo_leds_rojo.o utils/manejo_leds_rojo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/maquina_estados.o: utils/maquina_estados.c  .generated_files/flags/default/6cd903c8730ce73fe94a87168888d629b4493f5c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/maquina_estados.o.d 
	@${RM} ${OBJECTDIR}/utils/maquina_estados.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/maquina_estados.o.d" -o ${OBJECTDIR}/utils/maquina_estados.o utils/maquina_estados.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/tmr_aux_cnt.o: utils/tmr_aux_cnt.c  .generated_files/flags/default/cd96b30297a464efa6b6b6b67cd348440a79152e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/tmr_aux_cnt.o.d 
	@${RM} ${OBJECTDIR}/utils/tmr_aux_cnt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/tmr_aux_cnt.o.d" -o ${OBJECTDIR}/utils/tmr_aux_cnt.o utils/tmr_aux_cnt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/WS2812.o: utils/WS2812.c  .generated_files/flags/default/f82e75cfccf9dc693db4d4fe7f8ee9bd07bc12e0 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/WS2812.o.d 
	@${RM} ${OBJECTDIR}/utils/WS2812.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/WS2812.o.d" -o ${OBJECTDIR}/utils/WS2812.o utils/WS2812.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/b01073f35d3a2ba3240a8e32140aa3569328e412 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/default/23f733c6661cc5813bdd6aaa4816368e7f04481c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d" -o ${OBJECTDIR}/mcc_generated_files/spi1.o mcc_generated_files/spi1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o: mcc_generated_files/usb/usb_device_events.c  .generated_files/flags/default/63fc4932d8c4d0c9bf750442ea2301b95f23a565 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o mcc_generated_files/usb/usb_device_events.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/default/fc227f81963eeee44edd0656c2d87edc0ed7462c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o mcc_generated_files/usb/usb_device.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/default/249613b936e4a09d079b80601788b99197ac7fdf .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o mcc_generated_files/usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o: mcc_generated_files/usb/usb_device_cdc.c  .generated_files/flags/default/1d19f47422fd999940fa4674dee4fe5452f18694 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o mcc_generated_files/usb/usb_device_cdc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1098631528/LIS3DH.o: ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c  .generated_files/flags/default/e62cf8b6af271a446e10f1acb849a3c80908e1e7 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/_ext/1098631528" 
	@${RM} ${OBJECTDIR}/_ext/1098631528/LIS3DH.o.d 
	@${RM} ${OBJECTDIR}/_ext/1098631528/LIS3DH.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/_ext/1098631528/LIS3DH.o.d" -o ${OBJECTDIR}/_ext/1098631528/LIS3DH.o ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/995403417/Accelerometer.o: ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c  .generated_files/flags/default/60c1de41ab2f6a85975e88c898545cad8358e588 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/_ext/995403417" 
	@${RM} ${OBJECTDIR}/_ext/995403417/Accelerometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/995403417/Accelerometer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/_ext/995403417/Accelerometer.o.d" -o ${OBJECTDIR}/_ext/995403417/Accelerometer.o ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/freeRTOS/croutine.o: freeRTOS/croutine.c  .generated_files/flags/default/3d3e67e2fbc767d43ac6e1e077a91032e2c83110 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/croutine.o.d" -o ${OBJECTDIR}/freeRTOS/croutine.o freeRTOS/croutine.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/event_groups.o: freeRTOS/event_groups.c  .generated_files/flags/default/a773c0b8598b19120d5d68f7b49e72359c81e1e6 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/event_groups.o.d" -o ${OBJECTDIR}/freeRTOS/event_groups.o freeRTOS/event_groups.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/list.o: freeRTOS/list.c  .generated_files/flags/default/25c6dc84ea7aa6fef8b364656c74f00c834069b2 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/list.o.d" -o ${OBJECTDIR}/freeRTOS/list.o freeRTOS/list.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/queue.o: freeRTOS/queue.c  .generated_files/flags/default/86e4b07bf8b78ea48ea220793bff067daf7d7d7b .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/queue.o.d" -o ${OBJECTDIR}/freeRTOS/queue.o freeRTOS/queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/tasks.o: freeRTOS/tasks.c  .generated_files/flags/default/85fae7f5b92d373ad1af160b4197acdc7adf7d6e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/tasks.o.d" -o ${OBJECTDIR}/freeRTOS/tasks.o freeRTOS/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/timers.o: freeRTOS/timers.c  .generated_files/flags/default/ee7058d33520302b4e470f08b817823a1c514a29 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS" 
	@${RM} ${OBJECTDIR}/freeRTOS/timers.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/timers.o.d" -o ${OBJECTDIR}/freeRTOS/timers.o freeRTOS/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o: freeRTOS/portable/MemMang/heap_4.c  .generated_files/flags/default/1ecdf09f66470a651d9042e6db27e0c678e789ee .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MemMang" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o.d" -o ${OBJECTDIR}/freeRTOS/portable/MemMang/heap_4.o freeRTOS/portable/MemMang/heap_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o: freeRTOS/portable/MPLAB/PIC32MM/port.c  .generated_files/flags/default/ff489d2b3129e7a5e8277a3705d1b6b594f75d33 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM" 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o.d 
	@${RM} ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o.d" -o ${OBJECTDIR}/freeRTOS/portable/MPLAB/PIC32MM/port.o freeRTOS/portable/MPLAB/PIC32MM/port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/4f2e0d2bdeb36bd907af8ed3d6f7802c74dcb67 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/942cb13b3df9197410199fb603db68ae01c5ab99 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/flags/default/c27eecb06d04dfc81c46384e0784772464aef311 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/f00bb108396e370b460afb418a2a9aac98f837be .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/ab062e9602c897eb88ea100c6a97156ba1fc0a76 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/caf06654c89408bc864fcf4d203f51b3ca353247 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/rtcc.o: mcc_generated_files/rtcc.c  .generated_files/flags/default/3acba0976eded391f6222fa1b9d68aae83bb57ad .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/rtcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/rtcc.o mcc_generated_files/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/default/6fc2eaf3b4214474f474c2eac44357e255b80054 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d" -o ${OBJECTDIR}/mcc_generated_files/tmr2.o mcc_generated_files/tmr2.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/delay.o: utils/delay.c  .generated_files/flags/default/f9794ce6409bbac7881ced6c5807c7979fe3093e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/delay.o.d 
	@${RM} ${OBJECTDIR}/utils/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/delay.o.d" -o ${OBJECTDIR}/utils/delay.o utils/delay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/fecha_hora.o: utils/fecha_hora.c  .generated_files/flags/default/58a182f8ac1005d28023169a4249832667d0bd7b .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/fecha_hora.o.d 
	@${RM} ${OBJECTDIR}/utils/fecha_hora.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/fecha_hora.o.d" -o ${OBJECTDIR}/utils/fecha_hora.o utils/fecha_hora.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejoUSB.o: utils/manejoUSB.c  .generated_files/flags/default/1289f39775d10e478601fc46566d1c4644426bb8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejoUSB.o.d 
	@${RM} ${OBJECTDIR}/utils/manejoUSB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejoUSB.o.d" -o ${OBJECTDIR}/utils/manejoUSB.o utils/manejoUSB.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejo_leds_rgb.o: utils/manejo_leds_rgb.c  .generated_files/flags/default/ab561be1c606ac32f50837fe1862aee16c4efc9c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejo_leds_rgb.o.d" -o ${OBJECTDIR}/utils/manejo_leds_rgb.o utils/manejo_leds_rgb.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/manejo_leds_rojo.o: utils/manejo_leds_rojo.c  .generated_files/flags/default/48697c8542f2c40f79e189eee5ccd0d90807159c .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rojo.o.d 
	@${RM} ${OBJECTDIR}/utils/manejo_leds_rojo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/manejo_leds_rojo.o.d" -o ${OBJECTDIR}/utils/manejo_leds_rojo.o utils/manejo_leds_rojo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/maquina_estados.o: utils/maquina_estados.c  .generated_files/flags/default/389a768c0ca3eb9da6910860d0c574490a96a5b8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/maquina_estados.o.d 
	@${RM} ${OBJECTDIR}/utils/maquina_estados.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/maquina_estados.o.d" -o ${OBJECTDIR}/utils/maquina_estados.o utils/maquina_estados.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/tmr_aux_cnt.o: utils/tmr_aux_cnt.c  .generated_files/flags/default/55485a63b41f5aad514cd173794463cfffdd57c8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/tmr_aux_cnt.o.d 
	@${RM} ${OBJECTDIR}/utils/tmr_aux_cnt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/tmr_aux_cnt.o.d" -o ${OBJECTDIR}/utils/tmr_aux_cnt.o utils/tmr_aux_cnt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utils/WS2812.o: utils/WS2812.c  .generated_files/flags/default/df7512715104561b1da88703590ffcb5983332f4 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/WS2812.o.d 
	@${RM} ${OBJECTDIR}/utils/WS2812.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/utils/WS2812.o.d" -o ${OBJECTDIR}/utils/WS2812.o utils/WS2812.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/c0b047464fe5b8651e64a16fb37adfc34d098e67 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/default/70b47343a1296c11b8f1b612db4e619bd22eda64 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d" -o ${OBJECTDIR}/mcc_generated_files/spi1.o mcc_generated_files/spi1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o: mcc_generated_files/usb/usb_device_events.c  .generated_files/flags/default/f2504024f2f36b49c75557c8f5465d09fb62c7d8 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_events.o mcc_generated_files/usb/usb_device_events.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/default/847afe62f91c96fd7118560418f0a7b6d3549a4e .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o mcc_generated_files/usb/usb_device.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/default/9d0a5649036de5a59e7ff231d8ba1cee37a4bfb4 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o mcc_generated_files/usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o: mcc_generated_files/usb/usb_device_cdc.c  .generated_files/flags/default/479063e1a56f7adf27b699ed478b0ab00c9434b2 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o.d" -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_cdc.o mcc_generated_files/usb/usb_device_cdc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1098631528/LIS3DH.o: ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c  .generated_files/flags/default/70763b09dabdc00a562f2b16d6114dffa11a6a12 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/_ext/1098631528" 
	@${RM} ${OBJECTDIR}/_ext/1098631528/LIS3DH.o.d 
	@${RM} ${OBJECTDIR}/_ext/1098631528/LIS3DH.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/_ext/1098631528/LIS3DH.o.d" -o ${OBJECTDIR}/_ext/1098631528/LIS3DH.o ../../../Proyecto/Proyecto.X/platform/LIS3DH/LIS3DH.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/995403417/Accelerometer.o: ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c  .generated_files/flags/default/6fc63ccd0dbafc3cd625651fb41b4f32d2924291 .generated_files/flags/default/63f80d3e53f67d92df857c76536421b47c21c374
	@${MKDIR} "${OBJECTDIR}/_ext/995403417" 
	@${RM} ${OBJECTDIR}/_ext/995403417/Accelerometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/995403417/Accelerometer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"freeRTOS/include" -I"freeRTOS/portable/MPLAB/PIC32MM" -MP -MMD -MF "${OBJECTDIR}/_ext/995403417/Accelerometer.o.d" -o ${OBJECTDIR}/_ext/995403417/Accelerometer.o ../../../Proyecto/Proyecto.X/framework/Accelerometer/Accelerometer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I freeRTOS/include -I freeRTOS/portable/MPLAB/PIC32MM -I .. -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Lab_RTOS.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
