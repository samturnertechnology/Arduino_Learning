int blinkNumber;
int outputPin = 13;
String msg="How many times should LED blink? ";

void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){

  }
  blinkNumber = Serial.parseInt();
  for(int i = 0; i < blinkNumber; i++){
    digitalWrite(outputPin, HIGH);
    delay(250);
    digitalWrite(outputPin, LOW);
    delay(250);
  }
  Serial.println("All Done!");
  digitalWrite(outputPin, LOW);
}
