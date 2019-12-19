# Parking Sensor #

Project Description
-------------------

The aim of this project is to implement a park sensor using HC-SR04 ultrasonic sensor, Multifunction Shield and Arduino UNO. The program should provide distance information using the LEDs, Buzzer and 7-Segment display.


Used Components
---------------

* [Ultrasonic Sensor - HC-SR04](https://www.sparkfun.com/products/15569)


* [Arduino UNO](https://store.arduino.cc/arduino-uno-rev3)


* Multifunction Shield

Implementation Overview
-----------------------

The code is implemented using C language and AVR library.

The sensor will be triggered with 10us of trigger signal.

The program will receive an echo signal and calculate the time difference between trigger and echo signals.For this purpose timer overflows will be used to calculate time difference between trigger and and echo signals.

The distance will be calculated using following basic formula:

Distance L = Number of Overflow / 58 cm

We count the number of overflows that are 16us and divide it by 58 to get the distance in cm.

According to calculated distance value, The programm will indicate the distance on 7-Segment display, on LEDs, as well as with buzzer.

Usage
-----

The park sensor should be placed against a surface. The HC-SR04 can measure distances from 2cm up to 4 meters.
The distance will be represented on the 7-Segment display. The buzzer will indicate the distance to user with high pitch sound. 


