//Library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Li          = 17;
int Lii         = 1; 
int Ri          = -1;
int Rii         = -1;



void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(5,0); lcd.print("WELCOME");
 lcd.setCursor(0,1); lcd.print("MANTAP");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(1,0); lcd.print("MANCING MANIA");
 lcd.setCursor(0,1); lcd.print("SENDY JULIANSYAH");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
}



















             //scroll
//String Scroll_LCD_Left(String StrDisplay){
//  String result;
//  String StrProcess = "                " + StrDisplay + "                ";
//  result = StrProcess.substring(Li,Lii);
//  Li++;
//  Lii++;
//  if (Li>StrProcess.length()){
//    Li=16;
//    Lii=0;
//  }
//  return result;
//}
//
//void Clear_Scroll_LCD_Left(){
//  Li=16;
//  Lii=0;
//}
////----------------------------------
//String Scroll_LCD_Right(String StrDisplay){
//  String result;
//  String StrProcess = "                " + StrDisplay + "                ";
//  if (Rii<1){
//    Ri  = StrProcess.length();
//    Rii = Ri-16;
//  }
//  result = StrProcess.substring(Rii,Ri);
//  Ri--;
//  Rii--;
//  return result;
//}
//
//void Clear_Scroll_LCD_Right(){
//  Ri=-1;
//  Rii=-1;
//}
