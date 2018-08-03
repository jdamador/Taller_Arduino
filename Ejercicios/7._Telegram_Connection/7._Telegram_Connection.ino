/*Ejemplo de conexion con un Bot de Telegram*/

//Definicion de variables globales
const int LED_VERDE=13 ;
const int LED_ROJO =10;
const int LED_AMARILLO= 9;
unsigned int dato; //Dato al que no se le ha asignado un valor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Se inicializa con una velocidad 9600
  pinMode(LED_VERDE,OUTPUT);
  pinMode(LED_AMARILLO,OUTPUT);
  pinMode(LED_ROJO,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly
  while(Serial.available()>0){ //Si la conexión es permitida entrar
    dato= Serial.read(); //Lectura del puerto serial
    /*Bloque de decisiones en el cual se analiza cual instución ejecutar*/
    if(dato=='G')digitalWrite(LED_VERDE,HIGH);
    if(dato=='g')digitalWrite(LED_VERDE,LOW);
    if(dato=='Y')digitalWrite(LED_AMARILLO,HIGH);
    if(dato=='y')digitalWrite(LED_AMARILLO,LOW);
    if(dato=='R')digitalWrite(LED_ROJO,HIGH);
    if(dato=='r')digitalWrite(LED_ROJO,LOW);
    if(dato=='T'){
      digitalWrite(LED_VERDE,HIGH);
      digitalWrite(LED_AMARILLO,HIGH);
      digitalWrite(LED_ROJO,HIGH);
    }
    if(dato=='t'){
      digitalWrite(LED_VERDE,LOW);
      digitalWrite(LED_ROJO,LOW);
      digitalWrite(LED_AMARILLO,LOW);
    }
  }

}
