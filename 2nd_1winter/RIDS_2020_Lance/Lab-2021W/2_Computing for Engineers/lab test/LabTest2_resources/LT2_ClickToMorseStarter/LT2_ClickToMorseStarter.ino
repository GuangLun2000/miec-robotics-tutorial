/**
 * This is starter code for LabTest2
 */
 
// Lab_Test 2 for ee108
// This code is contributed by Lance Cai
// Update in 2021.12.27

#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>

//------------------------------------------------------------
// types
//------------------------------------------------------------

struct MorseCode {
  char decodedChar; // this represents the decoded character
  const char *encodedStr; // the represents the morse encoding
};

typedef  struct MorseCode    MorseCode;

//------------------------------------------------------------
// constants
//------------------------------------------------------------

const MorseCode MORSE_TABLE[] = {
  { 'A', ".-" },
  { 'B', "-..." }, 
  { 'C', "-.-." },
  { 'D', "-..", },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', "-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  
  { '0', ".----" }, 
  { '1', "..---" }, 
  { '2', "...--" }, 
  { '3', "....-" }, 
  { '4', "....." },
  { '5', "-...." }, 
  { '6', "--..." }, 
  { '7', "---.." }, 
  { '8', "----." }, 
  { '9', "-----" }   
};

const int SUPERLOOP_DELAY_MS = 50;
const int MORSE_TABLE_SIZE = sizeof(MORSE_TABLE) / sizeof(MORSE_TABLE[0]);
const int T_MORSE=100;
static int tim=0;
static bool con=false;


//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

void writeBarLeds(unsigned int ledStates);


//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\n==============  LT2_ClickToMorseStarter starting... ================\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() {
  static char arr[10];
  static int num=0;
  // TODO - add your code
  int duration1=0;
  int *Time1=&duration1;
  int sw1Event=readSwitchEventTimes(sw1Object,Time1);
 

 if(sw1Event==SW_CLICK){
  delay(1000);
   long time1=millis();
  Serial.print(time1);
  Serial.print(" ms: Click, duration ");
  Serial.print(*Time1);
  Serial.print(" ms, symbol ");
  judge(*Time1,arr,num);
   Serial.println();
   tim=millis();
   con=true;
 }
  if(millis()-tim>2000&&con){
    check(arr,MORSE_TABLE);
    con=false;
  }
 
 
 

  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

/**
 * function to create any pattern of on/off Bar LEDs you want
 * in a single call
 * 
 * Example: To switch on Bar LEDs 2, 3, and 10 switch off all
 * others, the ledStates argument must evaluate to 
 * binary 10 0000 0110 which corresponds to hex 0x206:
 * 
 *     writeBarLeds(0x206);
 * 
 * @param ledStates  a bitmask which specifies the on/off state
 *                   of all Bar LEDs. Bits 0-9 correspond to 
 *                   Bar LEDs 1-10 respectively. If a bit is 1
 *                   then the corresponding Bar LED will be on
 *                   otherwise it will be off.
 */
void writeBarLeds(unsigned int ledStates) {
  int bitNumber;

  for (bitNumber = 0; bitNumber < NUM_BAR_LEDS; bitNumber++) {
    int bitValue = bitRead(ledStates, bitNumber);

    if (bitValue)
      digitalWrite(BAR_LED_1_PIN + bitNumber, HIGH);
    else
      digitalWrite(BAR_LED_1_PIN + bitNumber, LOW);
  }
}

void judge(int dura,char arr[],int num){
  
  if(dura<2*T_MORSE){
    Serial.print("DOT (.)");
    writeBarLeds(512);
    arr[num++]='.';
  }
  else if(dura>=2*T_MORSE&&dura<3*T_MORSE){
    Serial.print("UNRECOGNISED (?)");
    writeBarLeds(992);
    arr[num++]='?';
    Serial.println();
    Serial.print(millis());
    Serial.print(" ms: Morse symbol string \"");
    Serial.print(arr);
    Serial.print("\" not recognised");
  }
  else if(dura>=3*T_MORSE){
    Serial.print("DASH(-)");
    writeBarLeds(585);
    arr[num++]='-';
  }
}

void check(char arr[],MorseCode MORSE_TABLE[]){
  Serial.print(millis());
  bool res=true;
  for(int i=0;i<MORSE_TABLE_SIZE;i++){
    if(eq(arr,MORSE_TABLE[i].encodedStr)){
      res=false;
      Serial.print("recognised as ");
      Serial.println(MORSE_TABLE[i].decodedChar);
    }
  }
  if(res){
    Serial.println("not recognised");
  }
}

bool eq(char arr[],char table[]){
  bool res=true;
  for(int i=0;i<sizeof(table);i++){
    if(arr[i]!=table[i]){
      res=false;
      
    }
  }
  return res;
}


// Lab_Test 2 for ee108
// This code is contributed by Lance Cai
// Update in 2021.12.27
