#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

constexpr uint8_t SDA_PIN = 21;
constexpr uint8_t SCL_PIN = 22;
constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

uint8_t oledAddress = 0;
unsigned long testCount = 0;
unsigned long lastUpdate = 0;

bool deviceResponds(uint8_t address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

bool findOled() {
  if (deviceResponds(0x3C)) {
    oledAddress = 0x3C;
    return true;
  }

  if (deviceResponds(0x3D)) {
    oledAddress = 0x3D;
    return true;
  }

  return false;
}

void drawTestScreen() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MARKI OLED TEST");
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);
  display.setCursor(0, 17);
  display.println("Display: FOUND");
  display.setCursor(0, 29);
  display.print("Address: 0x");
  display.println(oledAddress, HEX);
  display.setCursor(0, 41);
  display.println("SDA: GPIO21");
  display.setCursor(0, 51);
  display.print("SCL: GPIO22");
  display.setCursor(88, 17);
  display.print("#");
  display.println(testCount);
  display.display();
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("Marki OLED screen test");
  Serial.println("Starting I2C...");

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!findOled()) {
    Serial.println("OLED not found at address 0x3C or 0x3D.");
    while (true) {
      delay(1000);
    }
  }

  Serial.print("OLED found at address 0x");
  Serial.println(oledAddress, HEX);

  if (!display.begin(SSD1306_SWITCHCAPVCC, oledAddress)) {
    Serial.println("SSD1306 initialization failed.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("OLED initialized successfully.");
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println("OLED");
  display.setCursor(10, 34);
  display.println("READY");
  display.display();
  delay(1500);
}

void loop() {
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();
    testCount++;
    drawTestScreen();
    Serial.print("OLED refresh: ");
    Serial.println(testCount);
  }
}
