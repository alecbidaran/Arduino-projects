
#include <avr/sleep.h>
#define sleep_pin 3
#define wakeup_pin 2
int speed=0,y=0;



void Sleep(){
  sleep_enable();
  attachInterrupt(0,wake_up,LOW);
  set_sleep_mode(SLEEP_MODE_IDLE);
  digitalWrite(4,LOW);
  digitalWrite(8,LOW);
  delay(1000);
  sleep_mode();
};
void wake_up(){
  sleep_disable();
  digitalWrite(4,HIGH);
  digitalWrite(8,HIGH);
  detachInterrupt(0);

};
void setup() {
pinMode(4,OUTPUT);
pinMode(sleep_pin,INPUT);
pinMode(8,OUTPUT);
digitalWrite(3,LOW);
}

void loop() {
int sleep_state=digitalRead(sleep_pin);
if (sleep_state==0){
  Sleep();
}
speed=analogRead(A0);
y=map(speed,0,255,255,0);
analogWrite(6,y);
}
