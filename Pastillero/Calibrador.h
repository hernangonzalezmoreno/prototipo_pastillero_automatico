#ifndef Calibrador_h
#define Calibrador_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "PulsadorPullup.h"

class Controlador;
class Calibrador{

  public:
    Calibrador( Controlador * );
    void ejecutar();

  private:
    Controlador *pControlador;

};

#endif
