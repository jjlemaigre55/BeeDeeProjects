/*  This program will read the digital signal of the
 *  Line Finder sensor attached to digital port D3.
 *  If the sensor is facing a reflective surface and 
 *  receiving a reflected IR beam, the PRIZM red LED
 *  will switch on. If the sensor is facing a dark 
 *  surface, or too far away from a reflective surface
 *  the red LED will be off. 
 */
  
  #include <PRIZM.h>    // include the PRIZM Library
  PRIZM prizm;          // create an object name of "prizm"
  
bool clawsClosed = false; // the code knows the claws aren't closed


void setup() {          // this code runs once

  prizm.PrizmBegin();   // initialize PRIZM
  prizm.setMotorInvert(2,1);  // invert one of the wheels to turn the same as the other
  
}

void loop() {           //this code repeats in a loop

 if(prizm.readSonicSensorCM(3) <= 3  && clawsClosed == false){  //if something is 3 or less cm away close GrabbyGrabbyClawThing
  prizm.setServoPosition(2,60);   // set the servo position to 60 degrees
  delay(1000);          // close the claws for 1 second
  clawsClosed = true;   // servo stops because the claws are closed
                               
  }
 
  if(prizm.readLineSensor(2) == 0)  // if the line sensor doesnt read black then turn left
  {
  prizm.setMotorPowers(10,20);      // turn left
  prizm.setRedLED(HIGH);            // turn red LED on 
  }  

  if(prizm.readLineSensor(2) == 1) // if the line sensor reads black turn right
  {
  prizm.setMotorPowers(20,10);  // turn right
  prizm.setRedLED(LOW);         // turn red LED off
  }
  delay(10);  // stop for a hot sec

}
