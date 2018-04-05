#include <LiquidCrystal.h>

// LCD setup
const int rs = 12; 
const int en = 11; 
const int d4 = 5; 
const int d5 = 4; 
const int d6 = 3;
const int d7 = 2;
// setup function 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pinout for buttons
/*  buttonPin1 -> 6;   
    buttonPin2 -> 7;
    buttonPin3 -> 8;
    buttonPin4 -> 9; */
const int buttonPin [4] = {6, 7, 8, 9};
const int enterPin = 10; // pin 10

// current and old button states, need old to hold value
bool currButton [4] = {0,0,0,0};
bool oldButton [4] = {1,1,1,1}; 

bool enter = 0; // Enter value
int sum = 0; // input sum
int x = 0; // loop variable

int hours = 12; // start hours
int minutes = 59; //start min
int seconds = 55; //start seconds
int alarmHour = 1; // hour time for alarm
int alarmMin = 0; // minute time for alarm

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(9,0);
  lcd.print("Sum:"); 

  // set all button pins for INPUT mode
  for(x = 0; x < 4; x++) {
    pinMode(buttonPin[x], INPUT);
  }

  // set baud rate
  Serial.begin(9600);
}




/////////////////// MAIN LOOP ////////////////////////
void loop() {

   // printing clock logic
   while (true) {
     printClock();
     printAlarm();
     printAlarmStatus();
     
   }
   
  while(digitalRead(enterPin) != HIGH) {
    readPins();
    
    // sum of all input
    sum = 0;
    displayBinary();

    printSum();
  
    // debugging
    Serial.print(sum);
    Serial.print("\n");
  }

  printEnd();

  delay(3000);
  lcd.setCursor(10,1);
  lcd.print("      "); // clear screen
} // END MAIN




/////////////////// HELPER FUNCTIONS //////////////////////
// reads the binary pushbutton pins
void readPins() { 
  // read each button, if pressed -> HIGH
  for(x = 0; x < 4; x++) {
    if(digitalRead(buttonPin[x]) == HIGH) {
      currButton[x] = !currButton[x];
      delay(200); // debouncing delay 
    }
  } 
}

// displays the binary number on the screen
// also calculates the sum of the binary number
void displayBinary() {
  // change the screen value shown and gather decimal sum
  for(x = 0; x < 4; x++) {
    if(currButton[x] == 1 && oldButton[x] == 0) {
      lcd.setCursor(15 - x, 1); // first- col, second num is row
      lcd.print(currButton[x]);
    }
    
    if(currButton[x] == 0 && oldButton[x] == 1) {
      lcd.setCursor(15 - x, 1); // first- col, second num is row
      lcd.print("0");
    }
    if(currButton[x] == 1) {
      sum = sum + ceil(pow(2,x)); // ceil- need to round power function up
    }
    oldButton[x] = currButton[x];
  }
}

// prints the sum to the screen
void printSum() {
  // prints sum to screen
  if(sum < 10) {
    lcd.setCursor(14,0);
    lcd.print('0');
    lcd.print(sum);
  }
  else {
    lcd.setCursor(14,0);
    lcd.print(sum);
  }
}

/////////////// CLOCK FUNCTIONS ////////////////////
// clock printing logic, includes proper 0's
void printClock() {
  lcd.setCursor(0, 0);
  (hours < 10) ? lcd.print("0") : NULL;
  lcd.print(hours);
  lcd.print(":");
  (minutes < 10) ? lcd.print("0") : NULL;
  lcd.print(minutes);
  lcd.print(":");
  (seconds < 10) ? lcd.print("0") : NULL;
  lcd.print(seconds);
  lcd.display();
  stepUp();
  delay(1000);
}

// clock logic
 void stepUp() {
   if (seconds < 59) {
     seconds ++;
   } 
   else if (minutes < 59) {
      seconds = 0;
      minutes ++;
   } 
   else if (hours < 12) {
      seconds = 0;
      minutes = 0; 
      hours ++;       
    }
    else {
      seconds = 0;
      minutes = 0; 
      hours = 1; 
   }
 }

// prints alarm to screen
 void printAlarm() {
  lcd.setCursor(0, 1);
  (alarmHour < 10) ? lcd.print("0") : NULL;
  lcd.print(alarmHour);
  lcd.print(":");
  (alarmMin < 10) ? lcd.print("0") : NULL;
  lcd.print(alarmMin); 
 }


/////////////// DEBUGGING FUNCTIONS ////////////////
void printAlarmStatus() {
  lcd.setCursor(6, 1);
  if(alarmHour != hours && alarmMin != minutes) {
     lcd.print("off");
  }
  else {
    lcd.print("on");
    lcd.print(" ");
  }
}

// prints end message to screen
void printEnd() {
  // end message
  if(sum > 5) {
    lcd.setCursor(10,1);
    lcd.print("Winner");
  }
  else {
    lcd.setCursor(11,1);
    lcd.print("Loser");
    lcd.print(" ");
  }
}

