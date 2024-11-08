#include <Arduino.h>
#include "eepromkv.h"

void EEPROMKVClass::read_all() {
  EEPROM.begin(EEPROM_SIZE);
  String data_str = ""; unsigned int i; unsigned char byte;
  for (i = 0; i < EEPROM_SIZE; i++) {
    byte = EEPROM.read(i);
    if (byte == '\0') {
      break;
    } else {
      data_str += char(byte);
    }
  }

  DeserializationError error = deserializeJson(json_data, data_str);
  if (error) {
    deserializeJson(json_data, "{}");
  }
  EEPROM.end();
  
}


void EEPROMKVClass::clear() {
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < EEPROM_SIZE; i++) EEPROM.write(i, '\0');
  EEPROM.commit();
  EEPROM.end();
}


String EEPROMKVClass::get(String k) {
  return (EEPROMKVClass::read(k));
}


String EEPROMKVClass::read(String k) {
  EEPROMKVClass::read_all();
  String value = json_data[k];
  return (value);
}

int EEPROMKVClass::put(String k, String v) {
  return EEPROMKVClass::write(k, v);
}

int EEPROMKVClass::write(String k, String v) {
  String data_str;
  int return_val = 1;
  EEPROMKVClass::read_all();
  EEPROM.begin(EEPROM_SIZE);
  json_data[k] = v;
  serializeJson(json_data,data_str);
  
  if (data_str.length() < EEPROM_SIZE-1) {
    for (int i = 0; i < data_str.length(); i++) {
      EEPROM.write(i, data_str.charAt(i));
    }
    EEPROM.write(data_str.length(), '\0');
    EEPROM.commit();
  } else {
    Serial.println("ERROR: Not enough space of EEPROM. (" + String(EEPROM_SIZE) + ")");
    return_val = 0;
  }
 
  EEPROM.end();
  return return_val;
}
