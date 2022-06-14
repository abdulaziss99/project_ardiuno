#include <Wire.h>
#include <OneButton.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>


#define mulai digitalRead(13)==0
#define reset digitalRead(12)==0
#define tambah digitalRead(11)==0
#define kurang digitalRead(10)==0

LiquidCrystal_I2C lcd(0x27,20,4);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
