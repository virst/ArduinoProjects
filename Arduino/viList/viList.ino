#include "v_list.h"

unsigned long time;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Serial.println("begin");
  
 vList<int> l;
 
 for(int i=0;i<17;i++)
    l.Add(i);

 for(int i=0;i<l.Length();i++)
    Serial.println(l.GetItem(i),DEC);
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
