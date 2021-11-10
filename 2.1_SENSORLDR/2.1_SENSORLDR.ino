//Inisialisasi pembuatan variable
int sensorLDR =A0;
int pinLED = 3;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorLDR,INPUT);
 pinMode (pinLED, OUTPUT);
}


void loop() {
 //Program yang akan dijalankan berulang-ulang
 //BACA DATA
 int bacaLDR=analogRead(sensorLDR); //Membaca Nilai Sensor PIR
     bacaLDR = map(bacaLDR,3,1024,10,255);
 
 //Print ke Serial Monitor
 Serial.print("Sensor LDR:");
 Serial.print(bacaLDR);
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik

 analogWrite(pinLED,bacaLDR);
 }
