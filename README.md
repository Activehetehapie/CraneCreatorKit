# Crane CreatorKit

## Overview

**English:**  
This repository is designed specifically for the Crane CreatorKit. It contains multiple libraries that help you easily build your own cool crane without dealing with all the complicated parts. These libraries are intended for the ESP32 microcontroller and may not work properly with other microcontrollers. The motor library works exclusively with the TB6612FNG motor controller.

**Nederlands:**  
Deze repository is speciaal ontwikkeld voor de Crane CreatorKit. Het bevat verschillende bibliotheken die je helpen eenvoudig je eigen gave kraan te bouwen, zonder dat je je zorgen hoeft te maken over ingewikkelde details. Deze bibliotheken zijn bedoeld voor de ESP32-microcontroller en zullen waarschijnlijk niet goed werken met andere microcontrollers. De motorbibliotheek werkt uitsluitend met de TB6612FNG-motorcontroller.

---

## Functions Documentation for the motor library/ Functiebeschrijving voor motor bibiliotheek

---

### `Motor::Motor(int PWM, int IN1, int IN2, int STBY, int CHANNEL)`

**English:**  
Create a Motor object. 

**Nederlands:**  
Maak een Motor-object aan.

---

### `void Motor::forward(int speed)`

**English:**  
Drives the motor forward at given speed.

**Nederlands:**  
Draait de motor vooruit met de opgegeven snelheid.

---

### `void Motor::backward(int speed)`

**English:**  
Drives the motor backward at given speed.

**Nederlands:**  
Draait de motor achteruit met de opgegeven snelheid.

---

### `void Motor::brake()`

**English:**  
Stops the motor immediately.

**Nederlands:**  
Stops de motor direct.

---

### `void drive_forward(Motor& left, Motor& right, int speed)`

**English:**  
Drives two motors forward.

**Nederlands:**  
Laat twee motoren vooruit rijden.

---

### `void drive_backward(Motor& left, Motor& right, int speed)`

**English:**  
Drives two motors backward.

**Nederlands:**  
Laat twee motoren achteruit rijden.

---

### `void turn(Motor& left, Motor& right, int direction, int speed)`

**English:**  
Turn by running one motor forward and the other backward.  
`direction`: 0 = left, 1 = right.

**Nederlands:**  
Draai door de ene motor vooruit en de andere achteruit te laten draaien.  
`direction`: 0 = links, 1 = rechts.

---

### `void brake(Motor& left, Motor& right)`

**English:**  
Stops both motors.

**Nederlands:**  
Stopt beide motoren.
