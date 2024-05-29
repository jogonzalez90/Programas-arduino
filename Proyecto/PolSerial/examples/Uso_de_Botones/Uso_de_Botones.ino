/*
 * En este ejemplo se demostrara el uso de la libreria para poder hacer uso de los botones del software
 * 
 * Autor:Paul Santana
 */
#include <PolSerial.h>// se debe incluir la libreria 
PolSerial p;// instanciamos un objeto "Nota solo es necesario instanciar 1"
void setup() {
  Serial.begin(9600);//Inicializamos el puerto Serial "Nota Debe coincidir con la del programa"
  pinMode(13,OUTPUT);
}
//METODOS 
//Estos metodos Devuelven un valor bool
// true si el boton fue presionado
// false si no fue presionado

// el btn1Presionado es cuando es un presionado normal del boton del software
//btn1Presionado()
//btn2Presionado()
//btn3Presionado()
//btn4Presionado()



void loop() {
  p.escuchar();// este metodo siempre debe ir en el Loop

/*
 * Si el boton1 fue presionado se enciende el pin 13
 */
  if(p.btn1Presionado())digitalWrite(13,1);

/*
 * Si el boton2 fue presionado se apaga el pin 13
 */
  if(p.btn2Presionado())digitalWrite(13,0);

}
