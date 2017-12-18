#define RELAY1 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(RELAY1,LOW);
  Serial.println("Light ON");
  
  delay(2000);
  
  digitalWrite(RELAY1, HIGH);
  Serial.println("Light OFF");
  delay(2000);  
  
}
