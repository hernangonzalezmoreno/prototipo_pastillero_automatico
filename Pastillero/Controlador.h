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
    Delta *pDelta;
    Motor_28BYJ_48 *pMotor;
    PulsadorPullup *pPulsadorA, *pPulsadorB, *pPulsadorC;

    Controlador( Delta *, bool, bool, int, int );

    void ejecutar();
    void setLedBuiltin( uint8_t );

  private:
    Calibrador *pCalibrador;

};

#endif
