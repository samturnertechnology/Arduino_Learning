const int ledPins[4] = {5, 4, 3, 2}; // 8s, 4s, 2s, 1s
const int weights[4] = {8, 4, 2, 1};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int n = 0; n <= 15; n++) {
    showBinary(n);
    delay(1000);
  }
}

void showBinary(int n) {
  int remaining = n;
  for (int i = 0; i < 4; i++) {
    if (remaining >= weights[i]) {
      digitalWrite(ledPins[i], HIGH);
      remaining -= weights[i];
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}