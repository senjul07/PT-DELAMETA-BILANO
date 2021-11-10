//Library Onewire dan DalasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

//Inisialisasi pembuatan variable
int sensorSuhu =2;
int buzzer = 3;
int R = 4;  // LED RED
int Y = 5;  // LED YELLOW
int G = 6;  // LED GREEN
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

//Menentukan Fungsionalitas dari PIN pada Microcontroller
void setup() {
  Serial.begin(115200);
  sensors.begin(); //Memanggil Fungsi
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);
  pinMode (buzzer,OUTPUT);
}

//Program yang akan dijalankan berulang-ulang
void loop() {
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);    //Membaca data di index 0 pada one wire
  Serial.print(" Suhu Ruangan : ");
  Serial.print(bacaSuhu);
  Serial.println();
  delay(250);

  
 if(bacaSuhu >=0 and bacaSuhu <=29.99){
  digitalWrite (buzzer,LOW);
  digitalWrite (R,LOW);
  digitalWrite (Y,LOW);
  digitalWrite (G,HIGH);
 }else if(bacaSuhu >=30.00 and bacaSuhu <=31.99){
  digitalWrite (buzzer,LOW);
  digitalWrite (R,LOW);
  digitalWrite (Y,HIGH);
  digitalWrite (G,LOW);
  }else if(bacaSuhu >=32.00){
  digitalWrite (buzzer,HIGH);
  delay(300);
  digitalWrite (R,HIGH);
  digitalWrite (Y,LOW);
  digitalWrite (G,LOW);
  }
}
