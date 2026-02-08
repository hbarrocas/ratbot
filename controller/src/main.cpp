#include <Arduino.h>
#include "controller.h"

int main()
{
	init();
	Controller c;

	c.run();
}
