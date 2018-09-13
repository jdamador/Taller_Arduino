#define pinLed1 8
#define pinLDR 0
int valorLDR = 0;
const int valor_limite=200;
void setup() {      
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLDR,INPUT);
  Serial.begin(9600);
}
void loop ()  //Configuracion de los valores del LDR
{
  valorLDR = analogRead(pinLDR);
  Serial.print(valorLDR);
  Serial.println("LUZ");
  delay(300);
  if(valorLDR<=valor_limite){
    digitalWrite(pinLed1,HIGH);
  }else{
    digitalWrite(pinLed1,LOW);
  }
}
