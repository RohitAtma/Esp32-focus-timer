#define BUTTON_PIN 4

bool timing = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (timing == false) {
      startTime = millis();
      timing = true;
      Serial.println("Timer started");
    } else {
      unsigned long elapsed = millis() - startTime;
      timing = false;
      Serial.print("You studied for ");
      Serial.print(elapsed / 1000);
      Serial.println(" seconds");
    }
    delay(300);
  }
  delay(50);
}