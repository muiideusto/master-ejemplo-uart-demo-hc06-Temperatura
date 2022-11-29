/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500
DigitalOut led1(PA_5);
AnalogIn NTC(A2);
Ticker tickerTemp;
float vNTC;
static UnbufferedSerial serial_port(PA_0, PA_1, 9600);
char cadena[20];
char datoRx[1];

void mideTemp() { vNTC = NTC.read_voltage(); }

int main() {
  serial_port.set_blocking(false);
  NTC.set_reference_voltage(3.3);
  tickerTemp.attach(&mideTemp, 1000ms);
  printf("Iniciado\n");

  while (true) {

    if (serial_port.readable() == true) {
      serial_port.read(&datoRx, 1);
      if (datoRx[0] == 'a') {
        led1 = 0;
        printf("A recibida, apagando\n");
      } else if (datoRx[0] == 'e') {
        led1 = 1;
        printf("E recibida, encendiendo\n");
      } else if (datoRx[0] == 't') {
        int lcadena = sprintf(cadena, "%f\n", vNTC);
        serial_port.write(&cadena, lcadena);
        printf("F recibida, pidiendo temperatura\n");
      }

      wait_us(1000);
    }
  }
}