#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

// Marki ESP32 LED and buzzer test.
//
// This is the tested first-control sketch from the physical build. It creates
// a local Wi-Fi access point and serves three simple controls: LED on, LED off,
// and a short buzzer test. It is deliberately separate from the OLED and
// two-board work, which are still being mapped and verified.

constexpr uint8_t LED_PIN = 18;
constexpr uint8_t BUZZER_PIN = 19;

const char* WIFI_NAME = "Marki";
// Set a private access-point password before uploading. Do not commit it.
const char* WIFI_PASSWORD = "CHANGE_ME_BEFORE_UPLOAD";

WebServer server(80);

void redirectHome() {
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(WIFI_NAME, WIFI_PASSWORD);

  server.on("/", []() {
    server.send(200, "text/html",
                "<h1>Marki Controller</h1>"
                "<a href='/on'><button>LED ON</button></a>"
                "<a href='/off'><button>LED OFF</button></a>"
                "<a href='/beep'><button>BUZZER TEST</button></a>");
  });

  server.on("/on", []() {
    digitalWrite(LED_PIN, HIGH);
    redirectHome();
  });

  server.on("/off", []() {
    digitalWrite(LED_PIN, LOW);
    redirectHome();
  });

  server.on("/beep", []() {
    tone(BUZZER_PIN, 2000, 250);
    redirectHome();
  });

  server.begin();
  Serial.println("Marki online!");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  server.handleClient();
}
 