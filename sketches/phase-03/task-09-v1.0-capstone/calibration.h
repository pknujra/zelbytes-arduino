#ifndef CALIBRATION_H
#define CALIBRATION_H

// Soil Sensor Calibration
// Change these values based on your actual dry and wet readings
#define SOIL_DRY_ADC  4095
#define SOIL_WET_ADC  0

// Soil Threshold
// If raw soil value is greater than this, soil is considered dry
#define DRY_THRESHOLD 2000

#endif
