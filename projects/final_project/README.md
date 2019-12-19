# Parking Sensor #

Project Description
-------------------

The aim of this project is to implement a park sensor using HC-SR04 ultrasonic sensor, Multifunction Shield and Arduino UNO. The program should provide distance information using the LEDs, Buzzer and 7-Segment display.


Used Components
---------------

*[![Ultrasonic Sensor - HC-SR04](https://cdn.sparkfun.com//assets/parts/1/3/5/0/8/15569-Ultrasonic_Distance_Sensor_-_HC-SR04-01a.jpg)](https://www.sparkfun.com/products/15569))

*![Arduino UNO](https://store.arduino.cc/arduino-uno-rev3)

*Multifunction Shield


Implementation Overview
-----------------------

The code is implemented using C language and AVR library.

The sensor will be triggered with 10us of trigger signal.

The program will receive an echo signal and calculate the time difference between trigger and echo signals.For this purpose timer overflows will be used to calculate time difference between trigger and and echo signals.

The distance will be calculated using following basic formula:

Distance L = 1/2 × T × C

where L is the distance, T is the time between the emission and reception, and C is the sonic speed. (The value is multiplied by 1/2 because T is the time for go-and-return distance.)

According to calculated distance value, The programm will indicate the distance on 7-Segment display, on LEDs, as well as with buzzer.


Usage
-----

The park sensor should be placed against a surface. The HC-SR04 can measure distances from 2cm up to 4 meters.
The distance will be represented on the 7-Segment display. The buzzer will indicate the distance to user with high pitch sound. 


