#include<Servo.h>
int mode=1;
Servo m1;
int i;

void setup() {
  m1.attach(1); //Pin Number
  m1.write(90);
  
}

void loop() {


 for(i=90;i<=180 && i>=0; )
 {
   if(mode==1)
      i++;
   else if(mode==0)
      i--;
   if(i==180)
        mode=0;
   if(i==0)
        mode=1;
   m1.write(i);        
 }

}
