// Duelling Tones - Simultaneous tone generation.
// To mix the output of the signals to output to a small speaker (i.e. 8 Ohms or higher),
// simply use 1K Ohm resistors from each output pin and tie them together at the speaker.
// Don't forget to connect the other side of the speaker to ground!

// This example plays notes 'a' through 'g' sent over the Serial Monitor.
// 's' stops the current playing tone.  Use uppercase letters for the second.

#include <Tone.h>

Tone freq1;

void setup(void)
{
  Serial.begin(9600);
  freq1.begin(11); 
}

void loop(void)
{
  
  freq1.play(100000);
  delay(1000);
  
}
