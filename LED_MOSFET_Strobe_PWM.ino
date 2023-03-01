#include <PWM.h>

int analogPin = 2;
int ledPin = 5;
int modePin = 2;
int PWMFreq = 6000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(modePin, INPUT_PULLUP);
  
  if(digitalRead(modePin) == HIGH){
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
  
  else{
    InitTimers();
    bool b = SetPinFrequency(ledPin, PWMFreq);
    while(0 == 0){
      pwmWrite(ledPin, map(analogRead(analogPin), 0, 1023, 0, 255));
    }
  }
}

void loop() {
  
}
