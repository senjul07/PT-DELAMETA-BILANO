void setup() {
  // put your setup code here, to run once:
  //pinMode(i,OUTPUT);
  
  for(int i=2; i<=4; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=2; i<=4; i++){
  digitalWrite(i,HIGH);
  delay(50);
  digitalWrite(i,LOW);
  delay(50);
  }
}
