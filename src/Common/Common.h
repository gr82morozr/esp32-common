#pragma once 

#include <Arduino.h>
#include <ArduinoJson.h>
#include "freertos/FreeRTOS.h"  // Correct include path for FreeRTOS
#include "freertos/task.h"      // Required to use vTaskDelay(), xTaskCreate(), etc.
#include "Utils/eepromkv.h"

#define _BAUD_RATE_         115200
#define DELAY(x)            vTaskDelay(pdMS_TO_TICKS(x))
#define _DELAY_(x)          vTaskDelay(pdMS_TO_TICKS(x))
#define SYS_HALT            while(true)
#ifdef _DEBUG_
    #define PRINT(x)        Serial.print(x)
    #define PRINTF(x, y)    Serial.print(x, y)
    #define PRINTLN(x)      Serial.println(x)
    #define PRINTLNF(x, y)  Serial.println(x, y)
#else
    #define PRINT(x)
    #define PRINTF(x, y)
    #define PRINTLN(x)
    #define PRINTLNF(x, y)
#endif 


void common_init();

int sign(float x);


String to_str(char * data);

char * to_chars(int data);
char * to_chars(long data);
char * to_chars(double data);
char * to_chars(String data);
char * copy_chars(char * src_chars);
char * concat_chars(char * src1_chars, char * src2_chars);
char * concat_chars(char * src1_chars, char * src2_chars, char * src3_chars);




// Fast implementation of GPIO functions
static inline void toggleGPIO(uint8_t pin) {
  // a faster way to toggle LED
  if (pin < 32) {
    GPIO.out ^= (1 << pin);
  } else {
    GPIO.out1.val ^= (1 << (pin - 32));
  }
};

static inline void writeGPIO(uint8_t pin, bool level) {
  if (pin < 32) {
    if (level) {
      GPIO.out_w1ts = (1UL << pin);  // Set pin
    } else {
      GPIO.out_w1tc = (1UL << pin);  // Clear pin
    }
  } else {
    uint8_t shift = pin - 32;
    if (level) {
      GPIO.out1_w1ts.val = (1UL << shift);  // Set pin
    } else {
      GPIO.out1_w1tc.val = (1UL << shift);  // Clear pin
    }
  }
}

static inline bool readGPIO(uint8_t pin) {
  if (pin < 32) {
    return (GPIO.in >> pin) & 0x1;
  } else {
    return (GPIO.in1.val >> (pin - 32)) & 0x1;
  }
}
