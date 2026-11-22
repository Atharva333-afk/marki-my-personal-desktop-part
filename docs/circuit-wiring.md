# circuit wiring and component placement

this is my current wiring note for the breadboard setup in the photos. the photos are useful for seeing where things are sitting, but they cannot prove an exact pin number. i still need to check the board markings, module labels, and datasheets before calling the wiring final.

## where everything is

| item | where it appears | what still needs checking |
| --- | --- | --- |
| ESP development board(s) | In the middle and lower part of the workbench photo. One controller is next to the display in the portrait breadboard photo. | I still need to confirm the exact board model and GPIO numbering. |
| small OLED display | Beside the controller board in the portrait breadboard photo. The header looks like it has the usual power and I2C labels. | I need to check the display voltage and controller instead of guessing from the picture. |
| breadboard and jumper wires | Under and around the controller in the two build photos. | This is the current prototype layout, not the final tidy version. |
| LEDs, resistors, sensors, and other modules | Shown in the ELEGOO starter-kit reference image. | This is just a kit reference. It does not mean every pictured part is connected right now. |

## working wiring map

this is the starting point i am using while tracing the real wires. the `TBD` entries are there on purpose until the board labels and firmware agree with the physical setup.

| signal | from | to | what it is for | status |
| --- | --- | --- | --- | --- |
| power | The board's supported VCC/3V3 rail | Controller and display power pins | Give the modules the voltage they are meant to use | check before power-on |
| ground | Common ground rail | Controller GND and display GND | Give everything the same electrical reference | check continuity |
| I2C clock | Controller GPIO `TBD` | OLED `SCL` | Clock line for the display | confirm the real GPIO |
| I2C data | Controller GPIO `TBD` | OLED `SDA` | Data line for the display | confirm the real GPIO |
| board-to-board power | `TBD` | `TBD` | Work out how the second board will be powered | do not assume the breadboard rail is safe for both boards |
| board-to-board data | `TBD` | `TBD` | Let the two boards talk to each other | pick and write down the protocol first |

## bring-up checklist

1. Disconnect USB and any other power before moving a jumper wire.
2. Check the exact controller board and the display's VCC requirement from the silkscreen or datasheet.
3. Make sure the ground rail is continuous and that the controller and display share it.
4. Trace the power, `SCL`, and `SDA` wires one at a time, then write them in [pin-map.csv](pin-map.csv).
5. Power the controller by itself first. Add the display only after the voltage and polarity checks look right.
6. Add the second board and board-to-board communication after the single-board display test is stable.

the photo is not enough to prove a pin assignment. especially do not connect a 5 V rail to a 3.3 V-only module unless the module's documentation says that it is okay.

## file map

- [`assets/README.md`](../assets/README.md) — the visual asset gallery.
- [`assets/images/marki-workbench-wiring.jpg`](../assets/images/marki-workbench-wiring.jpg) — the workbench wiring photo.
- [`assets/images/marki-board-and-oled.jpg`](../assets/images/marki-board-and-oled.jpg) — the controller and OLED breadboard photo.
- [`assets/images/elegoo-starter-kit.webp`](../assets/images/elegoo-starter-kit.webp) — the component-kit reference image.
- [`docs/pin-map.csv`](pin-map.csv) — where i am writing down checked connections.
- [`docs/parts-and-next-steps.md`](parts-and-next-steps.md) — the parts list and the next things to figure out.
