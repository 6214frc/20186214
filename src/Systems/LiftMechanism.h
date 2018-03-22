#pragma once

#include <Spark.h>

class LiftMechanism {
public:


    frc::Spark *intake;
    frc::Spark *lift;

    void Intake(double speed);

    void Lift(double speed);

    LiftMechanism(int LiftID, int IntakeID);
    virtual ~LiftMechanism();
};
