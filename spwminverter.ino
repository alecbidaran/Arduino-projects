const int SpwmArry[] = {500,500,750,500,1250,500,2000,500,1250,500,750,500,500}; // Array of SPWM values.
const int SpwmArryValues = 13; //Put length of an Array depends on SpwmArray numbers. 
const int spwmpin1=9;
const int spwmpin2=8;
bool spwm1status=true;
bool spwm2status=true;


void setup() {
pinMode(spwmpin2,OUTPUT);
pinMode(spwmpin1,OUTPUT);

}

void loop() {
for(int i=0;i<13;i++){
  if(spwm1status){
    digitalWrite(spwmpin1,HIGH);
    delayMicroseconds(SpwmArry[i]);
    spwm1status=false;
  }
  else{
    digitalWrite(spwmpin1,LOW);
    delayMicroseconds(SpwmArry[i]);
    spwm1status=true;
  }
}
for(int i=0;i<13;i++){
  if(spwm2status){
    digitalWrite(spwmpin2,HIGH);
    delayMicroseconds(SpwmArry[i]);
    spwm2status=false;
  }
  else{
    digitalWrite(spwmpin2,LOW);
    delayMicroseconds(SpwmArry[i]);
    spwm2status=true;
  }
}
}
