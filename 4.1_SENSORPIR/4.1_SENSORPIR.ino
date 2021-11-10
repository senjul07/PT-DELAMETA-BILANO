//Inisialisasi pembuatan variable
int sensorPIR =A0;
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
 int bacaPIR=digitalRead(sensorPIR); //Membaca Nilai Sensor PIR

 
 //Print ke Serial Monitor
 Serial.print("Sensor PIR:");
 Serial.print(bacaPIR);
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}
