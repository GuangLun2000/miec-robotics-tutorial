#include <ee108.h>

const int SUPERLOOP_MS = 20;


//
// function declarations
//

void rectangle(int length, int width); // TODO - will need to be modified


// ==============================================================
// top level functions
// ==============================================================
 
void setup() {
  Serial.begin(9600);
  Serial.println("========= Lab6_RectOutputParams starting ===========");
  Serial.println("Press SW1 to start...");
}

void loop() {
  int sw1Event;
  int length;
  int width;

  sw1Event = readSwitchEvent(sw1Object);

  if (sw1Event == SW_CLICK) {
    // TODO: generate random values for length and width

    // TODO: you will need to modify this call to the rectangle function
    // to take account of your output parameters

    rectangle(length, width);

    // TODO: you will need to modify this printing code to include output values

    Serial.print("Rectange: length=");
    Serial.print(length);
    Serial.print(", width=");
    Serial.print(width);
    Serial.println(""); // newline on its own


    Serial.println("\nPress SW1 to do it again...");
  }
  
  delay(SUPERLOOP_MS);
}

// ==============================================================
// helper functions
// ============================================================== 

// TODO - this function will need to be modified

void rectangle(int length, int width) {
  
  // TODO - you need to add code here
  
}
