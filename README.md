# TouchSensorLib

A simple Arduino library to work with capacitive touch sensors like TTP223.

## Features

- Detects touch press
- Tap detection
- Long press detection
- Debounce handling

## Usage

```cpp
#include <TouchSensorLib.h>

TouchSensor touch(4);

void setup() {
  touch.setDebounceTime(50);
}

void loop() {
  touch.update();
  if (touch.wasTapped()) {
    // do something
  }
}
```

## License

MIT License