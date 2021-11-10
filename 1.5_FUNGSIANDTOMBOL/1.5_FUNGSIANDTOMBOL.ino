  //UNTUK TOMBOL
  int button1 = 2;
  int button2 = 3;

  //UNTUK LED
  int led1 = 5;

void setup() {
  //
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  //BACA DATA
  int readButton1= digitalRead(button1);
  int readButton2= digitalRead(button2);

  //PRINT SERIAL
  Serial.print("kondisi button 1: ");Serial.print(readButton1);
  Serial.print(" | kondisi button 2: ");Serial.print(readButton2);
  Serial.println();

  //LOGIC

  //START OF BUTTON 1 LED 1
  if(readButton1 == 1 and readButton2 == 1){
    digitalWrite(led1,HIGH);
    }else{
    digitalWrite(led1,LOW);
    }
  //END OF BUTTON 1 LED 1
}
