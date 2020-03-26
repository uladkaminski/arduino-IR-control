
#define BUZZER_PIN 3
#define LDR_PIN A0

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int ldr_val;
  int frequency;
  ldr_val = analogRead(LDR_PIN);
  frequency = map(ldr_val, 0, 1023, 3500, 4500);
  tone(BUZZER_PIN, frequency, 20);
}
