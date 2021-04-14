#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H



#include "coins.h"




#define NUMBER_OF_CHEMICALS 32
#define NUMBER_OF_IN_OUT_PINS 5

#define MAX_MONEY_PER_LITER 70
#define MIN_CENTI_SEC_PER_LITER (5*10)
#define MAX_CENTI_SEC_PER_LITER (2*60*10)


#define COINS_PIN 2

//#define ANYBUTTON A3

#define WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS (50)
#define REMOVE_CREDIT_AFTER_x_SECONDS (10*60)
#define HIDE_PRICE_AFTER_x_SECONDS (2*60)

//#define ENABLE_SERIAL

#define MEGA_TESTBOX_HOUSE


#ifdef MEGA_TESTBOX_HOUSE

//#define BTN_PROG_MODE A4

#endif



#endif
