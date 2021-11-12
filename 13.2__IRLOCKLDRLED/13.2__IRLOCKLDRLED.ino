//inisialisasi variable
int IR = PA2;
int LDR = PA3;
int R = PA0;
int Y = PA1;
int G = PA3;
int kunci = 0;


void setup() {
  // put your setup code here, to run once:
  // FUNGSI INPUT OUTPUT PADA PIN
Serial.begin (9600);
pinMode (IR,INPUT);
pinMode (LDR,INPUT);
pinMode (R,OUTPUT);
pinMode (Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacaIR=digitalRead (IR);
  int bacaLDR=analogRead (LDR);
      bacaLDR=map(bacaLDR,50,4095,1,255);
  
  //print serial
  Serial.print ("   IR    : ");Serial.print(bacaIR);
  Serial.print ("   |   LDR   : ");Serial.print(bacaLDR);
  Serial.print ("   |   kunci : ");Serial.print(kunci);
  Serial.println();
  delay(500);



//LOGIKA
  if(bacaIR == 0 and kunci == 0){
    digitalWrite(R,HIGH);
    analogWrite(Y,0);
    delay(250);
    kunci = 1;
  }else if(bacaIR == 0 and kunci == 1){
    digitalWrite(R,LOW);
    analogWrite(Y,bacaLDR);
    delay(250);
    kunci = 0;

}
