//inisialisasi variable
#include <NewPing.h>


int PIR = PA0;
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
  // FUNGSI INPUT OUTPUT PADA PIN
  pinMode (PIR,INPUT);
  pinMode (FLAME,INPUT);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
 int bacaJarak=cm.ping_cm();
 int bacaPIR=digitalRead (PIR);
 int bacaFLAME=analogRead (FLAME);
     bacaFLAME=map(bacaFLAME,4095,50,0,255);
 delay(250);

  //print serial
Serial.begin (115200);
Serial.print (" PIR : ");Serial.print (bacaPIR);
Serial.print (" | FLAME : ");Serial.print (bacaFLAME);
Serial.print (" | KUNCI  : ");Serial.print (kunci);
Serial.print(" JARAK : ");Serial.print(bacaJarak);Serial.print("cm");
Serial.println();
delay(250);


//LOGIKA SENSOR PIR
if(bacaPIR == 1){
  digitalWrite(Y,HIGH);
  }else{
    digitalWrite(Y,LOW);
  }


//LOGIKA SENSOR FLAME
if(bacaFLAME >=1){
  delay(250);
  digitalWrite(R,HIGH);
  }else{
    delay(250);
    digitalWrite(R,LOW);
  }


//LOGIKA SENSOR ULTRASONIK
  if(bacaJarak <=30 and bacaJarak !=0 ){
     delay(50);
    digitalWrite (G,HIGH);
    }else{
      delay(700);
      digitalWrite (G,LOW);
     }
}
