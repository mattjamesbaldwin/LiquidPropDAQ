int tempSensorPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadResolution(16);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempValue;
  
  tempValue = analogRead(tempSensorPin);

  
  Serial.println(tempValue);

}
