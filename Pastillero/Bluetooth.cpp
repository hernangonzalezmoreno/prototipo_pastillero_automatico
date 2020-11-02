#include "Bluetooth.h"

Bluetooth::Bluetooth( Delta *pD ){
  pDelta = pD;
  pSerialBluetooth = new SoftwareSerial( 2, 3 );//RX,TX
  pSerialBluetooth->begin( 9600 );
}

void Bluetooth::enviarMsj( byte _msj ){
  msj = _msj;
  envioActivo = true;
  numeroDeEnvio = 0;
  enviar();
}

void Bluetooth::ejecutar(){

  if( !envioActivo ) return;

  tiempoEnvio += pDelta->get();
  if( tiempoEnvio >= TIEMPO_ENTRE_ENVIOS ) enviar();

  if( numeroDeEnvio >= CANTIDAD_DE_ENVIOS ) envioActivo = false;

}

void Bluetooth::enviar(){
  pSerialBluetooth->println( msj );
  numeroDeEnvio++;
  tiempoEnvio = 0;
}
