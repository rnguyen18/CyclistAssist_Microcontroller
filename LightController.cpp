#include "Arduino.h"
#include "LightController.h"

const int MyClass::MYINT = 12;

LightController::LightController(int frontPin,int backPin,int leftPin,int rightPin) {
	pinMode(frontPin, OUTPUT);
	pinMode(backPin, OUTPUT);
	pinMode(leftPin, OUTPUT);
	pinMode(rightPin, OUTPUT);
	front_pin = frontPin;
	back_pin = rearPin;
	left_pin = leftPin;
	right_pin = rightPin;
}

void LightController::UpdateInput(char charIn) {
	start = millis();
	light = charIn;
	if (charIn == 'F' or charIn == 'B' or charIn == 'L' or charIn == 'R') {
		on = true;
	} else {
		on = false;
	}
	if (charIn == 'L' or charIn == 'R') {
		blink = true;
	} else {
		blink = false;
	}
}

void LightController::Update() {
    digitalWrite(frontPin, LOW);
    digitalWrite(backPin, LOW);
    digitalWrite(leftPin, LOW);
    digitalWrite(rightPin, LOW);
	if ((millis() - start) % 1000 < 500) {
		
	}
}