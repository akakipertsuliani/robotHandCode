#include <Servo.h>

Servo myServo;
Servo myServo1;
Servo myServo2;

#define xAxis A0
#define yAxis A1

#define firstServo 10
#define secondServo 11
#define threeServo 12

#define setButtonUp 2
#define leftButtonClose 3
#define rightButtonOpen 5
#define resetButton 8

int handServoDegree = 90;

void setup() {
  pinMode(setButtonUp, INPUT);
  pinMode(leftButtonClose, INPUT);
  pinMode(rightButtonOpen, INPUT);
  pinMode(resetButton, INPUT);

  myServo.attach(firstServo);
  myServo1.attach(secondServo);
  myServo2.attach(threeServo);

  myServo.write(90);
  myServo1.write(90);
  myServo2.write(130);
}

void loop() {
  int xReader = analogRead(xAxis);
  int yReader = analogRead(yAxis);

  xReader = map(xReader, 0, 1023, 0, 180);
  yReader = map(yReader, 0, 1023, 100, 180);

  if (!digitalRead(leftButtonClose)) {
    if (handServoDegree >= 180) {
      handServoDegree = 180;
    }

    handServoDegree += 10;
    myServo2.write(handServoDegree);
    delay(100);
  }

  if (!digitalRead(rightButtonOpen)) {
    if (handServoDegree >= 130) {
      handServoDegree = 130;
    }

    handServoDegree -= 10;
    myServo2.write(handServoDegree);
    delay(100);
  }

  if (!digitalRead(resetButton)) {
    myServo.write(90);
    myServo1.write(90);
    myServo2.write(130);
  }

  myServo.write(yReader);
  myServo1.write(xReader);
}
