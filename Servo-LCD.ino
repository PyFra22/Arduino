
#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;

int readButtonUp;
int readButtonDown;
int readButtonEnter;
int readButtonReset;

#define buttonUp 6
#define buttonDown 7
#define errorLed 8
#define pinServo 9
#define buttonEnter 10
#define buttonReset 13

int servoDegrees = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void readStatus(){
  readButtonUp = digitalRead(buttonUp);
  readButtonDown = digitalRead(buttonDown);
  readButtonEnter = digitalRead(buttonEnter);
  readButtonReset = digitalRead(buttonReset);

}

void principalMessagge(){
    lcd.setCursor(0,0);
    lcd.print("Gradi Totali:");
    lcd.setCursor(13, 0);
    lcd.print(servoDegrees);
}

void resetCondition(){
    lcd.clear();
    myservo.write(0);
    servoDegrees = 0;
}

void errorSetUp(){
  digitalWrite(errorLed, HIGH);
  lcd.setCursor(0, 0);
  lcd.clear();
}

void setup()
{
  pinMode(buttonReset, INPUT);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonEnter, INPUT);
  pinMode(errorLed, OUTPUT);
  myservo.attach(pinServo);
  lcd.begin(16, 2); 
  Serial.begin(9600);
  myservo.write(0);
}
void loop()
{

  readStatus();

  if(readButtonUp == HIGH){
    servoDegrees = servoDegrees + 1;
  }
  if(readButtonDown == HIGH){
    servoDegrees = servoDegrees - 1;
  }
  if(readButtonEnter == HIGH){
    readButtonEnter = HIGH;
    myservo.write(servoDegrees);
  }else{
    principalMessagge();
  }
  if (readButtonReset == HIGH){
    resetCondition();
  }
  if(servoDegrees>180 && readButtonEnter == HIGH){
      errorSetUp();
      resetCondition();
      
  }else{
    digitalWrite(errorLed, LOW);
  }
  delay(150);
  if(servoDegrees < 0){
    servoDegrees = 0;
  }

}