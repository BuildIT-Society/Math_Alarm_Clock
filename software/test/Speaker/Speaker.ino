#include <Tone.h>

Tone tone1;

void setup() {
  // put your setup code here, to run once:
  tone1.begin(13);
  Serial.begin(9600);
}

 int x = 0;
void loop() {
 //delay(800);
 if((x % 1000) == 0){
  tone1.play(1200,500);
 }
 else {
  //tone1.stop();
  Serial.println(x);
 }
 x++;
}
