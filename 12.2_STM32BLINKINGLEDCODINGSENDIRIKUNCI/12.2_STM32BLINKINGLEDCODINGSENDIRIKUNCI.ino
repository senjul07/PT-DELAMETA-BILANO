//inisialisasi variable
int TB1 = PA3;
int TB2 = PA4;
int TB3 = PA5;
int R = PA0;
int Y = PA1;
int G = PA2;
int kunci1 = 0;
int kunci2 = 0;
int kunci3 = 0;


void setup() {
  // put your setup code here, to run once:
  // FUNGSI INPUT OUTPUT PADA PIN
Serial.begin (9600);
pinMode (TB1,INPUT);
pinMode (TB2,INPUT);
pinMode (TB3,INPUT);
pinMode (R,OUTPUT);
pinMode (Y,OUTPUT);
pinMode (G,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacaB1=digitalRead (TB1);
  int bacaB2=digitalRead (TB2);
  int bacaB3=digitalRead (TB3);
  
  //print serial
  Serial.print ("tombol");Serial.print(bacaB1);Serial.println();
  Serial.print (" | tombol");Serial.print(bacaB2);Serial.println();
  Serial.print (" | tombol");Serial.print(bacaB3);Serial.println();



//LOGIKA
  if(bacaB1 == 1 and kunci1 == 0){
    digitalWrite (R, HIGH);
    kunci1 = 1;
    delay(500);
  }else if(bacaB1 == 1 and kunci1 == 1){
    digitalWrite (R,LOW);
    kunci1 = 0;
    delay(500);
  }

  if(bacaB2 == 1 and kunci2 == 0){
    digitalWrite (Y, HIGH);
    kunci2 = 1;
    delay(500);
  }else if(bacaB2 == 1 and kunci2 == 1){
    digitalWrite (Y,LOW);
    kunci2 = 0;
    delay(500);
  }

if(bacaB3 == 1 and kunci3 == 0){
    digitalWrite (G, HIGH);
    kunci3 = 1;
    delay(500);
  }else if(bacaB3 == 1 and kunci3 == 1){
    digitalWrite (G,LOW);
    kunci3 = 0;
    delay(500);
  }

}
