//inisialisasi variable m 
int R = PA2;
int Y = PA3;
int G = PA4;
int kunci = 0;



void setup() {
  // put your setup code here, to run once:
  // FUNGSI INPUT OUTPUT PADA PIN
  pinMode (IR,INPUT);
  pinMode (LDR,INPUT);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
 int bacaIR=digitalRead (IR);
 int bacaLDR=analogRead (LDR);
     bacaLDR=map(bacaLDR,50,4095,0,250);
     

  //print serial
Serial.begin (115200);
Serial.print (" IR : ");Serial.print (bacaIR);
Serial.print (" | LDR : ");Serial.print (bacaLDR);
Serial.print (" | KUNCI  : ");Serial.print (kunci);
Serial.println();
delay(250);



//LOGIKA
if (bacaIR == 0 and kunci == 0){
  kunci = 1;
}else if (bacaIR == 0 and kunci == 1){
  kunci = 0;
}


if (kunci == 1 and bacaLDR >=200 and bacaLDR <= 250){
  digitalWrite(R,HIGH);
}else{
 digitalWrite(R,LOW);
}

if (kunci == 1 and bacaLDR >=100 and bacaLDR <= 200){
  digitalWrite(Y,HIGH);
}else{
 digitalWrite(Y,LOW);
}

if (kunci == 1 and bacaLDR >=0 and bacaLDR <= 100 ){
  digitalWrite(G,HIGH);
}else{
 digitalWrite(G,LOW);
}

}


//void RED(){
//  int bacaLDR=analogRead (LDR);
//      bacaLDR=map(bacaLDR,50,4095,0,250);
//if (bacaLDR >=200 and bacaLDR = 250){
//  digitalWrite(R,HIGH);
//}else{
//  digitalWrite(R,LOW);
//}
//}
//
//void YELLOW(){
//  int bacaLDR=analogRead (LDR);
//      bacaLDR=map(bacaLDR,50,4095,0,250);    
//if (bacaLDR >=100 and bacaLDR = 200){
//  digitalWrite(Y,HIGH);
//}else{
//  digitalWrite(Y,LOW);
//}
//}
//
//void GREEN(){
//  int bacaLDR=analogRead (LDR);
//      bacaLDR=map(bacaLDR,50,4095,0,250);
//if (bacaLDR >=0 and bacaLDR = 100){
//  digitalWrite(G,HIGH);
//}else{
//  digitalWrite(G,LOW);
//}
//}
