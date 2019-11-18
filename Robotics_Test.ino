#include <PRIZM.h>

PRIZM prizm;

void setup() {
 prizm.PrizmBegin();  
 prizm.setMotorInvert(2,1);  //the motors will go in opposite directions to move forward
 prizm.setServoSpeed(1,25);  //set servo speed 25%
           //the code doesn't loop
}

void loop() {

//stop when something is in the way
    if (prizm.readSonicSensorCM(3) >=10 ){
    RobotOffRoad();
    } else {
    prizm.setMotorPowers (0,0);
    }


}
 void RobotOffRoad(){ 
//red light blinks to signal turn
  prizm.setRedLED(HIGH);
  delay(500);
  prizm.setRedLED(LOW);
  delay(500);

  prizm.setRedLED(HIGH);
  delay(500);
  prizm.setRedLED(LOW);
  delay(500);

//move forward for 1 seconds
  prizm.setMotorPowers(25,25);   //turns motor 1 and 2 on at 25% power
  delay(500);                    //wait for .5 seconds while motors are spinning
  
//make the servo go up to signal turning
  prizm.setServoPosition(1,90);  //rotate to 90 degrees
  delay(1000);                   //wait for 1 second

//drive forward
  prizm.setMotorPowers(35,35);   //turns motor 1 and 2 up to 35%
  delay(200);                    //wait for 1.5

//turn right
  prizm.setMotorPowers(10,25);   //motor 1 spins at 10% power, motor 2 spins at 25% power
  delay(1700);                   //wait for 1.7 seconds while motors are spinning

//move forwards for a hot sec
  prizm.setMotorPowers(15,15);   //move at 15% power
  delay(300);                    //wait for .3 seconds while motors are spinning

//turning to the left
  prizm.setMotorPowers(25,10);   //motor 1 spins at 25% power, motor 2 spins at 10% power
  delay(1500);                   //wait for 1.5 seconds while motors are spinning

//move forward slowly to a stop
  prizm.setMotorPowers(25,25);   //motor 1 and 2 slow down to 25% power
  delay(700);                    //wait for .7 seconds while motors spin


//stops the robot completely  
  prizm.setMotorPowers(0,0);     //make a complete stop
  delay(800);                    //wait .8 seconds until next code

//make servo return to the normal poition
 prizm.setServoPosition(1,-90);  //rotate to -90 degrees
  delay(1000);

//stop the code from looping
 prizm.PrizmEnd();               //code stops
 }


  
