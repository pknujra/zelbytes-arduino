// Day 9 - HC-SR04 Distance Sensor

const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;

const unsigned long READ_INTERVAL_MS = 500;
unsigned long lastRead = 0;

//--------------------------------------------------
// Single distance measurement
//--------------------------------------------------
float readDistanceCM() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;   // timeout / invalid
  }

  float distance = duration * 0.0343 / 2.0;

  return distance;
}

//--------------------------------------------------
// Median of 3 filter
//--------------------------------------------------
float median3(float a, float b, float c) {

  if (a > b) { float t = a; a = b; b = t; }
  if (b > c) { float t = b; b = c; c = t; }
  if (a > b) { float t = a; a = b; b = t; }

  return b;
}

//--------------------------------------------------
void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  Serial.println(F("time_s,distance_cm"));
}

//--------------------------------------------------
void loop() {

  if (millis() - lastRead >= READ_INTERVAL_MS) {

    lastRead = millis();

    float d1 = readDistanceCM();
    delay(20);

    float d2 = readDistanceCM();
    delay(20);

    float d3 = readDistanceCM();

    // Check for invalid readings
    if (d1 < 0 || d2 < 0 || d3 < 0) {

      Serial.print(millis() / 1000);
      Serial.println(F(",INVALID"));

      return;
    }

    float distance = median3(d1, d2, d3);

    Serial.print(millis() / 1000);
    Serial.print(",");

    Serial.println(distance, 1);
  }
}
