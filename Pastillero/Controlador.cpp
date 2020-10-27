#include "Controlador.h"

Controlador::Controlador( Delta *pD ){
  estado = ESTADO_CALIBRACION;
  pDelta = pD;
  pCalibrador = new Calibrador( this );
  pinMode( LED_BUILTIN, OUTPUT );
  setLedBuiltin( HIGH );
  pPulsadorA = new PulsadorPullup( PULSADOR_A );
  pPulsadorB = new PulsadorPullup( PULSADOR_B );
  pPulsadorC = new PulsadorPullup( PULSADOR_C );
}

void Controlador::iniciar( bool direccion ){
  motor.iniciar( pDelta, direccion );
}

void Controlador::ejecutar(){

  switch ( estado ) {

    case ESTADO_CALIBRACION:
      pCalibrador->ejecutar();
      break;

    case ESTADO_PRODUCCION:
      break;

  }

}

void Controlador::setLedBuiltin( uint8_t valor ){
  digitalWrite( LED_BUILTIN, valor );
}
