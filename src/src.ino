#include "LowPower.h"
#include "switch-reader.h"
#include "motor.h"

#define DI_UP 2
#define DI_DOWN 3
#define MOTOR_START_UP 5
#define MOTOR_START_DOWN 7
#define MOTOR_UP 9
#define MOTOR_DOWN 10

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

SwitchReader readDIUp(DI_UP);
SwitchReader readDIDown(DI_DOWN);
Motor *motor;
short sleepAfter = 5000;
int lastInterruption = 0;

void onUpChanged() {
  readDIUp.onInterruption();
  lastInterruption = millis();
}

void onDownChanged() {
  readDIDown.onInterruption();
  lastInterruption = millis();
}

void setup() {
  Serial.begin(9600);
  while(!Serial) { delay(100); }

  Serial.println("Hello Desk");

  motor = new Motor(170, MOTOR_DOWN, MOTOR_START_DOWN, MOTOR_UP, MOTOR_START_UP);

  pinMode(DI_UP, INPUT_PULLUP);
  pinMode(DI_DOWN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(DI_UP), onUpChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DI_DOWN), onDownChanged, CHANGE);
}

void loop() {
  if (readDIUp.getState() == HIGH) {
    motor->forward();
  }
  else if (readDIDown.getState() == HIGH) {
    motor->backward();
  } else {
    motor->stop();
  }

  int now = millis();
  if (now - lastInterruption < sleepAfter) {
    return;
  }

  Serial.println("Going to bed, bye!");
  blink(true);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}
