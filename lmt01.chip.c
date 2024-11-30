
// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 Tando Mahlati

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const uint32_t interval = 1; // MicroSeconds

typedef struct {
  // TODO: Put your chip variables here
  pin_t pin_out;
  float inVoltage; 
  float T_temp;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  // TODO: Initialize the chip, set up IO pins, create timers, etc.
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_out = pin_init("OUT", ANALOG);
  printf("Hello from custom chip!\n");

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, interval, true);
}

void chip_timer_event(void *user_data){
    chip_state_t *chip = (chip_state_t*)user_data;
    float voltage = 3.3;
    pin_dac_wite(chip->pin_out, voltage);
}
