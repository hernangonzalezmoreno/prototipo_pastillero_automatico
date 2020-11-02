/* Pastillero */

//------- Parametros de configuracion -------
#define INICIO_MODO_CALIBRACION false //Inicia en modo calibracion
#define MOTOR_SENTIDO_HORARIO true
#define TIEMPO_PRIMER_PASTILLA 5000 // 5 segundos (tiempo en milisegundos)
#define TIEMPO_PASTILLAS 10000 // (tiempo en milisegundos)
//-------------------------------------------

#include "Controlador.h"

Controlador controlador(
  INICIO_MODO_CALIBRACION,
  MOTOR_SENTIDO_HORARIO,
  TIEMPO_PRIMER_PASTILLA,
  TIEMPO_PASTILLAS
 );

void setup(){}

void loop(){
  controlador.ejecutar();
}
