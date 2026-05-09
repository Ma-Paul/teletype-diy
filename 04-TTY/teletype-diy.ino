/* 
 * RS234 Adapter connected with PS/2 Keyboard
 * RX Arduino <-> TX RS234
 * During upload: disconnect RX!
*/
#include <AltSoftSerial.h>
AltSoftSerial mySerial;
bool uppercase;
int indent;
bool skip;

void setup()
{
    Serial.begin(19200);
    mySerial.begin(19200);
}

void
loop()
{
    if (mySerial.available() > 0) {
        int x = mySerial.read();
        if (x == 0x1B) {
            skip = true;
        }
        if (!skip) {
            if (x == '\r') {
                // Serial.print("\r\n");
            }
            Serial.write(x);
        }
        if (skip && (x == 'm' || x == 'l')) {
            skip = false;
        }
    }
    if (Serial.available() > 0) {
        char x = Serial.read();
        switch (x) {
            default:
                mySerial.print("Scancode: 0x");
                mySerial.println(x, HEX);
                x = 0; 
                break;
            case 0x58: x = 0; uppercase = !uppercase; break;
            case 0x5A: x = '\n'; break;
            case 0x1C: x = uppercase ? 'A' : 'a'; break;
            case 0x42: x = uppercase ? 'K' : 'k'; break;
            case 0x1B: x = uppercase ? 'S' : 's'; break;
            case 0x23: x = uppercase ? 'D' : 'd'; break;
            case 0x2B: x = uppercase ? 'F' : 'f'; break;
            case 0x34: x = uppercase ? 'G' : 'g'; break;
            case 0x33: x = uppercase ? 'H' : 'h'; break;
            case 0x3B: x = uppercase ? 'J' : 'j'; break;
            case 0x4B: x = uppercase ? 'L' : 'l'; break;
            case 0x1A: x = uppercase ? 'Z' : 'z'; break;
            case 0x22: x = uppercase ? 'X' : 'x'; break;
            case 0x21: x = uppercase ? 'C' : 'c'; break;
            case 0x2A: x = uppercase ? 'V' : 'v'; break;
            case 0x32: x = uppercase ? 'B' : 'b'; break;
            case 0x31: x = uppercase ? 'N' : 'n'; break;
            case 0x3A: x = uppercase ? 'M' : 'm'; break;
            case 0x16: x = uppercase ? '!' : '1'; break;
            case 0x1E: x = uppercase ? '@' : '2'; break;
            case 0x26: x = uppercase ? '#' : '3'; break;
            case 0x25: x = uppercase ? '$' : '4'; break;
            case 0x2E: x = uppercase ? '%' : '5'; break;
            case 0x36: x = uppercase ? '^' : '6'; break;
            case 0x3D: x = uppercase ? '&' : '7'; break;
            case 0x3E: x = uppercase ? '*' : '8'; break;
            case 0x46: x = uppercase ? '(' : '9'; break;
            case 0x45: x = uppercase ? ')' : '0'; break;
            case 0x15: x = uppercase ? 'Q' : 'q'; break;
            case 0x1D: x = uppercase ? 'W' : 'w'; break;
            case 0x24: x = uppercase ? 'E' : 'e'; break;
            case 0x2D: x = uppercase ? 'R' : 'r'; break;
            case 0x2C: x = uppercase ? 'T' : 't'; break;
            case 0x35: x = uppercase ? 'Y' : 'y'; break;
            case 0x3C: x = uppercase ? 'U' : 'u'; break;
            case 0x43: x = uppercase ? 'I' : 'i'; break;
            case 0x44: x = uppercase ? 'O' : 'o'; break;
            case 0x4D: x = uppercase ? 'P' : 'p'; break;
            case 0x29: x = ' '; break;
            case 0x49: x = uppercase ? '>' : '.'; break;
            case 0x4A: x = uppercase ? '?' : '/'; break;
            case 0x3D: x = uppercase ? '+' : '='; break;
    
        }
        mySerial.print(x);
    }

}
