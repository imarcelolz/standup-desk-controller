#include <Arduino.h>

typedef enum Direction {
  BACKWARD = 0,
  FORWARD = 1
};

class Motor {
  Motor(byte pwm, byte IN1, byte IN2);

  bool isMoving();
  void backward();
  void forward();
  void stop();

  private:
  void setDirection(Direction direction);
  void setIsMoving(bool isMoving);

  byte pwm;
  byte in1;
  byte in2;

  byte speed;
  bool isEngineMoving = false;
  Direction direction;
};
