/*/
 * A9  to RX USBTTL
 * A10 to TX USBTTL
 * PB0 to RESET
 * PB1 to SDA / SS
 * PA5 to CLK
 * PA6 to MISO
 * PA7 to MOSI
 * Tekan Reset sebelum Upload
 * Pilih Board    :fake STM32F10 
 * Upload methode :Serial
 */
//Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//Inisialisasi pembuatan variable
#define SS_PIN  PB9 //SDA
#define RST_PIN PB0  //RESET
int outServo=PA0; //Pin untuk Servo
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;
int buzzer = PA2;
int IR = PA1;
int kunci = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN); 


void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  pinMode(buzzer,OUTPUT);
  pinMode(IR,INPUT);

  //LCD
  lcd.begin();
  myservo.attach(outServo);

  buzzerBunyi();
  Serial.println("Tempelkan Kartu!");
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if(content == "A-A8-90-15"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(4,0); lcd.print("BERHASIL!");
      delay(1000);
      Serial.println("Silahkan Masuk");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
      myservo.write(180); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      kunci = 1;

      
    }else if (content == "5A-2E-E7-80"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(4,0); lcd.print("BERHASIL!");
      delay(1000);
      Serial.println("Silahkan Masuk");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
      myservo.write(180); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      kunci = 1;

      
    }else{
      Serial.println("GAGAL");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(5,0); lcd.print("GAGAL!");
      buzzerBunyiGagal();
      Serial.println("Tempelkan Kartu!");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
    }
    IRnyala();
  }

void IRnyala(){
  int bacaIR=digitalRead(IR);
if (bacaIR == 0 and kunci == 1){
    buzzerBunyi2();
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
    Serial.println("PALANG TERTUTUP");
    Serial.println("");
    delay(1000);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
    Serial.println("Tempelkan Kartu!");
    myservo.write(90); //0-180
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
