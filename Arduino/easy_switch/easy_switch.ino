int switchPin = 2;
int switchValue;
String switchState;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchValue = digitalRead(switchPin);
  if(switchValue == 1){
    switchState = "Not Pressed";
  } else {
    switchState = "Pressed";
  }
  Serial.print("Your Button is: ");
  Serial.println(switchState);
  delay(500);
}
