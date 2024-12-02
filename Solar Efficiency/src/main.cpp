include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define I2C_SDA 18
#define I2C_SCL 19

// --- Buttons: counted from the left --- ///
#define Button1 4
#define Button2 5
#define Button3 6
#define Button4 7
#define Button5 8
// --- End Buttons --- //

// Create the LCD object 
LiquidCrystal_I2C lcd2(0x27, 16, 2);

// --- Add RTOS tasks parameter declaration --- //
void lcdTask(void *pvParameters);
// --- End of RTOS tasks parameter declaration --- //

// --- RTOS handler --- //
TaskHandle_t lcdTaskHandle;
// --- End RTOS handler --- //

// --- Variables --- //
typedef enum State {
  TIME_REST,
  CALIBRATION,
  DESPLAY_REVOLVE,
  ENVIRONMENT_MEASURE,
  PV_MEASURE,
  RTC_SET
} state_t;

typedef struct EnvironmentMeasurementType{
  
} enMeas_t;

typedef struct PVMeasureType{

} pvMeas_t;

typedef struct DisplayDataType{

} dispData_t;
// --- End variable --- //

void setup() {

  // --- LCD initialisation --- //
  lcd2.init();
  lcd2.backlight();
  lcd2.println("LCD active.");
  // --- End LCD initialisation --- //
  
  // --- Button setup --- //
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);
  pinMode(Button5, INPUT_PULLUP);
  // --- End button setup --- //


  // --- Create RTOS tasks --- //
  xTaskCreate(lcdTask, "lcdTask", 1024, NULL, 1, &lcdTaskHandle);
  // --- End create RTOS tasks --- //
}

void loop() {
  // put your main code here, to run repeatedly:
}

// --- RTOS tasks start --- //
void lcdTask(void *pvParameters){
  while(true){
    
    lcd2.setCursor(0,0);
    lcd2.print("Hello world");
    vTaskDelay(pdMS_TO_TICKS(1000)); // 1-second delay
  }
}
// --- End RTOS tasks start --- //