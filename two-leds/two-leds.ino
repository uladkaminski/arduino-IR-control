#include <Servo.h>

Servo servo;
int yellow = 3;
int red = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  servo.attach(7);

}

void loop() {
  // put your main code here, to run repeatedly: // put your main code here, to run repeatedly:
  servo.write(0);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(1000);
  servo.write(270);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
}
