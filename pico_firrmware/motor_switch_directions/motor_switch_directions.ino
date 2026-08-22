// Left Motor Pin Constants
const int MOTOR_LEFT_POSITIVE = 2;
const int MOTOR_LEFT_NEGATIVE = 3;
const int MOTOR_LEFT_A = 14;
const int MOTOR_LEFT_B = 15;
const int MOTOR_LEFT_PWM = 13;

// Position Variables
volatile long motor_left_position = 0;



void LeftEncoderInterrupt() {
  bool a = digitalRead(MOTOR_LEFT_A);
  bool b = digitalRead(MOTOR_LEFT_B);
  
  if (a == b) {
    motor_left_position++;
  } else {
    motor_left_position--;
  }
}






void setup() {
  // Setting Direction Pins to Output
  pinMode(MOTOR_LEFT_POSITIVE, OUTPUT);
  pinMode(MOTOR_LEFT_NEGATIVE, OUTPUT);

  // Setting Encoder Pins to Input
  pinMode(MOTOR_LEFT_A, INPUT_PULLUP);
  pinMode(MOTOR_LEFT_B, INPUT_PULLUP);

  // Setting PWM Pins to OUTPUT
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  analogWrite(MOTOR_LEFT_PWM, 50);

  // Attatch the Interupt
  attachInterrupt(digitalPinToInterrupt(MOTOR_LEFT_A), LeftEncoderInterrupt, CHANGE);

  // Begin Serial Log
  Serial.begin(115200);
}

void loop() {
  digitalWrite(MOTOR_LEFT_POSITIVE, HIGH);
  digitalWrite(MOTOR_LEFT_NEGATIVE, LOW);

  delay(1000);

  digitalWrite(MOTOR_LEFT_POSITIVE, LOW);
  digitalWrite(MOTOR_LEFT_NEGATIVE, LOW);

  Serial.println(motor_left_position);

  delay(250);

  digitalWrite(MOTOR_LEFT_POSITIVE, LOW);
  digitalWrite(MOTOR_LEFT_NEGATIVE, HIGH);

  delay(1000);

  digitalWrite(MOTOR_LEFT_POSITIVE, LOW);
  digitalWrite(MOTOR_LEFT_NEGATIVE, LOW);

  Serial.println(motor_left_position);

  delay(250);
}
