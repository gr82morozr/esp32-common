#pragma once 
#include <Arduino.h>
#include <Common/Common.h>
#include <EEPROM.h>



#define EEPROM_SIZE 512  //ESP32 EEPROM_SIZE

class EEPROMKVClass {
  public:
    String get(String k);
    String read(String k);
    int put(String k, String v);
    int write(String k, String v);
    void clear();
    
  private:
    void read_all();
    StaticJsonDocument<EEPROM_SIZE> json_data;  // declare main data object 

};

static EEPROMKVClass EEPROMKV;
extern EEPROMKVClass EEPROMKV;