/*============== EE108_ASS03 LANCE_CAI 20211222============*/
// A3_ClickArrays
// Assignment3-1 for ee108
// This code is contributed by Lance Cai
// Update in 2021.12.22

#include <ee108_switches.h>
#include <ee108_printf.h>
#include <ee108_constants.h>
#include <ee108.h>

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}


void loop() {
    // put your main code here, to run repeatedly:

    //initialization parameter
    static int a1[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    static int a2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int pre = 0;
    int temp = pre;
    int flag = readSwitchEventTimes(sw1Object, &temp);

    if (flag < 20) {
//      pre += flag;
        pre = 0;
    } else {
        pre += flag;
    }
    if (pre > 20) {
        if (pre > 50 && pre < 100) {
            longClick(a1);
        } else if (pre >= 100) {
            veryLongClick(a1);
        }
        printArray(a1, a2);
    } else if (readSwitchEvent(sw2Object) == SW_CLICK) {
        change(a1, a2);
        printArray(a1, a2);
    }
    delay(300);
//    printArray(a1, a2);
}

void printArray(int *a1, int *a2) {
    Serial.print("array 1: {");
    for (int i = 0; i < 10; i++) {
        if (i) {
            Serial.print(", ");
        }
        Serial.print(a1[i]);
    }
    Serial.println("}");
    Serial.print("array 2: {");
    for (int i = 0; i < 10; i++) {
        if (i) {
            Serial.print(", ");
        }
        Serial.print(a2[i]);
    }
    Serial.println("}");
}

void longClick(int* a1) {
    for (int i = 0; i < 10; i++) {
        a1[i] = rand() % 100;
    }
}

void veryLongClick(int* a1) {
    for (int i = 0; i < 10; i++) {
        a1[i] = 0;
    }
}

void change(int* a1, int* a2) {
    for (int i = 0; i < 10; i++) {
        a2[i] = a1[i];
    }
}



// This code is contributed by Lance Cai
// Update in 2021.12.22
