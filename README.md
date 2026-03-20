# TouchDesigner Projector Lightshow

A creative system for real-time visual projection and LED control combining TouchDesigner visualization with Arduino-based LED matrices and pixel-mapped cubes. This project enables synchronized audio-reactive light effects across projectors and LED installations.

## 🎨 Project Overview

This repository integrates multiple visualization and lighting technologies:

- **TouchDesigner** - Real-time visual effects and projection design
- **LED Cube Mapping** - Pixel-mapped LED cubes with dynamic animations
- **Arduino Control** - Microcontroller-based LED matrix and LED strip control
- **UDP Communication** - Network-based control protocol for coordinating effects across devices
- **Audio Reactivity** - Audio-triggered visual and lighting effects

## 📁 Project Structure

### Root Level
- `AudioTox.tox` - Audio processing and analysis module for TouchDesigner
- `beamer_switch.toe` - Projector control and switching interface
- `beamer_switch_abstract.toe` - Abstract projector visualization system

### Cubes Folder (`/Cubes`)
LED cube-specific files for pixel mapping and LED control:
- `LEDmapping.toe` - Main LED cube mapping and visualization
- `240510_01_CubeUnwrapDMX.toe` - DMX unwrapping for cube control
- `Pixel Mapping with TouchDesigner & Arduino.toe` - Pixel mapping tutorial/reference
- `cube_script/cube_script.ino` - Arduino firmware for LED matrix control
- `Backup/` - Previous versions of LED mapping files

### zaubermuehle-led-main Folder
Python-based LED control system:
- `effects.py` - Effect definitions and animations (Pulse, Chase, Rainbow, Strobe, etc.)
- `leds.py` - LED cube/installation classes and control logic
- `led2udp.py` - Main controller that listens for UDP commands and triggers effects
- `arduino_effects/arduino_effects.ino` - Arduino firmware for LED effects
- `udp2led/udp2led.ino` - UDP receiver firmware for LED control via network

## 🔌 System Architecture

### Communication Flow
```
TouchDesigner (Visual Control)
    ↓
UDP Network Protocol
    ↓
Python LED Controller (led2udp.py)
    ↓
Arduino Microcontroller
    ↓
LED Matrices / LED Strips / Pixel-Mapped Cubes
```

### Key Components

**TouchDesigner (.toe files)**
- Create and design visual effects
- Send UDP commands to control LEDs
- Synchronize projections with lighting

**Python LED System**
- `Installation` class manages LED cube setup
- Hosts effects library with customizable parameters
- Receives UDP commands on port 6543
- Sends LED data to Arduino on port 3456 (192.168.11.100)

**Arduino**
- Receives UDP packets with LED color data
- Controls WS2812B LED strips or LED matrices in real-time
- Manages individual pixel or LED control

## 🚀 Getting Started

### Prerequisites
- TouchDesigner (free or commercial version)
- Python 3.7+ on the control machine
- Arduino board (UNO R4 WiFi or compatible)
- WS2812B addressable LED strips or LED matrices
- Network connection between machines

### Hardware Setup
1. Connect Arduino to power
2. Connect WS2812B LED strips/matrices to Arduino GPIO pins
3. Connect all devices to the same network
4. Update IP addresses in `led2udp.py` if needed:
   ```python
   ARDUINO_UDP_IP = "192.168.11.100"
   ARDUINO_UDP_PORT = 3456
   ```

### Software Setup
1. Upload Arduino firmware to your microcontroller
   - Use `arduino_effects/arduino_effects.ino` or `udp2led/udp2led.ino`
2. Install Python dependencies (check requirements if available)
3. Run the Python LED controller:
   ```bash
   python led2udp.py
   ```
4. Open desired `.toe` file in TouchDesigner
5. Configure TouchDesigner to send UDP commands to trigger effects

## 🎬 Available Effects

The system includes various visual effects (defined in `effects.py`):
- **PulseEffect** - Pulsing brightness animations
- **ChaseEffect** - Running light patterns
- **UnicolorEffect** - Solid color output
- **StrobeEffect** - Rapid on/off effects
- **RainbowEffect** - Cycling color effects
- **FadeEffect** - Smooth color transitions
- **BlinkEffect** - Timed blink animations
- **ColorExplosionEffect** - Burst effects
- **ColorWaveEffect** - Wave patterns
- And many more customizable effects

## ⚙️ Configuration

### Adjusting Effects
Edit `led2udp.py` to enable/disable effects and set timing:
```python
EFFECTS = [
    PulseEffect,
    ChaseEffect,
    # Add or remove effects here
]

EFFECT_TIME = 4.0  # Seconds per effect
```

### Brightness Control
```python
leds.brightness = 0.1  # Set to 0.0-1.0
```

### Network Configuration
Update IP and port settings for your network:
```python
ARDUINO_UDP_IP = "192.168.11.100"
ARDUINO_UDP_PORT = 3456
LOCAL_UDP_PORT = 6543  # TouchDesigner sends to this port
```

## 📡 UDP Protocol

TouchDesigner sends commands to the Python controller on `LOCAL_UDP_PORT` (6543). The system then routes these to the appropriate effects and sends LED data to Arduino.

## 🛠️ Troubleshooting

- **LEDs not responding**: Check network connectivity and verify IP addresses match
- **Effects not changing**: Ensure `led2udp.py` is running and listening on correct port
- **Arduino upload issues**: Verify correct board and COM port selection in Arduino IDE
- **Flickering**: Check power supply capacity for LED strips
- **Communication delays**: Consider reducing effect duration if experiencing lag

## 📝 Notes

- The system supports multiple cube configurations (8-cube setup shown)
- Effects can be extended by adding new classes to `effects.py`
- Adjust `EFFECT_TIME` in `led2udp.py` for different animation durations
- Default brightness is set to 0.1 for safety; increase gradually when testing

## 🔗 Related Technologies

- **TouchDesigner** - https://derivative.ca/
- **Arduino** - https://www.arduino.cc/
- **Python Socket Programming** - Network communication
- **WS2812B LEDs** - Addressable RGB LED strips