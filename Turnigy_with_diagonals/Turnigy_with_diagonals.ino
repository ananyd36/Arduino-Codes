void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);  
}
//Channel 1 : min 1037 and Max 1877 right joysticks left and right motion
//Channel 2 : min 1023 and max 1857 
//Channel 3 : min 1027 and max 1862 right joystick frwd and rev motion 
//Channel 4 : min 1024 and max 1862 
void loop()
{                                                                 //pass parameters = m1 + m2
  unsigned long int ch1,ch3;
  ch1 = pulseIn(A0,HIGH); 
  ch3 = pulseIn(A1,HIGH);
  
  ch1=map(ch1,1037,1877,1,127);
  ch3=map(ch3,1027,1862,1,127);
 
  int ver=0,x;
  if(ch3>=57 && ch3<=72 && ch1>=57 && ch1<=72){
      leftM(64);
      rightM(192);
  }
  
  else {
        if(ch3<57 || ch3>72 && (ch1>57 && ch1<72)){                         //only verti input 
            leftM(ch3);
            rightM(127+ch3);
        }
        
        else if( (ch3<57 || ch3>72) && (ch1<57 || ch1>72) ){                //multi axis input
            ch1=calcV(ch1);
            leftM(ch3+ch1);
            rightM(128+ch3-ch1);
        }

        else if( ( ch1<57 || ch1>72) && (ch3>=57 && ch3<=72) ){             //only horz input
               leftM(ch1);
               rightM(255-ch1);
        }
        }
      Serial.println(" ");
 delay(100);
}
int calcV(int ch1)
{
  ch1= map(ch1,1,127,-63,63);
  return(ch1);
}
void leftM(int val)
{
  if(val>127)
    val=127;
  if(val<1)
    val=1;
  Serial.print(val);
}
void rightM(int val)
{
  if(val>255)
    val=255;
  if(val<127)
    val=127;
  Serial.print(" ");
  Serial.print(val);
}

