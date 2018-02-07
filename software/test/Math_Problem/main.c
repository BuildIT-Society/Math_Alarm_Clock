#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mathProb.h"

int main() {
    //char string[]  = "Hello World";
    //printScreen(string, 1, 0);
    int hex[2];
    int ans;
    printf("\nHex or algebra:\n 1) Hex\n 2) Algebra\n");
    scanf("%d", &ans);

    if (ans == 1) {

        genHex(hex);
        printf("Hex: %c%c\n", hex[0], hex[1]);
    }
    else {
        printf("\nSolve the math problem to end the alarm.\n");
        bool stop = false;
        int i = 0;
        while(true) {
            // levels of difficulty
            if (i == 0) {
                stop = algebra1();
            }
            if (i == 1) {
                stop = algebra2(1);
            }
            if (i == 2) {
                stop = algebra2(2);
            }
            // breaks loop when answer is correct
            if (stop) {
                break;
            }
            // goes to next level if user wrong, then loops
            i = (i + 1) %  3;
        }

    }
}
