int pingPin = 5;

void setup() {

  Serial.begin(9600);
}

void loop() {
 
  long duration;int cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(A0, INPUT);
  duration = pulseIn(A0, HIGH);
  cm=duration/27/2;
  
delay(50);

  Serial.print(cm);
  Serial.println();

}
