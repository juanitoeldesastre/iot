#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

// Configuración del LCD sin I2C (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Configuración del teclado 4x4
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {A4, A5, 8, 9};   

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo servo;

String password = "1234";  // Contraseña definida
String input = "";         // Entrada del usuario
int attempts = 0;
bool locked = false;
unsigned long lockTime = 0;

void setup() {
  servo.attach(10);
  servo.write(0); // Posición inicial
  lcd.begin(16, 2);
  lcd.print("Sistema Listo");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (locked) {
    if (millis() - lockTime >= 30000) { // Desbloquear después de 30s
      locked = false;
      attempts = 0;
      lcd.clear();
      lcd.print("Sistema Listo");
      delay(2000);
      lcd.clear();
    } else {
      return;
    }
  }

  char key = keypad.getKey();
  if (key) {
    if (key == '#') { // Confirmar contraseña
      if (input == password) {
        lcd.clear();
        lcd.print("Acceso otorgado");
        servo.write(90);
        delay(3000);
        servo.write(0);
        input = "";
        attempts = 0;
        lcd.clear();
      } else {
        attempts++;
        lcd.clear();
        lcd.print("Clave errada");
        delay(2000);
        lcd.clear();
        input = "";
        if (attempts >= 3) {
          lcd.print("Bloqueo x 30s");
          lockTime = millis();
          locked = true;
        }
      }
    } else if (key == '*') { // Borrar entrada
      input = "";
      lcd.clear();
    } else {
      if (input.length() < 4) {
        input += key;
        lcd.setCursor(input.length() - 1, 0);
        lcd.print('*');
      }
    }
  }
}
