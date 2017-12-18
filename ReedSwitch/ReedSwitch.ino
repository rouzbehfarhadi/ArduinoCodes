#http://www.instructables.com/id/Arduino-Reed-Switch/step2/The-Sketch/
const int pinSwitch = 7; //Pin Reed

const int pinLed = 10; //Pin LED

int StatoSwitch = 0;

void setup()

{

    pinMode(pinLed, OUTPUT); //Imposto i PIN

    pinMode(pinSwitch, INPUT);

}

void loop()

{

    StatoSwitch = digitalRead(pinSwitch); //Leggo il valore del Reed
    
    if (StatoSwitch == HIGH) {

        digitalWrite(pinLed, HIGH);

    } else {

        digitalWrite(pinLed, LOW);

    }

}

