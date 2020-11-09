/* Pastillero */

//------- Parametros de configuracion -------
#define INICIO_MODO_CALIBRACION false //Iniciar en modo calibracion. (Presionando 3 segundos el boton A se puede cambiar de modo)
#define MOTOR_SENTIDO_HORARIO true //Sentido de giro del motor
#define TIEMPO_PRIMER_PASTILLA 5000 //Tiempo que tarda antes de expender la primer pastilla, en milisegundos
#define TIEMPO_PASTILLAS 10000 //Tiempo de espera entre pastilla y pastilla, en milisegundos
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
