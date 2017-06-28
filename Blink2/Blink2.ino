/*
  Blink
 
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 The circuit:
 * LED connected from digital pin 13 to ground.
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 
 Created 1 June 2005
 By David Cuartielles
 
 http://arduino.cc/en/Tutorial/Blink
 
 based on an orginal by H. Barragan for the Wiring i/o board
 
 */

int ledPin =  13;    // LED connected to digital pin 13
int i;


// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);     
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()
   {
   digitalWrite(13, HIGH); delay(100);
   digitalWrite(12, HIGH); delay(100);
   digitalWrite(11, HIGH); delay(100);
   digitalWrite(10, HIGH); delay(100);
   digitalWrite(9, HIGH); delay(100);
   digitalWrite(8, HIGH); delay(100);
   digitalWrite(13, LOW); delay(100);
   digitalWrite(12, LOW); delay(100);
   digitalWrite(11, LOW); delay(100);
   digitalWrite(10, LOW); delay(100);
   digitalWrite(9, LOW); delay(100);
   digitalWrite(8, LOW); delay(100);
   
   

   }


/*
void loop()                     
{
 for(i=0;i<10;++i)
   {
       digitalWrite(ledPin, HIGH);   // set the LED on
  delay(500);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(500);                  // wait for a second
   }

 for(i=0;i<25;++i)
   {
       digitalWrite(ledPin, HIGH);   // set the LED on
  delay(100);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(100);                  // wait for a second
   }   
   
//  digitalWrite(ledPin, HIGH);   // set the LED on
//  delay(1000);                  // wait for a second
//  digitalWrite(ledPin, LOW);    // set the LED off
//  delay(1000);                  // wait for a second
}
*/