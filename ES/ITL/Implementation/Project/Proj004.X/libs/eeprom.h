/* 
 * File:   eeprom.h
 * Author: gadis
 *
 * Created on July 6, 2017, 11:59 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "projMain.h"
    
#define EEPROM_ADDRESS_TIME_ZONE 0
#define EEPROM_ADDRESS_DAY_LIGHT_START 2
#define EEPROM_ADDRESS_DAY_LIGHT_END 4
#define EEPROM_ADDRESS_CENTURY 6
#define EEPROM_ADDRESS_CYCLE_DELAY 7
#define EEPROM_ADDRESS_BLINK_ON_TIME 9
#define EEPROM_ADDRESS_BLINK_OFF_TIME 10
#define EEPROM_ADDRESS_BLINK_LAST_X_SECONDS 11
#define EEPROM_ADDRESS_AUDIO_NORMAL_ON_TIME 12
#define EEPROM_ADDRESS_AUDIO_NORMAL_OFF_TIME 13
#define EEPROM_ADDRESS_AUDIO_SPECIAL_ON_TIME 14
#define EEPROM_ADDRESS_AUDIO_SPECIAL_OFF_TIME 15
#define EEPROM_ADDRESS_SPECIAL_AUDIO_LAST_X_SECONDS 16
#define EEPROM_ADDRESS_GPS_SYNC_AT_START 17
#define EEPROM_ADDRESS_GPS_SYNC_EVERY_x_SECONDS 18
#define EEPROM_ADDRESS_GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME 21
#define EEPROM_ADDRESS_AUDIO_NORMAL 23
#define EEPROM_ADDRESS_AUDIO_SPECIAL 43
#define EEPROM_ADDRESS_CYCLE_TYPES 63
#define EEPROM_ADDRESS_EVENTS 80
#define EEPROM_ADDRESS_STATES 224

    
UINT8 extern CENTURY, BLINK_ON_TIME, BLINK_OFF_TIME, BLINK_LAST_X_SECONDS, AUDIO_NORMAL_ON_TIME, AUDIO_NORMAL_OFF_TIME, AUDIO_SPECIAL_ON_TIME, AUDIO_SPECIAL_OFF_TIME, SPECIAL_AUDIO_LAST_X_SECONDS, GPS_SYNC_AT_START;
INT16 extern TIME_ZONE, CYCLE_DELAY;
GSK_YEAR_DAY extern DAY_LIGHT_START, DAY_LIGHT_END;
GSK_SECOND_IN_DAY extern GPS_SYNC_EVERY_x_SECONDS, GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME;

BYTE ReadEeprom(WORD_VAL Address);
void LoadSettingsFromEeprom (void);
void LoadEventsFromEeprom (void);
void LoadStatesFromEeprom (void);
void LoadAllFromEeprom (void);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

