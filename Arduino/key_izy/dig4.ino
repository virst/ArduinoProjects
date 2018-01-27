//задействованные контакты ардуино
#define SCLK 3
#define RCLK 4
#define DIO 5

byte digitBuffer[4];

void intDig4(){
  pinMode(RCLK, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(DIO, OUTPUT);
}

void SetNum(int n)
{
    //Заполняем массив
  digitBuffer[3] = n%10; n = n/10;
  digitBuffer[2] = n%10; n = n/10;
  digitBuffer[1] = n%10; n = n/10;
  digitBuffer[0] = n%10;
}

void showDisplay(){
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
  //выполняем один проход по всем цифрам
  for(byte i = 0; i <= 3; i++)
  {
    digitalWrite(RCLK, LOW); // Открываем защелку
      shiftOut(DIO,SCLK,MSBFIRST, digit[digitBuffer[i]]); // Отправляем байт с "числом"
      shiftOut(DIO,SCLK,MSBFIRST, chr[i]); // выбираем разряд
    digitalWrite(RCLK, HIGH); // Защелкиваем регистры (завтавляем защелку выставить состояние выводов соответственно отправленным байтам)
    delayMicroseconds(2500);  // 1000
  }
}
