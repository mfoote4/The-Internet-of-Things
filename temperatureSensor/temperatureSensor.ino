int sensorPin = A0;
void setup()
{
  Serial.begin(9600); 
}
 
void loop()                  
{

 int temp = analogRead(sensorPin);  
 
 float voltage = temp * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ; 

 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 
 delay(1000);                                    
}
