int ledPin = 10;

int readValue = 0;
int ledValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {
  readValue =analogRead(A0);
  ledValue = map(readValue, 0, 1023, 0, 255); //can only go to 1023
  analogWrite(ledPin, ledValue);
}


//10Bizs for anlaog pins
// 10 bits = 00000000011 ==> can be value 1023 possibilities
// 8 bits = 00000000 ==> for digital pins 255 possib





//int ledPin = 10;
//int val;
//
//void setup() {
//  pinMode(ledPin, OUTPUT);
//}
//  void loop() {
//     for(val=0; val<255; val++){
//      analogWrite(ledPin, val);
//      delay(50);
//     }
//      for(val=255; val>0; val--){
//        analogWrite(ledPin, val);
//        delay(50);
//     }
//  }
