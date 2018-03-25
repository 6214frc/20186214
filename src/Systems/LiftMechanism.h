#pragma once

#include <Spark.h>

class LiftMechanism {
public:


    frc::Spark *intake;
    frc::Spark *lift;
    frc::Spark *climb;

    void Intake(double speed);

    void Lift(double speed);
    
    void Climb(double speed);

    LiftMechanism(int LiftID, int IntakeID, int ClimbID);
    virtual ~LiftMechanism();
};
