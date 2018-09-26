const int L1 = 2;
const int L2 = 4;
const int R1 = 8;
const int R2 = 7;

const int ctrl = 5;
const int ctrl2= 6;

int pace=100;

void setup() {
//  Serial.begin(9600);
    pinMode(L1,OUTPUT);
    pinMode(L2,OUTPUT);
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(ctrl,OUTPUT);
    pinMode(ctrl2,OUTPUT);
    //digitalWrite(i,LOW);
 
  //analogWrite(ctrl,pace);
 // analogWrite(ctrl2,pace);
 
}

void loop() {
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  analogWrite(ctrl,pace);
  analogWrite(ctrl2,pace);
  delay(1000);
  
//  if(Serial.available()>0){
//    int val = Serial.read();
//      if(val=='w')
//          updateValue(1,0,1,0);
//
//      else if(val=='d')
//          updateValue(1,0,0,1);
//            
//      else if(val=='a')
//          updateValue(0,1,1,0);
//            
//      else if(val=='s')
//          updateValue(0,1,0,1);
//      else if(val=='x')
//          updateValue(0,0,0,0);
//  
//  }
//updateValue(1,0,1,0);
}

void updateValue(int a, int b, int c, int d)
{
  digitalWrite(L1,a);digitalWrite(L2,b);
  digitalWrite(R1,c);digitalWrite(R2,d);
}

