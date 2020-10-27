#ifndef PulsadorPullup_h
#define PulsadorPullup_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class PulsadorPullup{

  public:
    PulsadorPullup( uint8_t );
    uint8_t pin;
    bool isPressed();

  private:


};

#endif
