#pragma once

#include <Arduino.h>

typedef enum Direction {
  BACKWARD = 0,
  FORWARD = 1
};

class Motor {
  uint8_t pwm;
  uint8_t in1;
  uint8_t in2;

  byte speed;
  bool isEngineMoving = false;
  Direction direction;

  void setDirection(Direction direction);
  void setIsMoving(bool isMoving);

  public:

  Motor(uint8_t pwm, uint8_t IN1, uint8_t IN2);

  bool isMoving();
  void backward();
  void forward();
  void stop();
};
