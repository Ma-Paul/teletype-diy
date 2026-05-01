/* 
 * RS234 Adapter connected with PS/2 Keyboard
 * RX Arduino <-> TX RS234
 * During upload: disconnect RX!
*/ 

int indent;

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
            default:
                Serial.print("Scancode: 0x");
                Serial.println(x, HEX);
                x = 0; 
                break;
            case 0x1C: x = 'A'; break;
            case 0x42: x = 'K'; break;
            case 0x1B: x = 'S'; break;
            case 0x23: x = 'D'; break;
            case 0x2B: x = 'F'; break;
            case 0x34: x = 'G'; break;
            case 0x33: x = 'H'; break;
            case 0x3B: x = 'J'; break;
            case 0x4B: x = 'L'; break;
            case 0x5A: x = '\n'; break;
            case 0x1A: x = 'Z'; break;
            case 0x22: x = 'X'; break;
            case 0x21: x = 'C'; break;
            case 0x2A: x = 'V'; break;
            case 0x32: x = 'B'; break;
            case 0x31: x = 'N'; break;
            case 0x3A: x = 'M'; break;
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
            case 0x29: x = ' '; break;

        }
        if (x == '\n') {
            indent = 0;
            Serial.print("\r\n");
        } else if (x != 0) {
            ++indent;
            for (int i = 0; i < indent; ++i) {
                Serial.print(' ');
            }
            Serial.print(x);
            //Serial.write(0x1B);
            //Serial.write('@');
            Serial.print('\r');

        }
    }

}
