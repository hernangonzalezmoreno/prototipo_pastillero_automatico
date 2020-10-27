#include "Controlador.h"

Controlador::Controlador( Delta *pD, bool modoCalibracion, bool sentidoHorario, unsigned long _tiempoPrimerPastilla, unsigned long _tiempoPastillas ){

  pDelta = pD;
  pinMode( LED_BUILTIN, OUTPUT );

  if( modoCalibracion ){
    estado = ESTADO_CALIBRACION;
    setLedBuiltin( HIGH );
  }else{
    estado = ESTADO_PRODUCCION;
    setLedBuiltin( LOW );
  }

  tiempoProduccion = 0;
  tiempoPrimerPastilla = _tiempoPrimerPastilla;
  tiempoPastillas = _tiempoPastillas;

  pMotor = new Motor_28BYJ_48( sentidoHorario );
  pCalibrador = new Calibrador( this );
  pPulsadorA = new PulsadorPullup( PULSADOR_A );
  pPulsadorB = new PulsadorPullup( PULSADOR_B );
  pPulsadorC = new PulsadorPullup( PULSADOR_C );
}

void Controlador::setLedBuiltin( uint8_t valor ){
  digitalWrite( LED_BUILTIN, valor );
}

void Controlador::setEstado( byte _estado ){
  if( estado == _estado ) return;
  estado = _estado;
  if( estado == ESTADO_PRODUCCION ){
     primerPastilla = true;
     tiempoProduccion = 0;
     setLedBuiltin( LOW );
  }else setLedBuiltin( HIGH );
}

void Controlador::ejecutar(){

  switch ( estado ) {

    case ESTADO_CALIBRACION:
      pCalibrador->ejecutar();
      break;

    case ESTADO_PRODUCCION:
      produccion();
      break;

  }

}

void Controlador::produccion(){

  tiempoProduccion += pDelta->get();

  if( pPulsadorA->isPressed() ){

    tiempo += pDelta->get();
    if( tiempo >= TIEMPO_MAX_CAMBIO_ESTADO ){
      setEstado( ESTADO_CALIBRACION );
      tiempo = 0;
      return;
    }

  }

  if( primerPastilla && tiempoProduccion >= tiempoPrimerPastilla ){

    primerPastilla = false;
    pMotor->moverUnaParte();
    pMotor->ejecutar();
    tiempoProduccion = 0;

  }else if( tiempoProduccion >= tiempoPastillas ){

    pMotor->moverUnaParte();
    pMotor->ejecutar();
    tiempoProduccion = 0;

  }

}
