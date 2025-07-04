#include "Arduino.h"
#include "Motor.h"
#include <driver/ledc.h>

int clamp(int, int, int);

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

    ledcAttachChannel(_PWM, 5000, 8, _CHANNEL);
    ledcWrite(_PWM, 255);
}

void Motor::forward(int speed) {
    speed = clamp(0, 255, speed);
    digitalWrite(_STBY, HIGH);
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);
    ledcWrite(_PWM, speed);
}

void Motor::backward(int speed) {
    speed = clamp(0, 255, speed);
    digitalWrite(_STBY, HIGH);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    ledcWrite(_PWM, speed);
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
        right.backward(speed);
    }
}

void brake(Motor& left, Motor& right) {
    left.brake();
    right.brake();
}

int clamp(int lowerbound, int upperbound, int number) {
    if (number > upperbound) {
        return upperbound;
    } else if (number < lowerbound) {
        return lowerbound;
    }
    return number;
}