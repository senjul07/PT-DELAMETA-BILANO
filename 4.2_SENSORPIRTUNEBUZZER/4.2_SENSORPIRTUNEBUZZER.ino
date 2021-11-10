int sensorPIR = 5;

void setup(){  }

    void DO1() {tone(sensorPIR,50);}
    void RE1() {tone(sensorPIR,100);}
    void MI1() {tone(sensorPIR,150);}
    void FA1() {tone(sensorPIR,200);}
    void SOL1() {tone(sensorPIR,250);}
    void LA1() {tone(sensorPIR,300);}
    void SI1() {tone(sensorPIR,350);}
    
    
    void DO() {  tone(sensorPIR, 400); }  // fungsi variabel untuk nada DO
    void RE() {  tone(sensorPIR, 450); }  // fungsi variabel untuk nada RE
    void MI() {  tone(sensorPIR, 500); }   // fungsi variabel untuk nada MI
    void FA() {  tone(sensorPIR, 550); }   // fungsi variabel untuk nada FA
    void SOL() {  tone(sensorPIR, 600); }   // fungsi variabel untuk nada SOL
    void LA() {  tone(sensorPIR, 650); }   // fungsi variabel untuk nada LA
    void SI() {  tone(sensorPIR, 700); }   // fungsi variabel untuk nada SI
    void DOO() {  tone(sensorPIR, 750); }       // fungsi variabel untuk nada DOO
    void REE() {  tone(sensorPIR, 800); }   // fungsi variabel untuk nada REE
    void MII() {  tone(sensorPIR, 850); }   // fungsi variabel untuk nada MII
    void FAA() { tone(sensorPIR,875);}
    void SOOL() { tone(sensorPIR, 880);}
    void LAA() { tone(sensorPIR, 885); }
    void SII() { tone(sensorPIR,890);} 
    void DIAM() {  noTone(sensorPIR); }        // fungsi variabel untuk nada DIAM
    



void loop(){
  DO1();delay(500);
  RE1();delay(500);
  MI1();delay(500);
  FA1();delay(500);
  SOL1();delay(500);
  LA1();delay(500);
  SI1();delay(500);
  DO();delay(500);
  RE();delay(500);
  MI();delay(500);
  FA();delay(500);
  SOL();delay(500);
  LA();delay(500);
  SI();delay(500);
  DOO();delay(500);
  REE();delay(500);
  MII();delay(500);
  FAA();delay(500);
  SOOL();delay(500);
  LAA();delay(500);
  SII();delay(500);
}
