#pragma once

#include "Global.h"

class Flasher
{
	// Class Member Variables
	// These are initialized at startup
	int ledPin;      // the number of the LED pin
	unsigned long OnTime;     // milliseconds of on-time
	unsigned long OffTime;    // milliseconds of off-time

	// These maintain the current state
	int ledState;             		// ledState used to set the LED
	unsigned long previousMillis;  	// will store last time LED was updated

  int n;

  public:
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  Flasher(int pin, unsigned long on, unsigned long off);
  
  void setN(int times);

  //Update led states
  void Update();
};