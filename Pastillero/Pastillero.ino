#include <Delta.h>
#include "Controlador.h"

#define DIRECCION_MOTOR true

Delta delta;
Controlador controlador( &delta );

void setup(){
  Serial.begin( 9600 );
  controlador.iniciar( DIRECCION_MOTOR );
}

void loop(){
  delta.actualizar( millis() );
  controlador.ejecutar();
}
