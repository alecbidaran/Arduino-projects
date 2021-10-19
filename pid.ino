double kp=2;
double ke=5;
double kd=1;
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;

void setup() {
Serial.begin(9600);
pinMode(11, OUTPUT);
setPoint=40;

}

void loop() {
  input=analogRead(A0)*0.488;
  output=pid(input);
  delay(100);
  analogWrite(11,output);
  Serial.println("the pid value is\n");
  Serial.println(String(output)); 
}
double pid(double inp ){
  currentTime=millis();
  elapsedTime=(double)(currentTime-previousTime)*0.001;
  error=setPoint-inp;
  cumError+=error*elapsedTime;
  rateError=(error-lastError)/elapsedTime;
  double pid=kp*error+ke*cumError+kd*rateError;
  lastError=error;
  previousTime=currentTime;
  return pid;
}
