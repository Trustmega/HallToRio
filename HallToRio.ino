/* program for the arduino that converts the digital signals from the hall effect sensor to an analog value between 0 to 5V
Projektarbete i elektroteknik VT-2016
Uppsala University
Victor Bloetjes
*/

int maxSpeed = 42; //42hz = 70km/h
int toRio = 9;
int measureTime = 500; //measure revolutions 0.5sec at a time
int measuredValue = 0;
int pwm;

void setup() {
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), pulse, RISING);
}

void loop() {
  measuredValue = measuredValue * 2; //0.5sec * 2 = value for 1 second
  measuredValue = constrain(measuredValue, 0, maxSpeed);
  int pwm = map(measuredValue, 0, maxSpeed, 0, 255);
  analogWrite(toRio, pwm);
  measuredValue = 0;              //reset value to 0 for new cycle 
  delay(measureTime);
}

void pulse() {
    ++measuredValue;
}
