 #include <Arduino.h>
#include "Common/Common.h"
#include "Utils/utils.h"
#include "Utils/eepromkv.h"

void setup() { 
  init();

}

void loop() {
  String value = EEPROMKV.read("time");
  Serial.println(value);
  EEPROMKV.write("time",String(value.toInt() + 1));
  delay(1000);
 
}
 
 

