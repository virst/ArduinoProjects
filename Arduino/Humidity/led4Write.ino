//задействованные контакты ардуино
#define SCLK 3
#define RCLK 4
#define DIO 5

void led_stp(){
	pinMode(RCLK, OUTPUT);
	pinMode(SCLK, OUTPUT);
	pinMode(DIO, OUTPUT);
}

// byte digitBuffer[4];

const byte dotByte = 0b01111111;

const byte digit[10] = { //маска для цифры
	0b11000000,//0
	0b11111001,//1
	0b10100100,//2
	0b10110000,//3
	0b10011001,//4
	0b10010010,//5
	0b10000010,//6
	0b11111000,//7
	0b10000000,//8
	0b10010000 //9
};
const byte chr[4] = { // маска для разряда
	0b00001000,//1
	0b00000100,//2
	0b00000010,//3
	0b00000001,//4
};

void showDisplay(int n){

	String s = String(n);
	for(;s.length()<4;)
		s = "0" + s;         

	//выполняем один проход по всем цифрам
	for(byte i = 0; i < 4; i++)
	{
		digitalWrite(RCLK, LOW); // Открываем защелку
		shiftOut(DIO,SCLK,MSBFIRST, digit[(int)String(s[i]).toFloat()]); // Отправляем байт с "числом"
		shiftOut(DIO,SCLK,MSBFIRST, chr[i]); // выбираем разряд
		digitalWrite(RCLK, HIGH); // Защелкиваем регистры (завтавляем защелку выставить состояние выводов соответственно отправленным байтам)
		delayMicroseconds(1000);
	}
}

void showDisplay(float n){

	String s = String(n);
	int nk = 4;
	int k = 0;
	if(s.indexOf(".")>-1)
	nk=5;
	for(;s.length()<nk;)
	s = "0" + s;         

	//выполняем один проход по всем цифрам
	for(byte i = 0; i < nk; i++)
	{
		digitalWrite(RCLK, LOW); // Открываем защелку
		if(s[i]=='.')
		{
			k=-1;
			shiftOut(DIO,SCLK,MSBFIRST, digit[(int)String(s[i-1]).toFloat()]&dotByte ); // Отправляем байт с "числом"
			shiftOut(DIO,SCLK,MSBFIRST, chr[i+k]); // выбираем разряд
		}
		else
		{
			shiftOut(DIO,SCLK,MSBFIRST, digit[(int)String(s[i]).toFloat()]); // Отправляем байт с "числом"
			shiftOut(DIO,SCLK,MSBFIRST, chr[i+k]); // выбираем разряд
		}
		digitalWrite(RCLK, HIGH); // Защелкиваем регистры (завтавляем защелку выставить состояние выводов соответственно отправленным байтам)
		delayMicroseconds(1000);
	}
}
