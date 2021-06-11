#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H



#include "coins.h"


// The following settings are configured by the app
#ifndef PROGRAM_FROM_APP
#define NUMBER_OF_CHEMICALS 8
#define MAX_MONEY_PER_LITER 100
#define HIDE_PRICE_AFTER_x_SECONDS (10)
#define REMOVE_CREDIT_AFTER_x_SECONDS (10*60)
#define PROGRAM_SUMMARY
#define PROGRAM_SD
#define IS_SMD_MICRO
//#define USE_EASY_BUTTON_FOR_COIN
#define RESET_LCD_AFTER_x_MINUTES 60
#define RESET_SYSTEM_AFTER_x_MINUTES (1*24*60)
#endif

#ifdef PROGRAM_SD
#define CS_PIN_FOR_SD 10
#endif



#define NUMBER_OF_IN_OUT_PINS 5

#define MIN_CENTI_SEC_PER_LITER (5*10)
#define MAX_CENTI_SEC_PER_LITER (10*60*10)


#define MAX_LITERS_COUNTER (100*1000)
#define MAX_SALES_AMOUNT (1000*1000)
#define MAX_TOTAL_SALES_FACTOR 100


#define COINS_PIN 2



#define WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS (50)
//#define DEBOUNCE_x_MILLI_SECONDS_FOR_COIN (10)



#endif
