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
  analogWrite(motorPin, 0);
  pinMode(A2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
}

void loop() {

  if (Serial.available() > 0) {
    String receivedString = "";

    while(Serial.available() > 0) {

      receivedString += char(Serial.read());

    }

    if (receivedString == "1") {
      redLed();
      Serial.println("");
    }
    else if (receivedString == "2") {
      yellowLed();
      Serial.println("Test 2");
    }
    else if (receivedString == "3") {
      greenLed();
      Serial.println("");
    }
    else if (receivedString == "4") {
      blueLed();
      Serial.println("");
    }
    else if (receivedString == "5") {
      whiteLed();
      Serial.println("");
    }
    else {
      Serial.println("404 Error");
    }
  }

  lcd.setCursor(13,0);
  lcd.println("   ");

  DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature - 2);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  if (IR.decode()) {
    lcd.setCursor(0,0);
    Serial.print("Hex Value: ");
    Serial.print(IR.decodedIRData.decodedRawData, HEX);
    Serial.print(" - ");

    bool null = true;

    if (IR.decodedIRData.decodedRawData == 0xE916FF00) {
      redLed();
    }
    else if (IR.decodedIRData.decodedRawData == 0xF30CFF00) {
      yellowLed();
    }
    else if (IR.decodedIRData.decodedRawData == 0xE718FF00) {
      greenLed();
    }
    else if (IR.decodedIRData.decodedRawData == 0xA15EFF00) {
      blueLed();
    }
    else if (IR.decodedIRData.decodedRawData == 0xF708FF00) {
      whiteLed();
    }
    else {
      Serial.print("Button: Null - Fan Speed: Null");
    }

    Serial.println();

    delay(1500);
    IR.resume();
  }
}

void redLed() {
  analogWrite(motorPin, 0);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  Serial.print("Button: 0 - Fan Speed: 0%");
}

void yellowLed() {
  analogWrite(motorPin, 160);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  Serial.print("Button: 1 - Fan Speed: 50%");
}

void greenLed() {
  analogWrite(motorPin, 200);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  Serial.print("Button: 2 - Fan Speed: 75%");
}

void blueLed() {
  analogWrite(motorPin, 255);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  Serial.print("Button: 3 - Fan Speed: 100%");
}

void whiteLed() {
  if (DHT.temperature - 2 <= 18) {
    analogWrite(motorPin, 0);
  }
  else if (18 < DHT.temperature - 2 <= 20) {
    analogWrite(motorPin, 160);
  }
  if (20 < DHT.temperature - 2 <= 22) {
    analogWrite(motorPin, 200);
  }
  else {
    analogWrite(motorPin, 255);
  }
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  Serial.print("Button: 4 - Fan Speed: Temp");
}
