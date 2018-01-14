int blinkIntervals[NUM_LEDS];
unsigned long nextBlink[NUM_LEDS];
CRGB leds_tmp[NUM_LEDS];
CRGB l_tmp;
unsigned long time1;


void initBlink()
{
  for(int i=0;i<NUM_LEDS;i++)
    {
      blinkIntervals[i] = 0;
      nextBlink[i] = 0;
      leds_tmp[i] = CRGB(0,0,0); 
    }

  //blinkIntervals[0] = 100;
  //leds_tmp[0] = CRGB(200,0,0);
}

void blinkTick()
{
  time1 = millis();
  for(int i=0;i<NUM_LEDS;i++)
  {
    if(blinkIntervals[i] != 0 && time1 > nextBlink[i])
    {
      l_tmp = leds[i];
      leds[i] = leds_tmp[i] ;
      leds_tmp[i] = l_tmp;
      nextBlink[i] = time1 + blinkIntervals[i] ;
    }
  }
  FastLED.show();
}

