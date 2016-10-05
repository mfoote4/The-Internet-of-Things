int sensorPin = A0;
const int p1 = 1;
const int p2 = 2;
const int p3 = 3;
const int p4 = 4;
const int p5 = 5;
const int p6 = 6;
const int p7 = 7;
const int p8 = 8;
void setup()
{
  Serial.begin(9600); 
    Serial.begin(9600);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);

  pinMode(p1, HIGH);
  pinMode(p2, HIGH);
  pinMode(p3, HIGH);
  pinMode(p4, HIGH);
  pinMode(p5, HIGH);
  pinMode(p6, HIGH);
  pinMode(p7, HIGH);
  pinMode(p8, HIGH);
}
 
void loop()                  
{

 int temperatureF = analogRead(sensorPin);  
 
 float voltage = temperatureF * 5.0;
 voltage /= 1024.0; 
 
 float temperatureFeratureC = (voltage - 0.5) * 100 ; 

 float temperatureFeratureF = (temperatureFeratureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureFeratureF); Serial.println(" degrees F");

  while(Serial.available() > 0) {
    if(Serial.read() == '\n'){
      if(temperatureFeratureF > 80) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p2, LOW);}

      if(temperatureF >= 90) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p3, LOW);}

      if(temperatureF > 100) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p4, LOW);}

      if(temperatureF > 110) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p5, LOW);}

      if(temperatureF > 120) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p6, LOW);}

      if(temperatureF > 130) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p7, LOW);}

      if(temperatureF > 140) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p7, LOW);}

      if(temperatureF >= 150) {digitalWrite(p1, HIGH);}
      else {digitalWrite(p8, LOW);}

       delay(1000);
}
