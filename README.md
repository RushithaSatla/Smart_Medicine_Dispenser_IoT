# Smart Medicine Dispenser

The **Smart Medicine Dispenser** is an IoT-based device developed to assist patients in taking their medication on time. It automatically dispenses the correct dosage at preset times, helping users adhere to their medication schedules. This is especially beneficial for elderly patients or those managing multiple prescriptions. The dispenser uses sensors, microcontroller functions, and alarms/notifications to make medication management easier and more reliable.

## Features

- **Automated Dispensing**: Dispenses medication at pre-set times, reducing the chances of missed doses.
- **User Alerts**: Uses visual and audible alerts to notify the user when it's time to take medication.
- **Customizable Schedule**: Allows setting of various dispensing times based on user needs.
- **Status Monitoring**: Monitors medication levels to ensure timely refills.

## Components Used

- **Microcontroller**: ESP32 
- **Servo Motor**: Controls the compartment openings
- **Real-Time Clock (RTC)**: Keeps track of dosing schedules
- **Buzzer**: Notifies the user with sound alerts
- **LED**: Indicates status (e.g., Green for ready, Red for refill required)
- **Display**: (Optional) Shows the time, date, and dosing schedule on an LCD screen

## Wiring

| Component        | Pin Number on ESP32 | Description                      |
|------------------|---------------------|----------------------------------|
| Servo Motor      | 18                  | Controls dispensing mechanism    |
| RTC (SDA)        | 21                  | Data line for real-time clock    |
| RTC (SCL)        | 22                  | Clock line for real-time clock   |
| Buzzer           | 15                  | Provides sound alert             |
| LED (Green)      | 23                  | Indicates the ready state        |
| LED (Red)        | 19                  | Indicates low medication level   |
| Button           | 13                  | Manual dispense button (optional)|

## How It Works

1. **Time Tracking**: The RTC keeps the current time and matches it to the preset schedule for dispensing.
2. **Medication Dispensing**: When the time matches a scheduled dose, the servo motor activates to open the compartment, dispensing the required dosage.
3. **Alerts**: The buzzer sounds to notify the user that medication is ready, while the green LED lights up. If medication levels are low, the red LED will turn on.


## Setup and Configuration

1. **Install Required Libraries**:
   - ESP32Servo: For controlling the servo motor
   - RTClib: For real-time clock support
2. **Set Up the Circuit**:
   - Connect the components to the ESP32 as per the wiring table above.
3. **Upload the Code**:
   - Write or modify the code to include your specific dosage times.
   - Upload the code to the ESP32.

