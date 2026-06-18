#ifndef CONFIG_H
#define CONFIG_H

// Pin Configuration
#define SOIL_PIN    34
#define RELAY_PIN   26
#define BUTTON_PIN  27
#define LED_PIN      2

// Relay Configuration
#define RELAY_ACTIVE_LOW true

// Serial Configuration
#define SERIAL_BAUD 115200

// Timing Configuration
#define TELEMETRY_INTERVAL_MS 3000
#define BUTTON_DEBOUNCE_MS   300

// WiFi Credentials
const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// IoT Lab / Server Configuration
const char* API_KEY = "YOUR_API_KEY";
const char* SERVER_URL = "SERVER_URL";

#endif
