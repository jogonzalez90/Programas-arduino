/*
   Autor:Paul Alejandro Santana Guzmán
   04/11/2020
*/
class PolSerial {
  private:
    bool btn1Click, btn2Click, btn3Click, btn4Click;
    bool btn1Double, btn2Double, btn3Double, btn4Double;
    String btn1Nombre, btn2Nombre, btn3Nombre, btn4Nombre;
  public:
    PolSerial();
    void escuchar();
    bool btn1Presionado();
    bool btn2Presionado();
    bool btn3Presionado();
    bool btn4Presionado();

    bool btn1PresionadoDoble();
    bool btn2PresionadoDoble();
    bool btn3PresionadoDoble();
    bool btn4PresionadoDoble();

    void led1Encender();
    void led2Encender();
    void led3Encender();
    void led4Encender();

    void led1Apagar();
    void led2Apagar();
    void led3Apagar();
    void led4Apagar();

    void btn1Nombrar(String nombre);
    void btn2Nombrar(String nombre);
    void btn3Nombrar(String nombre);
    void btn4Nombrar(String nombre);

    void etiqueta1(String nombre);
    void etiqueta2(String nombre);
    void etiqueta3(String nombre);
    void etiqueta4(String nombre);
    void mostrarNombreBoton();
};
PolSerial::PolSerial() {}
void PolSerial::escuchar() {
  String datoRecivido;
  if (Serial.available()) {
    datoRecivido = Serial.readStringUntil('\n');
    if (datoRecivido == "btn1click") {
    btn1Click = true;
  } else if (datoRecivido == "btn2click") {
    btn2Click = true;
  } else if (datoRecivido == "btn3click") {
    btn3Click = true;
  } else if (datoRecivido == "btn4click") {
    btn4Click = true;
  }else if (datoRecivido == "btn1clickdoble") {
    btn1Double = true;
  }else if (datoRecivido == "btn2clickdoble") {
    btn2Double = true;
  }else if (datoRecivido == "btn3clickdoble") {
    btn3Double = true;
  }else if (datoRecivido == "btn4clickdoble") {
    btn4Double = true;
  } else if (datoRecivido == "mostrarNombreBoton") {
    mostrarNombreBoton();
  }
  }
  
}
bool PolSerial::btn1Presionado() {
  if (btn1Click) { // si el boton es true entonces fue presionado en algun momento
    btn1Click = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn2Presionado() {
  if (btn2Click) { // si el boton es true entonces fue presionado en algun momento
    btn2Click = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn3Presionado() {
  if (btn3Click) { // si el boton es true entonces fue presionado en algun momento
    btn3Click = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn4Presionado() {
  if (btn4Click) { // si el boton es true entonces fue presionado en algun momento
    btn4Click = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn1PresionadoDoble() {
  if (btn1Double) { // si el boton es true entonces fue presionado en algun momento
    btn1Double = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn2PresionadoDoble() {
  if (btn2Double) { // si el boton es true entonces fue presionado en algun momento
    btn2Double = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn3PresionadoDoble() {
  if (btn3Double) { // si el boton es true entonces fue presionado en algun momento
    btn3Double = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
bool PolSerial::btn4PresionadoDoble() {
  if (btn4Double) { // si el boton es true entonces fue presionado en algun momento
    btn4Double = false; // cambiamos la variable a false para que ya no esta marcada como presionada
    return true;
  } else {
    return false;
  }
}
void PolSerial::led1Encender() { //---------------  Encender los led
  Serial.println("led1On");
}
void PolSerial::led2Encender() {
  Serial.println("led2On");
}
void PolSerial::led3Encender() {
  Serial.println("led3On");
}
void PolSerial::led4Encender() {
  Serial.println("led4On");
}
void PolSerial::led1Apagar() { //--------------- Apagar los led
  Serial.println("led1Off");
}
void PolSerial::led2Apagar() {
  Serial.println("led2Off");
}
void PolSerial::led3Apagar() {
  Serial.println("led3Off");
}
void PolSerial::led4Apagar() {
  Serial.println("led4Off");
}
void PolSerial::btn1Nombrar(String nombre) { //----------- Nombrar los botones
  btn1Nombre = nombre;
  Serial.println("btn1txt" + btn1Nombre);
}
void PolSerial::btn2Nombrar(String nombre) {
  btn2Nombre = nombre;
  Serial.println("btn2txt" + btn2Nombre);
}
void PolSerial::btn3Nombrar(String nombre) {
  btn3Nombre = nombre;
  Serial.println("btn3txt" + btn3Nombre);
}
void PolSerial::btn4Nombrar(String nombre) {
  btn4Nombre = nombre;
  Serial.println("btn4txt" + btn4Nombre);
}
void PolSerial::etiqueta1(String nombre) { //---------------------   Nombrar las etiquetas
  Serial.println("etiqueta1" + nombre);
}
void PolSerial::etiqueta2(String nombre) {
  Serial.println("etiqueta2" + nombre);
}
void PolSerial::etiqueta3(String nombre) {
  Serial.println("etiqueta3" + nombre);
}
void PolSerial::etiqueta4(String nombre) {
  Serial.println("etiqueta4" + nombre);
}
void PolSerial::mostrarNombreBoton() {
  Serial.println("btn1txt" + btn1Nombre);
  Serial.println("btn2txt" + btn2Nombre);
  Serial.println("btn3txt" + btn3Nombre);
  Serial.println("btn4txt" + btn4Nombre);
}
