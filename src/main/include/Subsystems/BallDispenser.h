/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>

#include "WPILib.h"

class BallDispenser : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  Servo* servo;

  bool isOpen;

 public:
  BallDispenser();
  bool getOpenStatus();
  void switchOpenStatus();

  void setPosition(double pos);

  double getPosition();


  void InitDefaultCommand();

  /*------------
  Unused Commands: DispenseBall, MoveDispenserServo
  Unused Methods: getPosition
  -------------*/
};
