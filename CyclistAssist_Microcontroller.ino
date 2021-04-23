#include <SoftwareSerial.h>
#include <BluetoothController.h>
#include <LightController.h>
#include <SpeedometerController.h>
#include <BrakeLightController.h>
#include <BlindspotDetector.h>
#include <String.h>

// Bluetooth
int rxPin = 12;
int txPin = 13;

// Speedometer
int speedPin = 8;

// Brake Light
int sensorPin = 7;
int brakePin = 6;

// Head Lights
int headlightPin = 5;
int rearPin = 9;

// Turn Signals
int leftPin = 3;
int rightPin = 4;

// Radar
int triggerPinA = 28;
int echoPinA = 29;
int triggerPinB = 37;
int echoPinB = 36;
unsigned long radarTime = 0;

BlindspotDetector blindspotDetector(triggerPinA, echoPinA, triggerPinB, echoPinB);
BluetoothController bluetoothController(rxPin, txPin);
LightController lightController(headlightPin, leftPin, rightPin, rearPin);
SpeedometerController speedometerController(speedPin);
BrakeLightController brakeLightController(sensorPin, brakePin);

void setup()
{ 
  Serial.begin(9600);
  Serial.write("Start\n");
  delay(100);
}

void loop()
{
  brakeLightController.Update();

  lightController.UpdateInput(bluetoothController.Read());
  lightController.Update();
  
   int speedData = speedometerController.Update();
  if (speedData >= 0) {
    bluetoothController.WriteString("S" + String(speedData) + " ");
  }
  
  bluetoothController.Update();

  if ((millis() - radarTime + 500) > 1000) {
    radarTime = millis() + 500;
    bluetoothController.WriteString("R" + String(blindspotDetector.Update()) + " ");
  }
}
