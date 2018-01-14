#include "OneButton2.h"
#include <LCD_1602_RUS.h>
#include "FastLED.h"

#define COUNT_BUTTONS 6 
#define LCD_ROWS 4
#define LCD_COLS 20  
#define NUM_LEDS 4
#define DATA_PIN 10

CRGB leds[NUM_LEDS];

OneButton2 buttons1[COUNT_BUTTONS] =  {OneButton2(4,true) ,OneButton2(5,true) ,OneButton2(6,true) ,OneButton2(7,true) ,OneButton2(8,true) ,OneButton2(9,true) };

LCD_1602_RUS lcd(0x27, LCD_COLS, LCD_ROWS);
String w_strings[LCD_ROWS];

void setup() {
  lcd.init();
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Starting XsmDisplay");
  lcd.setCursor(1, 1);
  lcd.print("Loading");
  lcd.setCursor(1, 2);
  for(int i=0;i<18;i++)
  {
    lcd.print(".");
    delay(312);
  } 

 for(int i=0;i<COUNT_BUTTONS;i++)
 {
   buttons1[i].attachClick(click1);
   buttons1[i].attachDoubleClick(doubleclick1);
 } 

 initBlink();

 for(int i=0;i<NUM_LEDS;i++)
  leds[i] = CRGB(0,0,0);    
 FastLED.show();


}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<COUNT_BUTTONS;i++)
 {
   buttons1[i].tick();  
 } 

 if(Serial.available() > 0)
 {
    appInputCommand(readln()); 
    lcd.backlight();
 }   

 blinkTick();
  delay(10);
}
