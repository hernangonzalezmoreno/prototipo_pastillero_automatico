#ifndef Motor_28BYJ_48_h
#define Motor_28BYJ_48_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>

#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

#define TAMANO_PARTE 273
#define TAMANO_ULTIMA_PARTE 274

class Motor_28BYJ_48{

  public:
    Motor_28BYJ_48( bool );
    bool isOcupado();
    bool moverMediosPasos( int );
    bool moverUnaParte();
    void flip();
    void ejecutar();

  private:
    int indexParte = 0;
    bool ocupado = false;
    int cantidadMediosPasos;
    int indexMediosPasos = 0;
    bool sentidoHorario = true;
    int mediosPasos [ 8 ][ 4 ] = {
      {1, 0, 0, 0},
      {1, 1, 0, 0},
      {0, 1, 0, 0},
      {0, 1, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 1},
      {0, 0, 0, 1},
      {1, 0, 0, 1}
    };
    void avanzarMerdioPaso();


};

#endif
