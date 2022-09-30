/*============== EE108_ASS03 LANCE_CAI 20211222============*/
// A3_LIFO
// Assignment3-2 for ee108
// This code is contributed by Lance Cai
// Update in 2021.12.22

#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>

//initialization parameter
const int size = 4;
int flag = 0;

void setup() {
    Serial.begin(9600);
}

void insert(int* s, int& top) {
    Serial.print("Loop ");
    Serial.print(++flag);
    Serial.print(": [SW1 Click] ");
    if (top == 4) {
        Serial.println("Cannot add to buffer -- buffer full");
    } else {
        int num = rand() % 100;
        s[top++] = num;
        Serial.print("added to buffer, ");
        Serial.print(num);
        Serial.print(", buffer is now { ");
        for (int i = 0; i < top; i++) {
            if (i) {
                Serial.print(", ");
            }
            Serial.print(s[i]);
        }
        Serial.print(" }, ");
        Serial.print(top);
        Serial.println(" used");
    }
}

void erase(int* s, int& top) {
    Serial.print("Loop ");
    Serial.print(++flag);
    Serial.print(": [SW2 Click] ");
    if (!top) {
        Serial.println("Cannot remove from buffer -- buffer empty");
    } else {
        Serial.print("removed from buffer, ");
        Serial.print(s[--top]);
        Serial.print(", buffer is now { ");
        for (int i = 0; i < top; i++) {
            if (i) {
                Serial.print(", ");
            }
            Serial.print(s[i]);
        }
        Serial.print(" }, ");
        Serial.print(top);
        Serial.println(" used");
    }
}

void loop() {
    static int s[4] = {0, 0, 0, 0};
    static int top = 0;
    if (readSwitchEvent(sw1Object) == SW_CLICK) {
        insert(s, top);
    } else if (readSwitchEvent(sw2Object) == SW_CLICK) {
        erase(s, top);
    }
}


// This code is contributed by Lance Cai
// Update in 2021.12.22
