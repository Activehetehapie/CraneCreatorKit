#include <Motor.h>
#include "Arduino.h"

#define AIN1 26
#define AIN2 25
#define PWMA 33
#define STBY 27
#define BIN1 14
#define BIN2 12
#define PWMB 13
#define LEFT 0
#define RIGHT 1

Motor left_motor (PWMA, AIN1, AIN2, STBY, 0);
Motor right_motor (PWMB, BIN1, BIN2, STBY, 1);

char command;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.print("Received command: ");
    Serial.println(command);
  }

  switch (command) {
    case 'w':
      drive_forward(left_motor, right_motor, 55);
      break;
    case 's':
      drive_backward(left_motor, right_motor, 150);
      break;
    case 'a':
      turn(left_motor, right_motor, LEFT, 80);
      break;
    case 'd':
      turn(left_motor, right_motor, RIGHT, 80);
      break;
    case 'b':
      brake(left_motor, right_motor);
      break;
  }
}
