int redPin = 9;
int greenPin = 10;
int bluePin = 11;
String colour;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Which colour to turn on? ");
  while(Serial.available()==0){

  }
  colour = Serial.readString();
  if (colour == "red"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Serial.println("Red on");
  }
  else if (colour == "green"){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    Serial.println("Green on");
  }
  else if (colour == "blue"){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    Serial.println("Blue on");
  }
  else if (colour == "yellow"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 0);
    Serial.println("Yellow on");
  }
  else if (colour == "orange"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);
    Serial.println("Yellow on");
  }
  else if (colour == "purple"){
    analogWrite(redPin, 200);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    Serial.println("Purple on");
  }
  else if (colour == "aqua"){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    Serial.println("Purple on");
  }
  else if (colour == "off"){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Serial.println("Light off");
  }
  else{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Serial.println("Colour not found!");
  }


}
