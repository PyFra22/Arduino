int pinF = 6;
int pinLed = 5;
int valFd = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pinF, INPUT);
  
  pinMode(pinLed, OUTPUT);
}

void loop() {
  
  valFd = digitalRead(pinF);
  Serial.println(valFd);
  delay(2000);

  if(valFd == 0){
    pinMode(pinLed, HIGH);
  }
  else{
    pinMode(pinLed, LOW);
  }
  

}
