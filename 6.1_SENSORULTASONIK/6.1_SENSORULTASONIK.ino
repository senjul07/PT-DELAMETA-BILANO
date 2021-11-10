//Library Onewire dan DalasTemperature
#include <NewPing.h>

//Inisialisasi pembuatan variable
int echo =9;
int triger =8;
int batas =400;  //maksimal 400cm
int buzzer = 3;
int R = 4;  // LED RED
int Y = 5;  // LED YELLOW
int G = 6;  // LED GREEN

NewPing cm(triger,echo,batas);


//Menentukan Fungsionalitas dari PIN pada Microcontroller
void setup() {
  Serial.begin(115200);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);
  pinMode (buzzer,OUTPUT);
}

//Program yang akan dijalankan berulang-ulang
void loop() {
  int bacaJarak=cm.ping_cm();
  delay(250);



  if(bacaJarak <=20 and bacaJarak !=0 ){
  Serial.print(" JARAK : ");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println(" |  BAHAYA!!");
  Serial.print(bacaJarak);
  digitalWrite (buzzer,HIGH);
  delay(50);
  digitalWrite (buzzer,LOW);
  digitalWrite (R,HIGH);
  digitalWrite (Y,LOW);
  digitalWrite (G,LOW);
 }else if(bacaJarak >=21 and bacaJarak <=70){
  Serial.print("JARAK : ");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println(" |  BERHENTI!!");
  Serial.print(bacaJarak);
  digitalWrite (buzzer,HIGH);
  delay(700);
  digitalWrite (buzzer,LOW);
  digitalWrite (R,LOW);
  digitalWrite (Y,HIGH);
  digitalWrite (G,LOW);
  }else if(bacaJarak >=71){
  Serial.print(" JARAK : ");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println(" |  AMAN");
  Serial.print(bacaJarak);
  digitalWrite (buzzer,LOW);
  digitalWrite (R,LOW);
  digitalWrite (Y,LOW);
  digitalWrite (G,HIGH);
  }
}
