#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define mulai digitalRead(13)==0 //untuk start
#define cancel digitalRead(12)==0 //untuk cancel
#define tambah digitalRead(11)==0 //untuk menambah waktu
#define kurang digitalRead(10)==0 //untuk mengurangi waktu


LiquidCrystal_I2C lcd(0x27,20,4); //ukuran layar

int relay;
int set;
char state;
int cd;
long millisSebelum;
int hitungMulai;
unsigned long milis;
bool kondisi_relay=0;
bool t_down;
int set_detik;
int set_menit;


void setup() {
 lcd.init();
 pinMode(13, INPUT_PULLUP);
 pinMode(12, INPUT_PULLUP);
 pinMode(11, INPUT_PULLUP);
 pinMode(10, INPUT_PULLUP);

 pinMode(relay, OUTPUT);

 Serial.begin(9600);
}

void print_time(){
  set_detik = set_detik - 1;
  if (set_detik < 0) {
    set_detik = 59;
    set_menit = set_menit - 1;
  }
}

void loop() {
  if(millis() > millisSebelum + 100){
   millisSebelum = millis();
   if (hitungMulai ==60){
    cd--;
    lcd.clear();
    if(cd ==0){
      hitungMulai=0;
    }
   }
  }

  
  switch(state) {
    case 0:
    lcd.setCursor(0,0);
    lcd.print("Countdown = ");
    lcd.setCursor(11,0);
    lcd.print(cd);

    if(mulai){
      state = 60;
      delay(100);
      lcd.clear();
    }

    if(mulai){
      hitungMulai=60;
      delay(100);
    }
   break;

   case 1:
   lcd.setCursor(0,0);
   lcd.print("cd = ");
   lcd.setCursor(6,0);
   lcd.print(cd);
  
    if(tambah){
      cd++;
      delay(100);
      lcd.clear();
    }
    else if(kurang){
      cd--;
      delay(100);
      lcd.clear();
    }

    if(mulai){
      state=60;
      delay(100);
      lcd.clear();
    }
    else if(cancel){
      state=0;
      delay(100);
      lcd.clear();
      cd=0;
    }
    
   break;
   
  }

  lcd.setCursor(0,0);
  if (set == 0) {
    lcd.print(" Timer ");
  }
  if (set == 1) {
    lcd.print(" Set Time SS ");
  }
  if (set == 3 ) {
    lcd.print(" Set Timer HH ");
  }

  lcd.print(set_menit);
  lcd.print(":");
  if (set_detik <= 9) {
    lcd.print("0");
  }
  lcd.print(set_detik);
  lcd.print(" ");

  if (set_detik == 0 && set_menit == 0 && kondisi_relay == 1) {
    kondisi_relay = 0;
    digitalWrite(relay,LOW);
  }
  
  if (kondisi_relay = 1){
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(relay, LOW);
  }
  delay(1);
}
