#include "Controlador.h"

Controlador::Controlador( bool modoCalibracion, bool sentidoHorario, unsigned long _tiempoPrimerPastilla, unsigned long _tiempoPastillas ){

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
  pBluetooth = new Bluetooth( &delta );
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
  delta.actualizar( millis() );

  switch ( estado ) {

    case ESTADO_CALIBRACION:
      pCalibrador->ejecutar();
      break;

    case ESTADO_PRODUCCION:
      produccion();
      break;

  }

  pBluetooth->ejecutar();

}

void Controlador::produccion(){

  tiempoProduccion += delta.get();

  if( pPulsadorA->isPressed() ){

    tiempo += delta.get();
    if( tiempo >= TIEMPO_MAX_CAMBIO_ESTADO ){
      setEstado( ESTADO_CALIBRACION );
      tiempo = 0;
      return;
    }

  }else if( tiempo > 0 ){
    pBluetooth->enviarMsj( 2 );
    tiempo = 0;

  }else if( pPulsadorB->isPressed() ){

    pBluetooth->enviarMsj( 3 );

  }

  if( primerPastilla && tiempoProduccion >= tiempoPrimerPastilla ){
    primerPastilla = false;
    expenderPastilla();
  }else if( tiempoProduccion >= tiempoPastillas ){
    expenderPastilla();
  }

}

void Controlador::expenderPastilla(){
  pBluetooth->enviarMsj( 1 );
  pMotor->moverUnaParte();
  pMotor->ejecutar();
  tiempoProduccion = 0;
}
