//LIBRARY
#include <NewPing.h>

//INISIALISASI PIN
int FLAME = PA1;
int echo = PA2;
int triger = PA3;
int batas = 400;
int R = PA4;
int Y = PA5;
int G = PA6;
int kunci = 0;

NewPing cm(triger,echo,batas);

void setup() {
  // put your setup code here, to run once:
  //Inisialisasi pembuatan variable
pinMode(FLAME,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacaJarak=cm.ping_cm();
  int bacaFLAME=digitalRead (FLAME);
  Serial.begin(115200);
  Serial.print("Sensor FLAME : ");
  Serial.print(bacaFLAME);
  Serial.print(" | Data jarak:");
  Serial.print(bacaJarak);
  Serial.print(" cm");
  Serial.print(" | KUNCI : ");
  Serial.print(kunci);
  Serial.println();
  delay(200);

   if (bacaFLAME == 0 and kunci == 0){
      kunci = 1;
   }else if(bacaFLAME == 0 and kunci == 1){
      kunci = 0;
   }
  
if (bacaJarak >100 and kunci == 1){
  digitalWrite(R,HIGH);
  delay(200);
  digitalWrite(R,LOW);
  delay(200);
  digitalWrite(Y,HIGH);
  delay(200);
  digitalWrite(Y,LOW);
  delay(200);
  digitalWrite(G,HIGH);
  delay(200);
  digitalWrite(G,LOW);
  delay(200);
  digitalWrite(Y,HIGH);
  delay(200);
  digitalWrite(Y,LOW);
}else if(bacaJarak >=50 and bacaJarak <=99 and kunci == 1){
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(1000);
}else if(bacaJarak >=1 and bacaJarak <=49 and kunci == 1){
  delay(250);
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(100);
}
}
