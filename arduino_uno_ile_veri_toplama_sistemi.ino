#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
File sdkart;
int sensor1_pin = A0;
int cikis1_degeri ;
int sensor2_pin = A1;
int cikis2_degeri ;
int sensor3_pin = A2;
int cikis3_degeri ;
int sensor4_pin = A3;
int cikis4_degeri ;
int led_pin = 3;
int led_pin1 =4;
#define DHTPIN1 8
#define DHTTYPE1 DHT11 
DHT dht1(DHTPIN1, DHTTYPE1);
 #define DHTPIN2 5
#define DHTTYPE2 DHT11 
DHT dht2(DHTPIN2, DHTTYPE2);
#define DHTPIN3 6
#define DHTTYPE3 DHT11 
DHT dht3(DHTPIN3, DHTTYPE3);
#define DHTPIN4 7
#define DHTTYPE4 DHT11 
DHT dht4(DHTPIN4, DHTTYPE4);
void setup() {
  Serial.begin(9600);
SD.begin();
  if(SD.begin()){
     Serial.println("SD kart tanındı");
     digitalWrite(led_pin, HIGH);
     digitalWrite(led_pin1, LOW);

  }
  else{
    Serial.println("SD kart bulunamadı");
    return;
  }
  dht1.begin();  
   dht2.begin(); 
    dht3.begin(); 
     dht4.begin(); 
}
void loop() {
  cikis1_degeri= analogRead(sensor1_pin);
  cikis1_degeri = map(cikis1_degeri,550,0,0,100);
   cikis2_degeri= analogRead(sensor2_pin);
  cikis2_degeri = map(cikis2_degeri,550,0,0,100);
   cikis3_degeri= analogRead(sensor3_pin);
  cikis3_degeri = map(cikis3_degeri,550,0,0,100);
   cikis4_degeri= analogRead(sensor4_pin);
  cikis4_degeri = map(cikis4_degeri,550,0,0,100);
 sdkart = SD.open("data1.txt", FILE_WRITE);
 if(sdkart){
   digitalWrite(led_pin1, HIGH);
   digitalWrite(led_pin, LOW);
  float nem1 = dht1.readHumidity(); 
  float sicaklik1 = dht1.readTemperature();  
  
 sdkart.print("T1 , ");
 sdkart.print(cikis1_degeri);
 delay(1000);
 sdkart.print("%  , ");
  sdkart.print("N1 , ");      
  sdkart.print(nem1  );
  sdkart.print("  ,  S1 , ");
  sdkart.print(sicaklik1);
  sdkart.print(" , ");
   delay(1000);
  Serial.print("T1 : ");
 Serial.print(cikis1_degeri);
 Serial.print("%  , ");
  Serial.print("N1: Yüzde ");      
  Serial.print(nem1  );
  Serial.print("  ,  S1: ");
  Serial.print(sicaklik1);
  Serial.println(" C");
   delay(1000); 
    float nem2 = dht2.readHumidity();
  float sicaklik2 = dht2.readTemperature(); 
sdkart.print("T2 , ");
 sdkart.print(cikis2_degeri);
 sdkart.print("%  , ");
  delay(1000);
 sdkart.print("N2 , ");      
  sdkart.print(nem2  );
  sdkart.print("  ,  S2 , ");
 sdkart.print(sicaklik2);
  sdkart.print(" , ");
   delay(1000);
   Serial.print("T2 : ");
 Serial.print(cikis2_degeri);
 Serial.print("%  , ");
 Serial.print("N2: Yüzde ");      
  Serial.print(nem2  );
  Serial.print("  ,  S2: ");
  Serial.print(sicaklik2);
  Serial.println(" C");
  delay(1000); 
    float nem3 = dht3.readHumidity(); 
  float sicaklik3 = dht3.readTemperature();  
 sdkart.print("T3 , ");
 sdkart.print(cikis3_degeri);
sdkart.print("%  , ");
 delay(1000);
 sdkart.print("N3 , ");      
 sdkart.print(nem3  );
  sdkart.print("  ,  S3 , ");
  sdkart.print(sicaklik3);
sdkart.print(" , ");
 delay(1000);
Serial.print("T3 : ");
 Serial.print(cikis3_degeri);
 Serial.print("%  , ");
  Serial.print("N3: Yüzde ");      
  Serial.print(nem3  );
  Serial.print("  ,  S3: ");
  Serial.print(sicaklik3);
  Serial.println(" C");
   delay(1000); 
    float nem4 = dht4.readHumidity(); 
  float sicaklik4 = dht4.readTemperature();  
 sdkart.print("T4 , ");
sdkart.print(cikis4_degeri);
 sdkart.print("%  , ");
 delay(1000);
 sdkart.print("N4 , ");      
  sdkart.print(nem4  );
  sdkart.print("  ,  S4 , ");
 sdkart.print(sicaklik4);
  sdkart.println(" ");
   delay(1000);
   Serial.print("T4 : ");
 Serial.print(cikis4_degeri);
 delay(500);
 Serial.print("%  , ");
  Serial.print("N4: Yüzde ");      
  Serial.print(nem4  );
  Serial.print("  ,  S4: ");
  Serial.print(sicaklik4);
  Serial.println(" C");
   delay(1000); 
   sdkart.close();
   delay(20000);
     delay(20000);
       delay(20000);
         delay(20000);
           delay(20000);
             delay(20000);
 }
 else {
  Serial.println("data.txt açılamadı");
  delay(1000);
 }
}
