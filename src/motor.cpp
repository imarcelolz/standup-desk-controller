#include "motor.h"

Motor::Motor(byte pwm, byte in1, byte in2) {
  this->pwm = pwm;
  this->in1 = in1;
  this->in2 = in2;
  this->speed = 100;
}

bool Motor::isMoving() {
  return this->isEngineMoving;
}

void Motor::forward() {
  if(this->direction == BACKWARD) {
    this->stop();
  }

  this->setDirection(FORWARD);
  this->setIsMoving(true);
  analogWrite(this->pwm, this->speed);
}

void Motor::backward() {
  if(this->direction == FORWARD) {
    this->stop();
  }

  this->setDirection(BACKWARD);
  this->setIsMoving(true);
  analogWrite(this->pwm, this->speed);
}

void Motor::stop() {
  if(!this->isMoving()) {
    return;
  }

  this->setIsMoving(false);
  analogWrite(this->pwm, 0);
}

void Motor::setDirection(Direction direction) {
  digitalWrite(this->in1, direction == FORWARD ? HIGH : LOW);
  digitalWrite(this->in2, direction == FORWARD ? LOW : HIGH);
}

void Motor::setIsMoving(bool isMoving) {
  this->isEngineMoving = isMoving;
}
