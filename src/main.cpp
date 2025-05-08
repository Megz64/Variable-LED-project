#include <Arduino.h>

int green = 9;
int red = 10;
int blue = 11;
int button = 5;
int potentiometer = A5;
int power;

int buttonstate;
int color = 1;

void setup() {
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (color > 3) {
    color = 1;
  }

  buttonstate = digitalRead(button);
  if (buttonstate == HIGH) {
    color = color + 1;
    delay(200);
  } 

  power = analogRead(potentiometer);
  Serial.println(power);

  power = map(power, 0, 1023, 0, 255);
  

  switch (color) {
    case 1:
    analogWrite(green, power);
    break;

    case 2:
    analogWrite(red, power);
    break;

    case 3:
    analogWrite(blue, power);
    break;
  }
    
  
}