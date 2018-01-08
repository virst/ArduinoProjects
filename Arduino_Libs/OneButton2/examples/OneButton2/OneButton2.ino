#include "OneButton2.h"

#define COUNT_BUTTONS 6 
OneButton2 buttons1[COUNT_BUTTONS] =  {OneButton2(4,true) ,OneButton2(5,true) ,OneButton2(6,true) ,OneButton2(7,true) ,OneButton2(8,true) ,OneButton2(9,true) };

#include <LCD_1602_RUS.h>
LCD_1602_RUS lcd(0x27, 20, 4);

void setup() {
  
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Starting TwoButtons");

 for(int i=0;i<COUNT_BUTTONS;i++)
 {
   buttons1[i].attachClick(click1);
   buttons1[i].attachDoubleClick(doubleclick1);
 } 
 
} 

void loop() {

  for(int i=0;i<COUNT_BUTTONS;i++)
 {
   buttons1[i].tick();  
 } 
 
  delay(10);
} 

void click1(int p) {
  lcd.setCursor(0, 1);
  lcd.print(String(p) + " click.      ");
} 

void doubleclick1(int p) {
  lcd.setCursor(0, 1);
  lcd.print(String(p) + " doubleclick.");
} 



