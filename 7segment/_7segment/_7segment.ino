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
  
}

void blink(int arr[]) {
  int i = 0;
  for (i = 0; i< 8; i++) {
    digitalWrite(LED1+i,arr[i] ? HIGH : LOW);
  }

  delay(1000);
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

// the loop function runs over and over again forever
void loop() {
    int n = 0;
    for (n=0; n<6; n++) {
        blinkNumber(n);
    }
}
