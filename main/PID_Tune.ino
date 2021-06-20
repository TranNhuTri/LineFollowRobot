void LinePIDFilter() { //PID control in line tracking mode
  static double kP = 30, kI = 0.00001, kD = 35;
  static double previous_error = 0, prev_I = 0;
  double p = 0, i = 0, d = 0, pid_value;

  p = GetError();
  i = p + prev_I;
  d = p - previous_error;

  pid_value = kP * p + kI * i + kD * d;
  prev_I = i;
  previous_error = p;
  Motor[0] = constrain(INITIAL_SPEED - pid_value, 0, 255);
  Motor[1] = constrain(INITIAL_SPEED + pid_value, 0, 255);
}
