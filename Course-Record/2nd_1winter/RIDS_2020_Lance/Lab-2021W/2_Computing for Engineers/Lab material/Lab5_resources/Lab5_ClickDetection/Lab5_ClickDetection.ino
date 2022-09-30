/**
 * This is possibly the simplest demonstration of
 * click detection using the ee108 library
 */

#include <ee108.h>

const int SUPERLOOP_MS = 20;

// ==============================================================
// top level functions
// ==============================================================
 
void setup() {
  // serial output
  Serial.begin(9600);

  Serial.println("====== Lab5_ClickDetection starting ========");
}

void loop() {
  int sw1Event;

  // Input
  sw1Event = readSwitchEvent(sw1Object);

  // processing and output 
  if (sw1Event == SW_CLICK) {
    // output 1
    Serial.println("[Click]");
  } else if (sw1Event == SW_CLICK_LONG) {
    // output 2
    Serial.println("[LongClick]");
  }

  delay(SUPERLOOP_MS);
}
