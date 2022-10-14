#define MOTOR_PIN_A 5
#define MOTOR_PIN_B 6
#define BUTTON_PIN 3
#define ANALOG_INPUT A0

void setup()
{
  Serial.begin(9600);
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ANALOG_INPUT, INPUT);


}
void loop()
{
  int senseValue = analogRead(ANALOG_INPUT);
  int value = map(senseValue, 0, 1023, 0, 255); //wandelt analoge in digitale inputs um
  int stateButton = digitalRead(BUTTON_PIN);
  Serial.println(stateButton);

  if (stateButton == 0) {
    analogWrite(MOTOR_PIN_A, value);
    digitalWrite(MOTOR_PIN_B, LOW);
    //delay(5000);
  }
 if (stateButton == 1) {
    //The other direction
    digitalWrite(MOTOR_PIN_A, LOW);
    analogWrite(MOTOR_PIN_B, value);
    //delay(5000); // sind 5 sekunden
  }
}
