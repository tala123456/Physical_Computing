//void setup() {
//  pinMode(9, OUTPUT);
//}
//void loop() {
//  digitalWrite(9, HIGH);   
//}


int ledPin = 9;

int readValue = 0;
int ledValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  readValue = analogRead(A0);
  ledValue = map(readValue, 0, 1023, 0, 255); //can only go to 1023
  analogWrite(ledPin, ledValue);
}
