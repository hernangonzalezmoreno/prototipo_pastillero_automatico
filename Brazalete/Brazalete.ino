/* Brazalete */

#define FIJO "Fijo"
#define PARPADEO "Parpadeo"
#define COLORES "Colores"

//------- Parametros de configuracion -------
#define ALERTA_1 FIJO //Alerta cuando gira el motor
#define ALERTA_2 PARPADEO //Alerta pulsador A
#define ALERTA_3 COLORES //Alerta pulsador B
#define TIEMPO_ALERTA_1 3000 //Tiempo de alerta en milisegundos
#define TIEMPO_ALERTA_2 3000 //Tiempo de alerta en milisegundos
#define TIEMPO_ALERTA_3 3000 //Tiempo de alerta en milisegundos
#define RITMO_PARPADEO 250 //Tiempo encendido-apagado en milisegundos
#define COLORES_SEMICICLOS 4 //Cantidad de semiciclos en alerta COLORES
#define VALOR_ROJO 255 //Valor de rojo por defecto en alerta FIJO y PARPADEO
#define VALOR_VERDE 255 //Valor de verde por defecto en alerta FIJO y PARPADEO
#define VALOR_AZUL 255 //Valor de azul por defecto en alerta FIJO y PARPADEO
//-------------------------------------------

#include "Bluetooth.h"
#include "TiraDeLed.h"

Bluetooth bluetooth;
TiraDeLed tiraDeLed( ALERTA_1, ALERTA_2, ALERTA_3, TIEMPO_ALERTA_1, TIEMPO_ALERTA_2, TIEMPO_ALERTA_3,
                     RITMO_PARPADEO, COLORES_SEMICICLOS, VALOR_ROJO, VALOR_VERDE, VALOR_AZUL );

void setup(){}

void loop(){
  tiraDeLed.ejecutar( bluetooth.ejecutar() );
}
