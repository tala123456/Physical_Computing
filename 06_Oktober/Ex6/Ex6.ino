#define sensorPin A0
#define ledPin 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
    //sensorValue = map(sensorValue, 600, 700, 0, 255);
   // sensorValue = constrain(sensorValue, 0, 255);
   if (sensorValue <= 800) {
   digitalWrite(ledPin, HIGH);
}else {
  Serial.println(sensorValue);
  delay(50);
}
  Serial.println(sensorValue);
  delay(50);
}
