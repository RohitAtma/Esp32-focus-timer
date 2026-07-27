int segPins[7]={4,5,12,13,14,15,16};
int digPins[4]={17,18,19,21};
int digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};
#define BUTTON_PIN 22
bool timing = false;
unsigned long startTime = 0;

void showAtPosition(int number, int position){
  for (int i = 0; i < 4; i++) digitalWrite(digPins[i], HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[number][i]);
  }
  digitalWrite(digPins[position], LOW);
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digPins[i], OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (timing == false) {
      startTime = millis();
      timing = true;
    }
    else {
      timing = false;
    }
    delay(300);
    };
    if(timing == true){
      int seconds = (millis() - startTime) / 1000;

  showAtPosition((seconds/1000) % 10,0);
  showAtPosition((seconds/100) % 10,1);
  showAtPosition((seconds/10) % 10,2);
  showAtPosition(seconds % 10,3);
    }

  
}