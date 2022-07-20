
#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>

/**
 * This is possibly the simplest demonstration of
 * click detection using the ee108 library
 */

#include <ee108.h>

#define arrSize 8
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
  static int arr[arrSize] = {0};

  int sw1Event;

  // Input
  sw1Event = readSwitchEvent(sw1Object);

  // processing and output 

  if (sw1Event == SW_CLICK) {
Serial.print("[Click] array is {");
    // output 1
  for(int i=0;i<arrSize;i++){
Serial.print(arr[i]);
if(i==arrSize-1){
}else{
Serial.print(",");
  }

}
Serial.print("}");
Serial.println();
  } else if (sw1Event == SW_CLICK_LONG) {
    // output 2
    Serial.print("[LongClick] modified array {");
for(int i=0;i<arrSize;i++){
arr[i]=random(100);
}
for(int i=0;i<arrSize;i++){
Serial.print(arr[i]);
if(i==arrSize-1){
}else{
Serial.print(",");
    }

  }
  Serial.print("}");
Serial.println();
  delay(SUPERLOOP_MS);
}

}
