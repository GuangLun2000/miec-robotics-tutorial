#include <ee108.h>
#include <limits.h>

const int SAMPLE_MS = 250;
const int ANALOG_PIN = LDR_PIN;

const int NUM_SAMPLES = 8;
const int FIFO_LEN = 4;

//
// function declarations
//

int sampleAnalogIn(int pin); // TODO - will need to be modified


// ==============================================================
// top level functions
// ==============================================================
 
void setup() {
  Serial.begin(9600);
  Serial.println("========= Lab6_OptionalInOut starting ===========");
}

void loop() {
  int i;

  Serial.println("-----------");
  
  Serial.println("sample without the optional params...");
  
  for (i = 0; i < NUM_SAMPLES; i++) {
    int value = sampleAnalogIn(ANALOG_PIN); // TODO - will need to be modified
    
    Serial.print("Sample ");
    Serial.print(i+1);
    Serial.print(", value=");
    Serial.println(value);

    delay(SAMPLE_MS);
  }

  // TODO - at the correct point int the lab (the description will tell you when)
  // uncomment the following block and edit as necessary to handle udpating the
  // minVal and maxVal variables
  
//  Serial.println("sample using the optional params...");
//  for (i = 0; i < NUM_SAMPLES; i++) {
//    int value = sampleAnalogIn(ANALOG_PIN); // TODO - will need to be modified
//
//    TODO printing and FIFO
//    
//    delay(SAMPLE_MS);  
//  }
  
  delay(8000);
}

// ==============================================================
// helper functions
// ============================================================== 

// TODO - this function will need to be modified so that it can update
// the minVal or maxVal seen to date

int sampleAnalogIn(int pin) {
  int value = analogRead(pin);

  // TODO - extra code to go here
  
  return value;
}
