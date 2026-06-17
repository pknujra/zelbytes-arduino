# IoT Lab Telemetry Documentation

## Overview

This task demonstrates posting telemetry data to the Zelbytes IoT Learning Lab using a Python script and mock sensor values.

## Device Information

**Device ID:** `mock_device_01`

**Endpoint:**

```text
POST /api/iot-lab/v1/telemetry
```

**Authentication Header:**

```text
X-Iot-Lab-Key: <API_KEY>
```

## Day 11 CSV Format

Example CSV row:

```csv
temperature_c,humidity_pct,soil_moisture_pct,co2_ppm
28.6,76.5,40.3,913
```

## Field Mapping

| CSV Column        | JSON Field        | Description                  | Unit |
| ----------------- | ----------------- | ---------------------------- | ---- |
| temperature_c     | temperature_c     | Ambient temperature          | °C   |
| humidity_pct      | humidity_pct      | Relative humidity            | %    |
| soil_moisture_pct | soil_moisture_pct | Soil moisture level          | %    |
| co2_ppm           | co2_ppm           | Carbon dioxide concentration | ppm  |

## Example JSON Payload

```json
{
  "device_id": "mock_device_01",
  "temperature_c": 28.6,
  "humidity_pct": 76.5,
  "soil_moisture_pct": 40.3,
  "co2_ppm": 913
}
```

## Verification

Telemetry samples were successfully posted to the IoT Lab telemetry endpoint and verified through the IoT Lab Dashboard/API Explorer.

A dashboard screenshot showing the received telemetry samples is included with the submission.

```
```
