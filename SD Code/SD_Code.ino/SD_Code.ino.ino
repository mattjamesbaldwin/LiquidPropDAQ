#include <SPI.h>
#include <SD.h>

File dataFile;

//Sensor Pins
int tempSensorPin = 3;
int pressureSensorPin = 4;
int loadCellPin = 5;

void setup() {
  
  Serial.begin(9600);
  Serial.println("Initialising SD card...");

  //Check if SD connected succesfully
  if(!SD.begin(4)){
    Serial.println("SD Card Failure");
    while(1);
  }
  Serial.println("Initialisation done");

  //Open pre-made file on SD card called "test.txt"
  dataFile = SD.open("test.txt", FILE_WRITE);
}

void loop() {

  //Initialise sensor values
  int tempValue;
  int pressureValue;
  int loadCellValue;

  //Read sensors
  tempValue = analogRead(tempSensorPin);
  pressureValue = analogRead(pressureSensorPin);
  loadCellValue = analogRead(loadCellPin);

  //Print the values to serial for testing
  Serial.println(tempValue);
  Serial.println(pressureSensorPin);
  Serial.println(loadCellValue);

  //If the data file exists, print the sensor values to it; otherwise print error
  //Need to change, 1 file per sensor
  if(dataFile){
    dataFile.println(tempValue);
    dataFile.println(pressureSensorPin);
    dataFile.println(loadCellValue);
  }else{
    Serial.println("Error openning file on SD card");
  }
}
