//{{1,0,1,0}, {0,1,1,0}, {0,1,0,1}, {1,0,0,1}}; THIS WORKS
//{{0,0,1,0}, {0,1,0,0}, {0,0,0,1}, {1,0,0,0}}; THIS WORKS
//Limiting factor was torque
int steps[4][4] = {{0,0,1,0}, {0,1,0,0}, {0,0,0,1}, {1,0,0,0}};
int current_step = 0;
unsigned long prev_time = micros();
unsigned long prev_time_acc = micros();
unsigned long prev_time_pwm = micros();
float del = 80000;
int del_acc = 50;
int pwm_time_period = 1;
int pwm_cycles = del_acc / pwm_time_period;
bool accelerate = true;

void software_pwm(int pin, int duty_cycle){
  return;
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if((micros() - prev_time) >= del){
    for(int i = 0; i < 4; i++){
          digitalWrite(i+2, steps[current_step][i]);
    }
    current_step++;
    if(current_step >= 4){
      current_step = 0;
    }
    prev_time = micros();
  }

  if((micros() - prev_time_acc) >= del_acc){
    if(accelerate){
      del -= sq(del)*0.00000001+0.00001*del+0.1;
    }
    else{
      del += 1;
    }
    prev_time_acc = micros();

    if(del < 2000){
      del = 2000;
      accelerate = false;
    }
    if(del > 40000){
      del = 40000;
      accelerate = true;
    }
  }
}
