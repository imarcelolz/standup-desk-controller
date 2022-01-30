// // #include <L298N.h>

// #define UP 1 // Up direction
// #define DOWN 0 // Downdirection
// // Digital ports for interruption
// #define DI_UP 2
// #define DI_DOWN 3

// #define ENGINE_IN1 7
// #define ENGINE_IN2 8
// #define ENGINE_PWM_PORT 9

// // L298N motor(ENGINE_PWM_PORT, ENGINE_IN1, ENGINE_IN2);

// void setup() {
//   Serial.begin(9600);
//   while (!Serial){}

//   // pinMode(DI_UP, INPUT);
//   // pinMode(DI_DOWN, INPUT);
//   // pinMode(LED_BUILTIN, OUTPUT);
//   // motor.setSpeed(150); // min 30, max 256
//   attachInterrupt(digitalPinToInterrupt(DI_UP), onUpChange, CHANGE);
//   // attachInterrupt(digitalPinToInterrupt(DI_DOWN), onDownChange, CHANGE);
// }

// void loop() {
//   code();
//   // digitalWrite(LED_BUILTIN, upState ? HIGH : LOW);
// }

// bool upState = false;
// bool downState = false;

// void onUpChange() {
//   downState = false;
//   upState = !upState;

//   Serial.print("onUpChange ");
//   Serial.println(upState);
//   // digitalWrite(LED_BUILTIN, upState ? HIGH : LOW);
// }

// void onDownChange() {
//   upState = false;
//   downState = !downState;
// }

// void code() {
//   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//   delay(100);                       // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//   delay(100);
// //  if(!up && !down) {
// ////    if(motor.isMoving()) {
// ////      motor.stop();
// ////    }
// //    stop();
// //    digitalWrite(LED_BUILTIN, LOW);
// //    return;
// //  }
// //
// // if (up) {
// //   digitalWrite(LED_BUILTIN, HIGH);
// ////   if(!motor.isMoving()){
// ////    motor.forward();
// ////   }
// //   forward();
// //   return;
// // }
// //
// //  if (down) {
// //    digitalWrite(LED_BUILTIN, HIGH);
// ////    if(!motor.isMoving()) {
// ////      motor.backward();
// ////    }
// //    backward();
// //    return;
// //  }
// }

// void stop() {
//   analogWrite(ENGINE_PWM_PORT, 0);
// }

// void forward() {
//   digitalWrite(ENGINE_IN1, LOW);
//   digitalWrite(ENGINE_IN2, HIGH);
//   analogWrite(ENGINE_PWM_PORT, 100);
// }

// void backward() {
//   digitalWrite(ENGINE_IN1, HIGH);
//   digitalWrite(ENGINE_IN2, LOW);
//   analogWrite(ENGINE_PWM_PORT, 100);
// }

// void blink() {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(100);
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(100);
// }
