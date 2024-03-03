#include <Stepper.h>

const int pingPin = 2;
const int motorPin = 13;
void setup() {

  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  
  int duration, cm;


  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);


  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);


  cm = microsecondsToCentimeters(duration);


  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm < 329) {
    digitalWrite(motorPin, HIGH);
    delay(4000); 
  }
  else {
    digitalWrite(motorPin, HIGH);
  }
  digitalWrite(motorPin, LOW);
  delay(1000); 
}

long microsecondsToCentimeters(long microseconds) {

  return microseconds / 29 / 2;
}
