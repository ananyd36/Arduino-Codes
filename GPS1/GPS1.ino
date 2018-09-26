int longt[10];
int i,start;
char ch,str[100];


void setup(){
  Serial1.begin(9600);
  Serial.begin(9600);
  start=0;
  i=0;
  }

void loop(){
  
  while( Serial1.available()>0 ){
    ch=Serial1.read();  
    
    if(ch=='$')
        start=1;
    if(start==1){
        str[i]=ch;
        i++;
    }
    if(i==3 && str[3]!='G'){
        break;
    }
    if(ch=='*'){
        start=-1;
        i=0;
       evaluate();    
    }
      
  }
  
}

void evaluate()    
{
    int hh,mm,ss,cnt=7,i=0;
    float latd=0,logt=0;

    if(str[3]=='G' && str[4]=='G') {       //gga type statement L7 TO L12 have time
        Serial.println("----------------UPDATING---------------");
        hh=(int(str[7])-48)*10 + (int(str[8])-48);
        mm=(int(str[9])-48)*10 + (int(str[10])-48);
        ss=(int(str[11])-48)*10 + (int(str[12])-48);

        i=17;             //latitude coords start at L16
        
        while(cnt>0){
          if(str[i]=='.')
            i++;
          latd+=(str[i]-48)*pow(10,cnt);
          cnt--;
          i++;
        }
        
        i=30;               //longitude coords start at L29
        cnt=8;
        while(cnt>0){
          if(str[i]=='.')     
            i++;
          logt+=(int(str[i])-48)*pow(10,cnt);
          cnt--;
          i++;
        }
          
     if(mm>=30){
        mm-=30;
        hh++;
     }
     else
        mm+=30;
     hh+=5;
     if(hh>=24)
         hh-=24;
     
     Serial.print("Time is: "); Serial.print(hh); Serial.print(" Hours\t");Serial.print(mm);Serial.print(" Minutes\t");Serial.print(ss);Serial.println(" Seconds");
     Serial.print("Latitude  : ");latd/=1000000;Serial.println(latd,7);

    Serial.print("Longitude : ");logt/=1000000;Serial.println(logt,7);

    }
}
