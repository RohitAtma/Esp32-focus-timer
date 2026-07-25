#define BUTTON_PIN 4
#define Seg_A 26
#define Seg_B 27
#define Seg_C 14
#define Seg_D 13
#define Seg_E 5
#define Seg_F 33
#define Seg_G 32

bool timing = false;
unsigned long startTime = 0;

void shownumber(int N){
  digitalWrite(Seg_A, LOW);
  digitalWrite(Seg_B, LOW);
  digitalWrite(Seg_C, LOW);
  digitalWrite(Seg_D, LOW);
  digitalWrite(Seg_E, LOW);
  digitalWrite(Seg_F, LOW);
  digitalWrite(Seg_G, LOW);

  if (N==0){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_E, HIGH);
  digitalWrite(Seg_F, HIGH);
  }

    if (N==1){
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  }

  if (N==2){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_E, HIGH);
  digitalWrite(Seg_G, HIGH);
  }

  if (N==3){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_G, HIGH);
  }

    if (N==4){
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_G, HIGH);
  digitalWrite(Seg_F, HIGH);
  }

    if (N==5){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_G, HIGH);
  digitalWrite(Seg_F, HIGH);
  }

    if (N==6){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_G, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_E, HIGH);
  digitalWrite(Seg_F, HIGH);
  }

    if (N==7){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  }

    if (N==8){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_E, HIGH);
  digitalWrite(Seg_F, HIGH);
  digitalWrite(Seg_G, HIGH);
  }

    if (N==9){
  digitalWrite(Seg_A, HIGH);
  digitalWrite(Seg_B, HIGH);
  digitalWrite(Seg_C, HIGH);
  digitalWrite(Seg_D, HIGH);
  digitalWrite(Seg_F, HIGH);
  digitalWrite(Seg_G, HIGH);
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(Seg_A, OUTPUT);
  pinMode(Seg_B, OUTPUT);
  pinMode(Seg_C, OUTPUT);
  pinMode(Seg_D, OUTPUT);
  pinMode(Seg_E, OUTPUT);
  pinMode(Seg_F, OUTPUT);
  pinMode(Seg_G, OUTPUT);
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
      if (seconds > 9){seconds = 0;}
      shownumber(seconds);

    }
}