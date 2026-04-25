# Grain moisture monitoring system

## Project Overview

The **Grain Moisture Monitoring System** is an IoT-based solution designed to detect and monitor environmental conditions affecting stored grains. This system uses multiple sensors connected to an Arduino microcontroller to collect real-time data about grain quality, storage conditions, and security.

The system helps farmers and storage managers maintain grain quality, prevent spoilage, and reduce losses by providing continuous monitoring of critical environmental parameters.

---

## Key Features

- **Real-time Moisture Detection**: Monitors water content in grains to prevent spoilage
- **Temperature & Humidity Tracking**: Ensures optimal storage conditions
- **Motion Detection**: Identifies unauthorized access or disturbances in the storage area
- **Distance Monitoring**: Tracks grain levels and detects obstacles
- **Live LCD Display**: All data is displayed on a 16x2 LCD screen for easy monitoring
- **Serial Monitoring**: Data is also logged to the Serial Monitor for debugging and record-keeping

---

## Hardware Components

| Component | Model | Purpose |
|-----------|-------|---------|
| Microcontroller | Arduino Uno | Central processing unit |
| Moisture Sensor | FC-28 | Detects water content in grains |
| Temperature & Humidity Sensor | DHT11 | Monitors ambient conditions |
| Motion Sensor | PIR | Detects unauthorized access |
| Distance Sensor | Ultrasonic (HC-SR04) | Measures grain levels |
| Display | 16x2 LCD with I2C Module | Shows real-time data |
| Supporting Components | Breadboard, Jumper Wires, USB Cable | Connections and power |

---

## System Architecture

### Sensor Connections

- **Moisture Sensor (FC-28)**: Analog Pin A0
- **DHT11 Sensor**: Digital Pin (configurable)
- **PIR Motion Sensor**: Digital Input Pin
- **Ultrasonic Sensor (HC-SR04)**:
  - TRIG Pin: Digital Output Pin
  - ECHO Pin: Digital Input Pin
- **LCD Display with I2C**: SDA and SCL pins

### Processing Flow

1. Arduino reads sensor values from all connected sensors
2. Data is processed and converted to meaningful units (moisture %, temperature °C, distance cm, etc.)
3. Information is displayed on the LCD screen in two alternating screens
4. All values are printed to the Serial Monitor for logging

---

## System Operation

### Display Screens

**Screen 1**: Moisture, Temperature, and Humidity
- Shows real-time grain moisture level
- Displays ambient temperature and humidity
- Helps monitor storage environment quality

**Screen 2**: Distance and Motion Status
- Shows distance measured by ultrasonic sensor (grain level)
- Displays motion detection status
- Ensures security and storage monitoring

**Alert Screen**: Moisture Threshold Warning
- Triggers when moisture exceeds safe levels
- Visual warning displayed on LCD
- Prevents catastrophic grain loss due to excess moisture

---

## System Logic (Pseudocode)

```
BEGIN
  SET moisture pin as A0
  SET PIR pin as INPUT
  SET TRIG pin as OUTPUT
  SET ECHO pin as INPUT
  INITIALIZE LCD
  INITIALIZE DHT11 sensor
  START serial communication

  LOOP forever:
    READ moisture value from A0
    READ temperature from DHT11
    READ humidity from DHT11
    READ motion value from PIR

    // Ultrasonic sensor reading
    SET TRIG LOW
    WAIT 2 microseconds
    SET TRIG HIGH
    WAIT 10 microseconds
    SET TRIG LOW
    READ duration from ECHO
    CALCULATE distance = duration × 0.034 / 2

    // Display Screen 1: Moisture, Temperature, Humidity
    DISPLAY on LCD:
      SHOW moisture value
      SHOW temperature and humidity
    WAIT 2 seconds
    CLEAR LCD

    // Display Screen 2: Distance and Motion
    DISPLAY on LCD:
      SHOW distance
      SHOW motion status
    WAIT 2 seconds

    // Log to Serial Monitor
    PRINT all values to Serial Monitor

  END LOOP
END
```

---

## Key Monitoring Parameters

| Parameter | Sensor | Unit | Purpose |
|-----------|--------|------|---------|
| Grain Moisture | FC-28 | % | Detect spoilage risk |
| Temperature | DHT11 | °C | Monitor storage conditions |
| Humidity | DHT11 | % | Ensure optimal environment |
| Motion | PIR | Status | Detect disturbances |
| Grain Level | Ultrasonic | cm | Monitor storage quantity |

---

## Safety Features

- **Moisture Threshold Alert**: Automatic visual warning when moisture exceeds safe levels
- **Motion Detection**: Alerts on unauthorized access or disturbances
- **Continuous Monitoring**: 24/7 real-time data collection prevents grain loss
- **Fail-Safe Design**: Threshold-based warnings trigger preventive measures

---

## Project Team

| Sl. No | Name | SRN |
|--------|------|-----|
| 1 | Bhavya K | PES1UG24AM066 |
| 2 | Diya B R | PES1UG24AM097 |
| 3 | Bhogala Srika | PES1UG24AM067 |

---

## Getting Started

### Prerequisites
- Arduino IDE installed
- USB cable for Arduino programming
- Required Arduino libraries:
  - `LiquidCrystal_I2C` (for LCD display)
  - `DHT` (for DHT11 sensor)

### Installation Steps
1. Connect all components as per the circuit diagram
2. Upload the Arduino sketch to the microcontroller
3. Open Serial Monitor (9600 baud rate) to view logs
4. Power on the system and monitor the LCD display

---

## Applications

- **Agricultural Storage**: Monitor grain silos and storage facilities
- **Warehouse Management**: Track environmental conditions in bulk storage
- **Quality Control**: Prevent spoilage through early warning systems
- **Loss Prevention**: Reduce grain losses due to moisture and contamination
- **Security Monitoring**: Track access to sensitive storage areas

---

## Future Enhancements

- Cloud connectivity for remote monitoring
- Mobile app for real-time notifications
- Data logging and analytics dashboard
- Integration with automated ventilation systems
- Multi-location monitoring network

---

## License

This project is developed as part of the MPCA (Microcontroller and Embedded Systems) course.

---

*Last Updated: 2026*
