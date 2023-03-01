#include <PWM.h>

//핀 설정
int analogPin = 2;
int ledPin = 5;
int modePin = 2;

//PWM 스위칭 주파수 설정
int PWMFreq = 6000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(modePin, INPUT_PULLUP);
  
  if(digitalRead(modePin) == HIGH){ //스트로보스코프 모드
    long onTime = 250;
    int minDelay = 1;
    int maxDelay = 100;
    long strobeDelay = 0;
    while(0 == 0){
      strobeDelay = map(analogRead(analogPin), 0, 1023, maxDelay, minDelay);
      digitalWrite(ledPin, HIGH);
      delayMicroseconds(onTime);
      digitalWrite(ledPin, LOW);
      delay(strobeDelay);
    }
  }
  
  else{ //LED 밝기 제어 모드
    InitTimers();
    bool b = SetPinFrequency(ledPin, PWMFreq);
    while(0 == 0){
      pwmWrite(ledPin, map(analogRead(analogPin), 0, 1023, 0, 255));
    }
  }
}

void loop() {
  
}
