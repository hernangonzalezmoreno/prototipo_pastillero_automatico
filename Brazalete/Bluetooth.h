#ifndef Bluetooth_h
#define Bluetooth_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SoftwareSerial.h>

class Bluetooth{

  public:
    Bluetooth();

  private:
    SoftwareSerial *pSerialBluetooth;


};

#endif
