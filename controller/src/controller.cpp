#include <Arduino.h>
#include <Wire.h>
#include "controller.h"

void Controller::run()
{
	Wire.begin();

	while(1) {
		//update_encoders();
		//update_pid();
	}
}
