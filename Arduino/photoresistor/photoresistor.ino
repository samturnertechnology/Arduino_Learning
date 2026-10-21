int inputPin = A0;
int redPin = 11;
int greenPin = 9;
int lightValue;
int lightAmount = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(redPin, 9);
  pinMode(greenPin, 11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightValue = analogRead(inputPin);
  Serial.println(lightValue);

  if(lightValue > lightAmount){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else if (lightValue < lightAmount) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
  }

  delay(500);
}
