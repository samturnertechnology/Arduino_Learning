#include <Stepper.h>
int stepsPerRev = 2048;
int motorSpeed = 10;
int delayTime = 500;
int switchPin = 2;
int switchValue;
int prevSwitchValue;
bool switchState;
Stepper myStepper(stepsPerRev, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  prevSwitchValue = switchValue;
  switchValue = digitalRead(switchPin);
  if(prevSwitchValue == 1 && switchValue == 0){
    switchState = !switchState;
  }
  if(switchState == 0){
    myStepper.step(1);
  } else {
    myStepper.step(-1);
  }
}
