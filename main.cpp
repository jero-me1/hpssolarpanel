#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;
int LDR1_pin = GPIO_NUM_4;
int LDR2_pin = GPIO_NUM_2;
int right_LDR = 0;
int left_LDR = 0;
int diff = 0;
int error = 0;
int servo_pos = 131;


void setup()
{
    myServo.attach(servoPin);
    Serial.begin(9600);
}

void loop()
{
    right_LDR = analogRead(LDR1_pin);  
    left_LDR = analogRead(LDR2_pin);
    Serial.println(analogRead(LDR1_pin));
    //Serial.println(analogRead(LDR2_pin));

    if (right_LDR < 400 && left_LDR < 400)
    {
        while (servo_pos <= 140 && servo_pos >= 15)
        {
            myServo.write(++servo_pos);
            delay(100);
        }
    }

    diff = left_LDR - right_LDR;
    if (diff > 10)
    {
        if (servo_pos <= 140)
        {
            myServo.write(++servo_pos);
        }
    }
    else if (diff < -10)
    {
        if (servo_pos >= 15)
        {
            myServo.write(servo_pos);
        }
    }
    /*if (Serial.available())
    {
        int angle = Serial.parseInt();
        myServo.write(angle);
    }
    delay(20);*/
    
}
