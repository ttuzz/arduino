#include "withoutDelayH.h"


withoutDelay::withoutDelay(unsigned long interval) {
  _interval = interval;
  _previousMillis = 0;
}

bool withoutDelay::timeOver() {
  _currentMillis = millis();
  if (_currentMillis - _previousMillis >= _interval) {
    _previousMillis = _currentMillis;
    return 1;
  }
  return 0;
}

void withoutDelay::changeInterval(unsigned long newInterval) {
  _interval = newInterval;
}

