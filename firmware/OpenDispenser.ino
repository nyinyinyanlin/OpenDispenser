void setup() {
  pinMode(0,INPUT);
  pinMode(1,OUTPUT);
  digitalWrite(1,HIGH);
}

void loop() {
  if (digitalRead(0)){
    digitalWrite(1,LOW);
    delay(2000);
    digitalWrite(1,HIGH);
    delay(3000);
  }
  delay(100);
}
