/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ManualMoveArm.h"
#include "robot.h"

ManualMoveArm::ManualMoveArm(int upOrDown) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_arm);
  direction = upOrDown;
}

// Called just before this Command runs the first time
void ManualMoveArm::Initialize() {
  Robot::m_arm->switchStoppedStatus();
}

// Called repeatedly when this Command is scheduled to run
void ManualMoveArm::Execute() {
  if(direction == 1)
    Robot::m_arm->moveArm(-0.1);
  else{
    Robot::m_arm->moveArm(0.1);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ManualMoveArm::IsFinished() {
  if(Robot::m_arm->getStoppedStatus()){
    return true;
  }
  else{
    return false;
  }
}

// Called once after isFinished returns true
void ManualMoveArm::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualMoveArm::Interrupted() {}
