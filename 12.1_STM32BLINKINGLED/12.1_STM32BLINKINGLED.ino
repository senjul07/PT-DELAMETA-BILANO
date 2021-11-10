//inisialisasi pembuatan variable
int M = PA4;
int Y = PA3;
int G = PA2;
int button1 = PA5;
int button2 = PA6;
int button3 = PA7;
 
//menentukan fungsionalitas dari pin
void setup()
{
  Serial.begin(9600);
  pinMode (PA7, INPUT);
  pinMode (PA6, INPUT);
  pinMode (PA5, INPUT);
  pinMode (PA4, OUTPUT);
  pinMode (PA3, OUTPUT);
  pinMode (PA2, OUTPUT);
}
 
 //Program yang akan dijalankan berulang-ulang
void loop(){
  int tombol1= digitalRead(button1);
  int tombol2= digitalRead(button2);
  int tombol3= digitalRead(button3);
  
if(tombol1 == 1){
  //Print ke Serial Monitor
  Serial.print("LAMPU MERAH MENYALA");
  Serial.print(tombol1);
  Serial.println();
  digitalWrite(PA4,HIGH);
}else{
  Serial.print("LAMPU MERAH MATI");
  Serial.print(tombol1);
  Serial.println();
  digitalWrite(PA4,LOW);

  
}if(tombol2 == 1){
  Serial.print("LAMPU KUNING MENYALA");
  Serial.print(tombol2);
  Serial.println();
  digitalWrite(PA3,HIGH);
}else{
  Serial.print("LAMPU KUNING MATI");
  Serial.print(tombol2);
  Serial.println();
  digitalWrite(PA3,LOW);

  
}if(tombol3 == 1){
  Serial.print("LAMPU HIJAU MENYALA");
  Serial.print(tombol3);
  Serial.println();
  digitalWrite(PA2,HIGH);
}else{
  Serial.print("LAMPU HIJAU MATI");
  Serial.print(tombol3);
  Serial.println();
  digitalWrite(PA2,LOW);
}


}
