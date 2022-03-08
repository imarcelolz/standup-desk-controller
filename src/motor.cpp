#include "motor.h"

Motor::Motor(byte speed, uint8_t pwm_backward, uint8_t init_backward, uint8_t pwm_forward, uint8_t init_forward) {
  this->pwm_backward = pwm_backward;
  this->init_backward = init_backward;
  this->pwm_forward = pwm_forward;
  this->init_forward = init_forward;

  this->speed = speed;

  pinMode(pwm_backward, OUTPUT);
  pinMode(init_backward, OUTPUT);
  pinMode(pwm_forward, OUTPUT);
  pinMode(init_forward, OUTPUT);
}

bool Motor::isMoving() {
  return this->isEngineMoving;
}

void Motor::forward() {
  if(this->isEngineMoving) {
    analogWrite(this->pwm_backward, LOW);
    delay(10);
  }

  this->enable();
  this->setIsMoving(true);
  analogWrite(this->pwm_forward, this->speed);
}

void Motor::backward() {
  if(this->isEngineMoving) {
    analogWrite(this->pwm_forward, LOW);
    delay(10);
  }

  this->enable();
  this->setIsMoving(true);
  analogWrite(this->pwm_backward, this->speed);
}

void Motor::stop() {
  this->setIsMoving(false);

  analogWrite(this->pwm_backward, LOW);
  digitalWrite(this->init_backward, LOW);
  analogWrite(this->pwm_forward, LOW);
  digitalWrite(this->init_forward, LOW);
  delay(10);
}

void Motor::setIsMoving(bool isMoving) {
  this->isEngineMoving = isMoving;
}

void Motor::enable() {
  digitalWrite(this->init_backward, HIGH);
  digitalWrite(this->init_forward, HIGH);
}

void Motor::setSpeed(byte speed) {
  this->speed = speed;
}
