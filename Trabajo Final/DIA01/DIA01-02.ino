int pir = 2;
int buzzer = 8; 

void setup() {
  pinMode(pir, INPUT); 
  pinMode(buzzer, OUTPUT); 
  
  Serial.begin(9600);        // Iniciar la comunicación serie
}

void loop() {
  int estadoPIR = digitalRead(pir);  // Leer el estado del sensor

  if (estadoPIR == HIGH) {    // Si se detecta movimiento
    digitalWrite(buzzer, HIGH);  // Activar el zumbador
    Serial.println("Movimiento detectado!");
  } else {                   // Si no se detecta movimiento
    digitalWrite(buzzer, LOW);   // Apagar el zumbador
    Serial.println("No hay movimiento.");
  }
 
  delay(500);
}
