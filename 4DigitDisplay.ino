// 4-Digit 7-Segment Display — shows a number via multiplexing
// No button/timer — just displays the value of Num

int segPins[7] = {4, 5, 12, 13, 14, 15, 16};   // segments A,B,C,D,E,F,G
int digPins[4] = {17, 18, 19, 21};             // digit selects D1,D2,D3,D4

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

int Num = 1234;   // the number to display

// Shows one digit (number) in one position (0-3)
void showAtPosition(int number, int position) {
  for (int i = 0; i < 4; i++) digitalWrite(digPins[i], HIGH); // blank all digits
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[number][i]);              // set segments
  }
  digitalWrite(digPins[position], LOW);                        // light one digit
}

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digPins[i], OUTPUT);
}

void loop() {
  // split Num into its 4 digits and show each in its position
  showAtPosition((Num / 1000) % 10, 0);   // thousands
  showAtPosition((Num / 100) % 10, 1);    // hundreds
  showAtPosition((Num / 10) % 10, 2);     // tens
  showAtPosition(Num % 10, 3);            // ones
}
