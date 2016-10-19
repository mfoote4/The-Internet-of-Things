#include <Wire.h> 
#include <math.h> 
#define dht_dpin A0
byte bGlobalErr;
byte dht_dat[5];
int BH1750address = 0x23; 
byte buff[2];

int position;
int control_put = 0;
// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int p1 = 2;
const int p2 = 3;
const int p3 = 4;
const int p4 = 5;
const int p5 = 6;
const int p6 = 7;
const int p7 = 8;
const int p8 = 9;
const int p9 = 10;
int analog_no = 5 ;// define A5 as input signal pin

void setup()
{
  InitDHT();
  Wire.begin(); 
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);
  pinMode(p9, OUTPUT);
  pinMode(analog_no, INPUT);
}


void loop()
{
  int pin_value;
  int temperature;
  int val;
  int val_old;
  int i; 
  uint16_t lightVal = 0; 
  
  pin_value = analogRead(analog_no);
   
  float voltage = pin_value * 5.0;
  voltage /= 1024;
  float temperatureC = (voltage - 0.5) * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
    Serial.print("Current temperature is ") ;
  Serial.print(temperatureF) ;
  Serial.println("F");
  Serial.print(temperatureC) ;
  Serial.println("C");

  delay(500);

  int position = (int) temperatureC % 10;
  position = map(position, 0, 10, 0, 255);

  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
  digitalWrite(p5, LOW);
  digitalWrite(p6, LOW);
  digitalWrite(p7, LOW);
  digitalWrite(p8, LOW);
  digitalWrite(p9, LOW);
  
  if (temperatureC > 40){
    digitalWrite(p1, HIGH);
    analogWrite(p2, position);
  }

  else if (temperatureC > 50){
    digitalWrite(p2, HIGH);
    analogWrite(p3, position);
  }

  else if (temperatureC > 60){
    digitalWrite(p3, HIGH);
    analogWrite(p4, position);
  }

  else if (temperatureC > 70){
    digitalWrite(p4, HIGH);
    analogWrite(p5, position);
  }

  else if (temperatureC > 80){
    digitalWrite(p5, HIGH);
    analogWrite(p6, position);
  }

  else if (temperatureC > 90){
    digitalWrite(p6, HIGH);
    analogWrite(p7, position);
  }

  else if (temperatureC > 100){
    digitalWrite(p7, HIGH);
    analogWrite(p8, position);
  }

  else if (temperatureC > 110){
    digitalWrite(p8, HIGH);
    analogWrite(p9, position);
  }

  else if (temperatureC > 120){
    digitalWrite(p9, HIGH);
  }

//Read Moisture
 val=digitalRead(3); 
 digitalWrite(13,val); 
 val_old=1023-analogRead(0);
 Serial.print("Moisture Sensor Value:");
 Serial.println(map(val_old, 0, 1023, 0, 100)); 
 delay(100);

 //Read Humidity and Temperature
 ReadDHT();
  switch (bGlobalErr){
     case 0:
 Serial.print("Current humdity = ");
 Serial.print(dht_dat[0], DEC);
 Serial.print(".");
 Serial.print(dht_dat[1], DEC);
 Serial.print("%  ");
 Serial.print("temperature = ");
 Serial.print(dht_dat[2], DEC);
 Serial.print(".");
 Serial.print(dht_dat[3], DEC);
 Serial.println("C  ");
        break;
     case 1:
        Serial.println("Error 1: DHT start condition 1 not met.");
        break;
     case 2:
        Serial.println("Error 2: DHT start condition 2 not met.");
        break;
     case 3:
        Serial.println("Error 3: DHT checksum error.");
        break;
     default:
        Serial.println("Error: Unrecognized code encountered.");
        break;
      }
  delay(800);

 
//Read Light Levels
BH1750_Init(BH1750address);  

delay(200); 

if(2==BH1750_Read(BH1750address)) 

{ 

lightVal=((buff[0]<<8)|buff[1])/1.2; 

Serial.print(lightVal,DEC);

Serial.println("[lx]"); 

} 

delay(150); 
}

void InitDHT(){
   pinMode(dht_dpin,OUTPUT);
        digitalWrite(dht_dpin,HIGH);
}

void ReadDHT(){
bGlobalErr=0;
byte dht_in;
byte i;
digitalWrite(dht_dpin,LOW);
delay(20);

digitalWrite(dht_dpin,HIGH);
delayMicroseconds(40);
pinMode(dht_dpin,INPUT);
//delayMicroseconds(40);
dht_in=digitalRead(dht_dpin);

if(dht_in){
   bGlobalErr=1;
   return;
   }
delayMicroseconds(80);
dht_in=digitalRead(dht_dpin);

if(!dht_in){
   bGlobalErr=2;
   return;
   }
delayMicroseconds(80);
for (i=0; i<5; i++)
   dht_dat[i] = read_dht_dat();
pinMode(dht_dpin,OUTPUT);
digitalWrite(dht_dpin,HIGH);
byte dht_check_sum =
       dht_dat[0]+dht_dat[1]+dht_dat[2]+dht_dat[3];
if(dht_dat[4]!= dht_check_sum)
   {bGlobalErr=3;}
};

byte read_dht_dat(){
  byte i = 0;
  byte result=0;
  for(i=0; i< 8; i++){
      while(digitalRead(dht_dpin)==LOW);
      delayMicroseconds(30);
      if (digitalRead(dht_dpin)==HIGH)
     result |=(1<<(7-i));
    while (digitalRead(dht_dpin)==HIGH);
    }
  return result;
} 

int BH1750_Read(int address)  

{ 

int i=0; 

Wire.beginTransmission(address); 

Wire.requestFrom(address, 2);  
while(Wire.available())  

{ 

buff[i] = Wire.read();  

i++; 

} 

Wire.endTransmission();  

return i; 

} 

void BH1750_Init(int address) 

{ 

Wire.beginTransmission(address);  

Wire.write(0x10); 

Wire.endTransmission(); 

}
