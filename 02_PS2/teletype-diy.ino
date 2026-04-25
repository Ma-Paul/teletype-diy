/* 
 * RS234 Adapter connected with PS/2 Keyboard
 * RX Arduino <-> TX RS234
 * During upload: disconnect RX!
*/ 



void setup()
{
    Serial.begin(19200);
}

void
loop()
{
    if (Serial.available() > 0) {
        unsigned x = Serial.read();
        Serial.println(x, HEX);
    }

}
