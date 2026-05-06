#include <AltSoftSerial.h>

AltSoftSerial mySerial;
// Uno: RX = 8, TX = 9

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {
    if (mySerial.available() > 0) {
        Serial.write(mySerial.read());
    }

    if (Serial.available() > 0) {
        mySerial.write(Serial.read());
    }
}
