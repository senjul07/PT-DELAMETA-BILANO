  //UNTUK TOMBOL
  int button1 = 2;
  int button2 = 3;
  int button3 = 4;
  int kunci1 = 0;
  int kunci2 = 0;
  int kunci3 = 0;
  
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

  //LOGIC

  //START OF BUTTON 1 LED 1
  if(readButton1 == 1 and kunci1 == 0){
    delay(250);
    Serial.println("LED 1 ON");
    digitalWrite(led1,HIGH);
    kunci1=1;
    }else if (readButton1 == 1 && kunci1 == 1){
    delay(250);
    Serial.println("LED 2 OFF");
    digitalWrite(led1,LOW);
    kunci1=0;
    }
  //END OF BUTTON 1 LED 1

  
  //START OF BUTTON 2 LED 2
    if(readButton2 == 1 and kunci2 == 0){
    delay(250);
    Serial.println("LED 2 ON");
    digitalWrite(led2,HIGH);
    kunci2=1;
    }else if (readButton2 == 1 && kunci2 == 1){
    delay(250);
    Serial.println("LED 2 OFF");
    digitalWrite(led2,LOW);
    kunci2=0;
    }
  //END OF BUTTON 2 LED 2


  //START OF BUTTON 3 LED 3
    if(readButton3 == 1 and kunci3== 0){
    delay(250);
    Serial.println("LED 3 ON");
    digitalWrite(led3,HIGH);
    kunci3=1;
    }else if (readButton3 == 1 && kunci3 == 1){
    delay(250);
    Serial.println("LED 3 OFF");
    digitalWrite(led3,LOW);
    kunci3=0;
    }
   //END OF BUTTON 3 LED 3
}
