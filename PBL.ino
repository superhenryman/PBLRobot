#include <Simplify.h>

const int green_pin = 2;
const int yellow_pin = 3;
const int red_pin = 4;
const int trig_pin = 6;
const int echo_pin = 7;
Simplify sensor(trig_pin, echo_pin);
/*
Default time is 5 seconds, 3 seconds green, 2 seconds yellow, then it becomes red for 5 seconds. 
After every motion detection, the time increases by 10. So it becomes green for 8 seconds yellow for 2 and red for 10.
MAKE SURE THAT SENSOR IS TAPED AT THE BOTTOM, AND THAT LEDS ARE ON BREADBOARD!

*/

const int init_delay_time = 5 * 1000;
bool is_default = true;
int currentdel = 1000;
void setup() {
  pinMode(green_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void act(int time) {
  digitalWrite(green_pin, HIGH);
  delay(3 * time);
  digitalWrite(green_pin, LOW);

  digitalWrite(yellow_pin, HIGH);
  delay(2 * time);
  digitalWrite(yellow_pin, LOW);

  digitalWrite(red_pin, HIGH);
  delay(5 * time);
  digitalWrite(red_pin, LOW);
}

void loop() {
  long distance = sensor.GetDistance();
  if (distance < 10) {
    // "wee" -- mohammed 22/3/2025
    act(currentdel);
    currentdel+=1000;
  } else if (distance >= 20) {
    act(currentdel);
    currentdel+=2000;
  } else if (distance >= 30) {
    act(currentdel);
    currentdel+=3000;
  }
}