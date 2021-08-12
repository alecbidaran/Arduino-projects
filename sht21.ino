#include <Wire.h>
#define write_address 0x40 
#define tempreture_address 0xE3 
const uint16_t POLYNOMIAL = 0x131;
float humidity ;
float temp ;
uint16_t reading;
#define ERROR_TIMEOUT               999
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  reading=get_sensor_data(0XF3);
  reading &=~0x0003 ;
  temp=-46.85 + 175.72/65536 * (float)reading;
  if(temp!=-46.85){
  Serial.println(temp);
  delay(85);
  }
 
  }
uint16_t get_sensor_data(uint8_t command){
uint8_t checksum;
uint8_t data[2];
uint16_t result;
uint8_t counter=0 ;

     //Serial.println("the tempreture is reading");
    Wire.beginTransmission(0X40);
    Wire.write(command);
    Wire.endTransmission();
    delay(85);
    Wire.requestFrom(0X40,3);
    while(Wire.available() < 3) {
    counter++ ;
    delay(1);
    if(counter>100) return 999;
  }
      data[0]=Wire.read();
      data[1]=Wire.read();
      checksum=Wire.read();
      
      result=(data[0]<<8);
      result+=data[1];
      
      if(CRC_Checksum(data,2,checksum)){
        reset();
        return 1 ;
      }
      else return result ;
    
  }
uint8_t CRC_Checksum(uint8_t data[], uint8_t no_of_bytes, uint8_t checksum) {
  uint8_t crc = 0;  
    uint8_t byteCtr;

   //calculates 8-Bit checksum with given polynomial
    for (byteCtr = 0; byteCtr < no_of_bytes; ++byteCtr)
   { crc ^= (data[byteCtr]);
     for (uint8_t bit = 8; bit > 0; --bit)
     { if (crc & 0x80) crc = (crc << 1) ^ POLYNOMIAL;
       else crc = (crc << 1);
     }
   }
   if (crc != checksum) return 1;
   else return 0;
}
void reset(){
  Wire.beginTransmission(0X40);
    Wire.write(0XFE);
    Wire.endTransmission();
    delay(15);
}
  // put your main code here, to run repeatedly:
