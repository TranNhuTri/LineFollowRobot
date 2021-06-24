void LinePIDFilter() { //PID control in line tracking mode
  static double kP = 15, kI = 0.000001, kD = 20;
  static double previous_error = 0, prev_I = 0;
  double p = 0, i = 0, d = 0, pid_value;

  p = GetError();
  i = p + prev_I;
  d = p - previous_error;

  pid_value = kP * p + kI * i + kD * d;
  prev_I = i;
  previous_error = p;
  Motor[0] = INITIAL_SPEED - pid_value;
  Motor[1] = INITIAL_SPEED + pid_value;
}
