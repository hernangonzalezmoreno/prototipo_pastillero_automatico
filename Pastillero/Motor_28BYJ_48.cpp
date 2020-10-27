#include "Motor_28BYJ_48.h"

Motor_28BYJ_48::Motor_28BYJ_48( bool _sentidoHorario ){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  sentidoHorario = _sentidoHorario;
}

bool Motor_28BYJ_48::isOcupado(){
  return ocupado;
}

bool Motor_28BYJ_48::moverUnaParte(){
  bool retorno;
  if( indexParte < 14 ){
    retorno = moverMediosPasos( TAMANO_PARTE );
    if( retorno ) indexParte++;
  }else{
    retorno = moverMediosPasos( TAMANO_ULTIMA_PARTE );
    if( retorno ) indexParte = 0;
  }
  return retorno;
}

bool Motor_28BYJ_48::moverMediosPasos( int _cantidadMediosPasos ){
  if( !ocupado ){
    cantidadMediosPasos = _cantidadMediosPasos;
    ocupado = true;
    return true;
  }else return false;
}

void Motor_28BYJ_48::flip(){
  sentidoHorario = !sentidoHorario;
}

void Motor_28BYJ_48::ejecutar(){
  if( ocupado ){

    while( cantidadMediosPasos > 0 ){
      avanzarMerdioPaso();
      cantidadMediosPasos--;
    }

    ocupado = false;

  }
}

void Motor_28BYJ_48::avanzarMerdioPaso(){
  if( sentidoHorario ){
    indexMediosPasos++;
    indexMediosPasos %= 8;
  }else{
    indexMediosPasos--;
    if( indexMediosPasos < 0 ) indexMediosPasos = 7;
  }

  digitalWrite( IN1, mediosPasos[ indexMediosPasos ][ 0 ] );
  digitalWrite( IN2, mediosPasos[ indexMediosPasos ][ 1 ] );
  digitalWrite( IN3, mediosPasos[ indexMediosPasos ][ 2 ] );
  digitalWrite( IN4, mediosPasos[ indexMediosPasos ][ 3 ] );

  delay(2);
}
