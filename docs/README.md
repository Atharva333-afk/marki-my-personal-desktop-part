
# Marki, the build so far this is basically the build docs


ok so this is the shorter version of how Marki actually got to this point.

i wanted a little desk computer thing. something that could show a clock, my current task, a focus timer, or just a little face when it isn't doing anything. the whole thing should be controlled from my phone, but without having to build a massive app for it.

it started as an ESP8266 with an OLED, and somehow turned into two boards on a breadboard, a four digit display experiment, a bunch of wires, and a whole lot of figuring out why things weren't working lol.


## how it started

the first setup was an ESP8266 NodeMCU and an OLED screen. i was learning how the display connected, where SDA and SCL went, and how the breadboard actually worked. i also wanted the boards to be able to communicate with each other eventually, but that part is still a plan.

then i tried adding a 5641AS four digit display. i found two SN74HC595N shift registers and thought i could save a bunch of GPIO pins. technically that made sense, but once i started figuring out the segment wiring, resistors, and digit selection, it was way more wiring than i wanted. so i put that idea aside for now. i might use a display with a driver built in later.


## getting code onto the board was its own project

i wrote a very simple Wi-Fi controller for the ESP8266. it was supposed to make a network called Marki and let me press buttons on my phone. first i had to install the ESP8266 board package in Arduino IDE, because i couldn't even select the NodeMCU at the beginning.

the code compiled, but uploading was a whole different story.

```text
Failed to connect to ESP8266: Invalid head of packet (0x00)
```

i tried checking the USB port, lowering the upload speed, and using the FLASH/RST buttons. the onboard LED flashed when i connected it, so it was getting power, but the upload still wouldn't go through.

so i switched to my ESP32 DevKit V1, changed the libraries and GPIO pins, selected DOIT ESP32 DEVKIT V1 in Arduino IDE, and tried again. this time it actually uploaded.

```text
Hash of data verified.
Hard resetting via RTS pin...
```


## what worked, and the tiny LED situation

once the ESP32 was running, i connected my phone to the Marki Wi-Fi network and opened the little web controller at `http://192.168.4.1`. that worked. i pressed the buzzer button, and the buzzer actually made a sound. finally, something was doing what it was supposed to do.

the blue LED on GPIO18 wasn't cooperating, though. i traced the wiring hole by hole: yellow wire to F1, resistor from G1 to G2, LED from H2 to H3, then I3 to the ground rail. the layout was supposed to make a complete circuit, but i realized i didn't actually know the value of the resistor i'd used.

then i found a proper **220 ohm resistor** in the ELEGOO kit. i swapped it into the same spot. that fixed the resistor choice, but i'm keeping the final LED on/off test marked as one more thing to confirm, rather than pretending i already saw it working.


## where it stands right now

| part | status |
| --- | --- |
| ESP32 firmware upload | worked |
| Marki Wi-Fi and phone webpage | worked |
| Buzzer test | worked |
| Blue LED | 220 ohm resistor fitted; final retest to confirm |
| OLED interface | wired during testing; software still to do |
| Two-board communication | not finished |
| Four-digit display | experiment paused |
| Finished desktop case | definitely not yet |

i want to get the OLED showing something simple next. after that i can add clock, tasks, focus, status, custom messages, and maybe the little animated face. then i'll figure out whether the second board actually needs to do anything, and how to make the wiring less ridiculous.

the goal is still the same. i want Marki to feel like a real little device that has a reason to be on my desk, not just a pile of different Arduino tests.

more updates coming as Marki gets less breadboard and more desktop.

---

