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
  


  if (buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW) {
    Serial.print("1\n");
  }else if(buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == LOW){
    Serial.print("2\n");
  }else if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == LOW){
    Serial.print("3\n");
  }else if(buttonState1 == LOW && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == LOW){
    Serial.print("4\n");
  }else if(buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == LOW){
    Serial.print("5\n");
  }else if(buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == LOW){
    Serial.print("6\n");
  }else if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == LOW){
    Serial.print("7\n");
  }else if(buttonState1 == LOW && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == HIGH){
    Serial.print("8\n");
  }else if(buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == HIGH){
    Serial.print("9\n");
  }else if(buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == HIGH){
    Serial.print("10\n");
  }else if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == HIGH){
    Serial.print("11\n");
  }else if(buttonState1 == LOW && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == HIGH){
    Serial.print("12\n");
  }else if(buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == HIGH){
    Serial.print("13\n");
  }else if(buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
    Serial.print("14\n");
  }else if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH&& buttonState4 == HIGH){
    Serial.print("15\n");
  }else{
    Serial.print("0\n");
  }



  
 /* 
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
    Serial.print("1");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.print("0");
    digitalWrite(ledPin, LOW);
  }


    if (buttonState3 == HIGH) {
    Serial.print("1");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.print("0");
    digitalWrite(ledPin, LOW);
  }

    if (buttonState4 == HIGH) {
    Serial.print("1\n");
    digitalWrite(ledPin, HIGH);
    } else {
    Serial.print("0\n");
    digitalWrite(ledPin, LOW);
  }*/
}
