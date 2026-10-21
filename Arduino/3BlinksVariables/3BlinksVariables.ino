int redLED = 13;
int greenLED = 12;
int blueLED = 11;
int shortBlink = 100;
int midBlink = 300;
int longBlink = 600;
int delayTime = 1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 3; i++){
    digitalWrite(redLED, HIGH);
    delay(shortBlink);
    digitalWrite(redLED, LOW);
    delay(shortBlink);
  }
  delay(delayTime);
  
  for(int i = 0; i < 3; i++){
    digitalWrite(greenLED, HIGH);
    delay(midBlink);
    digitalWrite(greenLED, LOW);
    delay(midBlink);
  }
  delay(delayTime);

  for(int i = 0; i < 3; i++){
    digitalWrite(blueLED, HIGH);
    delay(longBlink);
    digitalWrite(blueLED, LOW);
    delay(longBlink);
  }
  delay(delayTime);
  
}
