#include <EEPROM.h>
#include <Keyboard.h>
#include "OneButton2.h"
#include "FastLED.h"

#define COUNT_COLORS 4
#define DATA_PIN 10

int status_info[COUNT_COLORS] = {3,67,3456,1199};


OneButton2 buttons1[4] =  {OneButton2(6,true) ,OneButton2(7,true) ,OneButton2(8,true) ,OneButton2(15,true)  };

int current_color = 0;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
   pinMode(9, OUTPUT); // beep pin
  intDig4();
  initRGB();
  // put your setup code here, to run once:


buttons1[2].attachClick(click1);
buttons1[0].attachClick(click2);
buttons1[3].attachClick(click3);
buttons1[1].attachClick(click4);

buttons1[2].attachDoubleClick(doubleclick1);
buttons1[0].attachDoubleClick(doubleclick2);
buttons1[3].attachDoubleClick(doubleclick3);
buttons1[1].attachDoubleClick(doubleclick4);

 SetLedColor(current_color);
 status_info[3] = getNum();
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<4;i++)
 {
   buttons1[i].tick();  
 } 

 showDisplay();
 SetNum(status_info[current_color]); 
 beep_loop();
 read_loop();
}


void click1(int p) { 
  Keyboard.print(pass());
  Keyboard.print(pass());
  
} 

void click2(int p) { 
  Keyboard.print(pass());
 
} 

void click3(int p) { 
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(50);
  Keyboard.releaseAll(); 
  delay(1000);
  click2(p);
} 

void click4(int p) { 
  current_color = (current_color + 1)%COUNT_COLORS;
  SetLedColor(current_color);
} 

void doubleclick1(int p) {
  click1(p);
 Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);
} 

void doubleclick2(int p) {
  click2(p);
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);
} 

void doubleclick3(int p) {
  click3(p);
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);
} 

void doubleclick4(int p) {
  byte nn = getNum();
  nn = (nn+1)%100;
  setNum(nn);
  current_color = 3;
  SetLedColor(current_color);
} 


