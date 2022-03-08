#pragma once

#include <Arduino.h>

#define EV_SIZE 4
class SwitchReader {
  volatile byte state = LOW;
  volatile int lastCall = 0;
  short digitalPort;
  short readDelay;

  public:

  SwitchReader(short digitalPort, short readDelay = 50) {
    this->digitalPort = digitalPort;
    this->readDelay = readDelay;
  }

  byte getState() { return this->state; }

  void onInterruption() {
    int now = millis();
    int callDiff = now - this->lastCall;

    this->lastCall = now;

    if(callDiff < this->readDelay) {
      return;
    }

    this->state = this->state == HIGH ? LOW : HIGH;

    // this->event();
  }

  byte previous = LOW;
  short eventIndex = 0;
  int lastEventCall = 0;
  byte eventQueue[4] = { 0, 0, 0, 0 };
  bool checking = false;

  void event() {
    if(this->state == this->previous) {
      return;
    }

    this->eventQueue[this->eventIndex++] = this->previous = this->state;
    checking = this->eventIndex % 2 == this->state;

    if(!checking) {
      this->reset();
    }

    this->printArray();

    if(this->eventIndex == 3) {
      if(checking) {
        Serial.println('Double Click');
      }
      this->reset();
    }
  }

  void printArray() {
    Serial.print("now: ");
    Serial.print(millis());
    Serial.print(" [");

    for (short i = 0; i < EV_SIZE; i++) {
      Serial.print(this->eventQueue[i]);
      if(i != 3) {
        Serial.print(",");
      }
    }

    Serial.print("] ");
    Serial.print(" eventIndex: ");
    Serial.print(eventIndex);
    Serial.print(" checking: ");
    Serial.println(checking);
    // Serial.print(" lastEventCall: ");
    // Serial.print(lastEventCall);
    // Serial.print(" previous: ");
    // Serial.println(previous);
  }

  void reset() {
    Serial.println('reset');

    checking = true;
    this->eventIndex = 0;

    for (short i = 0; i < EV_SIZE; i++) {
      this->eventQueue[i] = 0;
    }
  }
};
