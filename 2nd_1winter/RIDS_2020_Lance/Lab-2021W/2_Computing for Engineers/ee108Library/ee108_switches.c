/**
 * Version 3 of this file - developed for 2018-2019
 */
 
#include <ee108_switches.h>
#include <ee108_printf.h>

// IMPLEMENTATION NOTE: the literal pin numbers 18,19 are NOT portable to a different arduino board but are required
// so that the constants SW1_PIN and SW2_PIN can be used in a global initializer in ee108_switches.c
// #define PIN_SW1		19 /* A5 */
// #define PIN_SW2		18 /* A4 */


typedef struct SwitchInfo {
  int switchPin;  
  int prevSwitchValue; // raw switch value the last time the switch was checked
  int debouncedSwitchValue;
  unsigned int switchChangeTimeMs; // last time switch value changed or 0 if not yet set
  unsigned int debouncedChangeTimeMs;
  unsigned int prevStateStartTimeMs;
} SwitchInfo;


// static global variables means file scope - accessible only to functions in this file. 
// Cannot be directly accessed by any other code.

static unsigned int debounceMs = 10;
static unsigned int longClickMs = 1000;

static SwitchInfo sw1Info = { SW1_PIN, SW_INACTIVE, SW_INACTIVE, 0, 0, 0 };
SwitchPtr sw1Object = &sw1Info; // point at information for switch1

static SwitchInfo sw2Info = { SW2_PIN, SW_INACTIVE, SW_INACTIVE, 0, 0, 0 };
SwitchPtr sw2Object = &sw2Info; // point at information for switch2

/**
 * set the switch debounce time to a value other than the default.
 * The new value will apply for all subsequent tests of the switch
 * state
 *
 * @param debounceMsIn  the new debounce time to use in ms
 */
void setSwitchDebounceMs(unsigned int debounceMsIn) {
	debounceMs = debounceMsIn;
}

/**
 * set the long click threshold durations in ms
 *
 * @param longClickMsIn   the new long click duration threshold
 */
void setSwitchLongClickMs(unsigned int longClickMsIn) {
	longClickMs = longClickMsIn;
}

/**
 * debounces the specified switch (updating the switch info by side effect)
 * 
 * NOTE: this function does *not* change any debounced time values. This is
 * to allow the caller to calculate click durations etc.
 * 
 * @param sw    a SwitchPtr referring to valid switch state information
 * @param timeNowMs the time at which this read is occurring
 * @returns true if the debounced value has changed, false otherwise
 */
static boolean debounce(SwitchPtr sw, unsigned int timeNowMs) {
  int currentSwitchValue = digitalRead(sw->switchPin);
  boolean changed = false;

  if (currentSwitchValue != sw->prevSwitchValue) { // has raw switch value changed?
    sw->switchChangeTimeMs = timeNowMs;
    sw->prevSwitchValue = currentSwitchValue;
  } else { // no - raw switch value is unchanged
    // is raw switch value different to debounced value, and if so
    // has the raw switch value been stable for long enough to be stable/debounced?
    if (currentSwitchValue != sw->debouncedSwitchValue) {
      if ((timeNowMs - sw->switchChangeTimeMs) > debounceMs) {          
        sw->debouncedSwitchValue = currentSwitchValue;
		sw->debouncedChangeTimeMs = timeNowMs;
        changed = true; // debounced value has changed
      }
    }
  }
  return changed;
}

// read the current switch event and optionally output times also
// See ee108_switches.h for detailed comment

int readSwitchEventTimes(SwitchPtr sw, 
                          unsigned int *pPrevStateDurationMs) {
  boolean debouncedValueChanged;
  int switchEvent;
  unsigned long timeNowMs;

  // update the prevStateDurationMs before debouncing (since that might
  // change to the debounce for a new state rather than the prev state)

  // serialCPrintf("KEEP_PRESSED: prevStateStateTimeMs changed to %u\n", sw->debouncedChangeTimeMs);
  sw->prevStateStartTimeMs = sw->debouncedChangeTimeMs;

  timeNowMs = millis();
  debouncedValueChanged = debounce(sw, timeNowMs);

//  if (timeNowMs == TIME_NOT_SET) // ensure we don't use the not set value
//    timeNowMs -= 1;

  if (sw->debouncedSwitchValue == SW_ACTIVE) { // is debounced switch pressed?
    // if it has just changed, then we've just pressed, otherwise the switch is
    // being held down
    if (debouncedValueChanged)
      switchEvent = SW_ON_START;
    else
      switchEvent = SW_ON_CONTINUED;
  } else { // no, switch is not currently being pressed    
    if (debouncedValueChanged) // just released?
      switchEvent = SW_CLICK;
    else // not-pressed for a while
      switchEvent = SW_OFF_CONTINUED;
  }
  
  if (pPrevStateDurationMs)
    *pPrevStateDurationMs = timeNowMs - sw->prevStateStartTimeMs;

  return switchEvent;
}


// See ee108_switches.h for detailed comment

int readSwitchEvent(SwitchPtr sw) {
  unsigned int prevStateDurationMs = 0;
  int ret = readSwitchEventTimes(sw, &prevStateDurationMs);
  
  if (ret == SW_CLICK) {
    if (prevStateDurationMs >= longClickMs)
      ret = SW_CLICK_LONG;
  }
  
  return ret;
}
