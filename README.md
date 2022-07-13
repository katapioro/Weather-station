# Weather-station (2021)
## Authors
Katarzyna Pióro - code and connections
Łukasz Piasecki - connections and documentation description

## Introduction
Basic weather station made with ATMega328p, LCD and humidity/temperature sensor DHT11.

## Short description
This simple academic project was a result of use of free libraries(hd44780.h i dht11.h) and appropriate changes made to them. 
Inifinite while loop provides reading of measurement with 500ms synchronization.
DHT11 DATA 32-bit output contains humidity value(first 16-bits) and temperature value(second 16-bits), in both of them first 8-bit stands for integer number and second for fractions.

## Connection diagram
Look: Weather_station_diagram.png

## Video presentation
YouTube: https://youtu.be/AQvN4eyB9OQ (Polish)
