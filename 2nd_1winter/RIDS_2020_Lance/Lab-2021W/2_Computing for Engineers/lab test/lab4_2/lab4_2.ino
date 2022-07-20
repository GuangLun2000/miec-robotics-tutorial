

#include <ee108.h>
void setupBarLeds();
//This initializes all output pins
void blinkLed(int pin,int times,int ontime,int offtime);
//can blink any BarLED number you specify some specified number of times and with specified blink on/off durations
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
  setupBarLeds();
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
  Serial.print("Loop ");
  Serial.println(loopNum);

  // BarLED1
  Serial.println("  Blink BarLED1 on/off long pattern x 1");
  blinkLed(1,1,LONG_ON_MS,LONG_OFF_MS);
 
  // BarLED4
  Serial.println("  Blink BarLED4 on/off short pattern x 2 times");
  blinkLed(4,2,MED_ON_MS,MED_OFF_MS);
  
  // BarLED8
  Serial.println("  Blink BarLED8 on/off short pattern x 3 times");
  blinkLed(8,3,SHORT_ON_MS,SHORT_OFF_MS);
  loopNum++;
  // there are plenty of delays in the blinking code so we don't
  // need to add any extra delay at the end of the loop function
}

void blinkLed(int pin,int times,int ontime,int offtime){
  for (int i=0; i < times; i++) {
    digitalWrite( BAR_LED_1_PIN + pin - 1, HIGH );
    delay(ontime);
    
    digitalWrite( BAR_LED_1_PIN + pin - 1, LOW );
    delay(offtime);
  }
}


void setupBarLeds(){
  int ledIndex;
  // set up the LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // set up the Bar LEDs
  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++)
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  
}
