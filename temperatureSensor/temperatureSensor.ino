void setup()
{
  // initialize serialization
  Serial.begin(9600);
  // make outputs
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
}
