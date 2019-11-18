#include <TELEOP.h>       // TETRIX TeleOp module Library
#include <PRIZM.h>        // TETRIX PRIZM Library

PRIZM prizm;              // Create an instance within the PRIZM library class named prizm
PS4 ps4;                  // Create an instance within the PS4 lirary class named ps4

int PowerM1;              // Channel 1 Motor Power
int PowerM2;              // Channel 2 Motor Power

void setup() {
  prizm.PrizmBegin();                 // Invert right motor-- to allow for inversion of value sent to DC Motor
  prizm.setMotorInvert(2,1);

  ps4.setDeadZone(LEFT, 5);           // Sets a Left Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position 
  ps4.setDeadZone(RIGHT,5);           // Sets a Right Joystick Dead Zone axis range of +/- 5 about center stick. This eliminates servo jitter when joysticks are at center (neutral) position

}

  void loop(){  
 Rumble();                            // Start the Rumble function          
 
 MoveMotor();                         // Start the MoveMotor function            
  
 if (ps4.Button(R2) == true){         // If the controller button R2 is pushed then close the servo arms
 
    CloseServoArms();
  }
 if (ps4.Button(L2) == true){         // If the controller button L2 is pushed then open the servo arms
     OpenServoArms();
  }
       if (ps4.Button(R1) == true){   // If the controller button R1 is pushed wave the servo arm up
    Wave1();
  }
 if (ps4.Button(L1) == true){         // If the controller button L1 is pushed wave the servo arm down
     Wave2();
  }
}

void Rumble(){                                     // Start Rumble funtion
 if (prizm.readSonicSensorCM(3) < 5 ) {            // If the sonic sensor sees something 5 cm or closer rumble slow
    ps4.setRumble (SLOW);                       
  } else if (prizm.readSonicSensorCM(3) < 14 ) {   // Else if the sonic sensor sees something 14 cm or closer up to 5 cm rumble fast
    ps4.setRumble(FAST);                           
  } else {                                         // Else stop the code
    ps4.setRumble(STOP);                           
  }
}

void MoveMotor(){                               //Start MoveMotor function
    
    ps4.getPS4();                               // Get (read) PS4 connections status and all PS4 button and joystick data values

  if(ps4.Connected){                            // If PS4 controller has been succesfully connected, control motors
      PowerM1 = ps4.Motor(RY);                  // Power (speed) and direction of Motor 1 is set by position of Left Y-axis Joystick
      PowerM2 = ps4.Motor(LY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      prizm.setMotorPowers(PowerM1, PowerM2);   // set motor output power levels for PRIZM DC motor channels 1 and 2

      Serial.println(PowerM1);
  }
  else{                                         // If PS4 is not connected, stop motors
      prizm.setMotorPowers(0,0);
  }

  
}
  void CloseServoArms(){                       // Start the CloseServoArms function
  prizm.setServoPosition(2,55);                // Set the servo 2 position to 60 degrees
                                  
}
  void OpenServoArms(){                       // Start the OpenServoArms function
    prizm.setServoPosition(2,90);             // Set the servo 2 position to 90 degrees
  }
 void Wave1(){                                // Start the Wave1 function
   prizm.setServoPosition(1,180);             // Set the servo 1 positon to 180 degrees
 }
  void Wave2(){                               // Start the Wave2 function
     prizm.setServoPosition(1,0);             // Set the servo 1 position to 0 degrees
  }
















  
