#ifndef TiraDeLed_h
#define TiraDeLed_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>

#define PIN_ROJO 9
#define PIN_VERDE 10
#define PIN_AZUL 11

#define ESTADO_APAGADO 0x00
#define ESTADO_ALERTA_1 0x01
#define ESTADO_ALERTA_2 0x02
#define ESTADO_ALERTA_3 0x03

#define FIJO "Fijo"
#define PARPADEO "Parpadeo"

class TiraDeLed{

  public:
    TiraDeLed( String, String, String, int, int, int, int, byte, byte, byte, byte );
    void ejecutar( byte );

  private:
    byte estado;
    byte rojo, verde, azul;
    int tiempo, tiempoAlerta1, tiempoAlerta2, tiempoAlerta3;
    int tiempoParpadeo = 0, ritmoParpadeo;
    byte coloresSemiciclos;
    bool semicicloRojoAAzul;
    bool encendido = false;
    String alerta1, alerta2, alerta3;
    Delta delta;
    void ejecutarAlerta1();
    void ejecutarAlerta2();
    void ejecutarAlerta3();
    void parpadeo();
    void semiciclo( int );
    void apagar();
    void setHigh();
    void setHigh( byte, byte, byte );
    void setLow();

};

#endif
