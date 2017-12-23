/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

#define LED5 8
#define LED6 9
#define LED7 10
#define LED8 11

#define BUTTON_PIN 12


void blink(int arr[]) {
  int i = 0;
  for (i = 0; i< 8; i++) {
    digitalWrite(LED1+i,arr[i] ? HIGH : LOW);
  }
}

void blinkNumber(int num) {
    switch(num) {
        case 1: {
              int one[] = {1,0,1,1,0,1,1,1};
              blink(one); 
          }
          break;
        case 2: {
          int two[] = {1,1,0,0,0,0,1,0};
          blink(two);
          }
          break;
        case 3: {
          int three[] = {1,0,0,1,0,0,1,0};
          blink(three); 
          }
          break;
        case 4:
          {
              int four[] = {1,0,1,1,0,1,0,0};
              blink(four);
          }
          break;
        case 5:
          {
              int five[] = {1,0,0,1,1,0,0,0};
              blink(five);
          }
          break;
        case 6:
          {
              int six[] = {1,0,0,0,1,0,0,0};
              blink(six);
          }
          break;
        case 7:
          {
              int seven[] = {1,0,1,1,0,0,1,1};
              blink(seven);
          }
          break;
        case 8:
          {
              int eight[] = {1,0,0,0,0,0,0,0};
              blink(eight);
          }
          break;
        case 9:
          {
              int nine[] = {1,0,0,1,0,0,0,0};
              blink(nine);
          }
          break;
        case 0:
          {
              int zero[] = {1,0,0,0,0,0,0,1};
              blink(zero);
          }
          break;
        default:
        break;
    }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
  
  blinkNumber(0);

}


// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button



// the loop function runs over and over again forever
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(BUTTON_PIN);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      
       if (buttonPushCounter % 10 == 0) {
           buttonPushCounter = 0;
       } 
  
       blinkNumber(buttonPushCounter);
    } 
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
 


}
