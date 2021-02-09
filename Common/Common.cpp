#include <Arduino.h>
#include <Common/Common.h>

/*************************************************
 * 
 *  Common math functions
 * 
 ************************************************/
int sign(float x) {
  return ((x > 0) ? 1 : ((x < 0) ? -1 : 0));
};
