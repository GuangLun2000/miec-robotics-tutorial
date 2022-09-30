//sketch5   *****************************************************************

#include <ee108.h>

const int BUTTON_POLL_MS = 50;
const int BUTTON = A5;
const int BUTTON1 = A4;
const int PT = A0;
const int NUM_REPS = 5;
const int BETWEEN_REPS_MS = 500;

const int LED_ON_MS = 100;
const int LED_OFF_MS = 50;
int val = 0; 

void setup() {
  int ledIndex;
  
  Serial.begin(9600);
  Serial.println("============== starting Lab3_BarLedScan_Starter ============");  
  pinMode(BUTTON, INPUT);                //Additional questions  
  pinMode(BUTTON1, INPUT);
  pinMode(PT, INPUT);               //I used a potentiometer to get a simulated input from 0 to 1200 by potential change, and divide by 300 to get a good number to start with        
  // using a loop, we iterate over all Bar LED pins, enabling each one as an OUTPUT.
  // NOTE the idiom BAR_LED_1_PIN + ledIndex to get the pin number for any bar led
  // according to it's zero based index, e.g. where the second led has index 1
  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++)
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
}

void loop() {
  int state = 0;
  int sw1Event = 0; // used when checking SW1
  int sw2Event = 0 ; // user when checking SW2
  // busy wait at this point until SW1 is clicked (i.e. wait while sw1Event is not a click)
  
  while (readSwitchEvent(sw1Object) != SW_CLICK){
    delay(BUTTON_POLL_MS);
    }
   Serial.print("SW1 clicked, starting repetitions loop \n");
   sw1Event = 1;
   for(int i = 0; i < 10 ; i++){
   Serial.print("Rep ");
   Serial.println(i+1);
   val = analogRead(A0);
  int start = val / 300;
   for(int lednum= start; lednum < start+5 ; lednum++){
     if (readSwitchEvent(sw2Object)& SW_ON_ANY){
      lednum= 0;
      continue;
   }
      if (digitalRead(BUTTON)==SW_ACTIVE){
       state = 1;
       break;
      }
      digitalWrite(BAR_LED_1_PIN + lednum, HIGH);
      delay(LED_ON_MS);
      digitalWrite(BAR_LED_1_PIN + lednum, LOW);
      delay(LED_OFF_MS);
      }
   if(state == 1){
    Serial.println("release SW1!!");
    while(digitalRead(BUTTON)==SW_ACTIVE){
      delay(BUTTON_POLL_MS);
    }
    break;
   }
  }
   
  // TODO - at this point button SW1 has definitely been clicked
  // implement the rest of the lab as specified in the lab doc.
  // You will need a loop (a while-loop or for-loop) that repeats NUM_REPS times
  // and in each iteration/repetition you'll have to do some things as specified
  // in the lab doc.

  
  Serial.println("end of repetitions loop");  
  state = 0;
}
