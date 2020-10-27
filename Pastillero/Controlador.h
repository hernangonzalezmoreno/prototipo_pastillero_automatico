#ifndef Controlador_h
#define Controlador_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>
#include "Motor_28BYJ_48.h"

#define ESTADO_CALIBRACION 0x00
#define ESTADO_PRODUCCION 0x01

class Controlador{

  public:
    void iniciar( Delta *, bool );
    void ejecutar();

  private:
    byte estado;
    Delta *pDelta;
    Motor_28BYJ_48 motor;
    void calibracion();
    void produccion();

};

#endif
