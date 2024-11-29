#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define I2C_SDA 18
#define I2C_SCL 19

// Create the LCD object 
Adafruit_LiquidCrystal lcd(0x20);

// --- Add RTOS tasks parameter declaration --- //
void lcdTask(void *pvParameters);
// --- End of RTOS tasks parameter declaration --- //

// --- RTOS handler --- //
TaskHandle_t lcdTaskHandle;
// --- End RTOS handler --- //


void setup() {
  // put your setup code here, to run once:
  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.begin(16,2);

  // create lcd task.
  xTaskCreate(lcdTask, "lcdTask", 1024, NULL, 1, &lcdTaskHandle);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// --- RTOS tasks start --- //
void lcdTask(void *pvParameters){
  while(true){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hello world");

  }
}
// --- End RTOS tasks start --- //