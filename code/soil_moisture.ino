#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

#define SOIL_MOISTURE_PIN 34  

void setup() {
  Serial.begin(115200);               
  SerialBT.begin("Soil_Moisture");   

  pinMode(SOIL_MOISTURE_PIN, INPUT);

  Serial.println("Bluetooth Started. Pair with 'ESP32_Moisture'");
  SerialBT.println("Soil Moisture Sensor Ready");
}

void loop() {
  int moisture = analogRead(SOIL_MOISTURE_PIN); 
  String status;

  if (moisture > 3000) {
    status = "Dry Soil";
  } else if (moisture > 1500) {
    status = "Moist Soil";
  } else {
    status = "Wet Soil";
  }

  SerialBT.print("Soil Moisture Value: ");
  SerialBT.print(moisture);
  SerialBT.print(" - ");
  SerialBT.println(status);
 
  Serial.print("Soil Moisture Value: ");
  Serial.print(moisture);
  Serial.print(" - ");
  Serial.println(status);

  delay(2000);
}
