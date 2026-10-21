int readPin = A0;
int redPin = 10;
int readValue;
int delayTime = 500;
float referenceValue = 1023.;
float supplyVoltage = 5.;
float returnVoltage;


void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);
  returnVoltage = (supplyVoltage/referenceValue) * readValue;
  Serial.println(returnVoltage);
  
  delay(delayTime);
}
