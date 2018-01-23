/* Speaker GND and pin 9 
 * tone(pin, freq, duration)
 * 
 * 
 */
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int BLOCK = 255;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

}

// main
void loop() {
  //checkerPattern();
  tone(9, 75, 500);
  delay(500);
  noTone(9);
  tone(9, 1000, 500);
  delay(500);
  noTone(9);
  
  
  
}


void checkerPattern() {
  // set the cursor to column 0, line 1
  int row = 0; // 0 or 1
  int col = 0; // 0 - 15
  int timer = 500; // time between each block change
  int divider = timer / 32;
  for(int i = 0; i < 2; i++) {

    // fills screen following checkered pattern
    for(col = 0; col < 16; col++) {
      lcd.setCursor(col, row);
      if(row == 0) {
        row = 1;
      }
      else {
        row = 0;
      }
      lcd.write(BLOCK);
      delay(timer); 
      timer = timer - divider;
    }

    // fills in checkered pattern
    row++;
  }
  // resets screen
  lcd.clear();
}

