/**
 * Starter sketch for Lab3 - iteration
 */

#include <ee108.h>

const int BUTTON_POLL_MS = 50;

const int NUM_REPS = 5;
const int BETWEEN_REPS_MS = 500;

const int LED_ON_MS = 100;
const int LED_OFF_MS = 50;


void setup() {
  int ledIndex;
  
  Serial.begin(9600);
  Serial.println("============== starting Lab3_BarLedScan_Starter ============");  

  // using a loop, we iterate over all Bar LED pins, enabling each one as an OUTPUT.
  // NOTE the idiom BAR_LED_1_PIN + ledIndex to get the pin number for any bar led
  // according to it's zero based index, e.g. where the second led has index 1
  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++)
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
}

int ledIndex;

void loop() {
  int sw1Event; // used when checking SW1
  int sw2Event; // user when checking SW2
  
  Serial.println("\nloop function starting -- click SW1 to begin");

  // busy wait at this point until SW1 is clicked (i.e. wait while sw1Event is not a click)
  
  while (readSwitchEvent(sw1Object) != SW_CLICK)
    delay(BUTTON_POLL_MS);

  // TODO - at this point button SW1 has definitely been clicked
  // implement the rest of the lab as specified in the lab doc.
  // You will need a loop (a while-loop or for-loop) that repeats NUM_REPS times
  // and in each iteration/repetition you'll have to do some things as specified
  // in the lab doc.
  for (int ledIndex = 0; ledIndex < 11; ledIndex++)
  {
     Serial.print("Rep ");
     Serial.print(ledIndex+1);
     digitalWrite(BAR_LED_1_PIN, HIGH);
     delay(LED_ON_MS);
     digitalWrite(BAR_LED_1_PIN, LOW);
     delay(LED_OFF_MS);
  
     if(readSwitchEvent(sw2Object) == SW_ON_CONTINUED)
     {
          while (readSwitchEvent(sw2Object) != SW_OFF_CONTINUED)
            delay(BUTTON_POLL_MS);
          Serial.println();
          ledIndex=ledIndex-1;
          continue;
      }
     Serial.print(", Placeholder – bar LED scan would go here");
     Serial.println("");
     delay(BETWEEN_REPS_MS);
  }
     Serial.println("end of repetitions loop");  
  
}
