int interruptPin = 2;

void setup()
{
    Serial.begin(2000000);
    pinMode(interruptPin, INPUT);
}

void loop()
{
    int state, previousState = 2, counter=0;
    while (true)
    {
        state = digitalRead(interruptPin);
        if (state != previousState)
        {
            if (state == 1) Serial.print(state);
            previousState = state;
        }
    }
}
