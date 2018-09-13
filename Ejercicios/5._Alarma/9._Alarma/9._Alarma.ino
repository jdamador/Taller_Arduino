#include <NewPing.h>

#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 400 //Distancia maxima que queremos en centimetros.
#define BUZZER 11
#define LED_PIN 13
NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

int distanceCM;
int safeDistance=200;
void setup() {
  Serial.begin(9600); // Iniciamos la comunicación serial
  pinMode(BUZZER, OUTPUT); //   Buzzer como salida
  pinMode(LED_PIN, OUTPUT); //   Led como salida
}

void loop() {
  delay(100);
  distanceCM=sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(distanceCM); 
  Serial.println(" cm"); 
  if (distanceCM <= safeDistance){
     for (int i=0; i<=5; i++) {
        tone(BUZZER, 540,3000);
        delay(200);
        tone(BUZZER, 740,3000);
        delay(200);
        digitalWrite(LED_PIN, HIGH);
        delay(30);
        digitalWrite(LED_PIN, LOW);
    }  
    digitalWrite(LED_PIN, HIGH);
  }else{
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_PIN, LOW);
  }
}

