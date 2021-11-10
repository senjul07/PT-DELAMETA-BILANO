  //UNTUK TOMBOL
  int button1 = 2;
  int button2 = 3;
  int button3 = 4;

  //UNTUK LED
  int led1 = 5;
  int led2 = 6;
  int led3 = 7;

void setup() {
  //
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  //BACA DATA
  int readButton1= digitalRead(button1);
  int readButton2= digitalRead(button2);
  int readButton3= digitalRead(button3);

  //PRINT SERIAL
  Serial.print("kondisi button 1: ");Serial.print(readButton1);
  Serial.print(" | kondisi button 2: ");Serial.print(readButton2);
  Serial.print(" | kondisi button 3: ");Serial.print(readButton3);
  Serial.println();

  if(readButton1 == 1){
    digitalWrite(led1,HIGH);
    }else{
    digitalWrite(led1,LOW);
    }

  Serial.print("kondisi button: ");
  Serial.print(readButton2);
  Serial.println();

  if(readButton2 == 1){
    digitalWrite(led2,HIGH);
    }else{
    digitalWrite(led2,LOW);
    }
  Serial.print("kondisi button: ");
  Serial.print(readButton3);
  Serial.println();

  if(readButton3 == 1){
    digitalWrite(led3,HIGH);
    }else{
    digitalWrite(led3,LOW);
    }

}
