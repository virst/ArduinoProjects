#include "OneButton2.h"

#define COUNT_BUTTONS 6
 
OneButton2 buttons1[COUNT_BUTTONS] =  {OneButton2(4,true) ,OneButton2(5,true) ,OneButton2(6,true) ,OneButton2(7,true) ,OneButton2(8,true) ,OneButton2(9,true) };


void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Starting TwoButtons...");

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
  Serial.println("Button " + String(p) + " click.");
} 

void doubleclick1(int p) {
  Serial.println("Button " + String(p) + " doubleclick.");
} 



