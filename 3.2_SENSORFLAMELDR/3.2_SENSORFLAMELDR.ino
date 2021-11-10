//Inisialisasi pembuatan variable
int sensorFLAME = A0;
int sensorLDR = A1;
int pinLED1 = 3;
int pinLED2 = 4;
int pinLED3 = 6;
int pinBUZZER = 5;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode (pinLED1, OUTPUT);
 pinMode (pinLED2, OUTPUT);
 pinMode (pinLED3, OUTPUT);
}


void loop() {
 //Program yang akan dijalankan berulang-ulang
 //BACA DATA
 int bacaFLAME=analogRead(sensorFLAME); //Membaca Nilai Sensor FLAME
     bacaFLAME = map(bacaFLAME,1014,37,0,100);
 
 //Print ke Serial Monitor
 Serial.print("Sensor FLAME:");
 Serial.print(bacaFLAME);
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik

 //LOGIKA

 //KONDOISI 1 AMAN
if(bacaFLAME >=0 and bacaFLAME <20){
  delay(250);
  Serial.println("AMAN");
  digitalWrite(pinBUZZER,LOW);
  digitalWrite(pinLED3,HIGH);
  digitalWrite(pinLED1,LOW);
  digitalWrite(pinLED2,LOW);
}

//KONDISI 2 WASPADA
else if(bacaFLAME >20 and bacaFLAME <50){
  delay(250);
  Serial.println("WASPADA SISTEM MENDETEKSI API");
  analogWrite(pinBUZZER,50);
  digitalWrite(pinLED2,HIGH);
  digitalWrite(pinLED3,LOW);
  digitalWrite(pinLED1,LOW);
}

//KONDISI 3 BAHAYA
else if(bacaFLAME >50){
  delay(250);
  Serial.println("DANGER EVAKUASI");
  digitalWrite(pinBUZZER,HIGH);
  digitalWrite(pinLED1,HIGH);
  digitalWrite(pinLED2,LOW);
  digitalWrite(pinLED3,LOW);
 }
}
