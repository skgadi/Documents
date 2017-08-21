/* 
 * File:   tmr0.h
 * Author: gadis
 *
 * Created on July 24, 2016, 11:40 AM
 */

#ifndef TMR0_H
#define	TMR0_H

#include <stdint.h>
#include <stdbool.h>



#ifdef	__cplusplus
extern "C" {
#endif


/**
  Section: Macro Declarations
*/

#define TMR0_INTERRUPT_TICKER_FACTOR    64102

/**
  Section: TMR0 APIs
*/

/**
  @Summary
    Initializes the TMR0 module.

  @Description
    This function initializes the TMR0 Registers.
    This function must be called before any other TMR0 function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR0 module
        TMR0_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR0_Initialize(void);


/**
  @Summary
    Reads the TMR0 register.

  @Description
    This function reads the TMR0 register value and return it.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR0 register.

  @Example
    <code>
    // Initialize TMR0 module

    // Read the current value of TMR0
    if(0 == TMR0_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TMR0_Reload();
    }
    </code>
*/
uint8_t TMR0_ReadTimer(void);

/**
  @Summary
    Writes the TMR0 register.

  @Description
    This function writes the TMR0 register.
    This function must be called after the initialization of TMR0.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    timerVal - Value to write into TMR0 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR0 register
        if(ZERO == TMR0_ReadTimer())
        {
            // Do something else...

            // Write the TMR0 register
            TMR0_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR0_WriteTimer(uint8_t timerVal);

/**
  @Summary
    Reload the TMR0 register.

  @Description
    This function reloads the TMR0 register.
    This function must be called to write initial value into TMR0 register.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    while(1)
    {
        if(TMR0IF)
        {
            // Do something else...

            // clear the TMR0 interrupt flag
            TMR0IF = 0;

            // Reload the initial value of TMR0
            TMR0_Reload();
        }
    }
    </code>
*/
void TMR0_Reload(void);

/**
  @Summary
    Timer Interrupt Service Routine

  @Description
    Timer Interrupt Service Routine is called by the Interrupt Manager.

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void TMR0_ISR(void);

/**
  @Summary
    CallBack function

  @Description
    This function is called from the timer ISR. User can write your code in this function.

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this function.

  @Param
    None

  @Returns
    None
*/
void TMR0_CallBack(void);


#ifdef	__cplusplus
}
#endif

#endif	/* TMR0_H */

