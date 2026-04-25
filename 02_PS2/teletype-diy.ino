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
        char x = Serial.read();
        switch (x) {
            case 0x1C: x = 'A'; break;
            case 0x42: x = 'K'; break;
            case 0x1B: x = 'S'; break;
            case 0x23: x = 'D'; break;
            case 0x2B: x = 'F'; break;
            case 0x34: x = 'G'; break;
            case 0x33: x = 'H'; break;
            case 0x3B: x = 'J'; break;
            case 0x05: x = 'L'; break;
            case 0x0C: x = '\n'; break;
            case 0x0B: x = 'Z'; break;
            case 0x83: x = 'X'; break;
            case 0x0A: x = 'C'; break;
            case 0x01: x = 'V'; break;
            case 0x09: x = 'B'; break;
            case 0x78: x = 'N'; break;
            case 0x07: x = 'M'; break;
            
            default: x = '?'; break;
        }
        Serial.println(x);
    }

}
