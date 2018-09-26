
#include "Wire.h"
#include "I2Cdev.h"
#include "HMC5883L.h"

HMC5883L mag;

int16_t mx, my, mz, minX, minY, maxX, maxY, xOffset, yOffset;

#define LED_PIN 13
bool blinkState = false;

void setup() {
    
    Wire.begin();
    Serial.begin(9600);

    
    
    mag.initialize();
    Serial.println(mag.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");
    
}

void loop() 
{
  
  mag.getHeading(&mx, &my, &mz);
  if (mx < minX)
    minX = mx ;
  if (my < minY)
    minY=my ;
  if (mx > maxX)
    maxX=mx ;
  if (my > maxY)
    maxY=my ;
  xOffset = (maxX + minX) / 2 ;
  yOffset = (maxY + minY) / 2 ;
  mx-=xOffset;
  my-=yOffset;
    Serial.print("mag:\t");
    Serial.print(mx); Serial.print("\t");
    Serial.print(my); Serial.print("\t");
    Serial.print(mz); Serial.print("\t");
   
    double heading = atan2(my, mx);
    if(heading < 0)
      heading += 2*M_PI;
    
    heading*=(180/M_PI);
    
    heading=map(heading, 0, 360, 360, 0);
    heading-=90;
    if(heading<=0)
      heading+=360;
    Serial.print("heading:\t");
    Serial.println(heading);
}
