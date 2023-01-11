/* 
 * File:     main.c
 * Author:   Hanlin CAI (20122161)
 * Comments: This is the main function for EE302FZ final porject.
 * Includes: Basci I/O + ADC + LCD + UART + I2C + Real-time
 *
 * Latest update in 2022/12/15
 */

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <xc.h>       // Include standard PIC library
#include "ee302_Lcd.h" // Include required header file for LCD functions
#include "ee302_I2C.h" // Include required header file for I2C functions

#ifndef _XTAL_FREQ
// Unless already defined assume 4MHz system frequency
// This definition is required to calibrate the delay functions, __delay_us() and __delay_ms()
#define _XTAL_FREQ 4000000
#endif

#define SW1 RB0			// Assign Label SW1 to PortB bit 0 (RB0)
#define SW2 RB1			// Assign Label SW2 to PortB bit 1 (RB1)
#define SW3 RB2			// Assign Label SW2 to PortB bit 1 (RB1)
#define SW4 RB3			// Assign Label SW2 to PortB bit 1 (RB1)

#define CLOSED 0
#define OPEN 1
#define HIGH 1
#define LOW 0
#define hi 0x11
#define lo 0x55
#define G_led RC0
#define R_led RC1

/**********Global variables**********/
int data1 = 0;
int data2 = 0;
unsigned char newData = 0;
unsigned char AddData = 0;
char ch = 0;
int col = 16;
int flag = 1;
int i = 0;


/***********USER FUNCTIONS***********/

//prototypes
void setup(void);
void loop(void);
char receive(void);
void send_str(char *str);

// 3 version of LCD display
void LCDBegin(void);
void LCDTitle(void);
void LCDEnd(void);

// I2C function
void readLDR_data(void);
void Write_data(void);
void Send_data(void);
void receive_data(void);
void Light();


/******************************************************************************************/

void main()
{
    setup(); // do initialisation
    
    LCDBegin(); // LCD display version 1 (Begin).
    
    if (SW1 == CLOSED) // If SW1 closed then
	{
        for(;;){
            Write_data();
            Send_data();
            __delay_ms(500);
            
            if(SW3 == CLOSED) // If SW3 closed then
            {
                send_str("Ending_SW3");
                break;
            }
        }
    }
    
    if (SW2 == CLOSED) // If SW2 closed then
    {	
        for (;;) // endless loop
        {   
            readLDR_data();
            loop();
            LCDTitle();
            send_str("Working_SW2");
            
            if(SW3 == CLOSED) // If SW3 closed then
            {
                send_str("Ending_SW3");
                break;
            }
        }          
    }
    
    if (SW4 == CLOSED) // If SW4 closed then
    {
        for(;;){
        LCDEnd();
        send_str("Thank you!");
        __delay_ms(200);
        }
    }
    
}

void setup(void) // Setup stuff
{
    PORTD = 0b11111111;
    TRISD = 0b00000000;
    TXSTA = 0x24;        //Set TXEN bit to enable transmit.
    //Set BRGH bit for Baud Rate table selection.
    RCSTA = 0x90;        //Set CREN bit for continuous read.
    //Set SPEN bit to enable serial port.
    SPBRG = 0x19;        //Set Baud Rate as 9600

    TRISC = 0xd8;
    TRISD = 0x00;

    T1CON = 0x21;
    INTCON = 0xc0;
    PIE1 = 0x21;
    PIR1 = 0x00;
    Lcd8_Init();         // Required initialisation of LCD to 8-bit mode
    TRISB = 0x07;        // Set PORTB bit 0 as input

    TRISC = 0xd8;
    TRISD = 0x00;
    PORTD = 0xff;

    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 0x19;        // set Baud Rate

    T1CON = 0x21;
    INTCON = 0xc0;
    PIE1 = 0x21;
    PIR1 = 0x00;
    //Set the ACD registers
    
    TRISA = 0b00000101;   // Set PORTA bits 0 and 2 are output
    //TRISC = 0b00000000; // Set PORTC bit 1 and 0 as output
    PORTC = 0b00000010;
    ADCON0 = 0b01010001;  // Set FOSC/8,RA2 as analog input and A/D converter module is powered up
    ADCON1 = 0b00000010;  // Set Left justified
    OPTION_REG &= 0b01111111;
    
    
    
    TRISC = 0b1101100; // RC6 and RC7 must be set to inputs for USART. 
    TXSTA = 0x24;      // Set TXEN bit to enable transmit.
                       // Set BRGH bit for Baud Rate table selection.
    RCSTA = 0x90;      // Set CREN bit for continuous read.
    //Set SPEN bit to enable serial port.
    SPBRG = 0x19;      // Set Baud Rate to 9600
    i2c_init();        // Required initialisation of I2C
    
    
    
    PORTD = 0b11111111;
    TRISD = 0b00000000;
    //TRISC = 0xC0;    //RC6 and RC7 must be set to inputs for USART. 
    TXSTA = 0x24;      //Set TXEN bit to enable transmit.
                       //Set BRGH bit for Baud Rate table selection.
    RCSTA = 0x90;      //Set CREN bit for continuous read.
    //Set SPEN bit to enable serial port.
    SPBRG = 0x19;      //Set Baud Rate to 9600
}

void loop(void)
{
        if (data1 > flag)
        {
            T1CON = 0x01;
        }
        else if (data1 <= flag)
        {
            T1CON = 0x31;
        }
}


void __interrupt()  // Interrupt identifier
    isr(void)       // Here is interrupt function.
{
    if (TMR1IF)
    {
        TMR1IF = 0;
        i++;
        if (i == 2) {
            col--;
            i = 0;
        } else {
            
        }
    }
    else if (RCIF)
    {
        RCIF = 0;
        ch = RCREG;
    }
}

/******************************************************************************************/

char receive(void)
{
    RCIF = 0;
    while (!RCIF);
    return RCREG;
}


void send_str(char *str)
{
    int index = 0;
    char ch = *str;

    while (ch != '\0')
    {
        ch = *(str + index);
        index++;
        while (!TXIF)
            ;
        TXREG = ch;
    }
}

/******************************************************************************************/

// 3 LCD Display Version
// Beginning of the project, version 1.
void LCDBegin(void)
{
    Lcd8_Set_Cursor(1,1);    // select line 2 of LCD
    Lcd8_Write_String("EE302 Project  "); // display "EE302 Victory" on second line of LCD
//    Lcd8_Set_Cursor(2,1);    // select line 2 of LCD
//    Lcd8_Write_String("by Hanlin CAI  "); // display "EE302 Victory" on second line of LCD
    __delay_ms(1000);
}

// Once SW2 is closed, LCD version 2.
void LCDTitle(void)
{
    if (col < 0)
    {
        col = 16;
    }
    Lcd8_Clear();
    Lcd8_Set_Cursor(1, col);    // select line 1 of LCD
    Lcd8_Write_String("EE302FZ");		// print "Project" on line 1 of LCD
    
    Lcd8_Set_Cursor(2, col);    // select line 2 of LCD
    Lcd8_Write_String("Victory"); // display "EE302 Victory" on second line of LCD
    __delay_ms(300);
}

// Once SW4 is closed, LCD version 3.
void LCDEnd(void)
{
    Lcd8_Set_Cursor(1,1);    // select line 2 of LCD
    Lcd8_Write_String("Thank you!   "); // display "EE302 Victory" on second line of LCD
    Lcd8_Set_Cursor(2,1);    // select line 2 of LCD
    Lcd8_Write_String("by Hanlin CAI  "); // display "EE302 Victory" on second line of LCD
    __delay_ms(1000);
}

void Light(){

    if(data1+data2*0.1<1.5){
        R_led = HIGH;
        G_led = LOW;
    }else{
        R_led = LOW;
        G_led = HIGH;
        
    }
}

/******************************************************************************************/

// ADC function
void readLDR_data(void){
    if(1){
        __delay_ms(150);
            __delay_us(50);
            GO_nDONE = 1;
            while(GO_nDONE){
                continue;
            }
            
            if(ADRESH!=newData){
                AddData = ADRESH;
                data1 = (AddData*5/255);
                data2 = (AddData*10*5/255)%10;
            }
            
            Light();
            newData = AddData;
           __delay_ms(100);
        }
}

/******************************************************************************************/

// I2C function
void Write_data(void)
{
    unsigned char address_hi = hi;
    unsigned char address_lo = lo;
    unsigned char data[12] = "Click_SW1";
    int i = 0;
    while (i <= 10)
    {
        write_ext_eeprom(address_hi, address_lo, data[i]);
        address_lo++;
        i++;
    }
}


void Send_data(void)
{
    unsigned char address_hi = hi;
    unsigned char address_lo = lo;
    int i = 0;
    while (i <= 10)
    {
        while (!TXIF)
            ;
        TXREG = read_ext_eeprom(address_hi, address_lo);
        address_lo++;
        i++;
        __delay_us(500);
    }
}

// This program is created by Hanlin CAI in 2022/12/15
// EE302FZ Final Project.