/********************************************
	Para el desarrollo de este desafío se han
se ha partido de las premisas enunciadas a
continuación:

1- Se considera, interpretando de los comentarios
del profesor, que los semáforos permiten ingresar 
a las avenidas secundarios solo saliendo por la 
derecha, más no por la izquierda (Practica muy 
empleada en la cuidad donde vivo). Mientras que 
desde las avenidas secundarias se puede ingresar
a la principal girando tanto a izquierda como a
derecha.

2- Esto nos deja con un sistema de semáforos de 3
movimientos. Una secuencia para la avenida principal
(en ambos sentidos) y dos secuencias independientes 
para cada avenida secundaria.

3- Se ha tomado como tiempo de espera para cada
semáforo 60s (35s en rojo, 15s en amarillo y 10s
en parpadeo amarillo). La luz verde se mantendrá 
estática por 50s y luego parpadeara por otros 10s.

4- Si un peatón pulsase el botón de cruce, deberá esperar
a que la secuencia en ejecución se detenga, y luego
tendrá 25s para cruzar la calle.

Reto: Crea tu semáforo con Arduino
Curso: Fundamentos de Desarrollo de Hardware con Arduino
Profesor: Ricardo Celis
Alumno: Marcel Nahir Samur
Fecha: 25/10/2020
********************************************************/


// Avenida ppal.
const int pr = 11;
const int pa = 10;
const int pv = 9;
const int pb = 8;

//Avenida sec. 1
const int s1r = 5;
const int s1a = 6;
const int s1v = 7;
const int s1b = 4;

//Avenida sec. 2
const int s2r = A1;
const int s2a = A2;
const int s2v = A3;
const int s2b = A0;

const int arrSem[9] = {pr, pa, pv, s1r, s1a, s1v, s2r, s2a, s2v}; // Arreglo de LEDs
const int alarmaPeaton = 13; //Alarma de peatones


//Duración de las luces (en Milisegundos)
unsigned int drs = 35000;
unsigned int das = 15000;
unsigned int dap = 10000;
unsigned int dbs = 25000;

bool btnFlag = false;
int status;

void setup()
{ 
  Serial.begin(9600);
  //Luces 
  for (int i = 0 ; i < 9 ; i++)
    pinMode(arrSem[i], OUTPUT);
  
  //Pulsadores
  pinMode(pb, INPUT_PULLUP);
  pinMode(s1b, INPUT_PULLUP);
  pinMode(s2b, INPUT_PULLUP);
  
  //Alarma
  pinMode(alarmaPeaton, OUTPUT);
  
}

void loop()
{
  // Los estados son 4, 3 p/circulacion vehicular y 1 para cruce de peatones
  status = 1;
  
  for (int j = 0 ; j < 3 ; j++) //Ejecutamos las 3 secuencias de semáforos
  {
  	secuencia();
    
    // Se evalua en cada iteración si algun peaton ha oprimido el pulsador
    if (btnFlag == true) 
    {
      	for (int k = 0 ; k < 9 ; k++)
        {
   		digitalWrite(arrSem[k], LOW); // Semáforos apagados
        }
    	digitalWrite(pr, HIGH);  //Todos los semáforos
    	digitalWrite(s1r, HIGH); // vehiculares
    	digitalWrite(s2r, HIGH); // en rojo
      	digitalWrite(alarmaPeaton, HIGH); // Semáforos peatonales
    	delay(dbs);
      	
      	status++; // Se pasa a la siguiente secuencia
      	btnFlag = false; // Se desactiva la señal peatonal
    }
    else
    {
      status++; // Se pasa a la siguiente secuencia
    }
  }
}

/* Se utiliza el parpadeo de los LEDs verde
   y amarillo para indicar un cambio de estado inminente*/
int atencion(int at1,int at2,int at3)
{
  for (int f = 0 ; f < 5 ; f++) // Para generar el parpadeo
  {
  digitalWrite(at1, LOW);
  digitalWrite(at2, LOW);
  digitalWrite(at3, HIGH);
  peaton(1000);
  digitalWrite(at1, HIGH);
  digitalWrite(at2, HIGH);
  digitalWrite(at3, HIGH);
  peaton(1000);
  }
}
// Estado de circulación libre o detención total
int estatico(int static1,int static2,int static3,int static4)
{
  digitalWrite(static1, HIGH);
  digitalWrite(static2, HIGH);
  digitalWrite(static3, HIGH);
  peaton(drs);
  digitalWrite(static3, LOW);
  digitalWrite(static4, HIGH);
  peaton(das);
}

/* Función para ejecutar los 3 posibles estados
   de los semáforos vehiculares */
int secuencia()
{
  for (int g = 0 ; g < 9 ; g++) 
    digitalWrite(arrSem[g], LOW); // Semáforos apagados
  
  switch (status)
  {
    case 1:
    	estatico(pv, s1r, s2r, s2a);
    	atencion(pv, s2a, s1r);
    	break;
    case 2:
    	estatico(s2v, pr, s1r, s1a);
    	atencion(s2v, s1a, pr);
    	break;
    case 3:
    	estatico(s1v, s2r, pr, pa);
    	atencion(s1v, pa, s2r);
    	break;
    default:
    	Serial.println("Error! Contacte a soporte técnico");
    	break;
  }
}

/* Se utiliza esta función para comprobar si un
   peaton ha pulsado el boton */
bool peaton(unsigned int dFrac)
{
  int dRes = 250; //Resolución, utilizado p/ dividir el retardo
  dFrac = dFrac/dRes;
  for (int dBtn = 0 ; dBtn < dFrac ; dBtn++)
  {
  	if (digitalRead(pb) == LOW || digitalRead(s1b) == LOW || digitalRead(s2b) == LOW)
  	{
    	btnFlag = true;
      	digitalWrite(alarmaPeaton, HIGH); 
    	delay(dRes);
  	}
  	else
    {
  		delay(dRes);
      	digitalWrite(alarmaPeaton, LOW); // Indicador de peatones apagado
    }
  }
  return btnFlag; // Se retorna el valor que se evaluará
}				  // en la función principal 