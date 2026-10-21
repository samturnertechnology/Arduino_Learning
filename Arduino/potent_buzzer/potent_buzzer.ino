int buzzerPin = 11;
int powerPin = 13;
int potentPin = A0;
int upperLimit = 10000;
int lowerLimit = 60;
int referenceValue = 1023;
int buzzerRange = upperLimit - lowerLimit;
int buzzerPercentage = buzzerRange / referenceValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(potentPin, INPUT);

  digitalWrite(powerPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potentRead = analogRead(potentPin);
  int buzzMS = buzzerPercentage * potentRead;
  if (potentRead > 1000 || potentRead < 10 ){
    digitalWrite(buzzerPin, LOW);
  }
  else {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(buzzMS);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(buzzMS);
  }
}
