#include <Arduino.h>

//Colocar o baudrate desejado para leitura
void Serialinit(unsigned x){
    Serial.begin(x);
}

byte getSerial()
{   
    byte byteRead;
    if (Serial.available()){
        byteRead = Serial.read();
    }
    return byteRead;

}

void writeSerial(char comando) {

    if(Serial.available()){
        Serial.write(comando);
    }
}
