#pragma once 

#include <Arduino.h>
#include <ArduinoJson.h>

#define _BAUD_RATE_         115200

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


void init();

int sign(float x);


String to_str(char * data);

char * to_chars(int data);
char * to_chars(long data);
char * to_chars(double data);
char * to_chars(String data);
char * copy_chars(char * src_chars);
char * concat_chars(char * src1_chars, char * src2_chars);
char * concat_chars(char * src1_chars, char * src2_chars, char * src3_chars);

