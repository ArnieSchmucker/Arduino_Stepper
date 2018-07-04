

#include "StepperMotor.h"

bool clockwise = true;
int delayTime;
volatile byte directionIndicator = 0;

StepperMotor stepper1(4,5,6,7);

void directionISR()
{
  directionIndicator = !directionIndicator;
}

void setup()
{
  stepper1.begin();
  attachInterrupt(0, directionISR, RISING);
}

void loop() {
  if (directionIndicator)
  { 
    clockwise = true;
  }
  else
  {
    clockwise = false;
  }
  
  int val = analogRead(A0);
  delayTime = map(val, 0,1023, 2, 40);
  stepper1.setDelay(delayTime);
  if (clockwise)
  {
    stepper1.forward();
  }
  else
  {
    stepper1.reverse();
  }
}



