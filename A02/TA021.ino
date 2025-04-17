// C++ code

const int pinred = 11;
const int pinblue = 10;
const int pingreen = 9;

const int pinputLDR_red = A0;  // Corrected from pinputLRD_red
const int pinputLDR_green = A1;
const int pinputLDR_blue = A2;

int valuesensor_red = 0;
int valuesensor_green = 0;
int valuesensor_blue = 0;

int valuered = 0;
int valuegreen = 0;
int valueblue = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pingreen, OUTPUT);
  pinMode(pinred, OUTPUT);
  pinMode(pinblue, OUTPUT);
}

void loop()
{
  valuesensor_red = analogRead(pinputLDR_red);  // Corrected variable name
  delay(5);
  valuesensor_green = analogRead(pinputLDR_green);
  delay(5);
  valuesensor_blue = analogRead(pinputLDR_blue);  // Corrected variable name

  Serial.print("Mapa de valores sensores\t Rojo: ");
  Serial.print(valuesensor_red);
  Serial.print("\t Verde: ");
  Serial.print(valuesensor_green);
  Serial.print("\t Azul: ");
  Serial.print(valuesensor_blue);

  valuered = valuesensor_red / 4;
  valuegreen = valuesensor_green / 4;
  valueblue = valuesensor_blue / 4;  // Corrected variable name

  Serial.print("Mapa de valores \t Rojo: ");
  Serial.print(valuered);
  Serial.print("\t Verde: ");
  Serial.print(valuegreen);
  Serial.print("\t Azul: ");
  Serial.print(valueblue);

  analogWrite(pinred, valuered); 
  analogWrite(pingreen, valuegreen);
  analogWrite(pinblue, valueblue);
}
