#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
#include <giroscopio.h>
#include <testemotor.h>
#include <Odometria.h>


void setup() {
  initPKS();
  Serialinit(9600);
  init_mpu();
}

void loop() {
  testeMotor();
  getPosicao(ENCDIR,positionDir,newPosDir);
  getPosicao(ENCESC,positionEsq,newPosEsq);
}

