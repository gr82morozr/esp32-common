#include <Arduino.h>
#include "Common.h"

void common_init() {
  if (Serial.availableForWrite() == 0) {
    Serial.begin(_BAUD_RATE_);
  }
  setCpuFrequencyMhz(240); 
}

void logMessage(const char* funcName, unsigned long timestamp, const char* msg) {
  // Format: fixed width timestamp (9 chars) + fixed width function name (10 chars)
  char line[128];
  snprintf(line, sizeof(line), "[%8lu] %-16s: %s", timestamp, funcName, msg);
  Serial.println(line);
}
void logMessagef(const char* func, const char* levelStr, unsigned long ms, const char* fmt, ...) {
    char buf[128];  // Adjust size as needed
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    Serial.printf("[%lu] [%s] [%s] %s\n", ms, levelStr, func, buf);
}



/*************************************************
 * 
 *  Common math functions
 * 
 ************************************************/
int sign(float x) {
  return ((x > 0) ? 1 : ((x < 0) ? -1 : 0));
};


String to_str(char * data) {
  return  String(data);
};

char * to_chars(int data) {
  String str_data = String(data);
  char * buf = new char[str_data.length()+1];
  str_data.toCharArray(buf, str_data.length()+1);
  return buf;
};

char * to_chars(long data) {
  String str_data = String(data);
  char * buf = new char[str_data.length()+1];
  str_data.toCharArray(buf, str_data.length()+1);
  return buf;
};


char * to_chars(double data) {
  String str_data = String(data);
  char * buf = new char[str_data.length()+1];
  str_data.toCharArray(buf, str_data.length()+1);
  return buf;
};

char * to_chars(String data) {
  char * buf = new char[data.length()+1];
  data.toCharArray(buf, data.length()+1);
  return buf;
};

char * copy_chars(char * src_chars) {
  String src_str = String(src_chars);
  char * buf = new char[src_str.length()+1];
  src_str.toCharArray(buf, src_str.length()+1);
  return buf;
};

char * concat_chars(char * src1_chars, char * src2_chars) {
  String src1_str = String(src1_chars);
  String src2_str = String(src2_chars);
  return to_chars(src1_str + src2_str);
};

char * concat_chars(char * src1_chars, char * src2_chars, char * src3_chars) {
  String src1_str = String(src1_chars);
  String src2_str = String(src2_chars);
  String src3_str = String(src3_chars);
  return to_chars(src1_str + src2_str + src3_str);
};
