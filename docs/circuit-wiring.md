# Circuit wiring and component placement

This document records the current breadboard layout shown in the supplied photos. It is a visual working note, not a final electrical schematic. Verify every connection against the exact board markings, module labels, and datasheets before powering the circuit.

## where everything is

| item | where it appears | current documentation status |
| --- | --- | --- |
| ESP development board(s) | Center and lower area of the workbench photo; one controller is beside the display in the portrait breadboard photo. | The exact board model and GPIO numbering still need to be confirmed. |
| Small OLED display | Beside the controller board in the portrait breadboard photo. The module header visibly uses power and I2C-style labels. | Treat the display voltage and controller as unverified until the module markings are checked. |
| Breadboard and jumper wires | Under and around the controller board in the two build photos. | This is the current prototype wiring layout. |
| LEDs, resistors, sensors, and other modules | Shown in the ELEGOO starter-kit reference image. | Reference inventory only; it does not prove that every pictured part is currently connected. |

## working wiring map

Use this as a checklist while tracing the physical wiring. The `TBD` entries are intentional until the board labels and firmware are verified.

| signal | from | to | purpose | status |
| --- | --- | --- | --- | --- |
| power | Supported board VCC/3V3 rail | Controller and display power pins | Supply the modules at their rated voltage | Verify before power-on |
| ground | Common ground rail | Controller GND and display GND | Provide a shared electrical reference | Verify continuity |
| I2C clock | Controller GPIO `TBD` | OLED `SCL` | Display clock | Confirm exact GPIO |
| I2C data | Controller GPIO `TBD` | OLED `SDA` | Display data | Confirm exact GPIO |
| board-to-board power | `TBD` | `TBD` | Power plan for the second board | Do not assume the breadboard rail is safe for both boards |
| board-to-board data | `TBD` | `TBD` | Communication between the two boards | Choose and document the protocol first |

## bring-up checklist

1. Disconnect USB and any external supply before moving jumper wires.
2. Identify the exact controller board and the display's VCC requirement from their silkscreen or datasheet.
3. Confirm that the ground rail is continuous and that the controller and display share it.
4. Trace the power, `SCL`, and `SDA` wires one at a time and record them in [pin-map.csv](pin-map.csv).
5. Power only the controller first, then connect the display after the voltage and polarity checks pass.
6. Add the second board and board-to-board communication only after the single-board display test is stable.

Never treat the photo alone as proof of a pin assignment. In particular, do not connect a 5 V rail to a 3.3 V-only module without confirming that the module supports it.

## file map

- [`assets/README.md`](../assets/README.md) — visual asset gallery.
- [`assets/images/marki-workbench-wiring.jpg`](../assets/images/marki-workbench-wiring.jpg) — workbench wiring photo.
- [`assets/images/marki-board-and-oled.jpg`](../assets/images/marki-board-and-oled.jpg) — controller and OLED breadboard photo.
- [`assets/images/elegoo-starter-kit.webp`](../assets/images/elegoo-starter-kit.webp) — component-kit reference image.
- [`docs/pin-map.csv`](pin-map.csv) — connection worksheet.
- [`docs/parts-and-next-steps.md`](parts-and-next-steps.md) — inventory and follow-up work.
