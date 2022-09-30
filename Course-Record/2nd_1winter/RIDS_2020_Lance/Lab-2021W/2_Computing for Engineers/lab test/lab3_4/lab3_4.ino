#include <ee108.h>
# define SHORT_TIME 200
# define DASH_TIME 600
# define DELAY_TIME 200

char res=65;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int i=0;i<10;i++){
  pinMode(BAR_LED_1_PIN+i,OUTPUT);
}

}

void loop() {
  // put your main code here, to run repeatedly:
  int duration1=0;
  int *Time1=&duration1;
  int sw1Event=readSwitchEventTimes(sw1Object,Time1);
  int duration2=0;
  int *Time2=&duration2;
  int sw2Event=readSwitchEventTimes(sw2Object,Time2);
    
    if(sw1Event==SW_CLICK){
      if(*Time1<1000&&*Time1>0){
      Serial.println("normal click SW1");
      Serial.print("current is ");
      Serial.println(res);
}
      lightLED(res);
    }

if(sw2Event==SW_CLICK){
  if(*Time2<1000&&*Time2>0){
  Serial.println("normal click SW2");
  if(res<69){
    res++;
  }else if(res=69){
    res=65;
  }
  Serial.println(res);
  lightLED(res);
}
  if(*Time2>1000){
  Serial.println("long click SW2");
  if(res>65){
    res--;
  }else if(res==65){
    res=69;
  }
   Serial.println(res);
   lightLED(res);
}
}

}
void lightLED(char input){
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

void lightShort(){
    digitalWrite(BAR_LED_1_PIN,HIGH);
    digitalWrite(BAR_LED_2_PIN,HIGH);
    delay(SHORT_TIME);
    digitalWrite(BAR_LED_1_PIN,LOW);
    digitalWrite(BAR_LED_2_PIN,LOW);
    delay(DELAY_TIME);
}

void lightLong(){
  for(int i=0;i<5;i++){
    digitalWrite(BAR_LED_6_PIN+i,HIGH);
  }
    delay(DASH_TIME);
  for(int i=0;i<5;i++){
    digitalWrite(BAR_LED_6_PIN+i,LOW);
  }
    delay(DELAY_TIME);
}
