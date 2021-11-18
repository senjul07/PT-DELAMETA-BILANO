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

//Inisialisasi pembuatan variable
#define SS_PIN  PB11 //SDA
#define RST_PIN PB10  //RESET

MFRC522 mfrc522(SS_PIN, RST_PIN); 


void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
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
  if (content == "ACB08F33") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("SENDY JULIANSYAH");
    delay(2000);
  }else{
    Serial.println("KARTU BELUM TERDAFTAR");
  }
  Serial.println("TEMPELKAN KARTU!");
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
