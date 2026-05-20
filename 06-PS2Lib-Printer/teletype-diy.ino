#include <AltSoftSerial.h>
#include <PS2Keyboard.h>

// Stuff for PS2 Keyboard
const int DataPin = 4;
const int IRQpin =  3;
PS2Keyboard keyboard;

// for 2nd Serial Interface
AltSoftSerial mySerial;

// for filtering out escape codes
bool skip;
bool flushed;

void setup() {
    delay(1000);
    keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
    Serial.begin(19200);
    mySerial.begin(19200);
    Serial.write(0x1B);
    Serial.write('@');
    Serial.println("Keyboard Test:");
}

void loop() {
    if (mySerial.available() > 0) {
        int x = mySerial.read();
        if (x == 0x1B) {
            skip = true;
        }
        if (!skip) {
            Serial.write(x);
            flushed = false;
            /*
            if (x == '\r' || x == '\n') {
                indent = 0;
            } else {
                ++indent;
            }
            */
        }
        if (skip && (x == 'm' || x == 'l' || x == 'h')) {
            skip = false;
        }
    } else if (!flushed) {
        flushed = true;
        Serial.write(0x1B);
        Serial.write('J');
        Serial.write(0x00);
    }
    if (keyboard.available()) {
    
        // read the next key
        char x = keyboard.read();
    
        // check for some of the special keys
        if (x == PS2_ENTER) {
            mySerial.write('\n');
        } else if (x == PS2_TAB) {
            mySerial.write('\t');
        } else if (x == PS2_PAGEUP || x == PS2_UPARROW) {
            mySerial.write(0x1B);
            mySerial.write('J');
            mySerial.write(0x10);
        } else if (x == PS2_PAGEDOWN || x == PS2_DOWNARROW) {
            mySerial.write(0x1B);
            mySerial.write('j');
            mySerial.write(0x10);
        } else {
            mySerial.write(x);
        }
    }
}
