/* Brazalete */

//------- Parametros de configuracion -------
#define ALERTA_1 "Fijo"
#define ALERTA_2 "Parpadeo"
#define TIEMPO_ALERTA_1 3000
#define TIEMPO_ALERTA_2 3000
#define VELOCIDAD_PARPADEO 250
#define VALOR_ROJO 255
#define VALOR_VERDE 255
#define VALOR_AZUL 255
//-------------------------------------------

#include "Bluetooth.h"
#include "TiraDeLed.h"

Bluetooth bluetooth;
TiraDeLed tiraDeLed( ALERTA_1, ALERTA_2, TIEMPO_ALERTA_1, TIEMPO_ALERTA_2,
                     VELOCIDAD_PARPADEO, VALOR_ROJO, VALOR_VERDE, VALOR_AZUL );

void setup(){}

void loop(){
  tiraDeLed.ejecutar( bluetooth.ejecutar() );
}
