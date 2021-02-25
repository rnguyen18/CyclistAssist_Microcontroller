#include <SoftwareSerial.h>
#include <LightController.h>
#include <BluetoothController.h>

int rxPin = 52;
int txPin = 50;
int frontPin = 53;
int rearPin = 53;
int leftPin = 51;
int rightPin = 53;
char sig = 0;
int start = 0;
SoftwareSerial mySerial(rxPin,txPin); 

void setup()
{
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);   
  Serial.begin(9600);  
  Serial.write("Start");
  delay(100);
}

void loop()
{
  if (Serial.available()>0) {
    mySerial.write(Serial.read());
  }
  if (mySerial.available()>0){
    sig = mySerial.read();
    start = millis();
    Serial.write(sig);
  }
  if ((millis() - start) % 1000 < 500) {
    if (sig == 'R') {
      digitalWrite(leftPin, HIGH);
      digitalWrite(rightPin, LOW);
    }
    else if (sig == 'L') {
      digitalWrite(rightPin, HIGH);
      digitalWrite(leftPin, LOW);
    }
    else if (sig == '3') {
      digitalWrite(leftPin, HIGH);
      digitalWrite(rightPin, HIGH);
    }
  } else {
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, LOW);
  }
}
