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
int pinPowerLCD = 8;


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
  lcdDisplay.clear();
  pinMode(pinPowerLCD, OUTPUT);

}

void loop() {


  // Get the data from analogic pin
  valueSterzi = analogRead(sterzoJoystickPinY);
  valueSpeed = analogRead(speedJoystickPin);

  // Map the values 
  valueSterzi = map(valueSterzi, 0, 1023, 0, 180);
  valueSpeed = map(valueSpeed, 512, 1023, 50, 100);
  
  // Set and print what we want on the lcd 20x4
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Direzione Sterzo: ");

  if(valueSterzi > 95 && valueSterzi < 105){
    lcdDisplay.setCursor(18, 0);
    lcdDisplay.print("Cx");
  }
  else if(valueSterzi < 95){
    lcdDisplay.setCursor(18, 0);
    lcdDisplay.print("Sx");
  }
  else if(valueSterzi > 105){
    lcdDisplay.setCursor(18, 0);
    lcdDisplay.print("Dx");
  }
  

  lcdDisplay.setCursor(0, 1);
  lcdDisplay.print("Ctrl Velocita: ");
  lcdDisplay.setCursor(16, 1);
  lcdDisplay.print(valueSpeed);
  //lcdDisplay.setCursor(19, 1);
  //lcdDisplay.print("%");


}
