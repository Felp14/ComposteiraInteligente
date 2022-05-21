
#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define boia 8
#define soloumid  A3

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(boia, INPUT);
  pinMode(soloumid, INPUT);
  
}

void loop() {
  
  int umidade = DHT.humidity;
  int temperatura = DHT.temperature;
  int val = analogRead(soloumid);

  DHT.read11(A1);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Composteira");
  lcd.setCursor(1,1);
  lcd.print("Inteligente!");

  delay(5000);
    
    if( DHT.temperature < 23) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(DHT.temperature);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Abaixo!!!");
    }
    else if( DHT.temperature >= 23 && DHT.temperature < 30 )
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(DHT.temperature);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Bom.");
    }
    else if( DHT.temperature >= 30)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temp. M.:");
        lcd.print(DHT.temperature);
        lcd.write(B11011111);
        lcd.print("C");
        lcd.setCursor(1,1);
        lcd.print("Status: Acima!!!");
    }
     delay(5000);
  
    if( DHT.humidity < 80) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(DHT.humidity);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Abaixo!!!");
    }
    else if( DHT.humidity >= 80 && DHT.humidity < 90 )
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(DHT.humidity);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Bom.");
    }
    else if( DHT.humidity >= 90)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Umid. M.:");
        lcd.print(DHT.humidity);
        lcd.print("%");
        lcd.setCursor(1,1);
        lcd.print("Status: Acima!!!");
    }
  delay(5000);

    if ((val > 700 && val <= 850) || (val >= 200 && val < 400))
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Status do Humus:");
        lcd.setCursor(1,1);
        lcd.print("Umidade Moderada!");
    }else if (val >= 400 && val <= 700)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Status do Humus:");
        lcd.setCursor(1,1);
        lcd.print("Umidade Boa!");
    }else if ((val >= 0 && val < 200) || (val > 850 && val <= 1024))
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Status do Humus:");
        lcd.setCursor(1,1);
        lcd.print("Umidade Baixa!!!");
    }

    delay(5000);
 
    if(digitalRead(boia) == 1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nivel do Chorume");
        lcd.setCursor(1,1);
        lcd.print("Status: Cheio!");
        
    }else if(digitalRead(boia) == 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nivel do Chorume");
        lcd.setCursor(1,1);
        lcd.print("Status: OK!");
    }
  delay(5000); 
} 
