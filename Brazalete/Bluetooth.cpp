#include "Bluetooth.h"

Bluetooth::Bluetooth(){
  pSerialBluetooth = new SoftwareSerial( 2, 3 );//RX,TX
  pSerialBluetooth->begin( 9600 );
}

byte Bluetooth::ejecutar(){

  if( pSerialBluetooth->available() > 0 ){

    int c = pSerialBluetooth->read();
    // 48 en ASCII es 0, 49 es 1, 50 es 2

    switch ( c ) {
      case 49:
        return 1;
      case 50:
        return 2;
      case 51:
        return 3;
      default:
        return 0;
    }

  }

}
