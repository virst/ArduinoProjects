#define LED_R 6
#define LED_G 7

int aPin=A6;
int avalue = 0;
int pvalue = 0;

void setup(){
	//  pinMode(LED_R, OUTPUT);
	//  pinMode(LED_G, OUTPUT);
	//  Load();

	led_stp();
	//  Serial.begin(9600);
	//  Serial.println("Begin");

}



void loop()
{     
	if(millis()%1000 == 0) {
		avalue=analogRead(aPin);        
		pvalue=map(avalue,1023,500,0,100);
		pvalue=constrain(pvalue,0,120);   
		//      Serial.print("avalue=");Serial.print(avalue);  Serial.print(";pvalue=");Serial.println(pvalue);     
		delay(1);
	}

	showDisplay(pvalue);
	/*         if(pvalue<40 || pvalue > 80)
	digitalWrite(LED_R, HIGH); 
	else
	digitalWrite(LED_R, LOW); 

	if(pvalue<80)
	digitalWrite(LED_G, HIGH);
	else
	digitalWrite(LED_G, LOW); */
}

void Load()
{
	for(int i=0;i<3;i++)
	{
		digitalWrite(LED_R, HIGH);   
		digitalWrite(LED_G, LOW); 
		delay(650);                       
		digitalWrite(LED_R, LOW);   
		digitalWrite(LED_G, HIGH);  
		delay(650);
	}

	for(int i=0;i<7;i++)
	{
		digitalWrite(LED_R, HIGH);   
		digitalWrite(LED_G, LOW); 
		delay(300);                       
		digitalWrite(LED_R, LOW);   
		digitalWrite(LED_G, HIGH);  
		delay(300);
	}


	for(int i=0;i<7;i++)
	{
		digitalWrite(LED_R, HIGH);   
		digitalWrite(LED_G, LOW); 
		delay(100);                       
		digitalWrite(LED_R, LOW);   
		digitalWrite(LED_G, HIGH);  
		delay(100);
	}
}

