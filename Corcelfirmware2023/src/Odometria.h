#ifndef ODOMETRIA_H
#define ODOMETRIA_H

#include <Encoder.h>
#include <math.h>
#include <defines.h>

double raioRoda = 30;
double voltas, distEsq, distDir;
long positionEsq, positionDir, newPosEsq, newPosDir;
Encoder ENCESC(DE1, DE2);
Encoder ENCDIR(DE3, DE4);

double getDistPercorrida(Encoder encoder, long position, long newPos, double dist)
{
    newPos = encoder.read();
    if (newPos != position)
    {
        position = newPos;
    }

    dist = (2 * raioRoda * PI) * voltas;
    
    return dist;
}

void getPosicao(Encoder encoder, long position, long newPos){

    newPos = encoder.read();
    if (newPos != position)
    {
        position = newPos;
    }
    Serial.println("Posição encoder: ");
    Serial.println(position);

}

#endif