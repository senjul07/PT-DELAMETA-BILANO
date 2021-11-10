//Library
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SS_PIN 10
#define RST_PIN 9
int buzzer = 8;

MFRC522 mfrc522(SS_PIN,RST_PIN);

//Menentukan Fungsionalitas dari PIN pada Microcontroller
void setup() {
  Serial.begin(115200);
  SPI.begin();  // Initiate SPI bus
  mfrc522.PCD_Init();  // Initiate MFRC522
  pinMode (buzzer,OUTPUT);
  lcd.begin();

}

//Program yang akan dijalankan berulang-ulang
void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()) {return;}
  //Select one of the cards
  if(!mfrc522.PICC_ReadCardSerial()) {return;}

  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content="";
  byte letter;
  for (byte i=0; i<mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content == "058D04AEAB7100") //Sesuaikan dengan ID kartu anda
 {
    Serial.println("MUHAMMAD HUSNUL SABIL");
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("MUHAMMAD HUSNUL");
    lcd.setCursor(0,1); lcd.print("     SABIL");
    delay(2000); //Jeda waktu perulagan seama 1000 mili deti
    digitalWrite (buzzer,HIGH);
    delay(500);
    digitalWrite (buzzer,LOW);
  }else if (content == "8A375A1A"){
    Serial.println("RFID ARDUINO");
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print(" RFID");
    lcd.setCursor(0,1); lcd.print("ARDUINO");
    delay(2000);
    digitalWrite (buzzer,HIGH);
    delay(500);
    digitalWrite (buzzer,LOW);
    }else if (content == "EABDCF80"){
    Serial.println("GANTUNGAN ARDUINO");
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("GANTUNGAN");
    lcd.setCursor(0,1); lcd.print(" ARDUINO");
    delay(2000);
    digitalWrite (buzzer,HIGH);
    delay(500);
    digitalWrite (buzzer,LOW);
    }else{
      Serial.println("Kartu Belum Terdaftar!");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(0,0); lcd.print("KARTU BELUM");
      lcd.setCursor(0,1); lcd.print("TERDAFTAR");
      delay(2000);
      digitalWrite (buzzer,HIGH);
      delay(250);
      digitalWrite (buzzer,LOW);
      delay(250);
      digitalWrite (buzzer,HIGH);
      delay(250);
      digitalWrite (buzzer,LOW);
      delay(250);
      digitalWrite (buzzer,HIGH);
      delay(250);
      digitalWrite (buzzer,LOW);
      delay(250);
      digitalWrite (buzzer,HIGH);
      delay(250);
      }
        Serial.println("Tempelkan Kartu!");
        lcd.clear(); //Untuk Menghapus karakter pada LCD
        digitalWrite (buzzer,LOW);
        delay(500); //Jeda waktu perulagan seama 500 mili detik
}
