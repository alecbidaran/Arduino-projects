#include <Arduino_FreeRTOS.h>
void TaskBlink( void *pvParameters );
void TaskSerial( void *pvParameters );
void setup() {
Serial.begin(9600);
TaskHandle_t Task_handle1;
TaskHandle_t Task_handle2;
xTaskCreate(Taskblink,"Taskblink",128,NULL,1,&Task_handle1);
xTaskCreate(TaskSerial,"TaskSerial",128,NULL,2,&Task_handle2);

}

void loop() {
  // put your main code here, to run repeatedly:
  

}
void Taskblink( void *pvParameters ){
  (void) pvParameters;
  pinMode(7,OUTPUT);
  for(;;){
    digitalWrite(7,HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(7,LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    
  }
}
void TaskSerial( void *pvParameters ){
  (void) pvParameters;
  Serial.println("hello from task2");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}
