//Inisialisasi pembuatan variable
int sensorFLAME = A0;
int sensorLDR = A1;
int sensorPIR = A2;
int pinLED1 = 3;
int pinBUZZER = 5;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode (pinLED1, OUTPUT);
}


void loop() {
 //Program yang akan dijalankan berulang-ulang
 //BACA DATA
 int bacaFLAME=analogRead(sensorFLAME); //Membaca Nilai Sensor FLAME
     bacaFLAME = map(bacaFLAME,1014,37,0,100);
 int bacaLDR=analogRead(sensorLDR);
     bacaLDR= map(bacaLDR,3,1024,0,100);
 int bacaPIR=digitalRead(sensorPIR);
 
 //Print ke Serial Monitor
 Serial.print("Sensor FLAME: ");
 Serial.print(bacaFLAME);
 Serial.print("| Sensor LDR: ");
 Serial.print(bacaLDR);
 Serial.print("| Sensor PIR: ");
 Serial.print(bacaPIR);
 Serial.println();
 delay(500);//Jeda waktu perulagan seama 500 mili detik

 //LOGIKA LDR
 analogWrite(pinLED1,bacaLDR);

 //LOGIKA

 //KONDOISI 1 AMAN
if(bacaFLAME >=0 and bacaFLAME <10){
  delay(250);
  digitalWrite(pinBUZZER,LOW);
}else if(bacaFLAME >20 and bacaFLAME <50){
  delay(250);
  digitalWrite(pinBUZZER,HIGH);
}else if(bacaFLAME >50){
  delay(250);
  digitalWrite(pinBUZZER,HIGH);
 }
}
