#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

Servo sterzoServo;
MPU6050 mpu(Wire);
LiquidCrystal_I2C lcdDisplay(0x27, 20, 4);

int sterzoJoystickPinY = A0;
int speedJoystickPin = A1;
int pinSterzoServo = 9;

int valueSterzi, valueSpeed;

void displayValue(){
  Serial.println("=========================");
  Serial.println(valueSterzi);
  Serial.println("=========================");
  Serial.println(valueSpeed);
}

void setup() {
  
  sterzoServo.attach(pinSterzoServo);
  Serial.begin(9600);
  Wire.begin();
  lcdDisplay.begin(20, 4);
  lcdDisplay.backlight();

}

void loop() {

  valueSterzi = analogRead(sterzoJoystickPinY);
  valueSpeed = analogRead(speedJoystickPin);
  valueSterzi = map(valueSterzi, 0, 1023, 0, 180);
  valueSpeed = map(valueSpeed, 512, 1023, 0, 100);
  
  lcdDisplay.clear();
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Direzione Sterzo");

  if(va)
  

  sterzoServo.write(valueSterzi);
  
 

}
