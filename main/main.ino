#define Sensor_HIGH  300 //High level for optical sensor

int INITIAL_SPEED = 120; // <=255

const int MotorInput[2] = {10, 9};
const int MotorOutput[2] = {11, 8};

const int Sensors[10] = {A0, A1, A2, A3, A4, A5, A7, A8, A9, A10};

long long int sys_start = 0;

int Motor[2] = {0};
bool Line[10] = {false};

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(MotorInput[i], OUTPUT);
    pinMode(MotorOutput[i], OUTPUT);
  }

  for (int i = 0; i < 10; i++) {
    pinMode(Sensors[i], INPUT);
  }
  Serial.begin(9600);
  Serial.println("System started");
}

void loop() {
  GetSensorStatus();
  LinePIDFilter();
  ShiftSpeed(Motor);
}
