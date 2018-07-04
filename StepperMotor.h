class StepperMotor
{
  public:
    StepperMotor(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
    void begin();
    void setDelay(int delayTime);
    void forward();
    void reverse();

  private:
    int _delayTime;
    int _motor_pin_1;
    int _motor_pin_2;
    int _motor_pin_3;
    int _motor_pin_4;
};


