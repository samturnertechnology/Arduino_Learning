#include <Servo.h>

Servo myServo;

int xPin = A0;
int yPin = A1;
int switchPin = 13;
int servoPin = 2;

int xVal;
int yVal;
int switchVal;
int servoPosition;

float maxValue = 1023;
float maxDegree = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  switchVal = digitalRead(switchPin);

  servoPosition = xValToDegree(xVal);
  myServo.write(servoPosition);

  delay(500);
  Serial.print("Servo Position ");
  Serial.println(servoPosition);
}

int xValToDegree(int xVal){
  int xPercentage = xVal / maxValue * 100;
  int degree = maxDegree / 100 * xPercentage;
  return degree;
}
