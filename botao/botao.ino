/* Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */
int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);    // declare pushbutton as input
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    if (light == 0) {
      light = 1;
    } else {
      light = 0;
    } 
    delay(200);
  } 

  if (light == 1) {
    Serial.println("on");
  } else {
    Serial.println("off");
  }
}
