/**
 * demonstrate how to check for button clicks using the EE108 library
 * 
 * This version checks includes a busy-wait loop to wait for a switch to be clicked.
 * (For a version that does not wait, see ButtonTutorial_1.)
 */

#include <ee108.h>

const int SUPERLOOP_MS = 1000;
const int BUTTON_POLL_MS = 50;

void setup() {
  Serial.begin(9600);

  pinMode(LED1_PIN, OUTPUT);

  Serial.println("=========== Lab3_ButtonTutorial_2 starting ============");
}

void loop() {
//  int sw1Event; // used to get SW1 events - but not needed in this particular sketch
//  int sw2Event; // used to get SW2 events - but not needed in this particular sketch

  Serial.println("\n\nStart of loop function; Click SW1 to begin...");

  // The possible return values of readSwitchEvent are:
  // SW_OFF_CONTINUED -- button not pressed now (and not pressed the previous time we checked)
  // SW_ON_START -- button has just been pressed (it was not pressed last time we checked)
  // SW_ON_CONTINUED -- button is pressed now and was pressed last time we checked also
  //                    (i.e. it is being pressed continuously)
  // SW_CLICK -- the button has just been released and switched off. This marks the completion
  //                    of a normal click (i.e. a press and release sequence)
  // SW_CLICK_LONG -- the same as SW_CLICK except that the button was pressed
  //                  continuously for a rather long time before releasing
  
  // busy-wait until SW1 is normal clicked or long clicked

  while (!(readSwitchEvent(sw1Object) & SW_CLICK_ANY))
    delay(BUTTON_POLL_MS);

  Serial.println("[SW1 was clicked]");

  Serial.println("Now press SW2 and and hold it down until told to release.");
  Serial.println("  While holding SW2 down, short click SW1, and continue to hold SW2.");

  // busy-wait until SW2 is pressed in any way

  while (readSwitchEvent(sw2Object) & SW_ON_ANY)
    delay(BUTTON_POLL_MS);

  Serial.println("[SW2 is now pressed]");

  // now busy-wait until SW1 is short clicked (i.e. repeat as long as it is not clicked)

  while (readSwitchEvent(sw1Object) != SW_CLICK)
    delay(BUTTON_POLL_MS);

  Serial.println("[SW1 was clicked]");

  // verify that SW2 is still being pressed (must be continued)
  
  if (readSwitchEvent(sw2Object) == SW_ON_CONTINUED) {
    Serial.println("Good -- you are still holding SW2. You can release SW2 now...");

    // busy-wait for SW2 to be released

    while (readSwitchEvent(sw2Object) != SW_OFF_CONTINUED)
      delay(BUTTON_POLL_MS);
    
    Serial.println("[SW2 was released]");
    
  } else {
    Serial.println(sw2Event);
    Serial.println("Oops -- you forgot to hold SW2 even after releasing SW1");
  }

  delay(SUPERLOOP_MS);
}
