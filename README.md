# The RGB WS2812 or SK6812 testing signal generator

A simple hookup for powering on and testing the addressed RGB LED or LED strip.

Built using [PlatformIO](https://platformio.org/) and [Wokwi for VSCode](https://wokwi.com/) for simulation.

### Features:
- Parameters adjustment using encoder
- Support a single or many LEDs
- OLED display

### Hardware:
- MCU (Arduino Uno, Arduino Nano, Arduino Pro Mini, STM32F103C8T6 Blue Pill)
- OLED display with I2C or SPI interface
- KY-040 encoder module
- WS2812 or SK6812 LED

### Configuration

Some PlatformIO configurations are included in the platformio.ini file.

Defines are used for configuration. They are listed in build_flags in platformio.ini:

`SG_BOARD` - MCU dev board selection.
- uno
- nano
- promini
- bluepill

`DISPLAY_SPI` - define if OLED display is using SPI interface.
`DISPLAY_I2C` - define if OLED display is using I2C interface.

The full pin configuration is located in src/pinconfig.h file.