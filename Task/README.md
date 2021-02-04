## Task Wrapper Abstract Class

Implement a multi-task framework to to allow any operations wrapped into a task (FreeRTOS), runs on specified CPU core at background.


 ```
 class MyClass : public Task {
  public:
    MyClass(int core) {
      Task::setCore(core);  // set CPU core to run the task
      pinMode (2, OUTPUT);
    };

    void run(void *data) {
      while (1) {            // always in infinite loop
        digitalWrite(2,HIGH);
        delay(300);
        digitalWrite(2,LOW);
        delay(100);
      };
    };
};

MyClass m1 = MyClass(0);      // Declare


void setup() {
  m1.start(nullptr);          // kick off the task
};


 ```
