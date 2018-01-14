String command;
int param;
String val;
long d,b,g,r;

void appInputCommand(String instr)
{
  command = instr.substring(0,3);
  param = instr.substring(3,5).toInt();
  val = instr.substring(5);

  if(command == "STR")
  {
    lcd.setCursor(0, param);
    StringToW(val,param);
    lcd.print_ascii(w_strings[param]);
  }else if(command == "RGB")
  {
     d = atol(val.c_str());

     b = d % 256; //b
     d = d / 256;
     g = d % 256; //g
     d = d / 256;
     r = d % 256; //r

    leds[param] = CRGB(r,g,b);    
   
    FastLED.show();
  }else if(command == "BLK"){
    blinkIntervals[param] = val.toInt();    
  }
}

void StringToW(String s,int n)
{
   w_strings[n] = s;
   for(int i=s.length();i<LCD_COLS;i++)
      w_strings[n] =  w_strings[n] + " ";
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
