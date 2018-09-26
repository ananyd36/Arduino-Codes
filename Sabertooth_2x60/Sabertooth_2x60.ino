//1-64-127
//128-192-255
void setup() {

Serial.begin(9600);
Serial1.begin(9600);
Serial1.write(192);
Serial1.write(64);

}

void loop() {
  
  if(Serial.available()){
    char inpt=Serial.read();
    switch(inpt){

      case 'w': Serial1.write(90);
                Serial1.write(200);break;
                
      case 's': Serial1.write(40);
                Serial1.write(170);break;
      
      case 'a': Serial1.write(40);
                Serial1.write(200);break;
                
      case 'd': Serial1.write(90);
                Serial1.write(180);break;
      
      case 'x': Serial1.write(64);
                Serial1.write(192);break;
    }
     
  }
}
