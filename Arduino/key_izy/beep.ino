void beep(int l)
{
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(l);                       // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
}

void beep(int l,int k)
{
  for(int i=0;i<k;i++)
    {beep(l);
    delay(l);  
    }
}

unsigned long beep_period = 30*1000;
unsigned long next_beep = 0;
int last_count = -1;

void beep_loop()
{
  if(next_beep < millis() || status_info[0] != last_count)
  {
    beep(100,status_info[0]);
    next_beep = millis() + beep_period;
    last_count = status_info[0];
  }
}

