// Encendido y apagado de 3 LEDs
int leds[] ={9,8,7};
void setup() { // Configura las SALIDAS
  for(int i=0;i<3;i++){
    pinMode(leds[i],OUTPUT);
  }
 
}
void loop() { //Bucle de Funcionamiento
  for(int i=0;i<3,i++){
    digitalWrite(leds[i],HIGH);
    delay(1000);
    digitalWrite(leds[i],LOW);
    delay(1000);
  }
}
