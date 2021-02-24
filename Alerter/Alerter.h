#pragma once
#include <Arduino.h>
#include <Task/Task.h>


#define ALERT_TYPE_LED       0 
#define ALERT_TYPE_BEEPER    1 
#define ALERT_TYPE_ALL       2

#define ALERT_DEFAULT_CORE   0


class Alerter : public Task {
  public:
    Alerter(int core) {
      Task::setCore(core);
      pinMode (2, OUTPUT);
    };

    Alerter(int led_pin, int beeper_pin, int type, int core) ;


    
  private:
    int led_pin;
    int beeper_pin;
    int type;

};