// definimos los pines y variables a utilizar
const int trigPin = 9;
const int echoPin = 10;
//const int buzzer = 11;
const int ledPin = 13;
int i;

// definimos l variable
long duration;
int distance;
int safetyDistance;

void setup() {
pinMode(trigPin, OUTPUT); //  trigPin como Output
pinMode(echoPin, INPUT); //    echoPin como entrada Input
//pinMode(buzzer, OUTPUT); //   Buzzer como salida
pinMode(ledPin, OUTPUT); //   Led como salida
Serial.begin(9600); // Iniciamos la comunicación serial
}

void loop() {
// inicializar trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// trigPin activo por 10 micro segundos
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Leemos echoPin, retornamos el tiempo de viaje de la onda de sonido en microsegundos
duration = pulseIn(echoPin, HIGH);

// Calculamos la distancia
distance= duration*0.034/2;

safetyDistance = distance;
// avaluamos el rango de acercamiento
if (safetyDistance <= 10){
  for (i=0; i<=5; i++) {
   //tone(buzzer, 540,3000);
   delay(200);
   //tone(buzzer, 740,3000);
   delay(200);
   digitalWrite(ledPin, HIGH);
   delay(30);
   digitalWrite(ledPin, LOW);
  }  

  digitalWrite(ledPin, HIGH);
}
else{
 // digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Imprimimos la distancia en el monitor serial
Serial.print("Distance: ");
Serial.println(distance);
}

