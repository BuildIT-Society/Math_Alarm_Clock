#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "clock.h"


// makes simple algebra problem
// Ax + B = C
bool algebra1(float * answer) {
    // randomly seeds random variable with time
    srand(time(NULL));
    float A;
    float B;
    float C;
    float x;
    // need to get numbers that make answer whole number
    do {
        A = rand() % 10;
        B = rand() % 20;
        C = rand() % 20;
        x = (C - B) / A;
        //printf("Generate x = %f\n", x);
        //printf("fmod(x,1) = %f\n", fmod(x,1));
    } while(fmod(x, 1) != 0.0 || (int)B == (int)C || (int)C == 0 || (int)A == 1);


    // equation to end alarms
    printf("%dx + %d = %d\n", (int) A, (int) B, (int) C);

    float result = 0.0;
    printf("x = ");
    scanf("%f", &result);
    //printf("You entered: %d\n", (int) result);
    printf("Answer: %d\n", (int) x);

    // check if the user input is correct answer
    if (result == x) {
        printf("(End Alarm)\n\n");
        return true;
    } else {
        printf("(Continue Alarm)\n\n");
        return false;
    }
}


// makes simple algebra problem, Ax + B = Cx + D
bool algebra2(int lvl) {
    // randomly seeds random variable with time
    srand(time(NULL));
    float A;
    float B;
    float C;
    float D;
    float x;
    // need to get numbers that make answer whole number
    do {
        A = rand() % 10;
        B = rand() % 10 * lvl;
        C = rand() % 10;
        D = rand() % 10 * lvl;
        x = (D - B) / (A - C);
        //printf("Generate x = %f\n", x);
        //printf("fmod(x,1) = %f\n", fmod(x,1));
    } while(fmod(x, 1) != 0.0);


    // equation to end alarms
    printf("%dx + %d = %dx + %d\n", (int) A, (int) B, (int) C, (int) D);

    float result = 0.0;
    printf("x = ");
    scanf("%f", &result);
    //printf("You entered: %d\n", (int) result);
    printf("Answer: %d\n", (int) x);

    // check if the user input is correct answer
    if (result == x) {
        printf("Success!\n");
        printf("(End Alarm)\n\n");
        return true;
    } else {
        printf("Try again! hahaha\n");
        printf("(Continue Alarm)\n\n");
        return false;
    }

}



// prints out screen view for debugging
void printScreen(char str[], int row, int cursor) {
    printf("\n");
    int len = LENGTH - cursor;

    len += 1;
    // get to the cursor position
    for (int k = 0; k < cursor; k++) {
        printf(" ");
    }

    // print top screen boundary
    for(int i = 0; i < LENGTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    if (row == 1) {
        printf("#");
    } else {
        printf("#\n");
    }


    int x = 0;
    while(str[x] != '\0') {
        printf("%c", str[x]);
        x++;
    }

    printf("#\n");
    printf("#\n");
    for(int i = 0; i < LENGTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}
