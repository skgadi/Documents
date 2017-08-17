/* 
 * File:   projMain.h
 * Author: gadis
 *
 * Created on June 19, 2017, 2:50 PM
 */

#ifndef PROJMAIN_H
#define	PROJMAIN_H

#ifdef	__cplusplus
extern "C" {
#endif


    
#include "../mcc_generated_files/mcc.h"
#include "GenericTypeDefs.h"
#include "ProjectTypeDefs.h"
#include "HD44780.h"
#include "gps.h"
#include "eeprom.h"
#include "funcs.h"
    

//Compiler Settings
#define LCD_SHOW 5//0->GPS Sync; 1->States; 2->Levels & Cycles; 5->GPS Test
//#define SET_EEPROM
//#define SET_START_TIME 57590

//Constants defined for the project
#define GPS_SWITCH LATCbits.LC1
#define AUDIO_SWITCH LATCbits.LC0
#define MAX_NO_OF_EVENTS 24
#define MAX_NO_OF_STATES 160
#define MAX_NO_OF_CYCLE_TYPES 17
#define DATA_BUS_SIZE 8
#define NO_OF_SECONDS_IN_A_DAY 86400
#define SECONDS_TO_ADJUST_FOR_DAY_LIGHT_SAVING 3600
#define MAX_ALLOWED_GPS_FAILURES 4
#define WAIT_x_SECONDS_AFTER_SWITCHING_ON_GPS (1*60)//20 //Satisfy the condition WAIT_x_SECONDS_AFTER_SWITCHING_ON_GPS > TIME_GAP_BETWEEN_TWO_GPS_READINGS
#define TIME_GAP_BETWEEN_TWO_GPS_READINGS (5*60)//5 //Satisfy the condition  WAIT_x_SECONDS_AFTER_SWITCHING_ON_GPS > TIME_GAP_BETWEEN_TWO_GPS_READINGS
static INT NO_OF_DAYS_IN_A_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Functions
void Timer0_10ms (void);

//Global variables read from the EEPROM
INT16 TIME_ZONE = 0;
INT16 CYCLE_DELAY = 0;
GSK_YEAR_DAY DAY_LIGHT_START, DAY_LIGHT_END;
GSK_SECOND_IN_DAY GPS_SYNC_EVERY_x_SECONDS, GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME;
UINT8 CENTURY = 20;
UINT8 BLINK_ON_TIME, BLINK_OFF_TIME, BLINK_LAST_X_SECONDS, AUDIO_NORMAL_ON_TIME, AUDIO_NORMAL_OFF_TIME, AUDIO_SPECIAL_ON_TIME, AUDIO_SPECIAL_OFF_TIME, SPECIAL_AUDIO_LAST_X_SECONDS, GPS_SYNC_AT_START;
GSK_EVENT EVENTS[MAX_NO_OF_EVENTS];
GSK_STATE STATES[MAX_NO_OF_STATES];
GSK_CYCLE CYCLES[MAX_NO_OF_CYCLE_TYPES];

//Global variables
INT8 PRESENT_EVENT=-1;
INT8 NEXT_EVENT=-1;
UINT8 PRESENT_STATE = 0;
UINT8 NEXT_STATE = 0;
UINT8 STATE_SECONDS = 0;
UINT8 STATE_SECONDS_REMAINING = 0;
UINT8 CENTI_SECOND_COUNT = 0;
UINT8 BLINK_STATE_ON_OFF_COUNTER = 0;
UINT8 NORMAL_AUDIO_STATE_ON_OFF_COUNTER = 0;
UINT8 SPECIAL_AUDIO_STATE_ON_OFF_COUNTER = 0;
GSK_DATE_TIME DATE_TIME;
GSK_DATE_TIME GPS_DATE_TIME;
UINT8 NO_OF_TIMES_GPS_FAILED = 0;
INT32 TIME_WHEN_GPS_IS_SWITCHED_ON = 0;
INT32 TIME_AT_LAST_GPS_SYNC = 0;
UINT8 *(LIGHTS[]) = {&LATA, &LATB};
INT16 SECONDS_TO_ADJUST = 0;
INT8 SECONDS_TO_ADJUST_PART = 0;

//Flags
BYTE_BITS FLAGS_0 = NULL;
#define ACTION_GPS_START FLAGS_0.bits.b0
#define ACTION_GPS_VERIFY_WAIT_TIME FLAGS_0.bits.b1
#define ACTION_GPS_READ FLAGS_0.bits.b2
#define ACTION_GPS_STOP FLAGS_0.bits.b3

BYTE_BITS FLAGS_1 = NULL;
#define ACTION_NEW_STATE FLAGS_1.bits.b0
#define FLAG_CYCLE_CHANGED FLAGS_1.bits.b1



//EEPROM Settings
#ifdef SET_EEPROM
INT8 EE_Settings[]={0x98, 0xFE, 1, 4, 1, 10, 20, 0xF6, 0xFF, 60, 40, 4, 8, 192, 8, 42, 5, 1, 128, 81, 1, 0, 5, 0xC5, 0xD5, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x2A, 0xAA, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 2, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 32, 12, 54, 14, 16, 127, -1, -1, -1, -1, 15, 127, -1, -1, -1, -1, 14, 127, -1, -1, -1, -1, 13, 127, -1, -1, -1, -1, 12, 127, -1, -1, -1, -1, 11, 127, 0, 16, 20, 16, 10, 127, -1, -1, -1, -1, 9, 127, -1, -1, -1, -1, 8, 127, -1, -1, -1, -1, 7, 127, -1, -1, -1, -1, 6, 127, -1, -1, -1, -1, 5, 127, -1, -1, -1, -1, 4, 127, -1, -1, -1, -1, 3, 127, -1, -1, -1, -1, 2, 127, -1, -1, -1, -1, 1, 127, -1, -1, -1, -1, 0, 127, -1, -1, -1, -1, 16, 127, -1, -1, -1, -1, 15, 127, -1, -1, -1, -1, 14, 127, -1, -1, -1, -1, 13, 127, -1, -1, -1, -1, 12, 127, -1, -1, -1, -1, 11, 127, -1, -1, -1, -1, 10, 127, 10, 0x24, 0x90, 0x12, 0x48, 10, 0x12, 0x48, 0x09, 0x24, 10, 0x09, 0x24, 0x24, 0x90, 3, 0x04, 0x90, 0x08, 0x00, 2, 0x14, 0x90, 0x00, 0x00, 21, 0x24, 0x24, 0x00, 0x00, 2, 0x24, 0x10, 0x00, 0x20, 2, 0x24, 0x50, 0x00, 0x00, 1, 0x00, 0x00, 0x14, 0x20, 2, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 4, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 4, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 10, 0x12, 0x48, 0x00, 0x00, 8, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 10, 0x12, 0x48, 0x00, 0x00, 3, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 3, 0x12, 0x48, 0x00, 0x00, 5, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 3, 0x12, 0x48, 0x00, 0x00, 3, 0x12, 0x48, 0x00, 0x00, 9, 0x12, 0x48, 0x00, 0x00, 9, 0x12, 0x48, 0x00, 0x00, 10, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 5, 0x12, 0x48, 0x00, 0x00, 10, 0x12, 0x48, 0x00, 0x00, 6, 0x12, 0x48, 0x00, 0x00, 4, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 4, 0x12, 0x48, 0x00, 0x00, 9, 0x12, 0x48, 0x00, 0x00, 7, 0x12, 0x48, 0x00, 0x00, 9, 0x12, 0x48, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00, };
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* PROJMAIN_H */

