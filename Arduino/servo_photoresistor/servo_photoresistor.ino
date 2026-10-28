#include <Servo.h>

int servoPin = 9;
int inputPin = A0;

int servoPosition = 0;
Servo myServo;

float lightValue;
float lightPercentage;
int lightToDegree;
int maxValue = 1023;
float maxDegree = 180;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightValue = analogRead(inputPin);
  servoPosition = convertLightToDegree(lightValue);
  myServo.write(servoPosition);
  printMessages(lightValue,lightPercentage,servoPosition);
  delay(1000);
}

void printMessages(int lightValue, int lightPercentage, int servoPosition){
  Serial.print("Light detected out of 1028:");
  Serial.println(lightValue);
  Serial.print("Light Percentage:");
  Serial.println(lightPercentage);
  Serial.print("Degrees:");
  Serial.println(servoPosition);
  Serial.println();
}

int convertLightToDegree(float lightValue) {
  lightPercentage = (lightValue / maxValue) * 100;
  int degree = (maxDegree / 100) * lightPercentage;
  return degree;
}
