/*
 * En este ejemplo se demostrara el uso de la libreria para poder cambiar el nombre de los botones de la interfaz 
 * 
 * Autor:Paul Santana
 */
#include <PolSerial.h>// se debe incluir la libreria 
PolSerial p;// instanciamos un objeto "Nota solo es necesario instanciar 1"
void setup() {
  Serial.begin(9600);//Inicializamos el puerto Serial "Nota Debe coincidir con la del programa"
  pinMode(13,OUTPUT);
  // en este caso cambiamos los botones 
  
  //                   "Nota se recomienda cambiar el nombre en el metodo setup Ya que ese metodo se ejecuta al inicio del programa"
  p.btn1Nombrar("btn1");// el boton 1 tendra el texto que le pasamos como parametro en este caso se llama btn1
  p.btn2Nombrar("btn2");
  p.btn3Nombrar("btn3");
  p.btn4Nombrar("btn4");
}
//METODOS Para cambiar los nombres de los botones


// este metodo recive como parametro un String que corresponde al nombre que le queremos poner al boton
//btn1Nombrar("Escribir el nombre del boton")
//btn2Nombrar("Escribir el nombre del boton")
//btn3Nombrar("Escribir el nombre del boton")
//btn4Nombrar("Escribir el nombre del boton")


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
