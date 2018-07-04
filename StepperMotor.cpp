#include <Arduino.h>
#include "StepperMotor.h"

StepperMotor::StepperMotor(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
    _motor_pin_1 = motor_pin_1;
    _motor_pin_2 = motor_pin_2;
    _motor_pin_3 = motor_pin_3;
    _motor_pin_4 = motor_pin_4;
}

void StepperMotor::begin()
{
  pinMode(_motor_pin_1, OUTPUT);
  pinMode(_motor_pin_2, OUTPUT);
  pinMode(_motor_pin_3, OUTPUT);
  pinMode(_motor_pin_4, OUTPUT);

  digitalWrite(_motor_pin_1, LOW);
  digitalWrite(_motor_pin_2, LOW);
  digitalWrite(_motor_pin_3, LOW);
  digitalWrite(_motor_pin_4, LOW);
}

void StepperMotor::setDelay(int delayTime)
{ 
  _delayTime = delayTime;
}

void StepperMotor::forward()
{ 
  for (int i= 0; i<4; i++) {
    switch (i)
    {
      case 0:
        digitalWrite(_motor_pin_1, HIGH);
        digitalWrite(_motor_pin_2, HIGH);
        digitalWrite(_motor_pin_3, LOW);
        digitalWrite(_motor_pin_4, LOW);
        break;
      case 1:
        digitalWrite(_motor_pin_1, LOW);
        digitalWrite(_motor_pin_2, HIGH);
        digitalWrite(_motor_pin_3, HIGH);
        digitalWrite(_motor_pin_4, LOW);
        break;
      case 2:
        digitalWrite(_motor_pin_1, LOW);
        digitalWrite(_motor_pin_2, LOW);
        digitalWrite(_motor_pin_3, HIGH);
        digitalWrite(_motor_pin_4, HIGH);
        break;
      case 3:
        digitalWrite(_motor_pin_1, HIGH);
        digitalWrite(_motor_pin_2, LOW);
        digitalWrite(_motor_pin_3, LOW);
        digitalWrite(_motor_pin_4, HIGH);
        break;
    }
    delay(_delayTime);
  }
}

void StepperMotor::reverse()
{
  for (int i=0; i<4; i++)
  {
    switch (i)
    {
      case 0:
        digitalWrite(_motor_pin_1, LOW);
        digitalWrite(_motor_pin_2, LOW);
        digitalWrite(_motor_pin_3, HIGH);
        digitalWrite(_motor_pin_4, HIGH);
        break;
      case 1:
        digitalWrite(_motor_pin_1, LOW);
        digitalWrite(_motor_pin_2, HIGH);
        digitalWrite(_motor_pin_3, HIGH);
        digitalWrite(_motor_pin_4, LOW);
        break;
      case 2:
        digitalWrite(_motor_pin_1, HIGH);
        digitalWrite(_motor_pin_2, HIGH);
        digitalWrite(_motor_pin_3, LOW);
        digitalWrite(_motor_pin_4, LOW);
        break;
      case 3:
        digitalWrite(_motor_pin_1, HIGH);
        digitalWrite(_motor_pin_2, LOW);
        digitalWrite(_motor_pin_3, LOW);
        digitalWrite(_motor_pin_4, HIGH);
        break;
    }
    delay(_delayTime);
  }
}
