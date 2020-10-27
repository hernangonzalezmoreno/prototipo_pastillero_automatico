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

    pControlador->pMotor->moverUnaParte();
    pControlador->pMotor->ejecutar();
    pControlador->tiempo = 0;

  }else if( pControlador->pPulsadorB->isPressed() ){

    pControlador->pMotor->moverMediosPasos(1);
    pControlador->pMotor->ejecutar();

  }else if( pControlador->pPulsadorC->isPressed() ){

    pControlador->pMotor->flip();
    pControlador->pMotor->moverMediosPasos(1);
    pControlador->pMotor->ejecutar();
    pControlador->pMotor->flip();

  }

}
