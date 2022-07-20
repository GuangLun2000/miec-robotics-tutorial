/**
 * Blinking various BarLEDs as required for Lab 4 but without using functions.
 * This results in quite a lot of repetitive code which differs only in the
 * specific LED to blink or the number of times to blink it and the length
 * of time to blink on and off.
 */
#include <ee108.h>

// ___________________________________________________________________
// constants

const int SHORT_ON_MS = 100;
const int SHORT_OFF_MS = 500;
const int MED_ON_MS = 500;
const int MED_OFF_MS = 700;
const int LONG_ON_MS = 1200;
const int LONG_OFF_MS = 600;


// ===================================================================
// Top level functions
// ===================================================================

/**
 * set up the sketch to use LEDs and serial
 */
void setup() {
  int ledIndex;
  
  // set up the LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // set up the Bar LEDs
  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++)
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  
  // serial output
  Serial.begin(9600);

  Serial.println("====== Lab4_BlinkNoFunctions starting ========");
}

/**
 * Blink the LEDs in accordance with the lab requirements each
 * time the loop function is called
 */
void loop() {
  static int loopNum = 0;
  int i;

  Serial.print("Loop ");
  Serial.println(loopNum);

  // BarLED1
  Serial.println("  Blink BarLED1 on/off long pattern x 1");
  digitalWrite(BAR_LED_1_PIN, HIGH);
  delay(LONG_ON_MS);
  digitalWrite(BAR_LED_1_PIN, LOW);
  delay(LONG_OFF_MS);

  // BarLED8
  Serial.println("  Blink BarLED8 on/off short pattern x 3 times");
  for (int i=0; i < 3; i++) {
    digitalWrite(BAR_LED_8_PIN, HIGH);
    delay(SHORT_ON_MS);
    digitalWrite(BAR_LED_8_PIN, LOW);
    delay(SHORT_OFF_MS);
  }

  // BarLED4
  Serial.println("  Blink BarLED4 on/off short pattern x 2 times");
  for (int i=0; i < 2; i++) {
    digitalWrite(BAR_LED_4_PIN, HIGH);
    delay(MED_ON_MS);
    digitalWrite(BAR_LED_4_PIN, LOW);
    delay(MED_OFF_MS);
  }

  // there are plenty of delays in the blinking code so we don't
  // need to add any extra delay at the end of the loop function
}
