// MOTOR
#define MOTOR_PIN_A 10
#define MOTOR_PIN_B 9
#define MOTOR_PIN_C 7
#define MOTOR_PIN_D 8


//FINITESWITCH STUFF

const byte START = 0;
const byte FORWARD = 1;
const byte LEFT = 2;
const byte REVERSE = 3;

byte myState;



// SENSOR DISTANCE

#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();


void setup() {
 Serial.begin(9600);
  myState = START;  // Initial State

  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);


// SENSOR 
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
}


void loop() {
  // SENSOR
  uint8_t range = vl.readRange();
  int intensity = map(range,13,255,0,2);
  Serial.println(intensity);

// SWITCH
switch (intensity) {

    case 0:
      /*Serial.println("Enter START state");
      delay(10);
      myState = FORWARD;
      */
      digitalWrite(MOTOR_PIN_A, HIGH);
      digitalWrite(MOTOR_PIN_B, LOW);
      digitalWrite(MOTOR_PIN_C, HIGH);
      digitalWrite(MOTOR_PIN_D, LOW);
      Serial.println(0);

      break;

    case 1:
      digitalWrite(MOTOR_PIN_A, LOW);
      digitalWrite(MOTOR_PIN_B, HIGH);
      digitalWrite(MOTOR_PIN_C, LOW);
      digitalWrite(MOTOR_PIN_D, HIGH);
      Serial.println(1);
      /*
      Serial.println("Enter FORWARD state");
      Serial.println("Move Forward"); // action
      if (analogRead(A0) < 100) {
        myState = REVERSE;
      }
      delay(500);*/
      break;

    case 2:
      Serial.println("Enter REVERSE state");
      Serial.println("Move Backward"); // action
      myState = LEFT;
      delay(500);
      break;

    case LEFT:
      Serial.println("Enter LEFT state");
      Serial.println("Move Left"); // action
      delay(500);
      myState = FORWARD;
      break;

  }
/*
  //One direction
  digitalWrite(MOTOR_PIN_A, HIGH);
  digitalWrite(MOTOR_PIN_B, LOW);
  digitalWrite(MOTOR_PIN_C, HIGH);
  digitalWrite(MOTOR_PIN_D, LOW);
  delay(5000);
  
  //The other direction
  digitalWrite(MOTOR_PIN_A, LOW);
  digitalWrite(MOTOR_PIN_B, HIGH);
  digitalWrite(MOTOR_PIN_C, LOW);
  digitalWrite(MOTOR_PIN_D, HIGH);
  delay(5000);*/
}
