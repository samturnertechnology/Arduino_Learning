int redLED = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redLED, 255);
  delay(1000);
  analogWrite(redLED, 125);
  delay(1000);
  analogWrite(redLED, 80);
  delay(1000);
  analogWrite(redLED, 30);
  delay(1000);
  analogWrite(redLED, 0);
  delay(2000);
}
