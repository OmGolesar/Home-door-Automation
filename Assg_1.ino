// C++ code
//

#include <Servo.h>
Servo myservo; // create servo object to control a servo
const int trigPin = 4;
const int echoPin = 2;

void setup()
{
  Serial.begin(9600); // initialize serial communication
  myservo.attach(9);  //attaches the servo on pin 9 to the servo object
}

void loop()
{
  long duration, cm;
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);  //read echo
  
  cm = microsecondsToCentimeters(duration); // convert time into a distance
  if ( cm < 40 )
  {
  digitalWrite(13, HIGH);
    myservo.write(90); // sets the final servo position
    delay(10);
  }
  else
  {
    digitalWrite(13, LOW);
    myservo.write(0); //sets the initial servo position
    delay(10);
  }
  Serial.print(cm); //print distance on serial window
  Serial.print("cm");
  Serial.println();
  delay(50);
  
  
}
long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
return microseconds / 29 / 2;
}
