#define LED_BLUE 7
#define LED_RED 6
#define LED_GR 8

void setup() {
  // put your setup code here, to run once:

  pinMode( LED_BLUE, OUTPUT);
  pinMode( LED_RED, OUTPUT);

  pinMode( LED_GR, OUTPUT);

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_GR, HIGH);
 

  
}
