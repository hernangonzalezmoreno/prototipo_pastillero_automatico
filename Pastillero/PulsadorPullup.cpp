#include "PulsadorPullup.h"

PulsadorPullup::PulsadorPullup( uint8_t _pin ){
  pin = _pin;
  pinMode( pin, INPUT_PULLUP );
}

bool PulsadorPullup::isPressed(){
  if( digitalRead( pin ) == 0 ) return true;
  else return false;
}
