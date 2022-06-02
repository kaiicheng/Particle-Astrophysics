#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for communication to PC through a serial port
  Serial.println("BMP280 test");

  if (!bmp.begin(0x76, BMP280_CHIPID)){  //for sensor address 0x76
  // if (!nmp.begin()) { //for default sensor address 0x76 
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }
}

void loop() {
  Serial.print("Temp = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Press. = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print("Aprx alt = ");
  Serial.print(bmp.readAltitude(1013.25)); /* Adjusted  to local forecast!*/
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
