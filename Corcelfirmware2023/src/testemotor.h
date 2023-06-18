#include <defines.h>
#include <motor.h>


void testeMotor() {
    while (true) {

        FW_PKS.writeMicroseconds(2000);
        ANG_PKS.writeMicroseconds(1000);
        delay(1000);
        FW_PKS.writeMicroseconds(2000);
        ANG_PKS.writeMicroseconds(2000);
        delay(1000);
        FW_PKS.writeMicroseconds(1500);
        ANG_PKS.writeMicroseconds(1500);
    }
}