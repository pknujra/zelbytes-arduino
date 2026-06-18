#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>

#include "config.h"
#include "calibration.h"

bool pumpState = false;
bool manualMode = false;

WebServer webServer(80);

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

void setPump(bool state) {
  pumpState = state;

  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, pumpState ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, pumpState ? HIGH : LOW);
  }

  digitalWrite(LED_PIN, pumpState ? HIGH : LOW);
}

void relayON() {
  manualMode = true;
  setPump(true);
  webServer.send(200, "text/plain", "Relay ON");
}

void relayOFF() {
  manualMode = true;
  setPump(false);
  webServer.send(200, "text/plain", "Relay OFF");
}

void relaySTATUS() {
  String statusText = pumpState ? "ON" : "OFF";
  webServer.send(200, "text/plain", statusText);
}

int readSoilPercent(int rawSoil) {
  int soilPercent = map(rawSoil, SOIL_DRY_ADC, SOIL_WET_ADC, 0, 100);
  return constrain(soilPercent, 0, 100);
}

void sendTelemetry(int soilPercent) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(SERVER_URL);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-Iot-Lab-Key", API_KEY);

    String payload = "{\"soil_moisture_pct\":" + String(soilPercent) + "}";

    int code = http.POST(payload);

    Serial.print("POST Code: ");
    Serial.println(code);

    http.end();
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  setPump(false);

  connectWiFi();

  webServer.on("/on", relayON);
  webServer.on("/off", relayOFF);
  webServer.on("/status", relaySTATUS);

  webServer.begin();

  Serial.println("Web Server Started");
  Serial.println("Commands: STATUS, FORCE_ON, FORCE_OFF");
}

void loop() {
  webServer.handleClient();

  int rawSoil = analogRead(SOIL_PIN);
  int soilPercent = readSoilPercent(rawSoil);

  if (digitalRead(BUTTON_PIN) == LOW) {
    manualMode = !manualMode;
    setPump(!pumpState);
    delay(BUTTON_DEBOUNCE_MS);
  }

  if (!manualMode) {
    if (rawSoil > DRY_THRESHOLD) {
      setPump(true);
    } else {
      setPump(false);
    }
  }

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "STATUS") {
      Serial.println("=== STATUS ===");

      Serial.print("Raw Soil: ");
      Serial.println(rawSoil);

      Serial.print("Soil Moisture %: ");
      Serial.println(soilPercent);

      Serial.print("Pump: ");
      Serial.println(pumpState ? "ON" : "OFF");

      Serial.print("Mode: ");
      Serial.println(manualMode ? "MANUAL" : "AUTO");
    }

    else if (cmd == "FORCE_ON") {
      manualMode = true;
      setPump(true);
      Serial.println("FORCE_ON: Pump ON");
    }

    else if (cmd == "FORCE_OFF") {
      manualMode = true;
      setPump(false);
      Serial.println("FORCE_OFF: Pump OFF");
    }

    else {
      Serial.println("Unknown command");
    }
  }

  sendTelemetry(soilPercent);

  delay(TELEMETRY_INTERVAL_MS);
}