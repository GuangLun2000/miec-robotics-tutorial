/************************************************************************
;
; Title:		demo-for-lab-1.c
; Platform:		PICmicro PIC16F877 @ 4 Mhz	
; Modified by:	Hanlin Cai
; Date:			Sep. 2022
;
; Function:		Outputs a square wave tones RC2 depending on the state of
;				two push buttons (RB0 and RB1)
;
*************************************************************************/


#ifndef _XTAL_FREQ
 // Unless already defined assume 4MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 4000000
#endif 

//Configuration Bits
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

//Prototype Declarations
void Tone();
void Init();
void test();

//Constant Declarations
#define BUTTON1 RB0 //bit 0 of PORTB
#define BUTTON2 RB1 //bit 1 of PORTB
#define BUTTON3 RB2 //bit 2 of PORTB

#define LED1	RC0	//bit 0 of PORTD
#define LED2	RC1	//bit 1 of PORTD
#define SPK1	RC2	//bit 2 of PORTC

#define OPEN	1	//Give a name to the open state of a button
#define PRESSED	0	//Give a name to the pressed state of a button

//Variables
int RepeatCount;	//Variable used in repeat loops

// Main Program
void main()
{
	Init();		//Do initialization
	for(;;)		//Continuous Superloop
	{
	// TwoTone();
    test();
	}
}

//Initialization
void Init()	
{
	PORTB = 0x00;	//Set PORTB outputs to 0
	TRISB = 0x03;	//Set RB0 and RB1 as inputs
	PORTC = 0x00;	//Set PORTC outputs to 0
	TRISC = 0x00;	//RC2 set as an output along with the rest of PORTC
    TRISD = 0x00;	//Set PORTD as outputs
    PORTD = 0xFF;	//Set PORTD outputs to 1, switches off all LEDs
    
}

//Functions

void Tone()	// 1 cycle of 2khz squarewave output
{
	SPK1 = 1;
	__delay_us(250);		//250us delay
	SPK1 = 0;
	__delay_us(250);		//250us delay

}

//void Tone2()	// 1 cycle of 500hz squarewave output
//{
//	SPK1 = 1;
//	__delay_ms(1);		//1ms delay
//	SPK1 = 0;
//	__delay_ms(1);		//1ms delay
//
//}

void test() {
    if ((BUTTON3 = PRESSED)) //If BUTTON3 PRESSED
    {
        LED1 = 1;
        LED2 = 1;
        Tone();    // 1 cycle of 500hz
    } else if ((BUTTON3 = OPEN) && (BUTTON2 = PRESSED) && (BUTTON2 = PRESSED)) //If only BUTTON3 OPEN
    {
        LED1 = 0;
        LED2 = 1;
        Tone();    // 1 cycle of 500hz
    } else {
        LED1 = 1;
        LED2 = 0;
        Tone();    // 1 cycle of 500hz
    }
}

// Modified by:	Hanlin Cai
// Date:		Sep.25th 2022