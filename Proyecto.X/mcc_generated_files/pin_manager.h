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
    SCK1_SetHigh();
    </code>

*/
#define SCK1_SetHigh()          ( LATCSET = (1 << 13) )
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
    SCK1_SetLow();
    </code>

*/
#define SCK1_SetLow()           ( LATCCLR = (1 << 13) )

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
    SCK1_SetValue(false);
    </code>

*/
inline static void SCK1_SetValue(bool value)
{
  if(value)
  {
    SCK1_SetHigh();
  }
  else
  {
    SCK1_SetLow();
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
    SCK1_Toggle();
    </code>

*/
#define SCK1_Toggle()           ( LATCINV = (1 << 13) )
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
    postValue = SCK1_GetValue();
    </code>

*/
#define SCK1_GetValue()         PORTCbits.RC13
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
    SCK1_SetDigitalInput();
    </code>

*/
#define SCK1_SetDigitalInput()   ( TRISCSET = (1 << 13) )
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
    SCK1_SetDigitalOutput();
    </code>

*/
#define SCK1_SetDigitalOutput()   ( TRISCCLR = (1 << 13) )
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
    SDO1_SetHigh();
    </code>

*/
#define SDO1_SetHigh()          ( LATDSET = (1 << 0) )
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
    SDO1_SetLow();
    </code>

*/
#define SDO1_SetLow()           ( LATDCLR = (1 << 0) )

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
    SDO1_SetValue(false);
    </code>

*/
inline static void SDO1_SetValue(bool value)
{
  if(value)
  {
    SDO1_SetHigh();
  }
  else
  {
    SDO1_SetLow();
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
    SDO1_Toggle();
    </code>

*/
#define SDO1_Toggle()           ( LATDINV = (1 << 0) )
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
    postValue = SDO1_GetValue();
    </code>

*/
#define SDO1_GetValue()         PORTDbits.RD0
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
    SDO1_SetDigitalInput();
    </code>

*/
#define SDO1_SetDigitalInput()   ( TRISDSET = (1 << 0) )
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
    SDO1_SetDigitalOutput();
    </code>

*/
#define SDO1_SetDigitalOutput()   ( TRISDCLR = (1 << 0) )
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
    SS1_SetHigh();
    </code>

*/
#define SS1_SetHigh()          ( LATDSET = (1 << 2) )
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
    SS1_SetLow();
    </code>

*/
#define SS1_SetLow()           ( LATDCLR = (1 << 2) )

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
    SS1_SetValue(false);
    </code>

*/
inline static void SS1_SetValue(bool value)
{
  if(value)
  {
    SS1_SetHigh();
  }
  else
  {
    SS1_SetLow();
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
    SS1_Toggle();
    </code>

*/
#define SS1_Toggle()           ( LATDINV = (1 << 2) )
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
    postValue = SS1_GetValue();
    </code>

*/
#define SS1_GetValue()         PORTDbits.RD2
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
    SS1_SetDigitalInput();
    </code>

*/
#define SS1_SetDigitalInput()   ( TRISDSET = (1 << 2) )
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
    SS1_SetDigitalOutput();
    </code>

*/
#define SS1_SetDigitalOutput()   ( TRISDCLR = (1 << 2) )
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
    SDI1_SetHigh();
    </code>

*/
#define SDI1_SetHigh()          ( LATDSET = (1 << 4) )
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
    SDI1_SetLow();
    </code>

*/
#define SDI1_SetLow()           ( LATDCLR = (1 << 4) )

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
    SDI1_SetValue(false);
    </code>

*/
inline static void SDI1_SetValue(bool value)
{
  if(value)
  {
    SDI1_SetHigh();
  }
  else
  {
    SDI1_SetLow();
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
    SDI1_Toggle();
    </code>

*/
#define SDI1_Toggle()           ( LATDINV = (1 << 4) )
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
    postValue = SDI1_GetValue();
    </code>

*/
#define SDI1_GetValue()         PORTDbits.RD4
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
    SDI1_SetDigitalInput();
    </code>

*/
#define SDI1_SetDigitalInput()   ( TRISDSET = (1 << 4) )
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
    SDI1_SetDigitalOutput();
    </code>

*/
#define SDI1_SetDigitalOutput()   ( TRISDCLR = (1 << 4) )

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



#endif
