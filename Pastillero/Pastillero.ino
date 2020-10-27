#include <Delta.h>
#include "Controlador.h"

#define DIRECCION_MOTOR true

Delta delta;
Controlador controlador;

void setup(){
  controlador.iniciar( &delta, DIRECCION_MOTOR );
  //controlador.iniciar( 9600, &delta );
  Serial.begin( 9600 );
}

void loop(){
  delta.actualizar( millis() );
  //Serial.print( "delta milisegundos: " );
  //Serial.println( delta.get() );
  controlador.ejecutar();
}
