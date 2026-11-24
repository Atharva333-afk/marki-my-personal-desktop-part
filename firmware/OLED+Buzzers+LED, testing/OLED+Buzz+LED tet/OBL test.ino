#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Marki hardware

const int LED_PIN = 18;
const int BUZZER_PIN = 19;

const int t int SCL_int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

const char* WIFI_NAME = "marki";
const char* WIFI_PASSWORD = "tungtung123";


Adafruit_SSD1306 display(
      SCREEN_WIDTH,
        SCREEN_HEIGHT,
          &Wire,
            -1
);

WebServer server(80);


bool oledReady = false;
bool ledOn = false;

uint8_t oledAddress = 0;

unsigned long lastScreenUpdate = 0;
unsigned long lastHeartbeat = 0;

int beepCount = 0;
int blinkCount = 0;


const char* brainrot[] = {
      "ESP32 locked in",
        "OLED got aura",
          "wifi has motion",
            "GPIO is cooking",
              "buzzer crashout",
                "marki final boss",
                  "absolute cinema",
                    "hardware rizz",
                      "bro became router",
                        "firmware maxxing",
                          "I2C locked in",
                            "LED has motion"
};

const int brainrotCount =
  sizeof(brainrot) / sizeof(brainrot[0]);


  bool i2cDeviceExists(uint8_t address) {
      Wire.beginTransmission(address);

        return Wire.endTransmission() == 0;
  }


  bool findOLED() {
      if (i2cDeviceExists(0x3C)) {
            oledAddress = 0x3C;
                return true;
      }

        if (i2cDeviceExists(0x3D)) {
                oledAddress = 0x3D;
                    return true;
        }

          return false;
    }


    bool startOLED() {
          Wire.begin(SDA_PIN, SCL_PIN);

            Serial.println("Looking for OLED...");

              if (!findOLED()) {
                    Serial.println("OLED not found at 0x3C or 0x3D");
                        Serial.println("bro disappeared from the I2C bus");

                            return false;
              }

                if (!display.begin(
                            SSD1306_SWITCHCAPVCC,
                                    oledAddress
                )) {
                        Serial.println("SSD1306 failed to start");

                            return false;
                }

                  display.clearDisplay();
                    display.setTextColor(SSD1306_WHITE);
                      display.display();

                        Serial.print("OLED found at 0x");
                          Serial.println(oledAddress, HEX);

                            return true;
            }


            void showMessage(
                  const String& title,
                    const String& showMessage) {
                          if (!oledReady) {
                                return;
                          }

                            display.clearDisplay();
                              display.setTextSize(1);

                                display.setCursor(0, 0);
                                  display.println(title);

                                    display.drawLine(
                                            0,
                                                11,
                                                    127,
                                                        11,
                                                            SSD1306_WHITE
                                    );

                                      display.setCursor(0, 19);
                                        display.println(message);

                                          display.display();
                                }


                                void showBootScreen() {
                                      if (!oledReady) {
                                            return;
                                      }

                                        display.clearDisplay();

                                          display.setTextSize(2);
                                            display.setCursor(34, 8);
                                              display.println("MARKI");

                                                display.setTextSize(1);
                                                  display.setCursor(24, 35);
                                                    display.println("booting up...");

                                                      display.setCursor(13, 51);
                                                        display.println("bro is locked in");

                                                          display.display();

                                                            delay(1000);

                                    }


                                    void setLED(bool state) {
                                          digitalWrite(
                                                LED_PIN,
                                                    state ? HIGH : __LONG_WIDTH__  );

                                                      ledOn = state;
                                          }


                                          void blinkLED(
                                              int times,
                                                int delayTime
                                          ) {
                                              for (int i = 0; i < times; i++) {
                                                    setLED(true);

                                                        delay(delayTime);

                                                            setLED(false);

                                                                delay(delayTime);

                                                                    blinkCount++;
                                              }
                                            }


                                            void beep(
                                                  int frequency,
                                                    int duration
                                            ) {
                                                  tone(
                                                        BUZZER_PIN,
                                                            frequency,
                                                                duration
                                                  );

                                                    delay(duration);

                                                      noTone(BUZZER_PIN);

                                                        beepCount++;
                                                }


                                                void startupSound() {
                                                      beep(500, 90);
                                                        delay(40);

                                                          beep(700, 90);
                                                            delay(40);

                                                              beep(900, 140);
                                                }


                                                void successSound() {
                                                      beep(650, 70);
                                                        delay(30);

                                                          beep(850, 70);
                                                            delay(30);

                                                              beep(1100, 140);
                                                }


                                                void errorSound() {
                                                      beep(300, 180);

                                                        delay(70);

                                                          beep(200, 250);
                                                }


                                                void buzzerSweep() {
                                                      Serial.println("running buzzer sweep");

                                                        for (int frequency = 300;
                                                                   frequency <= 1500;
                                                                          frequency += 150) {

                                                                                tone(BUZZER_PIN, frequency);

                                                                                    delay(60);
                                                                          }

                                                                            noTone(BUZZER_PIN);

                                                                              beepCount++;

                                                                                Serial.println("buzzer survived");
                                                                        }


                                                                        void oledTest() {
                                                                              if (!oledReady) {
                                                                                    return;
                                                                              }

                                                                                Serial.println("testing OLED");

                                                                                  display.clearDisplay();

                                                                                    display.drawRect(
                                                                                            0,
                                                                                                0,
                                                                                                    128,
                                                                                                        64,
                                                                                                            SSD1306_WHITE
                                                                                    );

                                                                                      display.drawCircle(
                                                                                            64,
                                                                                                32,
                                                                                                    18,
                                                                                                        SSD1306_WHITE
                                                                                      );

                                                                                        display.drawLine(
                                                                                                0,
                                                                                                    0,
                                                                                                        127,
                                                                                                            63,
                                                                                                                SSD1306_WHITE
                                                                                        );

                                                                                          display.drawLine(
                                                                                                127,
                                                                                                    0,
                                                                                                        0,
                                                                                                            63,
                                                                                                                SSD1306_WHITE
                                                                                          );

                                                                                            display.display();

                                                                                              delay(700);

                                                                                                showMessage(
                                                                                                        "OLED TEST",
                                                                                                            "display has aura"
                                                                                                );

                                                                                                  delay(700);
                                                                                            }


                                                                                            bool startWiFi() {
                                                                                                  Serial.println();
                                                                                                    Serial.println("Starting Marki WiFi");

                                                                                                      WiFi.mode(WIFI_AP);

                                                                                                        bool started = WiFi.softAP(
                                                                                                                WIFI_NAME,
                                                                                                                    WIFI_PASSWORD
                                                                                                        );

                                                                                                          if (!started) {
                                                                                                                Serial.println("WiFi failed");
                                                                                                                    Serial.println("router arc cancelled");

                                                                                                                        return false;
                                                                                                          }

                                                                                                            Serial.print("Network: ");
                                                                                                              Serial.println(WIFI_NAME);

                                                                                                                Serial.print("IP: ");
                                                                                                                  Serial.println(WiFi.softAPIP());

                                                                                                                    Serial.println("bro became the router");

                                                                                                                      return true;
                                                                                                        }


                                                                                                        String randomB
      }
}
)