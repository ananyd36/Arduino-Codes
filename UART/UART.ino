int out=1,receive;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

void loop() {
   
   Serial.write(out);
  delay(1500);
  out=out*-1;
}
