#include <IRremote.h>
#include <Servo.h>


const long RIGHT_BUTTON = 0x20DF609F;
const long LEFT_BUTTON = 0x20DFE01F;
const long POWER_BUTTON = 0x20DF10EF;
const int LED_PIN = 6;
const int SERV_PIN = 9;
const int STEP = 10;

IRrecv irrecv(2);
Servo servo;
decode_results results;

boolean ledStatus = false;
int servAngle = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SERV_PIN, OUTPUT);
  irrecv.enableIRIn();
  servo.attach(SERV_PIN);
  servo.write(180);
}

void loop()
{
  if (irrecv.decode(&results)) {

    switch (results.value) {
      case POWER_BUTTON:
        ledStatus = !ledStatus;
        digitalWrite(LED_PIN, ledStatus);
        break;
      case LEFT_BUTTON:
        servAngle -= STEP;
        servo.write(servAngle);
        break;
      case RIGHT_BUTTON:
        servAngle += STEP;
        servo.write(servAngle);
        break;
    }
    irrecv.resume();
  }
}
