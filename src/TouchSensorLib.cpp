
#include "TouchSensorLib.h"

TouchSensor::TouchSensor(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
  _lastState = LOW;
  _currentState = LOW;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
  _tapDetected = false;
  _longPressDetected = false;
  _longPressTime = 1000;
}

void TouchSensor::setDebounceTime(unsigned long ms) {
  _debounceDelay = ms;
}

void TouchSensor::setLongPressTime(unsigned long ms) {
  _longPressTime = ms;
}

void TouchSensor::update() {
  bool reading = digitalRead(_pin);
  if (reading != _lastState) {
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (reading != _currentState) {
      _currentState = reading;
      if (_currentState == HIGH) {
        _touchStartTime = millis();
        _tapDetected = false;
        _longPressDetected = false;
      } else {
        unsigned long duration = millis() - _touchStartTime;
        if (duration >= _longPressTime) {
          _longPressDetected = true;
        } else {
          _tapDetected = true;
        }
      }
    }
  }
  _lastState = reading;
}

bool TouchSensor::isTouched() {
  return _currentState;
}

bool TouchSensor::wasTapped() {
  if (_tapDetected) {
    _tapDetected = false;
    return true;
  }
  return false;
}

bool TouchSensor::wasLongPress() {
  if (_longPressDetected) {
    _longPressDetected = false;
    return true;
  }
  return false;
}
