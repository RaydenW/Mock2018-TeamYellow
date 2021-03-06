/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/MoveArm.h"
#include "Commands/ManualMoveArm.h"
#include "Commands/DispenseBall.h"
#include "Commands/BallServoOpen.h"
#include "Commands/BallServoClose.h"
#include "COmmands/ManualMoveArmStop.h"


OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)), moveArmBut(new JoystickButton(rightJoy, 3)), 
manualMoveArmButDown(new JoystickButton(leftJoy, 4)), manualMoveArmButUp(new JoystickButton(leftJoy, 6)),
dispenseBallBut(new JoystickButton(rightJoy, 1)), manualDispenseBallBut(new JoystickButton(leftJoy, 7)){
  // Process operator interface input here.
  moveArmBut->WhenPressed(new MoveArm());
  dispenseBallBut->WhenPressed(new DispenseBall());
  manualDispenseBallBut->WhenPressed(new BallServoOpen());
  manualDispenseBallBut->WhenReleased(new BallServoClose());

  manualMoveArmButDown->WhenPressed(new ManualMoveArm(0));
  manualMoveArmButDown->WhenReleased(new ManualMoveArmStop());
  manualMoveArmButUp->WhenPressed(new ManualMoveArm(1));
  manualMoveArmButUp->WhenReleased(new ManualMoveArmStop());
}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}
