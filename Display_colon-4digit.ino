              
/*
Electronics Studio
@file Display_colon-4digit.ino
@date  23-04-2025
@url https:https: https://github.com/electronicsstudio
@url YouTube: https://www.youtube.com/@ElectronicsStudio-v7o/featured
*/

#include <TM1637.h>

// Instantiation and pins configurations
// Pin 3 -> DIO
// Pin 2 -> CLK
TM1637 tm(2, 3);

void setup() {
    tm.begin();
    tm.setBrightnessPercent(90);
}

// Function to toggle the colon state (on/off)
void toggleColon() {
    static bool colonState = false;
    if (colonState) {
        tm.colonOff(); // Turn colon off
    } else {
        tm.colonOn(); // Turn colon on
    }
    colonState = !colonState; // Toggle colonState for next iteration
}

void loop() {
    // Display Integers:
    tm.display(1234);
    toggleColon(); // Toggle colon state
    delay(2000); // Half-second delay for blinking effect

    // Display float:
    tm.display(1020);
    toggleColon(); // Toggle colon state
    delay(2000); // Half-second delay for blinking effect

    // Display String:
    tm.display("PLAY");
    toggleColon(); // Toggle colon state
    delay(2000); // Half-second delay for blinking effect

    tm.display("STOP");
    toggleColon(); // Toggle colon state
    delay(2000); // Half-second delay for blinking effect
}
