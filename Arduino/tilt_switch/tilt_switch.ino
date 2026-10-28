int tiltPin = 11;
int greenPin = 2;
int redPin = 3;
int tiltValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  digitalWrite(tiltPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltValue = digitalRead(tiltPin);
  Serial.println(tiltValue);
  if(tiltValue == 0){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
  delay(200);
}
