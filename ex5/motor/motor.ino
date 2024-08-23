const int pins[] = {8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  motorControl(HIGH, LOW, HIGH, LOW, 8000);
  motorControl(HIGH,HIGH, LOW, LOW, 3000);
  motorControl(LOW, HIGH, LOW, HIGH, 8000);
  motorControl(LOW, LOW, LOW, LOW, 1000);
}

void motorControl(int in1, int in2, int in3, int in4, int duration) {
  int states[] = {in1, in2, in3, in4};
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], states[i]);
  }
  delay(duration);
}