#include <defines.h>
#include <motor.h>


void testeMotor() {
    while (true) {

        enablePKS(60000,60000);
        delay(5000);
        enablePKS(-60000,-60000);
        delay(5000);

    }
}