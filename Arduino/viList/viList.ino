#include "v_list.h"

unsigned long time;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Serial.println("begin");
  
 vList<int> l; 
 /*for(int i=0;i<17;i++)
    l.Add(i);

 l.DeleteAt(5);
 l.DeleteAt(7);

 for(int i=0;i<l.Length();i++)
    Serial.println(l.GetItem(i),DEC);


 l.EEPROM_write();*/

 l.EEPROM_read();
 for(int i=0;i<l.Length();i++)
    Serial.println(l.GetItem(i),DEC);
 
 Serial.println("end");     

}

void loop() {
  // put your main code here, to run repeatedly:

}
