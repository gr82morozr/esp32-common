#include <Arduino.h>
#include "utils.h"


int get_cpu_mhz() {
  return (getCpuFrequencyMhz());
}
