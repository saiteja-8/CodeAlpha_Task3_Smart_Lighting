const int pirPin = 2;
const int ldrPin = A0;
const int ledPin = 9;

int lightThreshold = 500;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightValue = analogRead(ldrPin);

  Serial.print("LDR: ");
  Serial.print(lightValue);
  Serial.print("  PIR: ");
  Serial.println(motion);

  if (motion == HIGH && lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}
