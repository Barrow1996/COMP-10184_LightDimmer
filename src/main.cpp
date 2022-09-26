/* I Shawn Barrow, 000332631 certify that this material is my original work and none
other person's work has been used without due acknowledgement. 2022-09-26 **/
#include <Arduino.h>
int readValue = 0;
int previousButton;
int ledValue = 0;
int buttonState = HIGH;
int ledState = LOW;
void setup() {
 // configure the USB serial monitor
 Serial.begin(115200);
 // configure pin D5 as digital input - this is the pushbutton
 pinMode(D5, INPUT_PULLUP);
 // configure pin D4 as a digital output - this is the LED
 pinMode(D4, OUTPUT);
  
}
void loop() {
  previousButton = digitalRead(D5);
  previousButton = buttonState;
  buttonState = digitalRead(D5);
  //Map the POT value to vary the brightness of the LED.
  readValue = analogRead(A0);
  ledValue = map(readValue,0,1023,255,0);

  //Control the LED  using button state
  if (previousButton == HIGH && buttonState == LOW) {
    if (ledState == LOW){
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }

  //Control initial state of LED
  if (ledState == HIGH){
  analogWrite(D4,ledValue);
  } else{
    digitalWrite(D4,HIGH);
  }
 
}