#include <SPI.h>
#include <SD.h>

File dataFile;

int tempSensorPin = 3;
int pressureSensorPin = 4;
int loadCellPin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Initialising SD card...");
  
  if(!SD.begin(4)){
    Serial.println("SD Card Failure");
    while(1);
  }
  Serial.println("Initialisation done");

  dataFile = SD.open("test.txt", FILE_WRITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempValue;
  int pressureValue;
  int loadCellValue;
  
  tempValue = analogRead(tempSensorPin);
  pressureValue = analogRead(pressureSensorPin);
  loadCellValue = analogRead(loadCellPin);
  
  Serial.println(tempValue);
  Serial.println(pressureSensorPin);
  Serial.println(loadCellValue);

  if(dataFile){
    dataFile.println(tempValue);
    dataFile.println(pressureSensorPin);
    dataFile.println(loadCellValue);
  }else{
    Serial.println("Error openning file on SD card");
  }
}
