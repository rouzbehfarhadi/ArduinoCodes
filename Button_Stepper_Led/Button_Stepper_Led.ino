
// Adapt these to your board and application timings:

#define BUTTON1_PIN        8  // Button
#define BUTTON2_PIN        9

#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5

#define GREEN_LED_PIN 10
#define RED_LED_PIN 12

boolean Direction = true;// gre
int Steps = 0;
unsigned long last_time;
unsigned long currentMillis ;
long time;
//////////////////////////////////////////////////////////////////////////////

void setup()
{
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT); 
  pinMode(GREEN_LED_PIN,OUTPUT);
  pinMode(RED_LED_PIN,OUTPUT);
   
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 

  digitalWrite(BUTTON1_PIN, HIGH); // pull-up
  digitalWrite(BUTTON2_PIN, HIGH);
  
  Serial.begin(115200);
}

void loop()
{

  int button1_pressed = !digitalRead(BUTTON1_PIN);
  int button2_pressed = !digitalRead(BUTTON2_PIN);
  if(button1_pressed){
    Direction = 0;
    digitalWrite(GREEN_LED_PIN,HIGH);
    digitalWrite(RED_LED_PIN,LOW);
  }else if(button2_pressed){
    Direction = 1;
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,HIGH);
  }else{
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,LOW);
  }
  
  while(button1_pressed || button2_pressed){
    button1_pressed = !digitalRead(BUTTON1_PIN);
    button2_pressed = !digitalRead(BUTTON2_PIN);
    currentMillis = micros();
    if(currentMillis-last_time>=1000){
        stepper(1); 
        time=time+micros()-last_time;
        last_time=micros();
    }
  }
  
}

void stepper(int xw){
    for (int x=0;x<xw;x++){
        switch(Steps){
        case 0:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
        break; 
        case 1:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
        break; 
        case 2:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
        break; 
        case 3:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
        break; 
        case 4:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
        break; 
        case 5:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
        break; 
         case 6:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
        break; 
        case 7:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
        break; 
        default:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
        break; 
        }
        SetDirection();
    }
} 
void SetDirection(){
    if(Direction==1){ Steps++;}
    if(Direction==0){ Steps--; }
    if(Steps>7){Steps=0;}
    if(Steps<0){Steps=7; }
}

