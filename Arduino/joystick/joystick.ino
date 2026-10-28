int xPin = A0;
int yPin = A1;
int switchPin = 13;
int bluePin = 2;
int redPin = 3;
int greenPin = 4;
int yellowPin = 5;

int xVal;
int yVal;
int switchVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);

  digitalWrite(switchPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  switchVal = digitalRead(switchPin);

  printValues(xVal, yVal, switchVal);

  if(yVal < 300){
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
  } else if (yVal > 900) {
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  if(xVal < 300){
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
  } else if (xVal > 900) {
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
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

