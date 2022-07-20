/**
 * Each time the loop function is called, flash the next Bar LED
 * in the range 1-5. Use a counter that is incremented on each
 * repetition of the loop function and wrapped to the range 0-4
 * inclusive to achieve this.
 */

#include <ee108.h>


const int SUPERLOOP_MS = 1000;
const int LED_ON_MS = 50;
const int NUM_LEDS = 5;

void setup() {
  // initialize 5 bar LEDs
  pinMode(BAR_LED_1_PIN, OUTPUT);
  pinMode(BAR_LED_2_PIN, OUTPUT);
  pinMode(BAR_LED_3_PIN, OUTPUT);
  pinMode(BAR_LED_4_PIN, OUTPUT);
  pinMode(BAR_LED_5_PIN, OUTPUT);
}

void loop() {
  // this variable tracks which Bar LED we want to light
  static int ledNum = 0;

  // flash the LED on briefly and then switch it off again
  digitalWrite(BAR_LED_1_PIN + ledNum, HIGH);
  delay(LED_ON_MS);
  digitalWrite(BAR_LED_1_PIN + ledNum, LOW);

  // TODO - increment the counter and wrap if necessary
  /*ledNum++;
  if(ledNum >= 5){
    ledNum = 0;
  }
  */

  // pause between LED flashes
  ledNum = (ledNum+1) % 5;
  //Attention
  delay(SUPERLOOP_MS);
}
