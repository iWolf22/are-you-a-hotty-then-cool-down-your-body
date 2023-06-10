#include <LiquidCrystal.h>
#include <IRremote.h>
#include <dht.h>

dht DHT;
IRrecv IR(7);
int motorPin = 9;

#define DHT11_PIN A0

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  IR.enableIRIn();
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  analogWrite(motorPin, 255);
}

void loop() {

  DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  if (IR.decode()) {
    lcd.setCursor(0,0);
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    lcd.print(IR.decodedIRData.decodedRawData, HEX);
    delay(1000);
    IR.resume();
  }
  
}
