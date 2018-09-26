int in;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);  
}

void loop() {
 
 if(Serial.available()){
    in=Serial.read();
    if(in==1)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
       
 }
}
