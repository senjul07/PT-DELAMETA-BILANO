  //UNTUK TOMBOL
  int button1 = 2;
  int kunci1 = 0;
  
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

  //LOGIC

  //START OF BUTTON 1 LED 1
  if(readButton1 == 0 and kunci1 == 0){
    delay(250);
    Serial.println("LED 1 ON");
    digitalWrite(led1,HIGH);
    kunci1=1;
    }else if (readButton1 == 0 && kunci1 == 1){
    delay(250);
    Serial.println("LED 1 OFF");
    digitalWrite(led1,LOW);
    kunci1=0;
    }
  //END OF BUTTON 1 LED 1
}
