/**
 * This is starter code for LabTest2
 */

// Lab_Test 2 for ee108
// This code is contributed by Lance Cai (20122161)
// Update in 2021.12.27 11：49
// Unfortunately, I couldn't finish all the advanced tasks, but I did my best to finish them.


#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>


//------------------------------------------------------------
// types
//------------------------------------------------------------
static String morse="";

struct MorseCode {
  char decodedChar; // this represents the decoded character
  const String encodedStr; // the represents the morse encoding
};

typedef  struct MorseCode    MorseCode;

//------------------------------------------------------------
// constants
//------------------------------------------------------------
#define  T_MORSE 300
static long runTime;
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


//initialization parameter
const int SUPERLOOP_DELAY_MS = 50;
const int MORSE_TABLE_SIZE = sizeof(MORSE_TABLE) / sizeof(MORSE_TABLE[0]);
static long swRunTime1 = 1000000;
static int sw = 1000000;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

void writeBarLeds(unsigned int ledStates);
void downBarLeds(unsigned int ledStates);
void lightBarLed(int judge);
void judgeSwTime(int Time);
//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  for(int i=0;i<10;i++)
  {
    pinMode(BAR_LED_1_PIN+i,OUTPUT);
  }
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\n==============  LT2_ClickToMorseStarter starting... ================\n");
  Serial.println("\nClick SW1 to start\n");    
}


void loop() {
  // TODO - add your code
  //initialization parameter
  runTime=millis();
  
  static int count=0;
  static String morseBuffer="";
  
  int sw1Event;
  int swTime1=0;
  int swTime = 0;
  int *pTime = &swTime;
  sw1Event = readSwitchEventTimes(sw1Object,pTime);
  static int swRunTime2=0;
  
  if(sw1Event== SW_CLICK)
  {
    swRunTime1=runTime;
    Serial.print(runTime);
    Serial.print(" ms: ");
    Serial.print("gap before ");
    Serial.print(runTime-swRunTime2-swTime1);
    Serial.print("ms, Click, duration ");
    Serial.print(swTime);
    Serial.print(" ms,");
    Serial.print(" symbol ");
    judgeSwTime(swTime);
    Serial.println();
    swTime1=swTime;
    swRunTime2=swRunTime1;
  }
 
  if(morse.equals("?"))
  {
    Serial.print(runTime);
    Serial.print(" ms: Morse symbol string ");
    Serial.print(morseBuffer);
    Serial.print("?");
    Serial.print(" not recognised");
    Serial.println();
    swRunTime1=1000000;
    morse="";
    count=0;
    morseBuffer="";
  }else
  {
    morseBuffer=morseBuffer+morse;
    
    if(!morse.equals(""))
      count++;
    morse="";
    if(count==5||runTime-swRunTime1>2000)
    {
      judgeMorse(morseBuffer,runTime);
      morseBuffer="";
      count=0;
      swRunTime1=1000000;
    }
    else if(runTime-sw>7*T_MORSE&&runTime-sw<7*T_MORSE+50)
    {
      Serial.print(runTime);
      Serial.print(" ms: WORD BREAK");
      Serial.println();
      morseBuffer="";
      count=0;
      sw=1000000;
    }
    
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
void judgeMorse(String morseWord,long runTime)
{
  int CounT=1;
  for(int i= 0;i<MORSE_TABLE_SIZE;i++)
  {
    if(morseWord.equals(MORSE_TABLE[i].encodedStr))
    {
      Serial.print(runTime);
      sw=runTime;
      Serial.print(" ms: CHAR BREAK DETECTED,Morse '");
      Serial.print(MORSE_TABLE[i].encodedStr);
      Serial.print("' recognised as ");
      Serial.print(MORSE_TABLE[i].decodedChar);
      Serial.println();
      CounT=0;
      break;
     
    }
  }
  if(CounT==1)
  {
    Serial.println("Wrong MorseCode");
  }
  
}
 
void judgeSwTime(int Time){
  int judge=0;
  if(Time<T_MORSE){
    morse=".";
    Serial.print("DOT");
    judge=1;
    
  }else if(Time>3*T_MORSE)
  {
    morse="-";
    Serial.print("DASH");
    judge=2;
  }else
  {
    morse="?";
    Serial.print("UNRECOGNISED");
    judge=3;
  }
  lightBarLed(judge);
}


void lightBarLed(int judge)
{
  if(judge==1)
  {
    Serial.print("(.)");
    writeBarLeds(1);
    delay(600);
    downBarLeds(1);
  }else if(judge==2)
  {
    Serial.print("(-)");
    writeBarLeds(31);
    delay(600);
    downBarLeds(31);
  }else if(judge==3){
    Serial.print("(?)");
    writeBarLeds(585);
    delay(600);
    downBarLeds(585);
  }
}


void downBarLeds(unsigned int ledStates)
{
  int bitNumber;

  for (bitNumber = 0; bitNumber < NUM_BAR_LEDS; bitNumber++) {
    int bitValue = bitRead(ledStates, bitNumber);
    
    if (bitValue)
      digitalWrite(BAR_LED_1_PIN + bitNumber, LOW);
  }
}


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

// Thank you for your check !!!
// Lab_Test 2 for ee108
// This code is contributed by Lance Cai (20122161)
// Update in 2021.12.27 11：49
