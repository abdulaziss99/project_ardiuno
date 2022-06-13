#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define mulai digitalRead(13)==0 //untuk start
#define cancel digitalRead(12)==0 //untuk cancel
#define tambah digitalRead(16)==0 //untuk menambah waktu
#define kurang digitalRead(17)==0 //untuk mengurangi waktu

LiquidCrystal_I2C lcd(0x20,4,20); //ukuran layar


char state;
int cd;
long millisSebelum;
int hitungMulai;
unsigned long milis;

void setup() {
 lcd.init();
 pinMode(13, INPUT_PULLUP);
 pinMode(12, INPUT_PULLUP);
 pinMode(16, INPUT_PULLUP);
 pinMode(17, INPUT_PULLUP);
 

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

}
