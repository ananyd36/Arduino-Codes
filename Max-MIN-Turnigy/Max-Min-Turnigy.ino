int MAX=0,MIN=2000;
void setup()
{
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}
//Channel 1 : min 1037 and Max 1877 right joysticks left and right motion
//Channel 2 : min 1023 and max 1857 
//Channel 3 : min 1027 and max 1862 right joystick frwd and rev motion 
//Channel 4 : min 1024 and max 1862 
void loop()
{                                                                 //pass parameters = m1 + m2
  unsigned long int ch1,ch3;
  ch1 = pulseIn(A0,HIGH); 
  if(ch1>MAX)
    MAX=ch1;
  if(ch1<MIN)
    MIN=ch1;
//  ch3 = pulseIn(A1,HIGH);
  
// ch3=map(ch3,1027,1862,1,127);
// ch1=map(ch1,1037,1877,1,127);
 Serial.println(ch1);
 Serial.print("Max = ");
 Serial.print(MAX);
 Serial.print(" Min = ");
 Serial.println(MIN);
// Serial.print(ch3);
//  if(ch3>=55 && ch3<=75 && ch1>=55 && ch1<=75)
//        pass(64,192); //stop condition
//  else {
//        if(ch3<55 || ch3>75)
//          pass(ch3,127+ch3);  
//        if(ch1<55 || ch1>75)
//          pass(ch1,255-ch1);
//      }
// delay(100);
}
//
//void pass(int a,int b)
//{
//  Serial1.write(a);
//  Serial1.write(b);
//  Serial.print(a);
//  Serial.print(" ");
//  Serial.println(b); 
//}
