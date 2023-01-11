/* 
 * File:     ee302_Lcd.h
 * Author:   Hanlin CAI (20122161)
 * Latest update in 2022/12/14
 * Comments: This is the head file for LCD display function.
 * Based on the open-source code implemented by JMaloco.
 */


/***********USER FUNCTIONS***********
1.	Lcd8_Init()
				- Must be called to initialise LCD.
				- Note what SFRs are effected and be sure not to overwrite these in yourt program initialisation.

2.	Lcd8_Clear()
				- Call this to Clear LCD display

3.	Lcd8_Set_Cursor(char a, char b)
				- The function sets the position of the cursor on the LCD. A = Line (1 or 2); B = Position (1 - 16).

4.	Lcd8_Write_Char(char a)
				- Write a character to the LCD e.g. 	Lcd8_Write_Char('A');

5.	Lcd8_Write_String(char *a)
				- Write a string to the LCD e.g. 	Lcd8_Write_Char("Hello");

6.	Lcd8_Shift_Right()
				- Shift the displayed characters one place to the right.

7.	Lcd8_Shift_Left()
				- Shift the displayed characters one place to the left.
*/


#include <xc.h>
#ifndef _XTAL_FREQ
 // Unless already defined assume 4MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 4000000
#endif 


#define RS RE0
#define RW RE1
#define EN RE2
#define D0 RD0
#define D1 RD1
#define D2 RD2
#define D3 RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
//LCD Functions Developed by electroSome

//LCD 8 Bit Interfacing Functions
void Lcd8_Port(char a)
{
	if(a & 1)
		D0 = 1;
	else 
		D0 = 0;
	
	if(a & 2)
		D1 = 1;
	else
		D1 = 0;
	
	if(a & 4)
		D2 = 1;
	else
		D2 = 0;
	
	if(a & 8)
		D3 = 1;
	else
		D3 = 0;
	
	if(a & 16)
		D4 = 1;
	else
		D4 = 0;

	if(a & 32)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 64)
		D6 = 1;
	else 
		D6 = 0;
	
	if(a & 128)
		D7 = 1;
	else
		D7 = 0;
}

void Lcd8_Cmd(char a)
{ 
  RS = 0;             // => RS = 0
  Lcd8_Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  __delay_ms(5);
  EN  = 0;             // => E = 0
}


//=============USER FUNCTIONS=============

void Lcd8_Init()
{
  	TRISE = 0x00;
  	TRISD = 0x00;
  	ADCON1 = 0x07;
  	RE1 = 0;
  
	Lcd8_Port(0x00);
	RS = 0;
	__delay_ms(25);
	///////////// Reset process from datasheet /////////
  Lcd8_Cmd(0x30);
  __delay_ms(5);
  Lcd8_Cmd(0x30);
	__delay_ms(15);
  Lcd8_Cmd(0x30);
  /////////////////////////////////////////////////////
  Lcd8_Cmd(0x38);    //function set
  Lcd8_Cmd(0x0C);    //display on,cursor off,blink off
  Lcd8_Cmd(0x01);    //clear display
  Lcd8_Cmd(0x06);    //entry mode, set increment
}


Lcd8_Clear()
{
	  Lcd8_Cmd(1);
}

void Lcd8_Set_Cursor(char a, char b)
{
	if(a == 1)
	  Lcd8_Cmd(0x80 + b);
	else if(a == 2)
		Lcd8_Cmd(0xC0 + b);
}


void Lcd8_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   Lcd8_Port(a);             //Data transfer
   EN  = 1;             // => E = 1
  __delay_ms(4);
   EN  = 0;             // => E = 04
}

void Lcd8_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd8_Write_Char(a[i]);
}

void Lcd8_Shift_Right()
{
	Lcd8_Cmd(0x1C);
}

void Lcd8_Shift_Left()
{
	Lcd8_Cmd(0x18);
}

// End LCD 8 Bit Interfacing Functions
// Lastly modified by Hanlin CAI
// EE302FZ Final Project.