/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC32MM0256GPM064
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.50
        MPLAB 	          :  MPLAB X v5.50
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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RB7, high using LATB7.

  @Description
    Sets the GPIO pin, RB7, high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 high (1)
    ACC_INT1_SetHigh();
    </code>

*/
#define ACC_INT1_SetHigh()          ( LATBSET = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RB7, low using LATB7.

  @Description
    Sets the GPIO pin, RB7, low using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 low (0)
    ACC_INT1_SetLow();
    </code>

*/
#define ACC_INT1_SetLow()           ( LATBCLR = (1 << 7) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB7, low or high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB7 to low.
    ACC_INT1_SetValue(false);
    </code>

*/
inline static void ACC_INT1_SetValue(bool value)
{
  if(value)
  {
    ACC_INT1_SetHigh();
  }
  else
  {
    ACC_INT1_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB7, using LATB7.

  @Description
    Toggles the GPIO pin, RB7, using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB7
    ACC_INT1_Toggle();
    </code>

*/
#define ACC_INT1_Toggle()           ( LATBINV = (1 << 7) )
/**
  @Summary
    Reads the value of the GPIO pin, RB7.

  @Description
    Reads the value of the GPIO pin, RB7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB7
    postValue = ACC_INT1_GetValue();
    </code>

*/
#define ACC_INT1_GetValue()         PORTBbits.RB7
/**
  @Summary
    Configures the GPIO pin, RB7, as an input.

  @Description
    Configures the GPIO pin, RB7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an input
    ACC_INT1_SetDigitalInput();
    </code>

*/
#define ACC_INT1_SetDigitalInput()   ( TRISBSET = (1 << 7) )
/**
  @Summary
    Configures the GPIO pin, RB7, as an output.

  @Description
    Configures the GPIO pin, RB7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an output
    ACC_INT1_SetDigitalOutput();
    </code>

*/
#define ACC_INT1_SetDigitalOutput()   ( TRISBCLR = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    ACC_INT2_SetHigh();
    </code>

*/
#define ACC_INT2_SetHigh()          ( LATBSET = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    ACC_INT2_SetLow();
    </code>

*/
#define ACC_INT2_SetLow()           ( LATBCLR = (1 << 8) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB8, low or high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB8 to low.
    ACC_INT2_SetValue(false);
    </code>

*/
inline static void ACC_INT2_SetValue(bool value)
{
  if(value)
  {
    ACC_INT2_SetHigh();
  }
  else
  {
    ACC_INT2_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB8, using LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    ACC_INT2_Toggle();
    </code>

*/
#define ACC_INT2_Toggle()           ( LATBINV = (1 << 8) )
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = ACC_INT2_GetValue();
    </code>

*/
#define ACC_INT2_GetValue()         PORTBbits.RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    ACC_INT2_SetDigitalInput();
    </code>

*/
#define ACC_INT2_SetDigitalInput()   ( TRISBSET = (1 << 8) )
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    ACC_INT2_SetDigitalOutput();
    </code>

*/
#define ACC_INT2_SetDigitalOutput()   ( TRISBCLR = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RC13, high using LATC13.

  @Description
    Sets the GPIO pin, RC13, high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 high (1)
    ACC_SCK_SetHigh();
    </code>

*/
#define ACC_SCK_SetHigh()          ( LATCSET = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RC13, low using LATC13.

  @Description
    Sets the GPIO pin, RC13, low using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 low (0)
    ACC_SCK_SetLow();
    </code>

*/
#define ACC_SCK_SetLow()           ( LATCCLR = (1 << 13) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RC13, low or high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RC13 to low.
    ACC_SCK_SetValue(false);
    </code>

*/
inline static void ACC_SCK_SetValue(bool value)
{
  if(value)
  {
    ACC_SCK_SetHigh();
  }
  else
  {
    ACC_SCK_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RC13, using LATC13.

  @Description
    Toggles the GPIO pin, RC13, using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC13
    ACC_SCK_Toggle();
    </code>

*/
#define ACC_SCK_Toggle()           ( LATCINV = (1 << 13) )
/**
  @Summary
    Reads the value of the GPIO pin, RC13.

  @Description
    Reads the value of the GPIO pin, RC13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC13
    postValue = ACC_SCK_GetValue();
    </code>

*/
#define ACC_SCK_GetValue()         PORTCbits.RC13
/**
  @Summary
    Configures the GPIO pin, RC13, as an input.

  @Description
    Configures the GPIO pin, RC13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an input
    ACC_SCK_SetDigitalInput();
    </code>

*/
#define ACC_SCK_SetDigitalInput()   ( TRISCSET = (1 << 13) )
/**
  @Summary
    Configures the GPIO pin, RC13, as an output.

  @Description
    Configures the GPIO pin, RC13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an output
    ACC_SCK_SetDigitalOutput();
    </code>

*/
#define ACC_SCK_SetDigitalOutput()   ( TRISCCLR = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RD0, high using LATD0.

  @Description
    Sets the GPIO pin, RD0, high using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD0 high (1)
    ACC_MOSI_SetHigh();
    </code>

*/
#define ACC_MOSI_SetHigh()          ( LATDSET = (1 << 0) )
/**
  @Summary
    Sets the GPIO pin, RD0, low using LATD0.

  @Description
    Sets the GPIO pin, RD0, low using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD0 low (0)
    ACC_MOSI_SetLow();
    </code>

*/
#define ACC_MOSI_SetLow()           ( LATDCLR = (1 << 0) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RD0, low or high using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RD0 to low.
    ACC_MOSI_SetValue(false);
    </code>

*/
inline static void ACC_MOSI_SetValue(bool value)
{
  if(value)
  {
    ACC_MOSI_SetHigh();
  }
  else
  {
    ACC_MOSI_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RD0, using LATD0.

  @Description
    Toggles the GPIO pin, RD0, using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD0
    ACC_MOSI_Toggle();
    </code>

*/
#define ACC_MOSI_Toggle()           ( LATDINV = (1 << 0) )
/**
  @Summary
    Reads the value of the GPIO pin, RD0.

  @Description
    Reads the value of the GPIO pin, RD0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD0
    postValue = ACC_MOSI_GetValue();
    </code>

*/
#define ACC_MOSI_GetValue()         PORTDbits.RD0
/**
  @Summary
    Configures the GPIO pin, RD0, as an input.

  @Description
    Configures the GPIO pin, RD0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD0 as an input
    ACC_MOSI_SetDigitalInput();
    </code>

*/
#define ACC_MOSI_SetDigitalInput()   ( TRISDSET = (1 << 0) )
/**
  @Summary
    Configures the GPIO pin, RD0, as an output.

  @Description
    Configures the GPIO pin, RD0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD0 as an output
    ACC_MOSI_SetDigitalOutput();
    </code>

*/
#define ACC_MOSI_SetDigitalOutput()   ( TRISDCLR = (1 << 0) )
/**
  @Summary
    Sets the GPIO pin, RD2, high using LATD2.

  @Description
    Sets the GPIO pin, RD2, high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 high (1)
    ACC_CS_SetHigh();
    </code>

*/
#define ACC_CS_SetHigh()          ( LATDSET = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RD2, low using LATD2.

  @Description
    Sets the GPIO pin, RD2, low using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 low (0)
    ACC_CS_SetLow();
    </code>

*/
#define ACC_CS_SetLow()           ( LATDCLR = (1 << 2) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RD2, low or high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RD2 to low.
    ACC_CS_SetValue(false);
    </code>

*/
inline static void ACC_CS_SetValue(bool value)
{
  if(value)
  {
    ACC_CS_SetHigh();
  }
  else
  {
    ACC_CS_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RD2, using LATD2.

  @Description
    Toggles the GPIO pin, RD2, using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD2
    ACC_CS_Toggle();
    </code>

*/
#define ACC_CS_Toggle()           ( LATDINV = (1 << 2) )
/**
  @Summary
    Reads the value of the GPIO pin, RD2.

  @Description
    Reads the value of the GPIO pin, RD2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD2
    postValue = ACC_CS_GetValue();
    </code>

*/
#define ACC_CS_GetValue()         PORTDbits.RD2
/**
  @Summary
    Configures the GPIO pin, RD2, as an input.

  @Description
    Configures the GPIO pin, RD2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an input
    ACC_CS_SetDigitalInput();
    </code>

*/
#define ACC_CS_SetDigitalInput()   ( TRISDSET = (1 << 2) )
/**
  @Summary
    Configures the GPIO pin, RD2, as an output.

  @Description
    Configures the GPIO pin, RD2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an output
    ACC_CS_SetDigitalOutput();
    </code>

*/
#define ACC_CS_SetDigitalOutput()   ( TRISDCLR = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RD4, high using LATD4.

  @Description
    Sets the GPIO pin, RD4, high using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 high (1)
    ACC_MISO_SetHigh();
    </code>

*/
#define ACC_MISO_SetHigh()          ( LATDSET = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RD4, low using LATD4.

  @Description
    Sets the GPIO pin, RD4, low using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 low (0)
    ACC_MISO_SetLow();
    </code>

*/
#define ACC_MISO_SetLow()           ( LATDCLR = (1 << 4) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RD4, low or high using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RD4 to low.
    ACC_MISO_SetValue(false);
    </code>

*/
inline static void ACC_MISO_SetValue(bool value)
{
  if(value)
  {
    ACC_MISO_SetHigh();
  }
  else
  {
    ACC_MISO_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RD4, using LATD4.

  @Description
    Toggles the GPIO pin, RD4, using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD4
    ACC_MISO_Toggle();
    </code>

*/
#define ACC_MISO_Toggle()           ( LATDINV = (1 << 4) )
/**
  @Summary
    Reads the value of the GPIO pin, RD4.

  @Description
    Reads the value of the GPIO pin, RD4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD4
    postValue = ACC_MISO_GetValue();
    </code>

*/
#define ACC_MISO_GetValue()         PORTDbits.RD4
/**
  @Summary
    Configures the GPIO pin, RD4, as an input.

  @Description
    Configures the GPIO pin, RD4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an input
    ACC_MISO_SetDigitalInput();
    </code>

*/
#define ACC_MISO_SetDigitalInput()   ( TRISDSET = (1 << 4) )
/**
  @Summary
    Configures the GPIO pin, RD4, as an output.

  @Description
    Configures the GPIO pin, RD4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an output
    ACC_MISO_SetDigitalOutput();
    </code>

*/
#define ACC_MISO_SetDigitalOutput()   ( TRISDCLR = (1 << 4) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0256GPM064
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Callback for ACC_INT1 Pin.

  @Description
    This routine is callback for ACC_INT1 Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        ACC_INT1_SetInterruptHandler(&ACC_INT1_CallBack);
    </code>
*/
void ACC_INT1_CallBack(void);


/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ACC_INT1_SetInterruptHandler(&ACC_INT1_CallBack);
    </code>
*/
void ACC_INT1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        ACC_INT1_SetIOCInterruptHandler(&ACC_INT1_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse ACC_INT1_SetInterruptHandler instead."))) ACC_INT1_SetIOCInterruptHandler(void *handler);


#endif
