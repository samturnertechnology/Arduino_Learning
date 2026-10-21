int LEDPin=8;
int buttonPin=12;
int oldState = 1;
int currentState = 1;
int delayTime = 100;

bool lightOn = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  oldState = currentState;
  currentState = digitalRead(buttonPin);
  Serial.println(currentState);
  
  if((currentState==1) && (oldState==0)){
    lightOn = !lightOn;
  }

  if(lightOn){
    digitalWrite(LEDPin, HIGH);
  }
  else{
    digitalWrite(LEDPin, LOW);
  }

  delay(delayTime);
}
