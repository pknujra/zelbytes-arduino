import requests
import time
import random

API_KEY = "YOUR_API_KEY"

URL = "SERVER_URL"

headers = {
    "Content-Type": "application/json",
    "X-Iot-Lab-Key": API_KEY
}

for i in range(10):
    payload = {
        "device_id": "bench-01",
        "temperature_c": round(random.uniform(22, 30), 1),
        "humidity_pct": random.randint(50, 90),
        "soil_moisture_pct": random.randint(30, 70),
        "co2_ppm": random.randint(400, 1000)
    }

    response = requests.post(URL, headers=headers, json=payload)

    print(f"Sample {i+1}: {response.status_code}")
    print(response.text)

    time.sleep(1)

print("Finished sending telemetry")
