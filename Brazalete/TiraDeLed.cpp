#include "TiraDeLed.h"

TiraDeLed::TiraDeLed( String _alerta1, String _alerta2, String _alerta3, int _tiempoAlerta1, int _tiempoAlerta2, int _tiempoAlerta3,
                      int _velocidadParpadeo, byte _coloresSemiciclos, byte _rojo, byte _verde, byte _azul )
{
  pinMode( PIN_ROJO, OUTPUT );
  pinMode( PIN_VERDE, OUTPUT );
  pinMode( PIN_AZUL, OUTPUT );
  alerta1 = _alerta1;
  alerta2 = _alerta2;
  alerta3 = _alerta3;
  tiempoAlerta1 = _tiempoAlerta1;
  tiempoAlerta2 = _tiempoAlerta2;
  tiempoAlerta3 = _tiempoAlerta3;
  velocidadParpadeo = _velocidadParpadeo;
  coloresSemiciclos = _coloresSemiciclos;
  rojo = _rojo;
  verde = _verde;
  azul = _azul;
}

void TiraDeLed::ejecutar( byte _estado ){
  delta.actualizar( millis() );

  if( _estado != ESTADO_APAGADO && _estado != estado ){
    estado = _estado;
    tiempo = tiempoParpadeo = 0;
    semicicloRojoAAzul = true;
  }

  switch ( estado ) {
    case ESTADO_ALERTA_1:
      ejecutarAlerta1();
      break;
    case ESTADO_ALERTA_2:
      ejecutarAlerta2();
      break;
    case ESTADO_ALERTA_3:
      ejecutarAlerta3();
      break;
  }

}

void TiraDeLed::ejecutarAlerta1(){
  tiempo += delta.get();

  if( alerta1.equals( FIJO ) ){
    setHigh();
  }else if( alerta1.equals( PARPADEO ) ){
    parpadeo();
  }else{
    semiciclo( tiempoAlerta1 );
  }

  if( tiempo >= tiempoAlerta1 ) apagar();
}

void TiraDeLed::ejecutarAlerta2(){
  tiempo += delta.get();

  if( alerta2.equals( FIJO ) ){
    setHigh();
  }else if( alerta2.equals( PARPADEO ) ){
    parpadeo();
  }else{
    semiciclo( tiempoAlerta2 );
  }

  if( tiempo >= tiempoAlerta2 ) apagar();

}

void TiraDeLed::ejecutarAlerta3(){
  tiempo += delta.get();

  if( alerta3.equals( FIJO ) ){
    setHigh();
  }else if( alerta3.equals( PARPADEO ) ){
    parpadeo();
  }else{
    semiciclo( tiempoAlerta3 );
  }

  if( tiempo >= tiempoAlerta3 ) apagar();
}

void TiraDeLed::parpadeo(){
  tiempoParpadeo += delta.get();
  if( tiempoParpadeo >= velocidadParpadeo ){
    tiempoParpadeo = 0;
    if( encendido ) setLow(); else setHigh();
  }
}

void TiraDeLed::semiciclo( int tiempoAlerta ){

  int tiempoSemiciclo = tiempoAlerta / coloresSemiciclos;
  int ciclo = tiempo / tiempoSemiciclo;
  int tiempoLocal = tiempo - tiempoSemiciclo * ciclo;
  bool par = ciclo % 2;

  int tiempoFraccion = tiempoSemiciclo / 4;
  int fraccion = tiempoLocal / tiempoFraccion;
  int tiempoLocalFraccion = tiempoLocal - tiempoFraccion * fraccion;

  if( par ){
    switch ( fraccion ) {
      case 0:
        setHigh( 255, map( tiempoLocalFraccion, 0, tiempoFraccion, 0, 255 ), 0 );
        break;
      case 1:
        setHigh( map( tiempoLocalFraccion, 0, tiempoFraccion, 255, 0 ), 255, 0 );
        break;
      case 2:
        setHigh( 0, 255, map( tiempoLocalFraccion, 0, tiempoFraccion, 0, 255 ) );
        break;
      case 3:
        setHigh( 0, map( tiempoLocalFraccion, 0, tiempoFraccion, 255, 0 ), 255 );
        break;
    }
  }else{
    switch ( fraccion ) {
      case 0:
        setHigh( 0, map( tiempoLocalFraccion, 0, tiempoFraccion, 0, 255 ), 255 );
        break;
      case 1:
        setHigh( 0, 255, map( tiempoLocalFraccion, 0, tiempoFraccion, 255, 0 ) );
        break;
      case 2:
        setHigh( map( tiempoLocalFraccion, 0, tiempoFraccion, 0, 255 ), 255, 0 );
        break;
      case 3:
        setHigh( 255, map( tiempoLocalFraccion, 0, tiempoFraccion, 255, 0 ), 0 );
        break;
    }
  }

}

void TiraDeLed::apagar(){
  setLow();
  estado = ESTADO_APAGADO;
  tiempoParpadeo = 0;
  tiempo = 0;
}

void TiraDeLed::setHigh(){
  analogWrite( PIN_ROJO, rojo );
  analogWrite( PIN_VERDE, verde );
  analogWrite( PIN_AZUL, azul );
  encendido = true;
}

void TiraDeLed::setHigh( byte r, byte g, byte b ){
  analogWrite( PIN_ROJO, r );
  analogWrite( PIN_VERDE, g );
  analogWrite( PIN_AZUL, b );
  encendido = true;
}

void TiraDeLed::setLow(){
  digitalWrite( PIN_ROJO, LOW );
  digitalWrite( PIN_VERDE, LOW );
  digitalWrite( PIN_AZUL, LOW );
  encendido = false;
}
