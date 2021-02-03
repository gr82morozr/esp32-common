#pragma once
#include <Arduino.h>

#define _BAUD_RATE  115200
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


// _DEBUG_