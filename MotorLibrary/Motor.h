/*
  Motor.h - Library for controlling motors on the esp32
  Created by Luuk. A. Grossouw, June 21, 2025.
  Released for people with the CraneCreaterKit.
*/
#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor
{
  public:
    Motor(int PWM, int IN1, int IN2, int STBY, int CHANNEL);
    void forward(int speed = 255);
    void backward(int speed = 255);
    void brake();
  private:
    int _PWM;
    int _IN1;
    int _IN2;
    int _STBY;
    int _CHANNEL;
};

void drive_forward(Motor& left, Motor& right, int speed = 255);
void drive_backward(Motor& left, Motor& right, int speed = 255);
void turn(Motor& left, Motor& right, int direction, int speed = 255);
void brake(Motor& left, Motor& right);

#endif