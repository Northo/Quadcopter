#include "Arduino.h"
#include "blink.h"

Blink::Blink(unsigned long onInterval, unsigned long offInterval, uint8_t blinkingLedId):
_onInterval(onInterval), _offInterval(offInterval), _blinkingLedId(blinkingLedId)
	     {
	       _ledActivity = true;
	       pinMode(_blinkingLedId, OUTPUT);
	     }
	     void Blink::oneBlink() {
	       if(_ledActivity == false)
		 return;

	       digitalWrite(_blinkingLedId, HIGH);
	       delay(_onInterval);

	       digitalWrite(_blinkingLedId, LOW);
	       delay(_offInterval);
	     }

	     void Blink::setLedActivity(bool ledActivity) {
	       _ledActivity = ledActivity;
	     }
