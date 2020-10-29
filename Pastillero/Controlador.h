#ifndef Controlador_h
#define Controlador_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>
#include "Motor_28BYJ_48.h"
#include "PulsadorPullup.h"
#include "Calibrador.h"
#include <SoftwareSerial.h>

#define ESTADO_CALIBRACION 0x00
#define ESTADO_PRODUCCION 0x01

#define TIEMPO_MAX_CAMBIO_ESTADO 3000

#define PULSADOR_A 5
#define PULSADOR_B 6
#define PULSADOR_C 7

class Controlador{

  public:
    byte estado;
    int tiempo;
    unsigned long tiempoProduccion, tiempoPrimerPastilla, tiempoPastillas;
    Delta *pDelta;
    Motor_28BYJ_48 *pMotor;
    PulsadorPullup *pPulsadorA, *pPulsadorB, *pPulsadorC;
    SoftwareSerial *pBluetooth;

    Controlador( Delta *, bool, bool, unsigned long, unsigned long );

    void setLedBuiltin( uint8_t );
    void setEstado( byte );
    void ejecutar();
    void expenderPastilla();

  private:
    bool primerPastilla;
    Calibrador *pCalibrador;
    void produccion();

};

#endif
