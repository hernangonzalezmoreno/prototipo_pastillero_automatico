#include "TiraDeLed.h"

TiraDeLed::TiraDeLed( String _alerta1, String _alerta2, int _tiempoAlerta1, int _tiempoAlerta2, int _velocidadParpadeo, byte _rojo, byte _verde, byte _azul ){
  pinMode( PIN_ROJO, OUTPUT );
  pinMode( PIN_VERDE, OUTPUT );
  pinMode( PIN_AZUL, OUTPUT );
  alerta1 = _alerta1;
  alerta2 = _alerta2;
  tiempoAlerta1 = _tiempoAlerta1;
  tiempoAlerta2 = _tiempoAlerta2;
  velocidadParpadeo = _velocidadParpadeo;
  rojo = _rojo;
  verde = _verde;
  azul = _azul;
}

void TiraDeLed::ejecutar( byte _estado ){
  delta.actualizar( millis() );

  if( _estado != ESTADO_APAGADO && _estado != estado ){
    estado = _estado;
    tiempo = tiempoParpadeo = 0;
  }

  switch ( estado ) {
    case ESTADO_ALERTA_1:
      ejecutarAlerta1();
      break;
    case ESTADO_ALERTA_2:
      ejecutarAlerta2();
      break;
  }

}

void TiraDeLed::ejecutarAlerta1(){
  tiempo += delta.get();

  if( alerta1.equals( FIJO ) ){
    setHigh();
  }else{
    parpadeo();
  }

  if( tiempo >= tiempoAlerta1 ) apagar();
}

void TiraDeLed::ejecutarAlerta2(){
  tiempo += delta.get();

  if( alerta2.equals( FIJO ) ){
    setHigh();
  }else{
    parpadeo();
  }

  if( tiempo >= tiempoAlerta2 ) apagar();

}

void TiraDeLed::parpadeo(){
  tiempoParpadeo += delta.get();
  if( tiempoParpadeo >= velocidadParpadeo ){
    tiempoParpadeo = 0;
    if( encendido ) setLow(); else setHigh();
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

void TiraDeLed::setLow(){
  digitalWrite( PIN_ROJO, LOW );
  digitalWrite( PIN_VERDE, LOW );
  digitalWrite( PIN_AZUL, LOW );
  encendido = false;
}
