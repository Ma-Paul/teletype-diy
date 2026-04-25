void 
setup()
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
            default: x = '?'; break;
        }
        Serial.println(x);
    }

}
