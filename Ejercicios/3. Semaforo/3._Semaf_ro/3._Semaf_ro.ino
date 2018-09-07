// Encendido y apagado de 3 LEDs
int ledPin1 = 10; // Define las salidas de los LED´s
int ledPin2 = 9;
int ledPin3 = 8;
void setup() { // Configura las SALIDAS
  pinMode(ledPin1, OUTPUT); // declarar LEDs como SALIDAS
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
 
}
void loop() { //Bucle de Funcionamiento
  digitalWrite(ledPin1, HIGH); // Apaga y enciende los leds cada 200 ms
  delay(200);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(200);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(200);
  digitalWrite(ledPin3, LOW);
}
