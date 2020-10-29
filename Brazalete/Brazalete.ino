#include <SoftwareSerial.h>
#include <Delta.h>

#define LED 8
#define TIEMPO_MAXIMO 3000

Delta delta;
SoftwareSerial bluetooth( 2, 3 );//RX, TX

bool encendido = false;
int tiempo = 0;

void setup(){
  pinMode( LED, OUTPUT );
  bluetooth.begin( 9600 );
}

void loop(){

  delta.actualizar( millis() );

  if( bluetooth.available() > 0 ){
    int c = bluetooth.read();
    if( c == 49 ){// 49 en ASCII es 1
      digitalWrite( LED, HIGH );
      encendido = true;
      tiempo = 0;
    }
  }

  if( encendido ){
    tiempo += delta.get();
    if( tiempo >= TIEMPO_MAXIMO ){
      digitalWrite( LED, LOW );
      encendido = false;
    }
  }

}
