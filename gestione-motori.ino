#include <Servo.h>

Servo servoLeft;
Servo servoRight;

#define pinServoLeft 8 
#define pinServoRight 7
#define motorRight 10
#define motorLeft 11

int degreesServoLeft = 0;
int degreesServoRight = 0;


void setup() {

  //pinMode(servoLeft, OUTPUT);
  //pinMode(servoRight, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
  servoLeft.attach(pinServoLeft);
  servoRight.attach(pinServoRight);
  Serial.begin(9600);
  
}

void loop() {
  servoRight.write(degreesServoRight);
  int counter = millis();
  if(counter > 20000){
    degreesServoRight = 90;
    servoRight.write(degreesServoRight);
    digitalWrite(motorRight, HIGH);
  }

}
