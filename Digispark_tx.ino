/*
 * I thought I would dummy up a simple RC controlled switch using
 * an Atmel ATTINY85 processor, but code it all in the Arduino 
 * environment.  The idea is to use pulseIn() to read the data signal
 * from the RC receiver, and threshold it, setting an output pin
 * if the pulse length is > 1500 ms, and clearing it if less.
 * Very simple.  It should be able to be powered directly from the 
 * receiver, and if we had some kind of FET we can switch large loads
 * (like a strip of LEDS). 
 */

int input1Pin = 2 ;  
int input2Pin = 4 ;
int output1Pin = 0 ;
int output2Pin = 1 ;
  
void
setup()
{
  pinMode(input1Pin, INPUT) ;
  pinMode(input2Pin, INPUT) ;
  pinMode(output1Pin, OUTPUT) ;
  pinMode(output2Pin, OUTPUT) ;
   
  // if we never get a pulse, we want to make sure the 
  // ourput stays switched off.
  digitalWrite(output1Pin, LOW) ;
  digitalWrite(output2Pin, LOW) ;
}
 
void
loop()
{
  digitalWrite(output1Pin,
    pulseIn(input1Pin, HIGH) > 1500 ? HIGH : LOW) ;  
  digitalWrite(output2Pin,
    pulseIn(input2Pin, HIGH) > 1500 ? HIGH : LOW) ;  
}
