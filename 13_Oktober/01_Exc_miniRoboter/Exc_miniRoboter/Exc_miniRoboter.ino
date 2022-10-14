#include <Servo.h>

Servo myservo;  // create servo object
int pos = 0;    // variable to store the servo position
int pin = 6;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pin,INPUT_PULLUP);
}

void loop() {
  //Serial.println(digitalRead(pin));

  int stateButton = digitalRead(pin);
  Serial.println(stateButton); 

//  if(stateButton == 1) {
//     Serial.println("RELEASED"); 
//  } else {
//     Serial.println("PRESSED"); 
//}
  

  if (stateButton == 0) {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(5);                       // waits 15ms for the servo to reach the position
  }
  }
 //myservo.write(pin);
}
