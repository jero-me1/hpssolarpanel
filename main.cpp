#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;

void setup()
{
    myServo.attach(servoPin);
    //Serial.begin(9600);
    myServo.write(0);
}

void loop()
{
    /*
    if (Serial.available())
    {
        int angle = Serial.parseInt();
        myServo.write(angle);
    }
    delay(20);  
    */
}