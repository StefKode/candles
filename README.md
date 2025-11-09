# Arduino Nano Project

A PlatformIO project for Arduino Nano (ATmega328P) with a basic blink example and serial output.

## Project Structure

- `src/main.cpp` - Main source file with blink example
- `platformio.ini` - PlatformIO configuration
- `lib/` - Place for project-specific libraries
- `.pio/` - Build files and temporary data (auto-generated)

## Building and Uploading

1. Build the project:
```bash
platformio run
```

2. Upload to Arduino Nano:
```bash
platformio run --target upload
```

3. Monitor serial output:
```bash
platformio device monitor
```

## Configuration

The project is configured for Arduino Nano with ATmega328P. If you have an older board with the original bootloader, uncomment the appropriate upload_speed setting in `platformio.ini`.

### Serial Monitor

Serial output is configured at 115200 baud with time stamps and colors enabled. You can adjust these settings in `platformio.ini`.
