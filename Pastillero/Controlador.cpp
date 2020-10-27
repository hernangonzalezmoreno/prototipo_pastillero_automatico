#include "Controlador.h"

void Controlador::iniciar( Delta *pD, bool direccion ){
  pDelta = pD;
  motor.iniciar( pD, direccion );
}

void Controlador::ejecutar(){
  motor.ejecutar();
}

void Controlador::calibracion(){

}

void Controlador::produccion(){

}
