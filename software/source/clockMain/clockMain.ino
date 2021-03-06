#include <LiquidCrystal.h>
#include <DS3231.h>
#include <Tone.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
Time clk; // Init a Time-data structure

// Speaker setup
Tone buzzer;

// LCD setup
const int rs = 12; 
const int en = 11; 
const int d4 = 5; 
const int d5 = 4; 
const int d6 = 3;
const int d7 = 2;
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

bool enter = 0; // User answer ready flag
int sum = 0; // user input sum
int level = 1; // user math level
int answer; // answer to math problem
int response; // user input response
int x = 0; // loop variable
int y = 0; // loop variable

int hours = 12; // start hours
int minutes = 59; //start min
int seconds = 58; //start seconds
int ampm = 0; // 0 = am, 1 = pm
int alarmHour = 8; // hour time for alarm
int alarmMin = 0; // minute time for alarm
bool alarmFlag = false; // flag to set alarm

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set up real time clock module
  rtc.begin();
  // set up the buzzer for the alarm
  buzzer.begin(13);
  
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
  while (alarmFlag == false) {
    printClock();
    
    if(alarmHour == hours && alarmMin == minutes) {
      buzzer.play(1200,300);
      //printAlarmStatus(); 
      alarmFlag = true; 
    }
    printAlarm();
  }
  
  lcd.clear();

  // find math question for user level
  switch(level) {
    case 1:
      answer = question1();
      break;
    case 2:
      //answer = question2();
      break;
    default:
      answer = question1();
      break;
  }

  printLevel(level); // prints user level to screen
 
  response = getResponse(); // get users answer for question
  
  Serial.print("******** OUT ********");
  lcd.clear();
  lcd.setCursor(0,0);
  alarmFlag = checkResponse(response, answer);
  minutes++;
  
  //printEnd();
} // END MAIN



//////////////// MATH FUNCTIONS ///////////////////
// Q: x to binary?
int question1() {
  // creates random number from 0 to 15
  int randomNum = random(0,16);
  lcd.setCursor(0,0);
  lcd.print("Q: ");
  lcd.print(randomNum);
  lcd.print(" to binary?");
  return randomNum;
}

// reads input pins
// converts the users binary value to decimal
int getResponse() {
  while(digitalRead(enterPin) != HIGH) {
    readPins();
    
    Serial.println(y); // DO NOT DELETE, buzzer library needs this to work
    y = buzzerPlay(y);
    
    // sum of all input
    sum = 0;
    sum = displayBinary();
    //printSum();   
    y++;
  }
  return sum;
}

// checks if the user's response is same as correct answer
bool checkResponse(int resp, int ans) {
  // debugging
  /*
  Serial.print("Ans ");
  Serial.print(ans);
  Serial.print("Resp ");
  Serial.println(resp);
  */
    
  if(resp == ans) {
    lcd.print("Correct");
    delay(2000);
    return false; // turns off alarm
  }
  else {
    lcd.print("Wrong!");
    lcd.setCursor(0,1);
    lcd.print("Answer is: ");
    lcd.print(ans);
    delay(2000);
    return true; // keeps alarm on
  }
}

// prints users math level to the screen
void printLevel(int lvl) {
  lcd.setCursor(8,1);
  lcd.print("level: ");
  lcd.print(lvl);
}


/////////////// CLOCK FUNCTIONS ////////////////////
// clock printing logic, includes proper 0's
void printClock() {
  lcd.setCursor(0, 0);
  
  // gets real time from rtc module then prints to lcd screen
  clk = rtc.getTime();
  
  if(clk.hour > 12) {
    hours = clk.hour - 12;
    ampm = 1;
  }
  else {
    hours = clk.hour;
    ampm = 0;
  }
  minutes = clk.min;
  seconds = clk.sec;

  // prints time to lcd screen
  (hours < 10) ? lcd.print("0") : NULL;
  lcd.print(hours);
  lcd.print(":");
  (minutes < 10) ? lcd.print("0") : NULL;
  lcd.print(minutes);
  lcd.print(":");
  (seconds < 10) ? lcd.print("0") : NULL;
  lcd.print(seconds);
  lcd.display();
   
}

// prints out a simulated clock to lcd
void printClockTest() {
  // used for debugging time issues
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

// creates a time interval between buzz sounds
int buzzerPlay(int count) {
  if((count % 300) == 0) {
    buzzer.play(1200,500); // (freq, duration (ms))
    count = 1;
  }
  return count;
}


// clock incrementing logic
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
int displayBinary() {
 
  // change the screen value shown and gather decimal sum
  for(x = 0; x < 4; x++) {
    if(currButton[x] == 1 && oldButton[x] == 0) {
      lcd.setCursor(3 - x, 1); // first- col, second num is row
      lcd.print(currButton[x]);
    }
    
    if(currButton[x] == 0 && oldButton[x] == 1) {
      lcd.setCursor(3 - x, 1); // first- col, second num is row
      lcd.print("0");
    }
    if(currButton[x] == 1) {
      sum = sum + ceil(pow(2,x)); // ceil- need to round power function up
    }
    oldButton[x] = currButton[x];
  }
  return sum;
}


/////////////// DEBUGGING FUNCTIONS ////////////////
void printAlarmStatus() {
  lcd.setCursor(6, 1);
  lcd.print("Alarm!");
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

