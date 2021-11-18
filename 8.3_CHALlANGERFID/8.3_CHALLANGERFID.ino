  //UNTUK TOMBOL
  int button1 = 2;
  int sensor2 = 3;
  int kunci1 = 0;
  
  //UNTUK LED
  int R = 5;
  int Y = 6;
  int G = 7;


void setup() {
  //
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  //BACA DATA
  int readButton1= digitalRead(button1);
  int readButton2= digitalRead(sensor2);

  //LOGIC

  if(readButton1 == 1 and kunci1 == 0){
    delay(250);
    Serial.println("WELCOME");
    digitalWrite(R,HIGH);
    kunci1=1;
  }

   if(readButton2 == 1 and kunci1 == 0){
    delay(250);
    Serial.println("TEKAN TOMBOL");
    digitalWrite(Y,HIGH);
    kunci1=1;
   }else if (readButton2 == 0 && kunci1 == 1)
   delay(250);
   Serial.println("");
   digitalWrite(led2,LOW);
   kunci1=0;

   if(readButton2 == 1 and kunci1 == 0){
    delay(250);
    Serial.println("");
    digitalWrite(led2,HIGH);
    kunci1=1;
   }else if (readButton1 == 0 && kunci1 == 1)
   delay(250);
   Serial.println("");
   digitalWrite(led2,LOW);
   kunci1=0;
   }else if (readButton1 == 0 && kunci1 == 1){
    delay(250);
    Serial.println("MASUKAN TIKET");
    digitalWrite(led1,LOW);
    kunci1=0;
   }



   
  //END OF BUTTON 1 LED 1
}
