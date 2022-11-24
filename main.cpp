/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500
DigitalOut led1(PA_10);
DigitalIn boton(PC_2);

int botonAnterior = 0;
static UnbufferedSerial serial_port(PC_12, PD_2,9600);

char datoRx[1];
char datoTx;




int main() {
    serial_port.set_blocking(false);
 
  printf("Iniciado\n");

  while (true) {
    if ((botonAnterior == 0) && (boton == 1)) {
      datoTx = 'p';
      serial_port.write(&datoTx, 1);
      printf("Mensaje enviado\n");
    }
    
    if(serial_port.readable()==true){
        serial_port.read(&datoRx, 1);
        led1=!led1;
        printf("dato %s\n",datoRx);
  }
  

    botonAnterior = boton;
    wait_us(1000);
  }
}
