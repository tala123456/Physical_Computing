#define MOTOR_PIN_A 5
#define MOTOR_PIN_B 6
#define MOTOR_PIN_C 7
#define MOTOR_PIN_D 8


void setup() 
{
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);
}
void loop() 
{
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
  delay(5000);
}
