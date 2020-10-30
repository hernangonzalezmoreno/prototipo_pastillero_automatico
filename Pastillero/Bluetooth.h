#ifndef Bluetooth_h
#define Bluetooth_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>
#include <SoftwareSerial.h>

#define CANTIDAD_DE_ENVIOS 5
#define TIEMPO_ENTRE_ENVIOS 100

class Bluetooth{

  public:
    Bluetooth( Delta * );
    void enviarMsj();
    void ejecutar();

  private:
    Delta *pDelta;
    SoftwareSerial *pSerialBluetooth;
    bool envioActivo = false;
    byte numeroDeEnvio = 0;
    int tiempoEnvio = 0;
    void enviar();

};

#endif
