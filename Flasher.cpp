#include "Flasher.h"

  Flasher::Flasher(int pin, unsigned long on, unsigned long off)
  {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);     
    digitalWrite(ledPin, HIGH);
    OnTime = on;
    OffTime = off;
    
    ledState = LOW; 
	  previousMillis = 0;

    n=2;
  }

  void Flasher::Update()
  {
    // check to see if it's time to change the state of the LED 
    
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime) && (n<2))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)&&(n<2))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);	  // Update the actual LED
      n++;
    }
  }

  void Flasher::setN(int times){
    n = times;
  }