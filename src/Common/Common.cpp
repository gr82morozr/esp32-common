#include <Arduino.h>
#include <Common/Common.h>

void init() {
  Serial.begin(_BAUD_RATE_);
  
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
