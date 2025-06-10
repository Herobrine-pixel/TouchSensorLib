
#include <TouchSensorLib.h>

TouchSensor touch(4); // Connect TTP223 OUT to D4

void setup() {
  Serial.begin(9600);
  touch.setDebounceTime(50);
  touch.setLongPressTime(1000);
}

void loop() {
  touch.update();

  if (touch.isTouched()) {
    Serial.println("Touching...");
  }

  if (touch.wasTapped()) {
    Serial.println("Tapped!");
  }

  if (touch.wasLongPress()) {
    Serial.println("Long Press Detected!");
  }

  delay(50);
}
