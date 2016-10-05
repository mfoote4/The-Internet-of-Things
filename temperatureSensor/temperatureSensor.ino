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
      if(temperatureFeratureF >= 80)
        analogWrite(temperatureF);

      if(temperatureF > 90)
        analogWrite(temperatureF);
        
      if(temperatureFeratureF > 100)
        analogWrite(temperatureF);

      if(temperatureF > 110)
        analogWrite(temperatureF);

      if(temperatureFeratureF > 120)
        analogWrite(temperatureF);

      if(temperatureF >= 130)
        analogWrite(temperatureF);

      if(temperatureFeratureF > 140)
        analogWrite(temperatureF);

      if(temperatureF >= 150)
        analogWrite(temperatureF);

       delay(1000);
}
