#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Composteira");
  lcd.setCursor(1,1);
  lcd.print("Inteligente!");
}

void loop() {
  char teste = Serial.read();

  if(teste == 'A'){
    lcd.setCursor(0,0);
    lcd.print("Temp. M.: 26 C");
    lcd.setCursor(0,1);
    lcd.print("Status: ok!");
  }
} 
