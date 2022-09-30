/**
 * demonstrate the use of nested if statements.
 * The sketch just lights different LEDs for short and long presses
 * of the button
 */
#include <ee108.h>

// TODO - define constants for the superloop duration and the number of ticks
// (i.e. superloop iterations) corresponding to a very long click

const int Red_LED = LED1_PIN;
const int Green_LED = LED2_PIN;
const int Button = SW1_PIN;
int count = 0;

void setup() {
  // TODO - initialise the LED pins that you'll be using
  pinMode(Red_LED,OUTPUT);
  pinMode(Green_LED,OUTPUT);
  pinMode(Button,INPUT);
  
}

void loop() {
  int sw1Event; // variable to save the current switch event 
  
  // check the current switch event
  sw1Event = readSwitchEvent(sw1Object);
  
  // TODO: check if the switch is currently pressed and light the LEDs 
  // as per the lab instruction
  //
  // You can check if the SW1 is currently pressed using *one* of the following
  // expression options in your if-statement:
  // expression 1:  if ((sw1Event == SW_ON_START) || (sw1Event == SW_ON_CONTINUED)) ...
  // expression 2:  if (sw1Event & SW_ON_ANY) ... 

    if(digitalRead(Button) == SW_ACTIVE){
      digitalWrite(Red_LED,HIGH);
      count++;
        if(count==10){
          digitalWrite(Green_LED,HIGH);
        }
    }
    
    else
    {
       count = 0;
       digitalWrite(Red_LED,LOW);
       digitalWrite(Green_LED,LOW);
    }
    
    delay(50);
  

  // TODO: delay for the appropriate amount of time
}
