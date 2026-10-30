int speedPin = 10;
int dir1Pin = 7;
int dir2Pin = 6;
// Clockwise and Counter Clock Wise
int cwButtonPin = 4;
int ccwButtonPin = 3;

int motorSpeed;

int cwButtonValue;
int cwPrevButtonValue;
int ccwButtonValue;
int ccwPrevButtonValue;
bool direction;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1Pin, OUTPUT);
  pinMode(dir2Pin, OUTPUT);
  pinMode(cwButtonPin, INPUT);
  pinMode(ccwButtonPin, INPUT);

  digitalWrite(cwButtonPin, HIGH);
  digitalWrite(ccwButtonPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  cwPrevButtonValue = cwButtonValue;
  cwButtonValue = digitalRead(cwButtonPin);
  ccwPrevButtonValue = ccwButtonValue;
  ccwButtonValue = digitalRead(ccwButtonPin);

  if(cwPrevButtonValue == 1 && cwButtonValue == 0){
    if(motorSpeed <= 100 && direction != true) {
      changeDirection(true);
      setInitialSpeed();
    } else if (direction == true && motorSpeed < 255){
      increaseSpeed();
    } else if (direction == false && motorSpeed <= 255) {
      decreaseSpeed();
    }
    printMessages(direction, motorSpeed);
    delay(500);
  }

  if(ccwPrevButtonValue == 1 && ccwButtonValue == 0){
    if(motorSpeed == 100 && direction != false) {
      changeDirection(false);
      setInitialSpeed();
    } else if (direction == false && motorSpeed < 255){
      increaseSpeed();
    } else if (direction == true && motorSpeed <= 255) {
      decreaseSpeed();
    }
    printMessages(direction, motorSpeed); 
    delay(500);
  }

  analogWrite(speedPin, motorSpeed);
}

void changeDirection(bool newDirection){
  if(newDirection == false){
    direction = false;
    digitalWrite(dir1Pin, HIGH);
    digitalWrite(dir2Pin, LOW);
  } else {
    direction = true;
    digitalWrite(dir1Pin, LOW);
    digitalWrite(dir2Pin, HIGH);
  }
}

void increaseSpeed(){
  motorSpeed += 31;
}

void decreaseSpeed(){
  motorSpeed -= 31;
}

void setInitialSpeed(){
  motorSpeed = 100;
}

void printMessages(bool direction, int motorSpeed){
  Serial.print("Direction: ");
  Serial.println(direction);
  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);
  
}
