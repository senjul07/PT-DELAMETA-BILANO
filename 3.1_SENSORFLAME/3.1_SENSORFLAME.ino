//Inisialisasi pembuatan variable
int sensorFLAME =A0;
int pinLED = 3;
int pinBUZZER = 5;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode (pinLED, OUTPUT);
}


void loop() {
 //Program yang akan dijalankan berulang-ulang
 //BACA DATA
 int bacaFLAME=analogRead(sensorFLAME); //Membaca Nilai Sensor FLAME
     bacaFLAME = map(bacaFLAME,3,1024,10,255);
 
 //Print ke Serial Monitor
 Serial.print("Sensor FLAME:");
 Serial.print(bacaFLAME);
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik
 }
