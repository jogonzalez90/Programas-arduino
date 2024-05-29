/*
   En este ejemplo se demostrara el uso de la libreria para poder cambiar el texto de las etiquetas del software

   Autor:Paul Santana
*/
#include <PolSerial.h>// se debe incluir la libreria 
PolSerial p;// instanciamos un objeto "Nota solo es necesario instanciar 1"
void setup() {
  Serial.begin(9600);//Inicializamos el puerto Serial "Nota Debe coincidir con la del programa"
  pinMode(13, OUTPUT);
  // en este caso cambiamos el nombre de las 4 etiquetas   Nota se debe presionar el boton de reset para que se realice los cambios
  p.etiqueta1("Dato1:1");
  p.etiqueta2("Dato1:2");
  p.etiqueta3("Dato1:3");
  p.etiqueta4("Dato1:4");
}
//METODOS Para poder cambiar el texto de las etiquetas

// este metodo recive como parametro un string que correponde al texto que queremos que tenga una etiqueta en especifico
//etiqueta1("Dato1Nuevo:1");
//etiqueta2("Dato2Nuevo:2");
//etiqueta3("Dato3Nuevo:3");// <-- en este caso le cambiamos el nombre a la etiqueta 3 por "dato3Nuevo:3"
//etiqueta4("Dato4Nuevo:4");
void loop() {

}
