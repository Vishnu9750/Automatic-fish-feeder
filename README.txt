Automatic Fish Feeder

Overview:

This project is an Automatic Fish Feeder controlled by an ESP32 microcontroller, which dispenses fish food every 6 hours using a servo motor. The feeder is integrated with the Blynk app, allowing remote control to turn the feeder on/off and adjust the amount of food delivered based on the fish count. The ESP32 connects to Wi-Fi for real-time control via the app.

Features:

Automatic Feeding: Dispenses food every 6 hours using a timer, controlled by a servo motor.
Blynk Integration: Allows users to control the feeder remotely, turn the feeding mechanism on or off, and adjust the amount of food through a slider.
Adjustable Feed Amount: Users can adjust the feed amount based on the number of fish by setting a value in the Blynk app.

Components:
ESP32: Main microcontroller to manage the servo motor and Blynk integration.
Servo Motor (Pin 13): Controls the rotation that moves the stick attached to the bottle to dispense food.
Bottle and Stick: Used to hold and dispense fish food.
Blynk App: Allows users to control the system remotely via Wi-Fi.
Power Supply (5V): To power the ESP32 and servo motor.

Circuit Diagram:

Servo Motor: Connected to digital pin 13 of the ESP32.
Power Supply: Use 5V to power the ESP32 and servo motor.

Working:

Automatic Feeding: The servo motor is programmed to rotate and dispense fish food every 6 hours. The rotation angle is set based on the number of fish (controlled by the fish count in the Blynk app).
Blynk Control: Users can turn the feeding system on or off using a switch in the Blynk app. Additionally, users can set the fish count using a slider, which determines how much food will be dispensed.
Fish Count Adjustment: If the fish count is set to zero, the system automatically turns off to avoid unnecessary feeding.

Procedure:

Step 1: Gather Components
ESP32
Servo Motor
Bottle and Stick
Wires and Jumper Cables
Blynk App (for remote control)

Step 2: 
Circuit Assembly
Servo Motor:

VCC → 5V on ESP32
GND → GND on ESP32
Signal → Digital pin 13 on ESP32
Power Supply:

Step 3: 

Install Arduino IDE and Blynk Library
Install Arduino IDE on your computer.
Install the Blynk library for ESP32.
Connect the ESP32 to your computer using a USB cable.

Step 4:Upload the Code

Open the Arduino IDE.
Copy and paste the following code into the IDE editor:
Select the Arduino Uno board and the correct COM port from the Tools menu in the IDE.
Click the Upload button to upload the code to the Arduino.

Step 5: Set Up Blynk App

Install the Blynk app on your smartphone.
Create a new project in the Blynk app and add the following widgets:
Switch (V0) to turn the feeder on or off.
Slider (V1) to set the fish count.
Use the Blynk Auth Token from your project in the code.

Step 6: Verify Working

Test the system to ensure that the servo motor dispenses food every 6 hours, and that the system can be controlled remotely via the Blynk app.

