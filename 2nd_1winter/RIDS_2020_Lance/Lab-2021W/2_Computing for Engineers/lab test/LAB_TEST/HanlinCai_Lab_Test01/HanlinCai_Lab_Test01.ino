/*============== starting Lab_test_1 Hanlin_Cai============*/
//lab_test1
//Hanlin Cai
//20122161

#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>

//initialise by the pointer
const int Button_Delay = 200;
const int Short_Time =200;
const int Dash_Time = 600;
//const int Button_Time = 30;
const int Button_1 = SW1_PIN;
const int Button_2 = SW2_PIN;
//int count = 0;
char letter = 65;


void setup() {
  // put your setup code here, to run once:
  int ledIndex = 0;
  Serial.begin(9600);
  Serial.println("============== starting Lab_test_1 Hanlin============");  

  pinMode(Button_1,INPUT);
  pinMode(Button_2,INPUT);

  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++){
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  }

}
  

void loop() {
  // put your main code here, to run repeatedly:
  
  //initialise by the pointer
  int duration_A = 0;
  int *Time1 = &duration_A;
  int sw1Event = readSwitchEventTimes(sw1Object,Time1);
  
  int duration_B = 0;
  int *Time2 = &duration_B;
  int sw2Event = readSwitchEventTimes(sw2Object,Time2);
    
//  while (readSwitchEvent(sw1Object) != SW_CLICK){
//    delay(Button_Time);
//  }

  //normal click SW1
  if(sw1Event==SW_CLICK){
        if(*Time1<1000 && *Time1>0){
          Serial.println("normal click SW1");
          Serial.print("current is ");
          Serial.println(letter);
        }
        light(letter);
    }

    //normal click SW2
    if(sw2Event==SW_CLICK)
    {
      
      if(*Time2<1000 && *Time2>0){
        Serial.println("normal click SW2");
        if(letter<69){
          letter++;
        }else if(letter=69){
           letter=65;
        }
        Serial.println(letter);
        light(letter);
      }
      
        //long click SW2!
        if(*Time2>1000)
        {
          Serial.println("long click SW2");
          
          if(letter>65){
            letter--;
          }else if(letter==65){
            letter=69;
          }
         Serial.println(letter);
         light(letter);
         }
    }
    
}


void light(char input){
  if(input==65){
    lightShort();
    lightLong();
  }
  else if(input==66){
    lightLong();
    lightShort();
    lightShort();
    lightShort();
  }
  else if(input==67){
    lightLong();
    lightShort();
    lightLong();
    lightShort();
  }
  else if(input==68){
    lightLong();
    lightShort();
    lightShort();
  }
  else if(input==69){
    lightShort();
  }
}

//short light function
void lightShort(){
    digitalWrite(BAR_LED_1_PIN,HIGH);
    digitalWrite(BAR_LED_2_PIN,HIGH);
    delay(Short_Time);
    digitalWrite(BAR_LED_1_PIN,LOW);
    digitalWrite(BAR_LED_2_PIN,LOW);
    delay(Button_Delay);
}

//long light function
void lightLong(){
  for(int i=0;i<5;i++){
    digitalWrite(BAR_LED_6_PIN+i,HIGH);
  }
    delay(Dash_Time);
  for(int i=0;i<5;i++){
    digitalWrite(BAR_LED_6_PIN+i,LOW);
  }
    delay(Button_Delay);
}


/*============== ending Lab_test_1 Hanlin_Cai============*/
