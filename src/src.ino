#include "motor.h"
#include "switch-reader.h"

#define DI_UP 2
#define DI_DOWN 3

#define IN1 8
#define IN2 7
#define ENA_PWM 9

#define IN3 5
#define IN4 4
#define ENB_PWM 6

void blink(bool fast = false);

Motor motorA(ENA_PWM, IN1, IN2);
Motor motorB(ENB_PWM, IN3, IN4);

SwitchReader readDIUp(DI_UP);
SwitchReader readDIDown(DI_DOWN);

void setup() {
  Serial.begin(9600);
  while(!Serial) { delay(100); }

  setupMotorSwitch();
  Serial.println("Hello Desk");
}

byte upState = LOW;
byte downState = LOW;

int print = 0;
void loop() {
  // onUpChange();

  // print++;
  // Serial.print(digitalRead(DI_UP));
  // if (print == 100) {
  //   Serial.println('');
  //   print = 0;
  //

  led(upState == 0 ? HIGH : LOW);

  delay(200);

  // if (state == HIGH) {
  //   blink(true);
  // }


  // led(HIGH);
  // motorA.forward();
  // motorB.forward();

  // delay(1000);
  // Serial.println("testing motor a");
  // testMotor(&motorA);

  // Serial.println("testing motor b");
  // testMotor(&motorB);

}

void testMotor(Motor* motor) {
  led(HIGH);

  motor->forward();
  delay(1000);

  motor->backward();
  delay(1000);

  motor->stop();

  led(LOW);

  delay(100 * 1000);
}

void onUpChanged() {
  upState = readDIUp.read();
}

void onDownChanged() {
  downState = readDIDown.read();
}

void setupMotorSwitch() {
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
