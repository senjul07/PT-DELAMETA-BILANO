  //UNTUK TOMBOL
  int button1 = 2;

  //UNTUK LED
  int led1 = 5;
  int led2 = 6;

void setup() {
  //
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  //BACA DATA
  int readButton1= digitalRead(button1);

  //PRINT SERIAL
  Serial.print("kondisi button 1: ");Serial.print(readButton1);
  Serial.println();

  //LOGIC

  //START OF BUTTON 1 LED 1
  if(readButton1 == 1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    }
  //END OF BUTTON 1 LED 1
}
