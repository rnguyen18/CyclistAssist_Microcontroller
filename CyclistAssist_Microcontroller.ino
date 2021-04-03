#include <SoftwareSerial.h>
#include <BluetoothController.h>
#include <LightController.h>

int rxPin = 12;
int txPin = 10;
int headlightPin = 5;
int leftPin = 4;
int rightPin = 3;

BluetoothController bluetoothController(rxPin, txPin);
LightController lightController(headlightPin, leftPin, rightPin);

void setup()
{
  Serial.begin(9600);  
  Serial.write("Start");
  delay(100);
}

void loop()
{
  if (Serial.available()>0) {
    bluetoothController.Write(Serial.read());
  }

  lightController.UpdateInput(bluetoothController.Read());
  lightController.Update();
}
