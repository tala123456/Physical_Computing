#define inputPin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(inputPin);
  int pinValue = digitalRead(inputPin);
  Serial.print("pin input 10:");
  Serial.println(pinValue);
  delay(100);
}
