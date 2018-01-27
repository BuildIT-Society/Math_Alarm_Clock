#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>


#define LENGTH 16


// makes simple algebra problem, Ax + B = C
bool algebra1();

// makes simple algebra problem, Ax + B = Cx + D
bool algebra2(int lvl);


// prints out screen view for debugging
void printScreen(char str[], int row, int cursor);





#endif
