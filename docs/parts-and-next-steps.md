# Parts and next steps

## parts visible in the supplied references

- ESP development board(s)
- Small OLED display module
- Full-size breadboard and jumper wires
- LEDs and resistors
- Assorted sensors and breakout modules from the ELEGOO reference kit

This is a visual inventory, not a purchase list. Confirm the exact part numbers before ordering replacements or writing a final wiring diagram.

## documentation gaps to close

- Exact controller board model and board variant
- Exact OLED controller, resolution, and supported voltage
- Verified GPIO assignments for the display
- Board-to-board communication protocol and power arrangement
- Firmware location, setup steps, and a repeatable test command

## recommended next steps

1. Label the two controller boards in the photos and record their exact silkscreen names.
2. Fill in [`pin-map.csv`](pin-map.csv) while tracing each connection with power disconnected.
3. Capture a clean, top-down wiring photo after the current prototype is stable.
4. Add a small firmware test that initializes the display and reports the selected I2C pins.
5. Document the board-to-board link separately once the single-board display test is reliable.
6. Replace this working note with a drawn schematic when the pin map stops changing.
