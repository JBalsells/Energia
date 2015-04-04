#include <Wire.h>

#define MPU6050 0B1101000 
#define A_R 0b11111111111111

int16_t Ax,Ay,Az,Gx,Gy,Gz,Tm;

void setup()
{  
  Wire.begin();
  Wire.beginTransmission(MPU6050);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  
  Serial.begin(115200);  
}

void loop()
{
  Wire.beginTransmission(MPU6050);
  Wire.write(0B111011);
  Wire.endTransmission(false); 
  
  Wire.requestFrom(MPU6050,14,true);
  
  Ax=Wire.read()<<8|Wire.read();
  Ay=Wire.read()<<8|Wire.read();
  Az=Wire.read()<<8|Wire.read();
  Tm=Wire.read()<<8|Wire.read();
  Gx=Wire.read()<<8|Wire.read();
  Gy=Wire.read()<<8|Wire.read();
  Gz=Wire.read()<<8|Wire.read();

  Serial.println("Ax:"+String(Ax)+"Ay:"+String(Ay)+"Az:"+String(Az)+"Gx:"+String(Gx)+"Gy:"+String(Gy)+"Gz:"+String(Gz)+"Tm:"+String(Tm));
  
   delay(10);
}
