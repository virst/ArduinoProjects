#include "v_split.h"
#include "vStringList.h"

unsigned long time;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Serial.println("begin");
  time = millis();
  vStringList lst = vStringList();
  for(int i=0;i<30;i++)
     lst.Add("123077007070");

  /*for(int i=0;i<30;i++)
    Serial.println(lst.GetItem(i));*/

  time = millis() - time;
  Serial.print("Need time is ");
  Serial.println(time,DEC);
 
  Serial.println("end");

}

void loop() {
  // put your main code here, to run repeatedly:

}
