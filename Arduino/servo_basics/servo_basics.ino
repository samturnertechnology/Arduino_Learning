#include <Servo.h>

int servoPin = 9;
int servoPosition = 0;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 180; i++){
    servoPosition = i;
    myServo.write(servoPosition);
    delay(10);
  }
  delay(300);
  servoPosition = 0;
  myServo.write(servoPosition);
  delay(500);
}
