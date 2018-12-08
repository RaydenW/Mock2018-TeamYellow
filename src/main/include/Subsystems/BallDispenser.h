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
  Servo* upperServo;
  Servo* lowerServo;

  bool isUpperOpen;
  bool isLowerOpen;

 public:
  BallDispenser();
  bool getUpperOpenStatus();
  void switchUpperOpenStatus();
  bool getLowerOpenStatus();
  void switchLowerOpenStatus();

  void setUpperPosition(double pos);
  void setLowerPosition(double pos);

  double getUpperPosition();
  double getLowerPosition();


  void InitDefaultCommand() override;
};