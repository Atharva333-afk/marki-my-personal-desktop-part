# Marki firmware

## ESP32 LED and buzzer test

[`esp32_led_buzzer_test.ino`](esp32_led_buzzer_test/esp32_led_buzzer_test.ino) is the small hardware test that was uploaded to the ESP32. It starts a local access point, serves a simple controller page, and lets me switch the LED or trigger a short buzzer sound.

The pin assignments used in this test are GPIO 18 for the LED and GPIO 19 for the buzzer. They are specific to this test build, not a confirmed map for the OLED or the eventual two-board setup.

Before uploading, replace `CHANGE_ME_BEFORE_UPLOAD` with a private password locally. Do not commit that password back to this repository.

## Upload notes

1. Open the sketch in Arduino IDE with an ESP32-compatible board selected.
2. Confirm the actual LED and buzzer wiring before connecting power.
3. Set a local access-point password in the sketch.
4. Upload and open Serial Monitor at 115200 baud.
5. Connect to the `Marki` network and open the IP address printed by the board.

The Arduino screenshots in [`../assets/arduino-screenshots/`](../assets/arduino-screenshots/) document the original compile and upload session. They are evidence of this small test, not proof that the final hardware design is complete.
