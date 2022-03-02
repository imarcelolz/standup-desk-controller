#include "motor.h"
#include "switch-reader.h"

#define DI_UP 2
#define DI_DOWN 3

#define IN1 8
#define IN2 7
#define ENA_PWM 9

void blink(bool fast = false);
void setupSwitches();
void led(uint8_t);
Motor motor(ENA_PWM, IN1, IN2);
SwitchReader readDIUp(DI_UP);
SwitchReader readDIDown(DI_DOWN);
bool wakeUp = false;

void setup() {
  Serial.begin(9600);
  while(!Serial) { delay(100); }

  setupSwitches();
  Serial.println("Hello Desk");
}

void loop() {
  // if(!wakeUp) {
  //   sleep(100);
  // }

  led(readDIUp.getState());
  led(readDIDown.getState());
  // delay(200);
  // wakeUp = false;
}

void testMotor(Motor* motor) {
  led(HIGH);

  motor->forward();
  delay(1000);

  motor->backward();
  delay(1000);

  motor->stop();

  led(LOW);
}

void onUpChanged() {
  readDIUp.onInterruption();

  wakeUp = true;
}

void onDownChanged() {
  readDIDown.onInterruption();
  wakeUp = true;
}

void setupSwitches() {
  pinMode(DI_UP, INPUT_PULLUP);
  pinMode(DI_DOWN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(DI_UP), onUpChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DI_DOWN), onDownChanged, CHANGE);
}

void led(uint8_t value) {
  digitalWrite(LED_BUILTIN, value);
}

void blink(bool fast = false) {
  int delayInterval = fast ? 100 : 400;

  digitalWrite(LED_BUILTIN, LOW);

  for (int i = 0; i < 10; i++) {
    byte value = i % 2 == 0 ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, value);
    delay(delayInterval);
  }

  digitalWrite(LED_BUILTIN, LOW);
}
