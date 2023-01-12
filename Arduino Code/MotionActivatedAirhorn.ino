#include <Servo.h>
int motionPin = 3;
int value = 0;
int pirState = LOW;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(motionPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
//  value = digitalRead(motionPin);
//  if (value == HIGH) {
//    myservo.write(30);              
//    delay(1000);
//    myservo.write(100);
//    delay(1000);
//    if (pirState == LOW) {
//      Serial.println("Motion Detected!");
//      pirState = HIGH;
//    }
//  }else{
//    
//    if(pirState == HIGH){
//      Serial.println("Motion Ended!");
//      pirState = LOW;
//      }
//    }

for (int i = 0; i < 10; i++)
{
  value = digitalRead(motionPin);
  if (value == HIGH)
  {
    Serial.println("High Detected");
  }
  else
  {
    Serial.println("Low Detected");
  }
  delay(1000);
}
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.print("position is: ");
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Serial.print("position is: ");
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

/*
 * int led = 13;
int pin = 2;

int value = 0;
int pirState = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  }else{
    digitalWrite(led, LOW);

    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
      }
    }
}
 */
