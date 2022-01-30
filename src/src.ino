#include "motor.h"

#define DI_UP 2
#define DI_DOWN 3

#define MOTOR_IN1 7
#define MOTOR_IN2 8
#define MOTOR_PWM_PORT 9

Motor motor(MOTOR_PWM_PORT, MOTOR_IN1, MOTOR_IN2);

volatile byte upState = LOW;
volatile byte downState = LOW;

void onUpChange () { upState = !upState; }
void onUpRaising () { upState = HIGH; }
void onUpFalling () { upState = LOW; }
void onDownChange () { downState = !downState; }

void setup() {
  Serial.begin(9600);
  while(!Serial) { delay(100); }

  pinMode(DI_UP, INPUT_PULLUP);
  pinMode(DI_DOWN, INPUT_PULLUP);

  // attachInterrupt(digitalPinToInterrupt(DI_UP), onUpChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DI_UP), onUpRaising, RISING);
  attachInterrupt(digitalPinToInterrupt(DI_UP), onUpFalling, FALLING);
  // attachInterrupt(digitalPinToInterrupt(DI_DOWN), onDownChange, CHANGE);

  Serial.println("Hello Desk");
}

void loop() {
  if (!upState && !downState) {
    // motor.stop();
    led(LOW);
    return;
  }

  if(upState) {
    led(HIGH);
    // motor.forward();
  }

  // if(downState) {
  //   led(HIGH);
  //   // motor.backward();
  // }

   delay(10);
}

void led(uint8_t value) {
  digitalWrite(LED_BUILTIN, value);
}
