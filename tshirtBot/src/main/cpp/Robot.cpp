// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// First we include FIRST's libararies, they make the robot work.
#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h> 

// RobotInit is called when the robot is enabled in FIRST driver station. 
// Literally all it does is initialize the autos and show fhem in smart dashboard
void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

 
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  double deadzone = 0.2;
  double XboxX;
  double XboxY;
  double output;

if (IsOperatorControl() && IsEnabled()) {
  
  if(Xbox.GetX(frc::XboxController::JoystickHand(0)) > deadzone || Xbox.GetX(frc::XboxController::JoystickHand(0)) < -deadzone) {
    XboxX = Xbox.GetX(frc::XboxController::JoystickHand(0));
  } else {
    XboxX = 0.0;
  }
  if(Xbox.GetY(frc::XboxController::JoystickHand(0)) > deadzone || Xbox.GetY(frc::XboxController::JoystickHand(0)) < -deadzone) {
    XboxX = Xbox.GetY(frc::XboxController::JoystickHand(0));
  } else {
    XboxY = 0.0;
  }
  if(Xbox.GetBumper(frc::XboxController::JoystickHand(1))){
    myRobot.ArcadeDrive(XboxY, output, true);
  } else {
    myRobot.ArcadeDrive(XboxY, XboxX/1.33, true);
  }
  if(Xbox.GetAButton()){
    Tshirt.Set(frc::DoubleSolenoid::Value(2));
  }else {
    Tshirt.Set(frc::DoubleSolenoid::Value(1));
  }
}
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
