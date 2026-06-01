//{{1,0,1,0}, {0,1,1,0}, {0,1,0,1}, {1,0,0,1}}; THIS WORKS
//{{0,0,1,0}, {0,1,0,0}, {0,0,0,1}, {1,0,0,0}}; THIS WORKS
//Limiting factor was torque
int steps[4][4] = {{0,0,1,0}, {0,1,0,0}, {0,0,0,1}, {1,0,0,0}};
int current_step = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 4; i++){
        digitalWrite(i+2, steps[current_step][i]);
  }
  delay(20);
  Serial.println(current_step);
  current_step++;
  if(current_step >= 4){
    current_step = 0;
  }
}
