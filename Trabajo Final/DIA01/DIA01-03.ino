#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ldrPin = A0;
const int backlightPin = 9; // pin PWM para controlar brillo
int ldrValue;

void setup() {
  lcd.begin(16, 2);
  pinMode(backlightPin, OUTPUT);
  lcd.print("Iniciando...");
  delay(1000);
  lcd.clear();
}

void loop() {
  ldrValue = analogRead(ldrPin);
  lcd.clear();
  lcd.setCursor(0, 0);

  if (ldrValue > 700) {
    lcd.print("DIA SOLEADO");
    analogWrite(backlightPin, 255); // brillo máximo
  } else {
    lcd.print("DIA NUBLADO");
    analogWrite(backlightPin, 100); // brillo bajo
  }

  delay(1000);
}
