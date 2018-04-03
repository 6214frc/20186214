/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**VARIABLES FOR MILLIE TO CHANGE**/
int INTAKE_ID1 = 4;
int CLIMB_ID = 5;

double INTAKE_SPEED_IN = .4;
double INTAKE_SPEED_OUT = -.8;

double LIFT_SPEED_UP = .7;
double LIFT_SPEED_DOWN = -.35;

double CLIMB_INTAKE_SPEED = 1;

double DEADZONE = .2;


#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Joystick.h>
#include <Timer.h>

#include "Systems/MyMecanumDrive.h"
#include "Systems/LiftMechanism.h"

class Robot : public frc::IterativeRobot {
private:

    frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
    MyMecanumDrive *drive;
    frc::Joystick *stick;
    LiftMechanism *lift;
    frc::Timer *time = new frc::Timer();


public:

    /**This is where you will set all your initial starting conditions.
     * Any mechanisms that are used during autonomous and user operated periods will be set here.
     * This is done once and will not happen again until the robot code is restarted.**/
    void RobotInit() override {
        //Setting the drive system variables.
        drive = new MyMecanumDrive;
        drive->threshold = DEADZONE;
        drive->setWheels(2,3,0,1);
        drive->setPolarity(-1, 1, 1, -1);

        //Setting the Lift system variables.
        lift = new LiftMechanism(9, INTAKE_ID1, CLIMB_ID);
        stick = new Joystick(0);
    }

    /**Disabled Init is called whenever the robot is disabled. If something should be killed
     * when the robot is disabled do it here. Usually you don't use this.**/
    void DisabledInit() override {
    }

    void DisabledPeriodic() override {
        //DO NOT PUT ANYTHING IN HERE THAT MOVES WHEN THE ROBOT IS DISABLED IT NEEDS TO BE STILL.
    }

    /**Autonomous is the first 10 seconds of the match in which you can score extra points
     *for crossing an autonomous line or scoring duing this period.**/
    void AutonomousInit() override {
        time->Reset();
        time->Start();
    }

    void AutonomousPeriodic() override {
        if (time->Get() <= 2.5) {
            drive->drive(0.0, -.75, 0.0);
        } else {
            drive->drive(0.0,0.0,0.0);
        }
    }

    /**Teleop is the period of time that we mortals control the robot. This is done through any sort of control mechanism we want.
     * The catch? You actually have to program stuff.**/
    void TeleopInit() override {

    }

    void TeleopPeriodic() override {
        
        drive->drive(stick->GetX(), stick->GetY(), stick->GetTwist());

        if (stick->GetRawButton(1) ) {
            lift->Intake(INTAKE_SPEED_IN);
        } else if (stick->GetRawButton(2) ) {
            lift->Intake(INTAKE_SPEED_OUT);
        } else {
            lift->Intake(0);
        }

        if (stick->GetPOV(0) == 0) {
            lift->Lift(LIFT_SPEED_UP);
        } else if (stick->GetPOV(0) == 180) {
            lift->Lift(LIFT_SPEED_DOWN);
        } else {
            lift->Lift(0);
        }
        if (stick->GetRawButton(6)) {
            lift->Climb(CLIMB_INTAKE_SPEED);
        } else { lift->Climb(0); }
    }

    /**Test is just an extra mode that you can use to test something without nessisairly
     *screwing with anything else.**/
    void TestInit() override {
    }

    void TestPeriodic() override {
        if (stick->GetRawButton(1) ) {
            lift->Intake(INTAKE_SPEED_IN);
        } else if (stick->GetRawButton(2) ) {
            lift->Intake(INTAKE_SPEED_OUT);
        } else {
            lift->Intake(0);
        }
    }

};

START_ROBOT_CLASS(Robot)


