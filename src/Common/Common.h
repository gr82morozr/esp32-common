#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

#include "Utils/eepromkv.h"
#include "freertos/FreeRTOS.h"  // Correct include path for FreeRTOS
#include "freertos/task.h"  // Required to use vTaskDelay(), xTaskCreate(), etc.

/* ===========================================================
 *
 *  Common definitions and functions for ESP32 projects
 *
 * =========================================================== */

// Define log levels
#define LOG_LEVEL_NONE 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_DEBUG 4

// Define the current log level
#ifndef CURRENT_LOG_LEVEL
#define CURRENT_LOG_LEVEL LOG_LEVEL_INFO
#endif

// Define the log level strings
#define LOG_BASE(level, levelStr, ...)                              \
  do {                                                              \
    if ((level) <= CURRENT_LOG_LEVEL)                               \
      logMessagef(__FUNCTION__, (levelStr), millis(), __VA_ARGS__); \
  } while (0)

// Define the log macros
#define LOG_ERROR(...) LOG_BASE(LOG_LEVEL_ERROR, "ERRO", __VA_ARGS__)
#define LOG_WARN(...) LOG_BASE(LOG_LEVEL_WARN, "WARN", __VA_ARGS__)
#define LOG_INFO(...) LOG_BASE(LOG_LEVEL_INFO, "INFO", __VA_ARGS__)
#define LOG_DEBUG(...) LOG_BASE(LOG_LEVEL_DEBUG, "DBUG", __VA_ARGS__)
#define LOG(...) LOG_BASE(LOG_LEVEL_INFO, "INFO", __VA_ARGS__)

// Define the log macro for errors with a function name
#define LED_BUILTIN 2
#define BUILTIN_LED LED_BUILTIN
#define _BAUD_RATE_ 115200
#define DELAY(x) vTaskDelay(pdMS_TO_TICKS(x))
#define _DELAY_(x) vTaskDelay(pdMS_TO_TICKS(x))
#define SYS_HALT while (true)

#ifdef _DEBUG_
#define PRINT(x) Serial.print(x)
#define PRINTF(x, y) Serial.print(x, y)
#define PRINTLN(x) Serial.println(x)
#define PRINTLNF(x, y) Serial.println(x, y)
#else
#define PRINT(x)
#define PRINTF(x, y)
#define PRINTLN(x)
#define PRINTLNF(x, y)
#endif

void common_init();

// Common functions
int sign(float x);
String to_str(char* data);

char* to_chars(int data);
char* to_chars(long data);
char* to_chars(double data);
char* to_chars(String data);
char* copy_chars(char* src_chars);
char* concat_chars(char* src1_chars, char* src2_chars);
char* concat_chars(char* src1_chars, char* src2_chars, char* src3_chars);
void logMessagef(const char* func, const char* levelStr, unsigned long ms,
                 const char* fmt, ...);

// Fast implementation of GPIO functions
static inline void toggleGPIO(uint8_t pin) {
  // a faster way to toggle LED
  if (pin < 32) {
    // Force set to output by setting the output enable bit (fast)
    GPIO.enable_w1ts = (1 << pin);
    // Toggle pin output
    GPIO.out ^= (1 << pin);
  } else {
    // For GPIO32–GPIO39
    GPIO.enable1_w1ts.val = (1 << (pin - 32));
    // Toggle pin output
    GPIO.out1.val ^= (1 << (pin - 32));
  }
};

static inline void writeGPIO(uint8_t pin, bool level) {
  uint8_t shift = (pin < 32) ? pin : (pin - 32);

  // Set as output
  if (pin < 32) {
    GPIO.enable_w1ts = (1UL << shift);
    if (level)
      GPIO.out_w1ts = (1UL << shift);
    else
      GPIO.out_w1tc = (1UL << shift);
  } else {
    GPIO.enable1_w1ts.val = (1UL << shift);
    if (level)
      GPIO.out1_w1ts.val = (1UL << shift);
    else
      GPIO.out1_w1tc.val = (1UL << shift);
  }
}

static inline bool readGPIO(uint8_t pin) {
  if (pin < 32) {
    return (GPIO.in >> pin) & 0x1;
  } else {
    return (GPIO.in1.val >> (pin - 32)) & 0x1;
  }
}
