void setup() {
  // put your setup code here, to run once:
  //pinMode(i,OUTPUT);
  Serial.begin(9600);
  for(int i=2; i<=4; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
//  // put your main code here, to run repeatedly:
//  for(int i=2; i<=4; i++){
//  digitalWrite(i,HIGH);
//  delay(50);
//  digitalWrite(i,LOW);
//  delay(50);
//  }
   for(int i=0; i<=255; i++){
  analogWrite(3,i);
  analogWrite(5,i);
  analogWrite(6,i);
  //int volt= map(1,0,255,0,5); // konversi nilai pwm ke volt
  float volt=(5.0/255.0);
  float ia = i*volt;
  Serial.print("volt" +String(i)+ " :");   
  Serial.println(ia);   // menampilkan hasil
  delay(0.1);                                  // NYALA BERSAMA
  }
    for(int i=255; i>=0; i--){
  analogWrite(3,i);
  analogWrite(5,i);
  analogWrite(6,i);
  //int volt= map(1,0,255,0,5); // konversi nilai pwm ke volt
  float volt=(5.0/255.0);
  float ia = i*volt;
  Serial.print("volt" +String(i)+ " :"); 
  Serial.println(ia);   // menampilkan hasil
  delay(0.1);
    }
}

//     for(int i=0; i<=255; i++){
//  analogWrite(3,i);
//  delay(1);
//  }
//     for(int i=255; i>=0; i--){
//  analogWrite(3,i);
//  delay(1);
//  }
//       for(int i=0; i<=255; i++){                             // NYALA SATU PERSATU
//  analogWrite(5,i);
//  delay(1);
//  }
//     for(int i=255; i>=0; i--){
//  analogWrite(5,i);
//  delay(1);
//  }
//       for(int i=0; i<=255; i++){
//  analogWrite(6,i);
//  delay(1);
//  }
//     for(int i=255; i>=0; i--){
//  analogWrite(6,i);
//  delay(1);
//  }
//}
