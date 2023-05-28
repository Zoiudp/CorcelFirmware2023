#ifndef MOTOR_H
#define MOTOR_H

#include <defines.h>
#include <giroscopio.h>

void enablePKS1(float vel) {
    if (vel > 0) {
        analogWrite(SD1_PK1, vel);
        analogWrite(SD2_PK1, 65535);
        digitalWrite(ENB1_PK1, HIGH);
        digitalWrite(ENB2_PK1, LOW);

    } else if (vel < 0) {
        vel = fabs(vel);
        analogWrite(SD2_PK1, vel);
        analogWrite(SD1_PK1, 65535);
        digitalWrite(ENB1_PK1, LOW);
        digitalWrite(ENB2_PK1, HIGH);

    } else {
        analogWrite(SD2_PK1, 0);
        analogWrite(SD1_PK1, 0);
        digitalWrite(ENB1_PK1, LOW);
        digitalWrite(ENB2_PK1, LOW);
    }
}

void enablePKS2(float vel) {
    if (vel > 0) {
        analogWrite(SD1_PK2, vel);
        analogWrite(SD2_PK2, 65535);
        digitalWrite(ENB1_PK2, HIGH);
        digitalWrite(ENB2_PK2, LOW);

    } else if (vel < 0) {
        vel = fabs(vel);
        analogWrite(SD2_PK2, vel);
        analogWrite(SD1_PK2, 65535);
        digitalWrite(ENB1_PK2, LOW);
        digitalWrite(ENB2_PK2, HIGH);

    } else {
        analogWrite(SD2_PK2, 0);
        analogWrite(SD1_PK2, 0);
        digitalWrite(ENB1_PK2, LOW);
        digitalWrite(ENB2_PK2, LOW);
    }
}

void stopPKS() {
    analogWrite(SD1_PK1, 0);
    analogWrite(SD2_PK1, 0);
    analogWrite(SD1_PK2, 0);
    analogWrite(SD2_PK2, 0);

    digitalWrite(ENB1_PK1, LOW);
    digitalWrite(ENB2_PK1, LOW);
    digitalWrite(ENB2_PK1, LOW);
    digitalWrite(ENB2_PK2, LOW);
}

void initPKS()
{
    pinMode(SD1_PK1, OUTPUT);  // SD Parkinson
    pinMode(SD2_PK1, OUTPUT);
    pinMode(SD1_PK2, OUTPUT);
    pinMode(SD2_PK2, OUTPUT);

    pinMode(ENB1_PK1, OUTPUT);  // Enable Parkinson
    pinMode(ENB1_PK2, OUTPUT);
    pinMode(ENB2_PK1, OUTPUT);
    pinMode(ENB2_PK2, OUTPUT);

    stopPKS();
}

void enablePKS(float vel1, float vel2) {
    enablePKS1(vel1);
    enablePKS2(-vel2);
}

float pidIMU(float target, float atual) {
    float kp = 60;
    
    float error = target - atual;
    float output = error * kp;
    return output;
}

float pidCamera(int target, int atual) {
    int kp = 0.00035;

    int error = target - atual;
    int output = error * kp;
    return output;
}

void motorsControl(float linear, float angular, int posCone) {
    float ROBO_V[2] = {0, 0};

    angular += pidCamera(CENTRO_CONE, posCone);

    angular = pidIMU(angular, readAngularSpeed());
    angular = angular > 100 ? 100 : angular;


    float Vel_R = -linear - angular ;
    float Vel_L = -linear + angular;

    Vel_L = abs(Vel_L) < 10 ? 0 : Vel_L;
    Vel_R = abs(Vel_R) < 10 ? 0 : Vel_R;

    ROBO_V[0] = map(Vel_L, -100, 100, -65535, 65535);
    ROBO_V[1] = map(Vel_R, -100, 100, -65535, 65535);

    enablePKS(ROBO_V[1], ROBO_V[0]);
}

#endif