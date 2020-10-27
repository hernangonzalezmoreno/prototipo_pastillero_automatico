/* Pastillero */

//----- Parametros de configuracion

#define INICIO_MODO_CALIBRACION true //Inicia en modo calibracion
#define MOTOR_SENTIDO_HORARIO true

#define TIEMPO_PRIMER_PASTILLA 5000 // 3 segundos (tiempo en milisegundos)
#define TIEMPO_PASTILLAS (3*60*1000) // 3 minutos o lo mismo que poner 180000 (milisegundos)

//-----

#include <Delta.h>
#include "Controlador.h"

Delta delta;
Controlador controlador(
  &delta,
  INICIO_MODO_CALIBRACION,
  MOTOR_SENTIDO_HORARIO,
  TIEMPO_PRIMER_PASTILLA,
  TIEMPO_PASTILLAS
 );

void setup(){
  Serial.begin( 9600 );
}

void loop(){
  delta.actualizar( millis() );
  controlador.ejecutar();
}
