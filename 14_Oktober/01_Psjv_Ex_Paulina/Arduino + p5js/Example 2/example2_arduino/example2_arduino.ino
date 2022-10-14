#include <Servo.h>
#define OUTPUT_PIN 11
#define SERVO 9

const int DELAY_MS = 20;
int inputVal;
Servo myServo;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(SERVO, OUTPUT);
  myServo.attach(9);
}

void loop() {
  // Check to see if there is any incoming serial data
  if (Serial.available() > 0) {
    // read string until the endo of the line
    String rcvdSerialData = Serial.readStringUntil('\n');

    value = rcvdSerialData.toInt();
    //this will be seen in the console
      Serial.print("Data received:" + value);
    myServo.write(value);

//    analogWrite(OUTPUT_PIN, rcvdSerialData.toInt());
//    analogWrite(SERVO, rcvdSerialData.toInt());

    delay(DELAY_MS);
  }
}
