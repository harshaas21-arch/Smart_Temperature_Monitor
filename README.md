# Smart_Temperature_Monitor
A smart system which can alert the user based on the temperature

Working:
The Temperature sensor used here is TMP36 which is used for measuring the temperature.This device contains semiconductor material that changes electrical properties consistently with changing temperatures. The center pin's signal changes as the temperature changes, and the microcontroller's program can convert this signal from 0-1023 to a temperature in °C or °F.
The power pin of the sensor is connected to the source through a 250 ohms resistor, ground to ground, the vout pin is connected to A0 of Arduino Uno for analog input.

There are 3 LEDs to show different temperatures;
Yellow: Temperatures below 10°C
Green: Temperatures between 10°C and 35°C
Red: Temperatures above 35°C

There is a LCD 16x2 display, which is connected through I2C protocol, the Serial Clock (SCL) pin is connected to A5, and the Serial Data (SDA) pin is connected to A4.
It displays;
"Temp Monitor, Initializing....." in the beginning and then,
"Too cold": Temperatures below 10°C
"Perfect Temp": Temperatures between 10°C and 35°C
"Too Cold": Temperatures above 35°C

Arduino UNO is microcontroller used for gathering sensor values and check for the condition and provide a necessary output.
