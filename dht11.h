 //Base code used as library for DHT11 from http://www.electronicwings.com
 //Non-comercial use

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DHT11_PIN 7
uint8_t c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;

void Request(void);
void Response(void);
uint8_t Receive_data8bit(void);
void Print_Measurements(void);