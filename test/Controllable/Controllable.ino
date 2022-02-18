#include <Servo.h>
Servo myservo;
Servo myservo2;
int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  Serial.begin(9600); 
  myservo.attach(10); //attaches the servo on pin 9 
  
  myservo2.attach(11);

}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 0, 180);
  mapY = map(yPosition, 0, 1023, 0, 180);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  myservo.write(mapX);
  myservo2.write(mapY);
}
