#include "Bluetooth.h"

Bluetooth::Bluetooth(){
  pSerialBluetooth = new SoftwareSerial( 2, 3 );//RX,TX
  pSerialBluetooth->begin( 9600 );
}
