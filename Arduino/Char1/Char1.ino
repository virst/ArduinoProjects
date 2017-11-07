int incomingByte = 0;   // for incoming serial data
char tmpc;
String s;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);  

  byte b =  160;
  char c = b;

  Serial.println(b,DEC);
  Serial.println(c,DEC);
}

// the loop function runs over and over again forever
void loop() {

  
}


