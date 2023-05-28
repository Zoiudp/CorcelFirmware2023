#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
#include <giroscopio.h>
#include <testemotor.h>


void setup() {
  initPKS();
  Serialinit(9600);
}

void loop() {
  testeMotor();
}

