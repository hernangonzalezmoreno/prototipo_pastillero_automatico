#include "Controlador.h"

Controlador::Controlador( Delta *pD, bool modoCalibracion, bool sentidoHorario, int tiempoPrimerPastilla, int tiempoPastilla ){

  pDelta = pD;
  pinMode( LED_BUILTIN, OUTPUT );

  if( modoCalibracion ){
    estado = ESTADO_CALIBRACION;
    setLedBuiltin( HIGH );
  }else{
    estado = ESTADO_PRODUCCION;
    setLedBuiltin( LOW );
  }

  pMotor = new Motor_28BYJ_48( sentidoHorario );
  pCalibrador = new Calibrador( this );
  pPulsadorA = new PulsadorPullup( PULSADOR_A );
  pPulsadorB = new PulsadorPullup( PULSADOR_B );
  pPulsadorC = new PulsadorPullup( PULSADOR_C );
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
