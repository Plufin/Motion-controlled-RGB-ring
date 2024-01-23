# MPU6050 LED Ring Display with Tilt-Based Pixel Growth & Color


This Arduino code is designed for an MPU6050 accelerometer sensor and a NeoPixel ring, providing a LED display that adjusts the number of illuminated pixels based on the tilt angle. As the tilt angle increases, more LEDs light up in a specific color, creating a visual representation of the tilt intensity.
You can also move the location of the LEDs based on the rotation of the accelerometer. This provides a 360-degree representation of movement, both direction and tilt.

### Angles
- Minimal = No light
- Small = Blue pixel
- Medium = Green pixels
- High =  Red pixels

## Components Required

- Arduino board
- MPU6050 accelerometer sensor
- NeoPixel ring (16 LEDs)

## Libraries Used

- Adafruit_MPU6050: Library for interfacing with the MPU6050 sensor.
- Adafruit_NeoPixel: Library for controlling NeoPixel LEDs.



## Code Explanation

### Sensor Setup

- Initializes communication with the MPU6050 sensor and checks for its presence.
- If the sensor is not found, the program enters an infinite loop.

### LED Ring Setup

- NeoPixel ring initialization, setting the brightness to 50.

### Accelerometer Configuration

- Configures the accelerometer sensor and prints its details.

### Main Loop

- Reads acceleration data from the accelerometer.
- Maps the acceleration data to LED positions, color values, and brightness.
- Dynamically adjusts the number of illuminated pixels based on the tilt angle, creating a visually proportional display.
- Sets the color of the corresponding LEDs on the NeoPixel ring based on the tilt angle.
- Clears the LED display in each iteration to update the colors.
- Delays for a specified interval before the next iteration.
