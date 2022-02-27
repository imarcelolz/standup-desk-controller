#pragma once

#include <Arduino.h>

class SwitchReader {
  private:

  byte state = LOW;
  int lastCall = 0;
  short digitalPort;
  short readDelay;

  public:

  SwitchReader(short digitalPort, short readDelay = 2) {
    this->digitalPort = digitalPort;
    this->readDelay = readDelay;
  }

  byte read() {
    int callDiff = millis() - this->lastCall;
    this->lastCall = millis();

    if(callDiff < this->readDelay) {
      return this->state;
    }

    int newState = digitalRead(this->digitalPort);
    if(state == newState) {
      delay(this->readDelay);
      this->state = digitalRead(this->digitalPort);
    }

    return this->state;
  }
};
