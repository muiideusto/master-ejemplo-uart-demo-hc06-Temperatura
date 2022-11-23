/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500
DigitalOut led1(PA_12);
DigitalIn boton(PC_2);

int botonAnterior = 0;
static BufferedSerial serial_port(PC_12, PD_2,9600);

char datoRx;
char datoTx;




int main() {

 
  printf("Iniciado\n");

  while (true) {
    if ((botonAnterior == 0) && (boton == 1)) {
      datoTx = 'p';
      serial_port.write(&datoTx, 1);
      printf("Mensaje enviado\n");
    }
    if(serial_port.readable()){
         char c;
        serial_port.read(&c, 1);
        printf("dato\n");

    }

    botonAnterior = boton;
    thread_sleep_for(10);
  }
}
