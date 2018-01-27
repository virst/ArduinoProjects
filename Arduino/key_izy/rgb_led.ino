CRGB leds[1] = {CRGB(0,0,0)};
CRGB colors[COUNT_COLORS] = {CRGB(0,10,0) , CRGB(0,0,10) ,CRGB(10,0,0),CRGB(10,10,0)} ;

void initRGB()
{
    FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, 1);
   
    FastLED.show();
}

void SetLedColor(int n)
{
  leds[0] = colors[current_color];
    FastLED.show();
}

