/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo[9];  // create servo object to control a servo

int randnum;
int pos = 0;

void setup() {
  for (int i=0;i<9;i++) {
    if(i==3) myservo[i].attach(4);
    else myservo[i].attach(5+i);  // attaches the servo on pin 5-13 to the servo object
    //myservo[i].write(35);
    for (pos = 30; pos <= 120; pos += 5) { // goes from 0 degrees to 180 degrees
      myservo[i].write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);
    }
    delay(500);  
    for (pos = 120; pos >= 30; pos -= 5) { // goes from 0 degrees to 180 degrees
      myservo[i].write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);
    }
    delay(100);
  }
}

void loop() {
  randnum = random(9);
  //if (randnum <5) randnum = 4; else randnum = 8;
  //randnum = 0;
  // sets the servo position according to the scaled value
  for (pos = 30; pos <= 120; pos += 5) { // goes from 0 degrees to 180 degrees
    myservo[randnum].write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);
  }
    delay(1500);  
  for (pos = 120; pos >= 30; pos -= 5) { // goes from 0 degrees to 180 degrees
    myservo[randnum].write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);
  }
    delay(1500);
}

