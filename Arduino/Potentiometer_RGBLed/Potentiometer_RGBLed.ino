int inputPin = A0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int delayTime = 500;
float readValue;
float referenceValue = 1023.;
float coloursAvailable = 6;
float segment = referenceValue / coloursAvailable;


void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(inputPin);

  if (readValue < segment){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  else if (readValue > segment && readValue < segment * 2){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);
  }
  else if (readValue > segment * 2 && readValue < segment * 3) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  else if (readValue > segment * 3 && readValue < segment * 4){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  else if (readValue > segment * 4 && readValue < segment * 5){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else if (readValue > segment * 5 && readValue < segment * 6){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }

  Serial.println(readValue);
  delay(delayTime);
}
