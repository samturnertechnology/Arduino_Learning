int inputPin = A0;
int outputPin = 10;
int delayTime = 500;
float readValue;
float returnVoltage;
float writeVoltage;
float referenceValue = 1023.;
float supplyVoltage = 5.;
float maxWrite = 255.;



void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(inputPin);
  writeVoltage = (maxWrite / referenceValue) * readValue;
  analogWrite(outputPin, writeVoltage);
  
  Serial.println(writeVoltage);
  delay(delayTime);
}
