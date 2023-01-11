/* 
 * File:     ee302_I2C.h
 * Author:   Hanlin CAI (20122161)
 * Latest update in 2022/12/14
 * Comments: This is the head file for I2C transfer function.
 * Based on the open-source code implemented by JMaloco.
 */


/***********USER FUNCTIONS***********

1.	i2c_init()
				- Must be called to initialise I2C device.
				- Note what SFRs are effected (TRISC) and be sure not to overwrite these in yourt program initialisation.

2.	write_ext_eeprom(unsigned char address_hi,unsigned char address_lo, unsigned char data);

3.	unsigned char read_ext_eeprom(unsigned char address_hi,unsigned char address_lo);
				- Returns a single character read.

*/

#include <pic.h>
#define _XTAL_FREQ 4000000
unsigned char data[20];


/******************typedef for data types *****************************/
typedef signed char     BYTE;
typedef signed short    WORD;
typedef signed long     DWORD;
typedef float           FLOAT;
typedef unsigned char   UBYTE;
typedef unsigned int    UWORD;
typedef unsigned long   UDWORD;


#define TRUE                1
#define FALSE               0
#define HIGH	            1
#define LOW		            0	
#define RX_BUFFER_SIZE     20

/** T R I S *********************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0


void i2c_init(void);
void write_ext_eeprom(unsigned char address_hi,unsigned char address_lo, unsigned char data);
unsigned char read_ext_eeprom(unsigned char address_hi,unsigned char address_lo);
unsigned char i2c_write( unsigned char i2cWriteData );
int i2c_read( unsigned char ack );
void i2c_stop(void);
void i2c_repStart(void);
void i2c_start(void);
void i2c_waitForIdle(void);
void write_string(unsigned char address_hi,unsigned char address_lo, const char* ptr);
void read_string(unsigned char address_hi,unsigned char address_lo, unsigned char data[], int length);

/******************************************************************************************/

void i2c_waitForIdle(void)
{
 while (( SSPCON2 & 0x1F ) | R_nW ) {}; // wait for idle and not writing
}

/******************************************************************************************/

void i2c_start(void)
{
 i2c_waitForIdle();
 SEN=1;
}

/******************************************************************************************/

void i2c_repStart(void)
{
 i2c_waitForIdle();
 RSEN=1;
}

/******************************************************************************************/

void i2c_stop(void)
{
 i2c_waitForIdle();
 PEN=1;
}

/******************************************************************************************/

int i2c_read( unsigned char ack )
{
unsigned char i2cReadData;
i2c_waitForIdle();
 RCEN=1;
 i2c_waitForIdle();
 i2cReadData = SSPBUF;
 i2c_waitForIdle();
 if ( ack )
  {
  ACKDT=0;				//ACK
  }
 else
  {
  ACKDT=1;				//NACK
  }
  ACKEN=1;               // send acknowledge sequence
 return( i2cReadData );
}

/******************************************************************************************/

unsigned char i2c_write( unsigned char i2cWriteData )
{
 i2c_waitForIdle();
 SSPBUF = i2cWriteData;
return ( ! ACKSTAT  ); // function returns '1' if transmission is acknowledged
}


//====================================================
//
//			MAIN USER FUNCTIONS
//
//			-	I2C Initialisation
//			-	EEPROM Byte Write
//			-	EEPROM Byte Read

//
//====================================================


void i2c_init(void)
{
 // Do in main code TRISC = 0b00011000;       // set SCL and SDA pins as inputs
 SSPCON = 0x38;            // set I2C master mode
 SSPCON2 = 0x00;
 SSPADD = 0x0A;            // 100k at 4Mhz clock
 CKE=1;                    // use I2C levels      
 SMP=1;                    // disable slew rate control  
 PSPIF=0;                  // clear SSPIF interrupt flag
 BCLIF=0;                  // clear bus collision flag
}

/*****************************************************************************************/

void write_ext_eeprom(unsigned char address_hi,unsigned char address_lo, unsigned char data)
 {
   i2c_start();					//Send Start Condition
   i2c_write(0xa0);				//Write Control Byte (A2,A1,A0 all low, R/W = 0)
   i2c_write(address_hi);		//Write high byte of address 
   i2c_write(address_lo);		//Write low byte of address 
   i2c_write(data);				//Write data
   i2c_stop();					//Send Stop condition
   __delay_ms(5);				//Necessary 5ms delay for write to propagate
}

/******************************************************************************************/

unsigned char read_ext_eeprom(unsigned char address_hi,unsigned char address_lo)
{
   unsigned char data;

    i2c_start();				//Send Start Condition
    i2c_write(0xa0);			//Write Control Byte (A2,A1,A0 all low, R/W = 0)
    i2c_write(address_hi);		//Write high byte of address 
    i2c_write(address_lo);		//Write low byte of address 
    i2c_repStart();				//Send reStart Condition
    i2c_write(0xa1);			//Write Control Byte (A2,A1,A0 all low, R/W = 1)
    data=i2c_read(0);			//Read Data followed by a NACK
    i2c_stop();					//Send Stop condition
    return(data);
}

// Lastly modified by Hanlin CAI
// EE302FZ Final Project.