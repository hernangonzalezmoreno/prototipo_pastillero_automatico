#ifndef TiraDeLed_h
#define TiraDeLed_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define PIN_ROJO 9
#define PIN_VERDE 10
#define PIN_AZUL 11

class TiraDeLed{

  public:
    TiraDeLed();

  private:
    byte rojo, verde, azul;


};

#endif
