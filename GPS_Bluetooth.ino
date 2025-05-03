/*
Electronics Studio
@file GPS_Bluetooth.ino
@date  23-04-2025
@url https:https: https://github.com/electronicsstudio
@url YouTube: https://www.youtube.com/@ElectronicsStudio-v7o/featured
*/

#include <TinyGPS++.h>
#include <BluetoothSerial.h>
#include <HardwareSerial.h>

#define GPS_RX 16  // GPIO16: connect to TX of GPS
#define GPS_TX 17  // GPIO17: connect to RX of GPS
#define GPS_BAUD 9600  // Most GPS modules use 9600 baud rate

BluetoothSerial SerialBT;
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);  // Use UART2

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_GPS");  // Bluetooth name

  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
  Serial.println("ESP32 Bluetooth GPS started");
  SerialBT.println("Bluetooth GPS is ready...");
}

void loop() {
  // Read and feed data to GPS parser
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  // If GPS has a valid location, print and send it
  if (gps.location.isValid()) {
    double lat = gps.location.lat();
    double lng = gps.location.lng();

    Serial.print("Latitude: ");
    Serial.print(lat, 6);
    Serial.print(" | Longitude: ");
    Serial.println(lng, 6);

    SerialBT.print("Latitude: ");
    SerialBT.print(lat, 6);
    SerialBT.print(" | Longitude: ");
    SerialBT.println(lng, 6);
  } else {
    Serial.println("GPS not Fixed");
    SerialBT.println("GPS not Fixed");
  }

  delay(1000);  // Adjust delay as needed
}

