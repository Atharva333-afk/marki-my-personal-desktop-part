# parts and next steps

## parts i can see in the references

- ESP development board(s)
- small OLED display module
- full-size breadboard and jumper wires
- LEDs and resistors
- assorted sensors and breakout modules from the ELEGOO reference kit

this is more of a what-i-can-see list than a shopping list. i still want to confirm the exact part numbers before ordering replacements or drawing the final wiring diagram.

## things i still need to figure out

- the exact controller board model and board variant
- the OLED controller, resolution, and supported voltage
- the real GPIO assignments for the display
- the board-to-board communication protocol and power arrangement
- where the firmware will live, how to set it up, and how to run a repeatable test

## next steps

1. Label the two controller boards in the photos and write down their exact silkscreen names.
2. Fill in [`pin-map.csv`](pin-map.csv) while tracing each connection with the power disconnected.
3. Take a clean, top-down wiring photo once the current prototype stops moving around.
4. Add a small firmware test that starts the display and reports the selected I2C pins.
5. Write down the board-to-board link after the single-board display test is reliable.
6. Replace this working note with a drawn schematic once the pin map stops changing every five minutes.
