#pragma once

#include <Arduino.h>


class Motor {
  uint8_t pwm_backward;
  uint8_t init_backward;

  uint8_t pwm_forward;
  uint8_t init_forward;

  byte speed;
  bool isEngineMoving = false;

  void setIsMoving(bool isMoving);
  void enable();

  public:

  Motor(byte speed, uint8_t pwm_backward, uint8_t init_backward, uint8_t pwm_forward, uint8_t init_forward);

  bool isMoving();
  void backward();
  void forward();
  void stop();
  void setSpeed(byte speed);
};
