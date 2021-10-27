/*
  PROGRAMA PARA ENCENDER Y APAGAR UN LED A TRAVÉS DE DOS BOTONES DE LA NEXTION MEDIANTE BLUETOOTH
  EL MAESTRO CONECTADO AL ARDUINO MEGA Y EL ESCLAVO A LA NEXTION
  EN LOS EVENTOS DE LA NEXTION prints "H",1 PARA EL BOTON DE ENCENDIDO Y PRINTS "a",1 PARA EL DE APAGADO
  LOS PINES RX Y TX CRUZADOS EN AMBOS
*/
#include "Nextion.h"
#include "SoftwareSerial.h"
int LedPin = 10;
NexButton botEncender = NexButton(0,1,"botEncender");     //parámetros de identifiacion de los botones en la pantalla nexion
NexButton botApagar = NexButton(0,2,"botApagar");
NexTouch *nex_listen_list[]=                    //cargar lista de botones y leer los cambios en los botones
{
  &botEncender,
  &botApagar,
  NULL
};
//void conexion()
//{
//  at_cmd("AT+CON0CEC80F0F0AD74","resultado:");                                // Conexion con bluetooth nextion.
// delay(1000);
//}
void BotonEncender()
{
  digitalWrite(LedPin,HIGH);
}
void BotonApagar()
{
  digitalWrite(LedPin,LOW);
}
void setup() {
  nexInit();
  //BOTONES
  botEncender.attachPop(BotonEncender);             //declarar que hace al pulsar cada botón
  botApagar.attachPop(BotonApagar);
  Serial.begin(9600);//INICIAMOS COMUNICACION PUERTO SERIE DEL ARDUINO EN EL SERIAL 1
  pinMode(LedPin,OUTPUT);//PONEMOS EL PIN 10 COMO SALIDA
  digitalWrite(LedPin, LOW);//LO INICIAMOS A ESTADO BAJO PARA QUE SIEMPRE ESTÉ APAGADO
}

void loop() {
 
      nexLoop(nex_listen_list); 
//  if (Serial.available())// If anything comes in Serial1 (pins 0 & 1) SI SE ESTABLECE LA COMUNICACION POR BLUETOOTH
//  {
//  {
//    conexion();
//  }
//      char Led = Serial.read();  //METEMOS EL VALOR DE LECTURA EN UNA VARIABLE
/*      if (Led == 'H')             //SI LA LETRA ES LA H ES DECIR BOTON DE ENCENDIDO
      {
              digitalWrite(LedPin, HIGH);   //ENCENDEMOS LED
    }
    else if (Led == 'A') {      //SI LA LETRA ES LA A BOTON DE APAGADO
              digitalWrite(LedPin, LOW);  //APAGAMOS LED
    }*/
//  }
}
