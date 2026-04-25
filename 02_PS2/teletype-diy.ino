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
            case 0x16: x = '1'; break;
            case 0x1E: x = '2'; break;
            case 0x26: x = '3'; break;
            case 0x25: x = '4'; break;
            case 0x2E: x = '5'; break;
            case 0x36: x = '6'; break;
            case 0x3D: x = '7'; break;
            case 0x3E: x = '8'; break;
            case 0x46: x = '9'; break;
            case 0x45: x = '0'; break;
            case 0x15: x = 'Q'; break;
            case 0x1D: x = 'W'; break;
            case 0x24: x = 'E'; break;
            case 0x2D: x = 'R'; break;
            case 0x2C: x = 'T'; break;
            case 0x35: x = 'Y'; break;
            case 0x3C: x = 'U'; break;
            case 0x43: x = 'I'; break;
            case 0x44: x = 'O'; break;
            case 0x4D: x = 'P'; break;
        }
        Serial.println(x);
    }

}
