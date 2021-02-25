/*
  BluetoothController.h - Library for controlling lights.
*/

#ifndef BluetoothController_h
#define BluetoothController_h

#include "Arduino.h"

class BluetoothController
{
  public:
    BluetoothController(int rxPin,int txPin);
    void Write();
    void Read();
  private:
    int rx_pin;
    int tx_pin;
};

#endif