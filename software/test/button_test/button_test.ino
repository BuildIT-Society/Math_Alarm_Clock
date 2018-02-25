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

const int buttonPin1 = 6;   
const int buttonPin2 = 7;
const int buttonPin3 = 8;
const int buttonPin4 = 9;



// variables will change:
int buttonState1 = 0;   
int buttonState2 = 0;   
int buttonState3 = 0;   
int buttonState4 = 0;   

int sum = 0;

void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Testing"); 
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  
  
  sum = 0;
  if(buttonState1 == HIGH) {
    sum = sum + 1;
    lcd.setCursor(3,1); // first- col, second num is row
    lcd.print("1");
    
  }
  else {
    lcd.setCursor(3,1); // first- col, second num is row
    lcd.print("0");
  }
  if(buttonState2 == HIGH) {
    sum = sum + 2;
    lcd.setCursor(2,1); // first- col, second num is row
    lcd.print("1");
  }
  else {
    lcd.setCursor(2,1); // first- col, second num is row
    lcd.print("0");
  }
  if(buttonState3 == HIGH) {
    sum = sum + 4;
    lcd.setCursor(1,1); // first- col, second num is row
    lcd.print("1");
  }
  else {
    lcd.setCursor(1,1); // first- col, second num is row
    lcd.print("0");
  }
  if(buttonState4 == HIGH) {
    sum = sum + 8;
    lcd.setCursor(0,1); // first- col, second num is row
   // lcd.print("1");
  }
  else {
    lcd.setCursor(0,1); // first- col, second num is row
    lcd.print("0");
  }

  
  // debugging
  Serial.print(sum);
  Serial.print("\n");
 
}
