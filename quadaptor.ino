#include <Arduino.h>
#define Motor1 7 
#define Motor2 8 
#define Motor3 4 
#define Motor4 2
#define Max_speed 180
#define Low_speed 50 
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(Motor1,OUTPUT);
  pinMode(Motor2,OUTPUT);
  pinMode(Motor3,OUTPUT);
  pinMode(Motor4,OUTPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
   pinMode(1,INPUT);
}

void loop() {
  int f=digitalRead(12);
  int b=digitalRead(11);
  int l=digitalRead(10);
  int r=digitalRead(1);

  if (f==1){
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Max_speed);
    analogWrite(6,Max_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Low_speed);
    analogWrite(3,Low_speed);
    Serial.println("w");
    delay(50);
  }
  else if (b==1)
  {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Low_speed);
    analogWrite(6,Low_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Max_speed);
    analogWrite(3,Max_speed);
    delay(50);
  }
  else if (l==1)
  {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Max_speed);
    analogWrite(6,Low_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Max_speed);
    analogWrite(3,Low_speed);
    delay(50);
  }
  else if (r==1)
  {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Low_speed);
    analogWrite(6,Max_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Low_speed);
    analogWrite(3,Max_speed);
    delay(50);
  }
  else if ((b==1)&&(l==1))
  {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Low_speed);
    analogWrite(6,Low_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Low_speed);
    analogWrite(3,Low_speed);
    delay(50);
  }
  else if ((f==1)&&(r==1))
  {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
    analogWrite(9,Max_speed);
    analogWrite(6,Max_speed);
    digitalWrite(Motor3,HIGH);
    digitalWrite(Motor4,HIGH);
    analogWrite(5,Max_speed);
    analogWrite(3,Max_speed);
    delay(50);
  }
  
    
 else{
  digitalWrite(Motor1,LOW);
 digitalWrite(Motor2,LOW);
 digitalWrite(Motor3,LOW);
 digitalWrite(Motor4,LOW);
 }
  
  // put your main code here, to run repeatedly:
}
