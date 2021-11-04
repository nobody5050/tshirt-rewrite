// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string> 

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include <frc/WPIlib.h>
//#include <frc/MedianFilter.h>

class Robot : public frc::TimedRobot {
 public:

 /*WPI_VictorSPX RightLead{1};
 WPI_VictorSPX LeftLead{3};
 WPI_VictorSPX RightFollow{2};
 WPI_VictorSPX LeftFollow{4};*/
 
 frc::VictorSP RightLead{2};
 frc::VictorSP LeftLead{3};
 frc::VictorSP RightFollow{0};
 frc::VictorSP LeftFollow{1};
 
 frc::SpeedControllerGroup Right{RightLead, RightFollow};
 frc::SpeedControllerGroup Left{LeftLead, LeftFollow};

 frc::DoubleSolenoid Tshirt{0, 1};

 frc::XboxController Xbox{0};

 frc::DifferentialDrive myRobot{Right, Left};

  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};

