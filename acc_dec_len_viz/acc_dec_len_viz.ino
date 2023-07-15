#define left_motor_dir 12
#define left_motor_pwm 11
#define right_motor_dir 10 
#define right_motor_pwm 9 

long long t_count = 0;
class _Motor{
  public:
    int pwm_pin, dir_pin, _pwm, _dir;
  _Motor(int _dir_pin, int _pwm_pin){
    pwm_pin = _pwm_pin;
    dir_pin = _dir_pin;
    pinMode(dir_pin, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
  }
  void run(long _cmd){
    _dir = (_cmd>=0) ? 1:0;
    _pwm = abs(_cmd);
    digitalWrite(dir_pin, _dir);
    if(_dir==1) {
      _pwm = abs(255-_pwm%256);
      analogWrite(pwm_pin, _pwm);
    }
    else analogWrite(pwm_pin, _pwm);
  }
};
_Motor left_motor(left_motor_dir, left_motor_pwm), right_motor(right_motor_dir, right_motor_pwm);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left_motor.run(0);
  right_motor.run(0);
  delay(5000);
  for(int i = 0; i<256; i++){
    left_motor.run(i);
    right_motor.run(i);
    delay(10);
  }
  for(int i = 254; i>0; i--){
    left_motor.run(i);
    right_motor.run(i);
    delay(10);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}


// result: 20cm average distance travelled.