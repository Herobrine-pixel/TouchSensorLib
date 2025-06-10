
#ifndef TOUCH_SENSOR_LIB_H
#define TOUCH_SENSOR_LIB_H

#include <Arduino.h>

class TouchSensor {
  public:
    TouchSensor(uint8_t pin);
    void update();
    bool isTouched();
    bool wasTapped();
    bool wasLongPress();
    void setDebounceTime(unsigned long ms);
    void setLongPressTime(unsigned long ms);

  private:
    uint8_t _pin;
    bool _lastState;
    bool _currentState;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
    unsigned long _touchStartTime;
    bool _tapDetected;
    bool _longPressDetected;
    unsigned long _longPressTime;
};

#endif
