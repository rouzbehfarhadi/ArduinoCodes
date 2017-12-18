
// Adapt these to your board and application timings:

#define BUTTON1_PIN        8  // Button
#define BUTTON2_PIN        9
#define LED_PIN            10

//////////////////////////////////////////////////////////////////////////////

void setup()
{
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(BUTTON1_PIN, HIGH); // pull-up
  digitalWrite(BUTTON2_PIN, HIGH);
  Serial.begin(9600);
}

boolean handle_button()
{
  int button_pressed = !digitalRead(BUTTON1_PIN); // pin low -> pressed
  return button_pressed;
}

void loop()
{
  // handle button
  boolean button_pressed = handle_button();

  int button1_pressed = !digitalRead(BUTTON1_PIN);
  int button2_pressed = !digitalRead(BUTTON2_PIN);
  
  if(button1_pressed){
    digitalWrite(LED_PIN,HIGH);
  }else if(button2_pressed){
    digitalWrite(LED_PIN,LOW);
  }
  
}

