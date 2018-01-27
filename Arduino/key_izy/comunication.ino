int b1,b2,b3;

void read_loop()
{
  if (Serial.available() > 0) {
    b1 = Serial.read();
    b2 = Serial.read();
    b3 = Serial.read();

    if(b1 < 100)
     status_info[b1] = b2*100+b3;   
    else if(b1 == 100) 
        setNum(b3);
    else if(b1 == 101)
        setString(readln());
    else if(b1 == 200)
        Serial.println(getString() + ";" + String(getNum()));
  }
    
}

String pass()
{
  return getString()+ toString(getNum());
}

String getString()
{
  String es = "";
  byte eb;  
  int n = 0 ;
  do
  {
    eb = EEPROM.read(n++);
    if(eb!=0)
      es += (char)eb;
  }while(eb!=0);
  return es;
}

void setString(String s)
{
  int i;
  for(i=0;i<s.length();i++)
     EEPROM.write(i,(byte)s[i]);
  EEPROM.write(i,0); 
}

int getNum()
{
  return EEPROM.read(100);
}

void setNum(byte n)
{
  EEPROM.write(100,n);
  status_info[3] = n;
}

String readln()
{
  int inb = 0; 
  char inc ;
  String ret = "";
  while(Serial.available() > 0)
  {
    inb = Serial.read();
    inc = inb;    
    if(inb == 10)
       break;
    if(inb != 13)   
      ret=ret+inc;
     
   
  }  
  return ret;
}

String toString(int n)
{
  if(n<10)
    return "0" + String(n);
   return String(n);
}

