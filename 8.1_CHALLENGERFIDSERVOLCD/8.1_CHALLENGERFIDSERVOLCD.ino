//Library 
#include<SPI.h>
#include<MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//Inisialisasi pembuatan variable
int outServo=4; //Pin untuk Servo
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;
int R = 5;
int Y = 6;
int G = 7;
int buzzer = 2;
int IR = 3;
int kunci = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  //INISIALISASI PIN OUTPUT ATAU PIN INPUT
  pinMode(buzzer,OUTPUT);
  pinMode(IR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

  //LCD
  lcd.begin();
  myservo.attach(outServo);

  buzzerBunyi();
  digitalWrite (R, HIGH);
  digitalWrite (Y, HIGH);
  digitalWrite (G, HIGH);
  delay(250);
  digitalWrite (R, LOW);
  digitalWrite (Y, LOW);
  digitalWrite (G, LOW);
  delay(250);
  digitalWrite (R, HIGH);
  digitalWrite (Y, HIGH);
  digitalWrite (G, HIGH);
  delay(250);
  digitalWrite (R, LOW);
  digitalWrite (Y, LOW);
  digitalWrite (G, LOW);
  Serial.println("SELAMAT DATANG");
  Serial.println("Tempelkan Kartu!");
  digitalWrite (R, HIGH);
  digitalWrite (Y, LOW);
  digitalWrite (G, LOW);
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("SELAMAT DATANG");
  delay(1000);
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Baca Data
  
  if(mfrc522.PICC_IsNewCardPresent()and kunci == 0){
    readRFID();
    Serial.print("Tag UID : ");
    Serial.println(uidString);
    
    if(uidString == "4-38-89-3A"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      digitalWrite (G, HIGH);
      digitalWrite (R, LOW);
      digitalWrite (Y, LOW);
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(4,0); lcd.print("BERHASIL!");
      delay(500);
      Serial.println("Silahkan Masuk");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
      myservo.write(90); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      kunci = 1;

      
    }else if (uidString == "8A-37-5A-1A"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      digitalWrite (G, HIGH);
      digitalWrite (R, LOW);
      digitalWrite (Y, LOW);
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(4,0); lcd.print("BERHASIL!");
      delay(500);
      Serial.println("Silahkan Masuk");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
      myservo.write(90); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      kunci = 1;

      
    }else{
      Serial.println("GAGAL");
      digitalWrite (Y, HIGH);
      digitalWrite (R, LOW);
      digitalWrite (G, LOW);
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(5,0); lcd.print("GAGAL!");
      buzzerBunyiGagal();
      Serial.println("Tempelkan Kartu!");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
      digitalWrite (R, HIGH);
      digitalWrite (Y, LOW);
      digitalWrite (G, LOW);
    }
  }
 IRnyala();
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}


void IRnyala(){
  int bacaIR=digitalRead(IR);
if (bacaIR == 0 and kunci == 1){
    buzzerBunyi2();
    digitalWrite (R, HIGH);
    digitalWrite (Y, LOW);
    digitalWrite (G, LOW);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
    Serial.println("PALANG TERTUTUP");
    Serial.println("");
    delay(500);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
    Serial.println("Tempelkan Kartu!");
    myservo.write(180); //0-180
    delay(1000); //Jeda waktu perulagan seama 500 mili detik
    kunci = 0;
    }
}
  
void buzzerBunyi(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  
}


void buzzerBunyi2(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);  
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  
}


void buzzerBunyiGagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}
