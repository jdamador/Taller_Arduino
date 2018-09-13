//Práctica: encender y apagar un LED con un botón pulsador
const int led=9; 
const int boton=8; 

int val=0; //Almacena el estado del pulsador
void setup(){
  pinMode(led,OUTPUT); //Se establece el pin como una señal de salida.
  pinMode(boton,INPUT); //Se establece el pin como una señal de entrada.
}

void loop(){
  val = digitalRead(boton); //Hace una lectura del estado del botón.
  if(val==HIGH){ //Si esta presionado se enciende el led.
    digitalWrite(led,HIGH);
  }else{ //Si no, entoces se apaga.
    digitalWrite(led,LOW);
  }
}

