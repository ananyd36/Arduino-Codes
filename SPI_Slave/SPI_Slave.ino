#include <SPI.h>

char buf [100];
volatile byte pos;
volatile boolean process_it;

void setup (void)
{
  Serial.begin (19200);   // debugging
  SPCR |= bit (SPE);
  pinMode(MISO, OUTPUT);
  pos = 0;  
  process_it = false;
  SPI.attachInterrupt();

}  

ISR (SPI_STC_vect)
{
byte c = SPDR;  

  
  if (pos < sizeof buf)
    {
    buf [pos++] = c;

    
    if (c == '\n')
      process_it = true;

    } 
}  


void loop (void)
{
  int i, c;
  delay(5);
  if (process_it)
  { buf[pos]=0;
    Serial.println(buf);
    pos = 0;
    process_it = false;
  } 
}  
