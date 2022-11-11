#ifndef USER_SETTINGS_H
#define USER_SETTINGS_H

// Add user project specfic settings here


// Default setttings are for Raspberry Pi Pico RP2040
#define USER_LED_PIN 25

// External PDM Microphone pins - Raspberry Pi Pico RP2040: data 2, clk 3; Seeed XIAO RP2040: data 4, clk 3; Arduino RP2040 Connect: data 22, clk 23
#define PDM_DATA_PIN 2
#define PDM_CLK_PIN 3

#define LABEL_DETECT_THRESHHOLD 0.50F
#endif
