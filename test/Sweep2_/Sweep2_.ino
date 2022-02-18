/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);
  myservo2.attach(11);// attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(0);
  myservo2.write(180);
  delay(3000);
  
  myservo.write(180);
  myservo2.write(0);
  delay(3000);
  
  myservo.write(0);
  myservo2.write(0);
  delay(3000);
  
  myservo.write(180);
  myservo2.write(180);
  delay(3000);
}
