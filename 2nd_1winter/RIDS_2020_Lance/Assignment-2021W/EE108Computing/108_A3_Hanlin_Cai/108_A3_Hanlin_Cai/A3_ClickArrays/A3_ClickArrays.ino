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
    static int len = 0;
    static int prev = 0;
    static int pret = 0;
    int now = readSwitchEventTimes(sw1Object, &len);
    if (now < 20) {
        len = 0;
    }
    if (!len && prev) {
        if (prev < 1000) { // 0 ~ 1000 ms
            if (!pret) {
                pret = millis();
            } else {
                if (millis() - pret - prev < 1000) {
                    swapArr(a1, a2);
                }
                pret = 0;
            }
        } else if (prev < 3000) { // 1000 ~ 3000 ms
            longClick(a1);
        } else if (prev >= 3000) { // > 3000 ms
            veryLongClick(a1);
        }
        printArray(a1, a2);
    }
    prev = len;
    delay(300);
}

void printArray(int* a1, int* a2) {
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
        a1[i] = rand() % 99;
    }
}

void veryLongClick(int* a1) {
    for (int i = 0; i < 10; i++) {
        a1[i] = 0;
    }
}

void swapArr(int* a1, int* a2) {
    for (int i = 0; i < 10; i++) {
        a2[i] = a1[i];
    }
}




// This code is contributed by Lance Cai
// Update in 2021.12.22
