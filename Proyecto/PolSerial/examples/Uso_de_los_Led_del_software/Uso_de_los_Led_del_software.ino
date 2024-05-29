/*
 * En este ejemplo se demostrara el uso de la libreria para poder Usar los led del software
 * 
 * Autor:Paul Santana
 */
#include <PolSerial.h>// se debe incluir la libreria 
PolSerial p;// instanciamos un objeto "Nota solo es necesario instanciar 1"
void setup() {
  Serial.begin(9600);//Inicializamos el puerto Serial "Nota Debe coincidir con la del programa"
  pinMode(13,OUTPUT);
}
//METODOS Para poder encender los LED que se muestran en el software

// con estos metodos podemos encender los led correspondientes
//led1Encender();
//led2Encender();
//led3Encender();
//led4Encender();

// con estos metodos podemo apagar los led correspondientes
//led1Apagar();
//led2Apagar();
//led3Apagar();
//led4Apagar();


void loop() {
  p.escuchar();// este metodo siempre debe ir en el Loop

/*
 * Si el boton1 fue presionado se enciende el led1 del software
 */
  if(p.btn1Presionado())p.led1Encender();

/*
 * Si el boton2 fue presionado se apaga el led1 del software
 */
  if(p.btn2Presionado())p.led1Apagar();

}
