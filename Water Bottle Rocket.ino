#include <Wire.h>  // Library for I2C communication
#include <SD.h>    // Library for SD card
#include <SPI.h>   // Library for SPI communication (required for SD card)

const int chipSelect = 10;  // Pin connected to the CS pin of SD card module

// Define your sensor's address
const int sensorAddress = 0x68;  // Example address, change it according to your sensor

File dataFile;  // File object to write data

void setup() {
  Serial.begin(9600);

  // Initialize the SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  // Create a new file on the SD card
  dataFile = SD.open("rocket_data.csv", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Error opening file!");
    return;
  }

  // Write headers to the CSV file
  dataFile.println("Time(ms),Acceleration_X(m/s^2),Acceleration_Y(m/s^2),Acceleration_Z(m/s^2)");

  // Close the file
  dataFile.close();

  // Turn on the sensor
  turnOnSensor();
}

void loop() {
  // Read sensor data
  float accelerationX = readSensorData(0x3B);  // Example register addresses for accelerometer data, change according to your sensor
  float accelerationY = readSensorData(0x3D);
  float accelerationZ = readSensorData(0x3F);

  // Open the data file in append mode
  dataFile = SD.open("rocket_data.csv", FILE_WRITE);
  if (dataFile) {
    // Write sensor data to the CSV file
    dataFile.print(millis());
    dataFile.print(",");
    dataFile.print(accelerationX);
    dataFile.print(",");
    dataFile.print(accelerationY);
    dataFile.print(",");
    dataFile.println(accelerationZ);

    // Close the file
    dataFile.close();
  } else {
    // If the file didn't open, print an error:
    Serial.println("Error opening file for writing!");
  }

  delay(1000);  // Adjust the sampling interval according to your requirements
}

void turnOnSensor() {
  // Write code to turn on the sensor, for example:
  Wire.beginTransmission(sensorAddress);
  // Send commands to configure the sensor
  // End transmission
  Wire.endTransmission();
}

float readSensorData(int regAddress) {
  // Read data from the sensor at the specified register address
  // Example code, replace with actual implementation for your sensor
  Wire.beginTransmission(sensorAddress);
  Wire.write(regAddress);  // Set the register address to read from
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(sensorAddress, 2);

  // Read the data
  int16_t rawData = Wire.read() << 8 | Wire.read();

  // Convert raw data to actual units (e.g., for accelerometer, divide by sensitivity factor)
  // Replace 1.0 with appropriate sensitivity factor
  return rawData / 1.0;
}
