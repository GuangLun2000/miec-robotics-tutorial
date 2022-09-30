/**
 * Simulate a subset of ANSI C printf by wrapping Serial.print
 */

#ifndef __EE108_PRINTF_H
#define __EE108_PRINTF_H


#include <Arduino.h>
#include <WString.h>

#ifdef __cplusplus

#include <HardwareSerial.h>



/** 
 * print to serial using printf style format string with optional
 * parameters that depend on the format string
 *
 * Example:
 *
 *    int x = 42;
 *    serialPrintf("the value of x is %d\n", x);
 */
void serialPrintf(const char *fmt, ... );

/** 
 * print to serial using printf style format string with optional
 * parameters that depend on the format string.
 * This function allows the format string to be stored in flash memory
 * (to save RAM space) by wrapping it with the F() macro.
 *
 * Example:
 *
 *    int x = 42;
 *    serialPrintf(F("[best to store format string in flash] the value of x is %d\n"), x);
 */

void serialPrintf(const __FlashStringHelper *fmt, ... );

#endif


// IMPLEMENTATION NOTE: the following function is only needed by strict C files
// such as some of the files internal to the ee108 library - it is not normally
// needed in sketch code and the ordinary serialPrintf functions above should
// be used instead

#ifdef __cplusplus
extern "C" {
#endif

void serialCPrintf(const char *fmt, ... );

#ifdef __cplusplus
}
#endif


#endif //  __EE108_SWITCHES_H