#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;


void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Composteira");
  lcd.setCursor(1,1);
  lcd.print("Inteligente!");

  DHT.read11();
}

void loop() {
  
  int umidade = DHT.humidity;
  int temperatura = DHT.temperature;

  teste_temperatua()
  teste_umidade()

  void teste_temperatura{
    if( DHT.temperature < 23) {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(temperatura);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Abaixo!!!");
    }
    else if( DHT.temperature >= 23 && DHT.temperature < 30 )
    {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(temperatura);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Bom.");
    }
    else if( DHT.temperature >= 30)
    {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(temperatura);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Acima!!!");
    }

   void teste_umidade{
    if( DHT.humidity < 80) {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(umidade);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Abaixo!!!");
    }
    else if( DHT.humidity >= 80 && DHT.humidity < 90 )
    {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(umidade);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Bom.");
    }
    else if( DHT.humidity >= 90)
    {
        lcd.clear
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(umidade);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Acima!!!");
    }
    
  }

  
} 
