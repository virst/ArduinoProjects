int incomingByte = 0;   // for incoming serial data
char tmpc;
String s;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  incomingByte = strlen("Hello");
  Serial.print("Len is :");
  Serial.println(incomingByte, DEC);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(50); 

    if (Serial.available() > 0) {
                s = readln();
                if(s=="Привет")
                  Serial.println("true");
                 else
                  Serial.println("false");
                 Serial.println(s);
        }
  
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

