
#include <Servo.h>

Servo servo;


void setup() {
  servo.attach(7);
}

void loop() {
 int potent = analogRead(5);
 potent =  map(potent, 0, 1023, 0, 180);
 servo.write(potent);
 delay(2);
}
