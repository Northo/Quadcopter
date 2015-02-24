#include "Arduino.h"

class Blink {
 private:
 unsigned long _onInterval;
 unsigned long _offInterval;
 uint8_t _blinkingLedId;
 bool _ledActivity;
 
public:
 
Blink(unsigned long onInterval, unsigned long offInterval, uint8_t blinkingLedId);
 
void oneBlink();
 
void setLedActivity(bool ledActivity);
 };
