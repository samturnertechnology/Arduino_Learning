// Pin Declarations
int redLed = 11;
int blueLed = 10;
int buttonPower = 7;
int buttonInput = A0;
// Brightness Values
int redValue = 255;
int blueValue = 0;
// Increment Values
int incrementValue = 5;
int internalDelay = 200;
int externalDelay = 1000;
// Increase / decrease brightness switch
bool increaseBrightness = false;
// Button Value
int previousButtonValue = 0;
int buttonValue = 0;
bool buttonState = false;

void setup() {
  // put your setup code here, to run once:
  // Pin Modes
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buttonPower, OUTPUT);
  pinMode(buttonInput, INPUT);
  // Serial Start
  Serial.begin(9600);
  // Initial Writes
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  digitalWrite(buttonPower, HIGH);
  delay(externalDelay);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(redValue > 0 || redValue < 255){
    previousButtonValue = buttonValue;
    buttonValue = digitalRead(buttonInput);
    if(buttonValue == 0 and previousButtonValue == 1){
      Serial.println("Button Pressed!");
      for(int i = 0; i < 3; i++){
        digitalWrite(redLed, HIGH);
        digitalWrite(blueLed, HIGH);
        delay(internalDelay);
        digitalWrite(redLed, LOW);
        digitalWrite(blueLed, LOW);
        delay(internalDelay);
      }
    }
    analogWrite(redLed, redValue);
    analogWrite(blueLed, blueValue);
    if(!increaseBrightness){
      redValue -= incrementValue;
      blueValue += incrementValue;
    } else if (increaseBrightness){
      redValue += incrementValue;
      blueValue -= incrementValue;
    }
    Serial.print("Red Brightness: ");
    Serial.print(redValue);
    Serial.print(", Blue Brightness: ");
    Serial.println(blueValue);
    if(redValue == 0){
      increaseBrightness = true;
    }
    else if (redValue == 255){
      increaseBrightness = false;
    }
    delay(internalDelay);
  }
  delay(externalDelay);
}
 
