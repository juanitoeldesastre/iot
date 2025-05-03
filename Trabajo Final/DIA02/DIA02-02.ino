int rojo = 4;
int amarillo = 3;
int verde = 2;

const int segmentos[7] = {5, 6, 7, 8, 9, 10, 11};

// Dígitos del 0 al 9 para el display 
// ánodo común ++: 0 = encendido 1 = apagado
const byte digitos[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {0,1,1,0,1,1,1}, // 1
  {1,0,0,0,0,1,0}, // 2
  {0,0,1,0,0,1,0}, // 3
  {0,1,1,0,1,0,0}, // 4
  {0,0,1,1,0,0,0}, // 5
  {0,0,0,1,0,0,0}, // 6
  {0,1,1,0,0,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,1,0,0,0,0}  // 9
};

void setup() {
  Serial.begin(9600);

  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
}

void loop() {
  // Luz roja
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
  Serial.println("Luz Roja encendida");
  contarSegundos(15);

  // Luz verde
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, HIGH);
  Serial.println("Luz Verde encendida");
  contarSegundos(15);

  // Luz amarilla
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, LOW);
  Serial.println("Luz Amarilla encendida");
  contarSegundos(3);
}

// Muestra un número (0-9) en el display
void mostrarNumero(int numero) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], digitos[numero][i]);
  }
}

// Función de cuenta regresiva
void contarSegundos(int tiempo) {
  for (int i = tiempo; i >= 0; i--) {
    mostrarNumero(i % 10);
    Serial.print("Segundos restantes: ");
    Serial.println(i);
    delay(1000);
  }
}
