// Variables
int switchState = 0;
int verde = 3;

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT); // Pulsador
}

void loop() {
  switchState = digitalRead(2);

  // Si el pulsador NO está presionado
  if (switchState == LOW) {
    digitalWrite(verde, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } 
  else {
    // Si el pulsador ESTÁ presionado
    digitalWrite(verde, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(200);
  }
}
