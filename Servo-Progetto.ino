#include<Servo.h>

int pinFotoA0 = A0;
int valFotoA0 = 0;

Servo myservo;
#define servoPin 9

void luxLecture(int val, int pin){
  val = analogRead(pin);
  val = map(val, 0, 679, 0, 100);
  Serial.println(val);
}

void setup() {

  myservo.attch(servoPin);
  Serial.begin(9600);

}

void loop() {

  luxLecture(valFotoA0, pinFotoA0);

  luxLecture()
  
}
