/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 10;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int incomingByte = 0;   // for incoming serial data
// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
   Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
         
       digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
                    delay(1000);  
                    digitalWrite(led, LOW);
                     delay(1000);   
} 

// the loop routine runs over and over again forever:
void loop()  { 
   if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                analogWrite(led, incomingByte);    
   }       
  fadeAmount=incomingByte;
  // set the brightness of pin 9:
  //analogWrite(led, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
 //if (brightness == 0 || brightness == 255) {
  //  fadeAmount = -fadeAmount ; 
 // }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

