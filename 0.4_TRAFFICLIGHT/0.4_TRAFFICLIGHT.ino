int R=2;
int Y=3;
int G=4;
void setup() {
  // put your setup code here, to run once:
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // LAMPU MERAH
digitalWrite(R,HIGH);
delay(5000);
digitalWrite(R,LOW);
delay(100);

  // LAMPU KUNING
digitalWrite(Y,HIGH);
delay(1000);
digitalWrite(Y,LOW);
delay(100);

  // LAMPU HIJAU
digitalWrite(G,HIGH);
delay(5000);
digitalWrite(G,LOW);
delay(100);
}
