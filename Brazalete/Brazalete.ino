/* Brazalete */

#define FIJO "Fijo"
#define PARPADEO "Parpadeo"
#define COLORES "Colores"

//------- Parametros de configuracion -------
#define ALERTA_1 FIJO
#define ALERTA_2 PARPADEO
#define ALERTA_3 COLORES
#define TIEMPO_ALERTA_1 3000
#define TIEMPO_ALERTA_2 3000
#define TIEMPO_ALERTA_3 3000
#define VELOCIDAD_PARPADEO 250
#define COLORES_SEMICICLOS 4
#define VALOR_ROJO 255
#define VALOR_VERDE 255
#define VALOR_AZUL 255
//-------------------------------------------

#include "Bluetooth.h"
#include "TiraDeLed.h"

Bluetooth bluetooth;
TiraDeLed tiraDeLed( ALERTA_1, ALERTA_2, ALERTA_3, TIEMPO_ALERTA_1, TIEMPO_ALERTA_2, TIEMPO_ALERTA_3,
                     VELOCIDAD_PARPADEO, COLORES_SEMICICLOS, VALOR_ROJO, VALOR_VERDE, VALOR_AZUL );

void setup(){
  Serial.begin(9600);
}

void loop(){
  tiraDeLed.ejecutar( bluetooth.ejecutar() );
}
