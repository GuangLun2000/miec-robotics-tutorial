/**
 * Header file for switch reading functionality
 * used with Arduino Uno.
 *
 * Version 3 of this file - developed for 2018-2019 
 */

#ifndef __EE108_SWITCHES_H
#define __EE108_SWITCHES_H
 
#include <ee108_constants.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * possible events returned by read switch event.
 * The switches are active low so SW_ACTIVE is LOW and SW_INACTIVE is HIGH
 * The following figure represents the digital signal on the switch pin
 * over time and shows the switch initially not pressed, then pressed
 * for a short time, and then released again.
 * Assume our code checks the value of the pin at time instants
 * marked by the numbers on the signal line.
 *
 *    HIGH (SW_INACTIVE)   ---1-----2--                      --6-------7---
 *                                     |                    |
 *    LOW (SW_ACTIVE)                  --3------4------5-----
 *                                                              time ====>
 * 
 * For this signal, the switch event returned by readSwitchEvent at each of the numbered
 * instants would be as follows:
 * 
 *   1. SW_OFF_CONTINUED since the switch is off and had been initialized off
 *   2. SW_OFF_CONTINUED since the switch is off and had been off for previous check
 *   3. SW_ON_START since the switch is on and had been off for the previous check
 *   4. SW_ON_CONTINUED since the switch is on and had been on for the previous check
 *   5. SW_ON_CONTINUED since the switch is on and had been on for the previous check
 *   6. SW_CLICK since the switch is off and had been on for the previous check meaning
 *      it has just been released after a press, i.e. a click. If it was pressed for
 *      a long time, the value might be SW_LONG_CLICK either
 *   7. SW_OFF_CONTINUED since the switch is off and had been off for previous check
 */

enum SwitchEvent {
	SW_CONTINUED = 0x1,	///! Advanced use - you won't need to use this directly
	SW_LONG = 0x2, 	///! Advanced use - you won't need to use this directly
	
	SW_OFF_ANY = 0x10, ///! can check for off start or continued by checking if (swEvent & SW_OFF_ANY) evaluates true
	                           // NOTE: (swEvent & SW_OFF_ANY) will also evaluate true for clicks so you must check 
							   // for clicks first if you need them
	SW_OFF_START = SW_OFF_ANY,	///! the switch is off now, but was on last time. 
	                       // Note: You won't see this on its own - it will always be part of a click
	SW_OFF_CONTINUED = SW_OFF_START | SW_CONTINUED, ///! the switch is off now and was off for last check also
	
	SW_ON_START = 0x20,	///! switch is on now but was on for last check, i.e. switch has just been pressed 
	SW_ON_CONTINUED = SW_ON_START | SW_CONTINUED, ///! switch is on now and was on for last check also
	SW_ON_ANY = SW_ON_START, ///! can check for on start or continued by checking if (swEvent & SW_ON_ANY) evaluates true
	
	SW_CLICK_ANY = 0x40, ///! can check for any type of click by checking if (swEvent & SW_CLICK_ANY) evaluates true
	SW_CLICK = SW_CLICK_ANY | SW_OFF_START, ///! switch off now but was on last time, i.e. just released switch after a press
	SW_CLICK_LONG = SW_CLICK | SW_LONG ///! same as click, but after switch was pressed a "long" time (usually about 1 sec)
};

// const int SW_OFF_START = 0x01; // switch off now, but was ON the last time we checked
                                //NOTE: you won't see SW_OFF_START on its own
                                //Instead it will be part of NORMAL_CLICK or LONG_CLICK
// const int SW_OFF_CONTINUED = 0x02; // switch OFF now and was also OFF the last time we checked
// const int SW_ON_START = 0x04; // switch ON now, but was OFF the last time we checked
// const int SW_ON_CONTINUED = 0x08; // switch ON now and was also ON the last time we checked

// const int SW_CLICK = 0x11; // just transitioned from switch ON to OFF after normal press duration
// const int SW_CLICK_LONG = 0x21; // just transitioned from switch ON to OFF (after a "long" press duration)

// bit masks to check for multiple events (only for use with bitwise tests)
// NOTE: we have to repeat the literal values here from above because of some 
// limitations of const values in C in this specific situation
// const int SW_ON_ANY = 0x04 | 0x08; // = SW_ON_START | SW_ON_CONTINUED;
// const int SW_CLICK_ANY = 0x11 | 0x21; // = SW_CLICK | SW_CLICK_LONG;


// const unsigned int TIME_NOT_SET = 0;

// struct SwitchInfo is defined in ee108_switches.c and not here because it
// is part of the private implementation of the ee108 library and should not be
// exposed to programs that are simply using the library.
//   We can still define a pointer to it here however and that is what we do.

typedef struct SwitchInfo * SwitchPtr;

extern SwitchPtr sw1Object;
extern SwitchPtr sw2Object;


void setSwitchDebounceMs(unsigned int debounceMs);
void setSwitchLongClickMs(unsigned int longClickMs);

/**
 * read the (debounced) switch value and optionally output the
 * time spent in the previous state.
 *
 * If the switch has just been released, the previous state duration was
 * all the time that the switch was pressed. If the switch was
 * just pressed, then the previous state duration was all the time that
 * the switch had not been pressed.
 *
 * Typically this function should be called once per superloop.
 * In any case, the function must be called relatively frequently (at least
 * every 100ms or so) in order to correctly detect the button being
 * held down and the difference between long and normal clicks. 
 * 
 * @param sw	the switch to read
 * @param pPrevStateDurationMs
 *         		[optional] if this value is not needed, pass in a NULL pointer.
 *              if you want this value, pass in a valid pointer. The pointee will
 *              be set to the length of time the switch was in the state it had the
 *              previous time this function was called.
 *
 *              EXAMPLE:
 *
 *              0 ms, SW1 is initially not pressed
 *              ...readSwitchEventTimes called multiple times and SW1 remains not pressed - other details not important
 *              990 ms, user presses SW1
 *              1000 ms, readSwitchEventTimes called,  currentSwState=ON, prevSwState=OFF,
 *                       prevStateDuration=1000ms (i.e. 1000 ms in the (prev) OFF state until this function called)
 *              1050 ms, readSwitchEventTimes called, currentSwState=ON, prevSwState=ON,
 *                       prevStateDuration=50ms (i.e. 50 ms in the (prev) ON state before this call)
 *              1100 ms, readSwitchEventTimes called, currentSwState=ON, prevSwState=ON,
 *                       prevStateDuration=100ms (i.e. 50 ms in (prev) ON state before this call)
 *              1120 ms, user releases SW1
 *              1150 ms, readSwitchEventTimes called, currentSwState=OFF, prevSwState=ON,
 *                       prevStateDuration=150ms (i.e. 150 ms in the (prev) ON state before this call)
 *              1200 ms, readSwitchEventTimes called, currentSwState=OFF, prevSwState=OFF,
 *                       prevStateDuration=50ms (i.e 50 ms in the (prev) OFF state before this call)
 *              etc.
 */
int readSwitchEventTimes(SwitchPtr sw, 
                          unsigned int *pPrevStateDurationMs);

/**
 * read the current switch event as simply as possible
 *
 * Usually this function or readSwitchEventTimes should be called
 * once per superloop.
 *
 * @param sw    a SwitchPtr referring to valid switch state information
 *              (usually sw1 or sw2)
 * @returns the current switch event which is one of:
 *            SW_OFF_CONTINUED the button is not pressed
 *            SW_ON_START      the button has just transitioned from not
 *                             pressed to pressed
 *            SW_ON_CONTINUED  the button was already pressed and has
 *                             been held down continuously since
 *            SW_CLICK_NORMAL the button has just been released. A press
 *                            followed by a release is called a click.
 *            SW_CLICK_LONG   the button has just been released after a long
 *                            hold
 */
int readSwitchEvent(SwitchPtr sw);


#ifdef __cplusplus
}
#endif

#endif //  __EE108_SWITCHES_H