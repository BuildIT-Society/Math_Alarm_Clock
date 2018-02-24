const int buttonPin1 = 2;   
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

const int ledPin =  12 ;      

// variables will change:
int buttonState1 = 0;   
int buttonState2 = 0;   
int buttonState3 = 0;   
int buttonState4 = 0;   

int sum = 0;

void setup() {
 
  pinMode(ledPin, OUTPUT);
  
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
  }
  if(buttonState2 == HIGH) {
    sum = sum + 2;
  }
  if(buttonState3 == HIGH) {
    sum = sum + 4;
  }
  if(buttonState4 == HIGH) {
    sum = sum + 8;
  }
  Serial.print(sum);
  Serial.print("\n");
 
}
