#define BLYNK_TEMPLATE_ID "TMPL3Q-Gf11Bj"
#define BLYNK_TEMPLATE_NAME "Smart Fish Feeder"
#define BLYNK_AUTH_TOKEN "uWrUHC4g9-8MVJf0LbUtGZydmHp3vuV7"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;  // Auth Token from Blynk
char ssid[] = "kalai";  // Your Wi-Fi name
char pass[] = "kalai1234";  // Your Wi-Fi password

Servo servo;
int servoPin = 13;
int fishCount = 0;  // Initial fish count
bool isServoOn = false;  // Flag to check if servo should rotate

BlynkTimer timer;

void rotateServo() {
  if (fishCount > 0) {
    for (int i = 0; i < fishCount; i++) {
      servo.write(90);  // Rotate 90 degrees
      delay(1000);  // Hold position for 1 second
      servo.write(0);   // Reset to 0 degrees
      delay(1000);  // Delay between each rotation
    }
  }
}

void periodicFeed() {
  if (isServoOn && fishCount > 0) {
    rotateServo();  // Feed based on the same fish count every 6 hours
  }
}

BLYNK_WRITE(V0) {
  isServoOn = param.asInt();  // Get switch state from Blynk
  if (isServoOn && fishCount > 0) {
    rotateServo();  // Rotate based on fish count if switch is on and fish count > 0
    timer.setInterval(6L * 3600L * 1000L, periodicFeed);  // Set the timer to feed every 6 hours
  }
}

BLYNK_WRITE(V1) {
  fishCount = param.asInt();  // Get fish count from slider
  if (fishCount == 0) {
    Blynk.virtualWrite(V0, 0);  // Turn off the switch if fish count is 0
  }
}

void setup() {
  Blynk.begin(auth, ssid, pass);
  servo.attach(servoPin);  // Attach the servo motor to pin 13
  servo.write(0);  // Initialize servo to 0 degrees
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run the Blynk timer
}

