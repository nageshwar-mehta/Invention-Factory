#include <Wire.h>
#include "Adafruit_MPR121.h"

// Create the MPR121 objects
Adafruit_MPR121 cap = Adafruit_MPR121();
Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    // Wait for serial port to be available
  }

  Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

  // Initialize the first MPR121
  if (!cap.begin(0x5A)) { // Specify the address here
    Serial.println("MPR121 #1 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 #1 found!");

  // Initialize the second MPR121
  if (!cap1.begin(0x5C)) { // Specify the address here
    Serial.println("MPR121 #2 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 #2 found!");

  // Initialize the third MPR121
  if (!cap2.begin(0x5D)) { // Specify the address here
    Serial.println("MPR121 #3 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 #3 found!");
}

void loop() {
  // Get the touch state for all 12 electrodes on the first MPR121
  uint16_t touched1 = cap.touched();
  Serial.print("Touched 1: 0x"); Serial.println(touched1, HEX);

  // Iterate over each electrode and print if it's touched on the first MPR121
  for (uint8_t i = 0; i < 12; i++) {
    if (touched1 & (1 << i)) {
      Serial.print("MPR121 #1 Electrode "); Serial.print(i); Serial.println(" is touched");
    }
  }

  // Get the touch state for all 12 electrodes on the second MPR121
  uint16_t touched2 = cap1.touched();
  Serial.print("Touched 2: 0x"); Serial.println(touched2, HEX);

  // Iterate over each electrode and print if it's touched on the second MPR121
  for (uint8_t i = 0; i < 12; i++) {
    if (touched2 & (1 << i)) {
      Serial.print("MPR121 #2 Electrode "); Serial.print(i); Serial.println(" is touched");
    }
  }

  // Get the touch state for all 12 electrodes on the third MPR121
  uint16_t touched3 = cap2.touched();
  Serial.print("Touched 3: 0x"); Serial.println(touched3, HEX);

  // Iterate over each electrode and print if it's touched on the third MPR121
  for (uint8_t i = 0; i < 12; i++) {
    if (touched3 & (1 << i)) {
      Serial.print("MPR121 #3 Electrode "); Serial.print(i); Serial.println(" is touched");
    }
  }

  // Small delay to avoid overwhelming the serial output
  delay(100);
}
