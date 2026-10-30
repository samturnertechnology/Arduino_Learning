int xPin = A5;
int yPin = A4;
int speedPin = 10;
int dir1Pin = 7;
int dir2Pin = 6;
int switchPin = 4;

int minMotorSpeed = 100;
int maxMotorSpeed = 255;
float diffMotorSpeed = maxMotorSpeed - minMotorSpeed;
int motorSpeed;

int xVal;
int yVal;
int switchVal;
int prevSwitchVal;
bool direction;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1Pin, OUTPUT);
  pinMode(dir2Pin, OUTPUT);

  digitalWrite(switchPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  switchVal = digitalRead(switchPin);

  if(yVal > 600) {
    motorSpeed = (155. / 423.) * (yVal - 600) + 100;
    digitalWrite(dir1Pin, HIGH);
    digitalWrite(dir2Pin, LOW);
    analogWrite(speedPin, motorSpeed);
  } else if (yVal < 560) {
    motorSpeed = (155. / -560.) * (yVal - 560) + 100;
    digitalWrite(dir1Pin, LOW);
    digitalWrite(dir2Pin, HIGH);
    analogWrite(speedPin, motorSpeed);
  } else {
    analogWrite(speedPin, 0);
  }
  // printValues(xVal, yVal, switchVal);

  delay(500);
}

void printValues(int xVal, int yVal, int switchValue){
  Serial.print("X Value is: ");
  Serial.println(xVal);
  Serial.print("Y Value is: ");
  Serial.println(yVal);
  Serial.print("Switch State is: ");
  Serial.println(switchVal);
}