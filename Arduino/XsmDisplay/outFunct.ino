void click1(int p) {
  Serial.println("CLK" + ToString(p) + "click1" );
} 

void doubleclick1(int p) {
  Serial.println("DBC" + ToString(p) + "doubleclick1" );
} 

String ToString(int n)
{
  String s = String(n);
  if(n<10)
    return "0" + s;
  return s;
}

