#define inputPin 10
#define ledPin 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(inputPin);
  int pinValue = digitalRead(inputPin);
  Serial.print("pin input 10:");
  Serial.println(pinValue);
  delay(100);

if (pinValue == 0) {
  digitalWrite(ledPin, HIGH);
}
  else {
    digitalWrite(ledPin, LOW);
  }
 
}
