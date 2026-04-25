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
