#ifndef withoutDelay_h
#define withoutDelay_h

#include "Arduino.h"

class withoutDelay
{
  public:
    withoutDelay(unsigned long interval);
    bool timeOver();
    void changeInterval(unsigned long newInterval);
  private:
    unsigned long _interval;
    unsigned long _currentMillis ;
    unsigned long _previousMillis;
};

#endif
