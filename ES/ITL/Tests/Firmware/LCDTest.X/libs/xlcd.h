/*********************************************************************
 *
 *                  Modified LCD access routines for XC8
 * 
 *********************************************************************
 *
 * Complier:        XC8
 *
 * Author           Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Danny Ng         6/Aug/12    1. Removed XLCDPutRomString
 *                              2. Port Setting in xlcdDef.h
 ********************************************************************/

/*********************************************************************
 *
 *                  External LCD access routines defs
 *
 *********************************************************************
 * FileName:        XLCD.h
 * Dependencies:    compiler.h
 * Processor:       PIC18
 * Complier:        MCC18 v1.00.50 or higher
 *                  HITECH PICC-18 V8.10PL1 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement 
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PICmicro� Microcontroller is intended and
 * supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * Author               Date    Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Naveen Raj     6/9/03  Original        (Rev 1.0)
 ********************************************************************/
#ifndef __XLCD_H
#define __XLCD_H
#define AddFile ///ADD_PROC_INC_FILE
#include <xc.h>
#include "xlcdDef.h"

void XLCDInit(void);                                //to initialise the LCD
void XLCDPut(char data);                            //to put dtat to be displayed
void XLCDPutRamString(char *string);                //to display data string in RAM
char XLCDIsBusy(void);                              //to check Busy flag
void XLCDCommand(unsigned char cmd);                //to send commands to LCD           
unsigned char XLCDGetAddr(void);
char XLCDGet(void);

#define XLCDL1home()    XLCDCommand(0x80)
#define XLCDL2home()    XLCDCommand(0xC0)
#define XLCDClear()     XLCDCommand(0x01)
#define XLCDReturnHome() XLCDCommand(0x02)

void XLCDDelay15ms(void);
void XLCDDelay4ms(void);
void XLCDDelay100us(void);
void XLCD_Delay500ns(void);
void XLCDDelay(void);

#endif
