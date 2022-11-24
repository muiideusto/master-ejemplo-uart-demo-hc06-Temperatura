/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500
DigitalOut led1(PA_5);



static UnbufferedSerial serial_port(PA_0, PA_1,9600);

char datoRx[1];





int main() {
    serial_port.set_blocking(false);
 
  printf("Iniciado\n");

  while (true) {
   
    
    if(serial_port.readable()==true){
        serial_port.read(&datoRx, 1);
       if(datoRx[0]=='a'){
            led1=0;
            printf("A recibida, apagando\n");
       }else if(datoRx[0]=='e'){
           led1=1;
           printf("E recibida, encendiendo\n");
       }
  }
  
    wait_us(1000);
  }
}
