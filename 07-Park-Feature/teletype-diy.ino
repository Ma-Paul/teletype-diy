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

int indent;
bool parked;
constexpr uint64_t park_timer_max = 1600000 / 3;
uint64_t park_timer = park_timer_max;

void setup() {
    delay(1000);
    keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
    Serial.begin(19200);
    mySerial.begin(19200);
    Serial.write(0x1B);
    Serial.write('@');
}

void park() {
    Serial.write(0x1B);
    Serial.write('$');
Serial.write(210);
    Serial.write(1);
    // Serial.write('.');
    Serial.write('`');

    /*
    Serial.write(0x1B);
    Serial.write('*');
    Serial.write(1);
    Serial.write(0);
    Serial.write(1);
    */


    Serial.write(0x1B);
    Serial.write('J');
    Serial.write(0x00);
    parked = true;
}

void loop() {
    if (mySerial.available() > 0) {
        // decide what we actually send to the printer
        int x = mySerial.read();
        if (x == 0x1B) {
            skip = true;
        }
        if (!skip) {
            if (parked) {
                int nL = 6 * indent % 256;
                int nH = 6 * indent / 256;
                Serial.write(0x1B);
                Serial.write('$');
                Serial.write(nL);
                Serial.write(nH);
                parked = false;
            } 
            Serial.write(x);
            flushed = false;
            if (x == '\n' || x == '\r') {
                indent = 0;
            } else {
                ++indent;
            }
        }
        if (skip && (x == 'm' || x == 'l' || x == 'h')) {
            skip = false;
        }
    } else {
        if (!parked) {
            if (park_timer > 0) {
                --park_timer;
            } else {
                park();
                park_timer = park_timer_max;
            }

        }
        if (!flushed) {
            flushed = true;
            Serial.write(0x1B);
            Serial.write('J');
            Serial.write(0x00);
        }
    }
    if (keyboard.available()) {
    
        // read the next key
        char x = keyboard.read();
        
        // check for some of the special keys
        if (x == PS2_ENTER) {
            mySerial.write('\n');
            indent = 0; 
        } else if (x == PS2_TAB) {
            mySerial.write('\t');
        } else if (x == PS2_PAGEUP || x == PS2_UPARROW) {
            /*
            Serial.write(0x1B);
            Serial.write('J');
            Serial.write(0xB4);
            Serial.write(0x1B);
            Serial.write('J');
            Serial.write(0xB4);
            mySerial.write('Y');*/
            park();
        } else if (x == PS2_PAGEDOWN || x == PS2_DOWNARROW) {
            Serial.write(0x1B);
            Serial.write('j');
            Serial.write(0xB4);
            Serial.write(0x1B);
            Serial.write('j');
            Serial.write(0xB4);
            Serial.write('X');
        } else {
            mySerial.write(x);
        }
    }
}
