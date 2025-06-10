# TouchSensor Arduino Library

The **TouchSensor** library provides a simple and reliable way to interface with capacitive touch modules like the **TTP223** using Arduino boards. With built-in debounce and edge detection, this library is ideal for touch-based input in interactive electronics, smart switches, and DIY projects.

---

## 🔧 Supported Hardware

- **TTP223 capacitive touch sensor**
- Any other capacitive touch sensor with a digital output pin
- Works with all Arduino-compatible boards (Uno, Nano, Mega, ESP32, etc.)

---

## ✨ Features

- 📲 **Touch detection** via simple `.isTouched()` function
- ⏱️ **Built-in debounce** support to avoid false multiple triggers
- 🔁 **Edge detection**:
  - `.justTouched()` — true only on the transition from not touched to touched
  - `.justReleased()` — true only on the transition from touched to not touched
- 🧠 **Clean abstraction** over `digitalRead()` with enhanced control
- ⚡ **Lightweight** and fast: minimal memory and CPU usage

---

## 🚀 Getting Started

### 1. **Installation**

You can install this library by:
- Downloading the ZIP from GitHub and adding it via **Arduino IDE > Sketch > Include Library > Add .ZIP Library**
- Or placing it in your `Arduino/libraries` folder manually

### 2. **Wiring Example (TTP223)**

| TTP223 Pin | Connect To        |
|------------|-------------------|
| VCC        | 3.3V or 5V (Arduino) |
| GND        | GND (Arduino)     |
| OUT        | Digital Pin (e.g., D2) |

---

## 💻 Example Code

```cpp
#include <TouchSensor.h>

TouchSensor touch(2);  // TTP223 sensor connected to digital pin 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  touch.update();  // Always call this first to refresh sensor state

  if (touch.isTouched()) {
    Serial.println("Currently being touched");
  }

  if (touch.justTouched()) {
    Serial.println("Touch started");
  }

  if (touch.justReleased()) {
    Serial.println("Touch ended");
  }

  delay(50);  // Adjust debounce timing if needed
}
```

---

## 📚 API Reference

| Method              | Description |
|---------------------|-------------|
| `TouchSensor(pin)`  | Constructor — sets the pin the sensor is connected to |
| `void update()`     | Refreshes internal state — must be called in `loop()` |
| `bool isTouched()`  | Returns `true` if the sensor is currently touched |
| `bool justTouched()`| Returns `true` only on the frame when touch starts |
| `bool justReleased()`| Returns `true` only on the frame when touch ends |

---

## 🧪 Applications

- Capacitive **touch light switch**
- **Smart home** control panels
- **Secret keypad** (touch-based password input)
- **Contactless interfaces** in public devices
- **DIY electronics** and Arduino projects

---

## 🛠️ Advanced Tips

- To make your sensor more or less sensitive, try:
  - Increasing the **grounding** around the sensor pad
  - Adding a resistor (~1MΩ) between OUT and GND for stability
- Works well with **interrupts** if `.update()` is moved into an ISR-safe structure

---

## 📄 License

This library is licensed under the [MIT License](LICENSE), so you are free to use, modify, and distribute it in personal or commercial projects.

---

## 👤 Author

Developed and maintained by **Herobrine Sah**

Feel free to [open an issue](https://github.com/your-repo/issues) or submit a pull request if you'd like to improve the library.

---

## 📦 Repository Structure

```
TouchSensor/
├── examples/
│   └── BasicTouch/             # Sample sketch
│       └── BasicTouch.ino
├── src/
│   └── TouchSensor.h
│   └── TouchSensor.cpp
├── library.properties
├── README.md
├── LICENSE
└── keywords.txt
```

---

## 🔗 Related Projects

- [ArduinoButton Library](https://github.com/LennartHennigs/Button) – Similar logic but for mechanical buttons
- [CapacitiveSensor Library](https://playground.arduino.cc/Main/CapacitiveSensor/) – For analog capacitive sensors

---

Happy Tinkering! 🛠️
