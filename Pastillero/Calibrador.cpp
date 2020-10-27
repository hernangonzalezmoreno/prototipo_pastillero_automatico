#include "Calibrador.h"
#include "Controlador.h"

Calibrador::Calibrador( Controlador *pC ){
  pControlador = pC;
}

void Calibrador::ejecutar(){

  if( pControlador->pPulsadorA->isPressed() ){

    pControlador->tiempo += pControlador->pDelta->get();
    if( pControlador->tiempo >= TIEMPO_MAX_CAMBIO_ESTADO ){
      pControlador->estado = ESTADO_PRODUCCION;
      pControlador->setLedBuiltin( LOW );
      pControlador->tiempo = 0;
      return;
    }

  }else if( pControlador->tiempo > 0 ){

    pControlador->motor.moverUnaParte();
    pControlador->motor.ejecutar();
    pControlador->tiempo = 0;

  }else if( pControlador->pPulsadorB->isPressed() ){

    pControlador->motor.moverMediosPasos(1);
    pControlador->motor.ejecutar();

  }else if( pControlador->pPulsadorC->isPressed() ){

    pControlador->motor.flip();
    pControlador->motor.moverMediosPasos(1);
    pControlador->motor.ejecutar();
    pControlador->motor.flip();

  }

}
