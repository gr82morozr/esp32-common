#pragma once 
#include <Arduino.h>
#include <Common/Common.h>
#include <EEPROM.h>

#define EEPROM_SIZE 4096

class EEPROMKVClass {
  public:
    void read_all();
    String read(String k);
    int write(String k, String v);
    void clear();
    
  private:
    StaticJsonDocument<EEPROM_SIZE> json_data;  // declare main data object 


};


static EEPROMKVClass EEPROMKV;
extern EEPROMKVClass EEPROMKV;