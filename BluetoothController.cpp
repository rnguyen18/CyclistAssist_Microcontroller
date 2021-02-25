#include "Arduino.h"
#include "BluetoothController.h"
#include <SoftwareSerial.h>

BluetoothController::BluetoothController(int rxPin,int txPin);
	rx_pin = rxPin;
	tx_pin = txPin;
	mySerial(rxPin, txPin);
	mySerial.begin(9600);
}

BluetoothController::Read() {
  if (mySerial.available()>0){
    char_input = mySerial.read();
  }
}

BluetoothController::Write(char char_output) {
  if (Serial.available()>0) {
    mySerial.write(char_output);
  }
}