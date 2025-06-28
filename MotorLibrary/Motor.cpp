#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int PWM, int IN1, int IN2, int STBY, int CHANNEL) {
    _PWM = PWM;
    _IN1 = IN1;
    _IN2 = IN2;
    _STBY = STBY;
    _CHANNEL = CHANNEL;

    pinMode(_PWM, OUTPUT);
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);
    pinMode(_STBY, OUTPUT);
    ledcSetup(_CHANNEL, 5000, 8);
    ledcAttachPin(_PWM, _CHANNEL);
    ledcWrite(_CHANNEL, 255);
}

void Motor::forward(int speed) {
    if (speed > 255) {
        speed = 255;
    } else if (speed < 0) {
        speed = 0;
    }
    digitalWrite(_STBY, HIGH);
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);
    ledcWrite(_CHANNEL, speed);
}

void Motor::backward(int speed) {
    if (speed > 255) {
        speed = 255;
    } else if (speed < 0) {
        speed = 0;
    }
    digitalWrite(_STBY, HIGH);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    ledcWrite(_CHANNEL, speed);
}

void Motor::brake() {
    digitalWrite(_STBY, LOW);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW);
}

void drive_forward(Motor& left, Motor& right, int speed) {
    left.forward(speed);
    right.forward(speed);
}

void drive_backward(Motor& left, Motor& right, int speed) {
    left.backward(speed);
    right.backward(speed);
}

void turn(Motor& left, Motor& right, int direction, int speed) {
    if (direction) {
        left.backward(speed);
        right.forward(speed);
    } else {
        left.forward(speed);
        right.forward(speed);
    }
}

void brake(Motor& left, Motor& right) {
    left.brake();
    right.brake();
}