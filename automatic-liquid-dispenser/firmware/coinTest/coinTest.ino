/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


unsigned int count;


void increaseCount() {
  count++;
}


void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),increaseCount, RISING); 
}




unsigned int i;
unsigned int pCount=0;
void loop() {
  if (pCount != count){
    Serial.println(count);
    lcd.setCursor(0,0);
    lcd.print(count);
    pCount = count;
  }
}
