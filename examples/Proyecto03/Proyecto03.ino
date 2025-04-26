const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);  // Abrir el puerto serie

  // Configura los pines digitales 2, 3 y 4 como salidas
  for (int pinNumber=2; pinNumber<5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW); // Inicialmente apagados
  }
}

void loop() 
{
int sensorVal=analogRead(sensorPin);
Serial.print("Valor del sensor: ");
Serial.print(sensorVal);
// Convertir la lectura ADC a tensión
float voltage = (sensorVal/1024.0)*5.0;
Serial.print(", Voltios: ");
Serial.print(voltage);
// Convertir la tensión en temperatura (grados Celsius)
float temperature=(voltage-0.5)*100;
Serial.print(", Grados C: ");
Serial.println(temperature);

  // Control de LEDs según temperatura
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(100);
}
