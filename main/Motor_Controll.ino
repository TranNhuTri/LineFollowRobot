void ChangeSpeedMotor()
{
  if(HighSignalCount() == 0)
  {
  }
  else
  {
//    analogWrite(MotorInput[0], Motor[0]);
//    digitalWrite(MotorOutput[0], LOW);
//    analogWrite(MotorInput[1], Motor[1]);
//    digitalWrite(MotorOutput[1], LOW);
    ShiftSpeed(Motor);
  }
}
void leftToward()
{
  analogWrite(MotorInput[0], 100);
  digitalWrite(MotorOutput[0], 0);
}

void leftBackward()
{
  analogWrite(MotorInput[0], 150);
  digitalWrite(MotorOutput[0], 1);
}

void rightToward()
{
  analogWrite(MotorInput[1], 100);
  digitalWrite(MotorOutput[1], 0);
}

void rightBackward()
{
  analogWrite(MotorInput[1], 150);
  digitalWrite(MotorOutput[1], 1);
}

void toward()
{
  leftToward();
  rightToward();
}

void stopMotor()
{
  analogWrite(10, 200);
  digitalWrite(11, 1);
  analogWrite(9, 200);
  digitalWrite(8, 1);

  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
}
void ShiftSpeed(int *MotorSpeed) { //Shift the speed to the motors
  MotorMapping(MotorSpeed);
  for (int i = 0; i < 2; i++) {
    if (MotorSpeed[i] >= 0) {
      analogWrite(MotorInput[i], MotorSpeed[i]);
      digitalWrite(MotorOutput[i], LOW);
    } else {
      analogWrite(MotorInput[i], 200 + MotorSpeed[i]);
      digitalWrite(MotorOutput[i], 1);
    }
  }
}

void MotorMapping(int *MotorSpeed) {
  int TEMP_INITIAL_SPEED = 0;
  if (millis() - sys_start < 600) {
    TEMP_INITIAL_SPEED = (float)(INITIAL_SPEED * ((millis() - sys_start)) / 600);
  } else {
    TEMP_INITIAL_SPEED = INITIAL_SPEED;
  }
  int maxx = MotorSpeed[0];
  maxx = (maxx < MotorSpeed[1]) ? MotorSpeed[1] : maxx;
  if (maxx > TEMP_INITIAL_SPEED) {
    double ratio = (double) TEMP_INITIAL_SPEED / maxx;
    for (int i = 0; i < 2; i++) {
      MotorSpeed[i] *= ratio;
    }
  }
}
