#include <Wire.h>
// #include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-C3!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
