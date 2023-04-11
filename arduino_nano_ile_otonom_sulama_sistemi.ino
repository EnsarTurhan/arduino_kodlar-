#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
#define Buton 4
unsigned long ilkdeger=0;
unsigned long sondeger=0;
int a=0;
int b=0;
int c=0;
void setup() {
  Serial.begin(9600);
   lcd.begin(); 
    lcd.backlight();
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT); 
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(Buton,INPUT); 

digitalWrite(7,HIGH);
digitalWrite(6,LOW);
digitalWrite(5,HIGH);    
}
void loop() {
   if(digitalRead(4)== 1)
  {
        digitalWrite(7,LOW);
      digitalWrite(5,LOW);
          digitalWrite(6,HIGH);
  }
  
 sondeger=millis();
if(sondeger-ilkdeger>=1000){
  ilkdeger=sondeger;
  a++;
  if(a==60){
  b++;
  a=0;
}
if(b==60){
  c++;
  b=0;
  }
if(c==12){
  c=0;
 digitalWrite(8,HIGH);
     digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
       digitalWrite(11,HIGH);
       delay(15000);
        digitalWrite(8,LOW);
     digitalWrite(9,LOW);
      digitalWrite(10,LOW);
       digitalWrite(11,LOW);
      }
  lcd.clear();
    Serial.print(c);
  Serial.print("--");
  Serial.print(b);
  Serial.print("--");
  Serial.println(a);
  lcd.setCursor(3,0);
     lcd.print("KRONOMETRE");
    lcd.setCursor(3,1);
     lcd.print(c);
     lcd.setCursor(5,1);
     lcd.print(":");
      lcd.setCursor(7,1);
     lcd.print(b);
     lcd.setCursor(9,1);
     lcd.print(":");
      lcd.setCursor(11,1);
     lcd.print(a);
     lcd.setCursor(5,1);
}
}
