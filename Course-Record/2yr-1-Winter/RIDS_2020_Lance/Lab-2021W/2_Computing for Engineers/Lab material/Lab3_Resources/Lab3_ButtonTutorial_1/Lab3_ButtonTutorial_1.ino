/**
 * demonstrate how to check for button clicks using the EE108 library
 * 
 * This version checks the button state briefly on each repetition of the superloop.
 * It does not wait for a click and the entire loop function repeats rather quickly.
 * (See ButtonTutorial_2 for a version that waits and prevents the superloop repeating
 * quickly.)
 */

#include <ee108.h>

const int SUPERLOOP_MS = 50;

void setup() {
  Serial.begin(9600);

  pinMode(LED1_PIN, OUTPUT);

  Serial.println("=========== Lab3_ButtonTutorial_1 starting ============");
}

void loop() {
  int sw1Event; // will be used to get SW1 events
  int sw2Event; // will be used to get SW2 events

  // check if SW1 is clicked
  // sw1Object is declared in ee108_switches.h and refers to switch SW1

  // when SW1 is pressed nothing happens. We only detect the click (i.e.
  // when the button is released) and then print out whether it was a normal
  // or long click. No LED lights for SW1 at any point.
  sw1Event = readSwitchEvent(sw1Object);
  if (sw1Event == SW_CLICK)
    Serial.println("SW1 was clicked");
  else if (sw1Event == SW_CLICK_LONG)
    Serial.println("SW1 was long-clicked");

  // check if SW2 is pressed in any way (i.e. a press just started or it has been
  // held down continously), and light LED1 when it is pressed. There is no
  // text output for SW2.
  // sw2Object refers to SW2

  sw2Event = readSwitchEvent(sw2Object); 
  if (sw2Event & SW_ON_ANY)
    digitalWrite(LED1_PIN, HIGH);
  else
    digitalWrite(LED1_PIN, LOW);

  // The possible return values of readSwitchEvent are:
  // SW_OFF_CONTINUED -- button not pressed now (and not pressed the previous time we checked)
  // SW_ON_START -- button has just been pressed (it was not pressed last time we checked)
  // SW_ON_CONTINUED -- button is pressed now and was pressed last time we checked also
  //                    (i.e. it is being pressed continuously)
  // SW_CLICK -- the button has just been released and switched off. This marks the completion
  //                    of a normal click (i.e. a press and release sequence)
  // SW_CLICK_LONG -- the same as SW_CLICK except that the button was pressed
  //                  continuously for a rather long time before releasing

  delay(SUPERLOOP_MS);
}
