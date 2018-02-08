const int buttonPin1 = 2;   
const int buttonPin2 = 3;
const int buttonPin3 = 4;
//const int buttonPin4 = 5;// the number of the pushbutton pin
const int ledPin =  12 ;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;   
int buttonState2 = 0;   
int buttonState3 = 0;   
int buttonState4 = 0;   // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  //pinMode(buttonPin4, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  //buttonState4 = digitalRead(buttonPin4);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    Serial.print("1");
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    Serial.print("0");
    digitalWrite(ledPin, LOW);
  }


    if (buttonState2 == HIGH) {
    // turn LED on:
    Serial.print("1");
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    Serial.print("0");
    digitalWrite(ledPin, LOW);
  }


    if (buttonState3 == HIGH) {
    // turn LED on:
    Serial.print("1\n");
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    Serial.print("0\n");
    digitalWrite(ledPin, LOW);
  }


}
