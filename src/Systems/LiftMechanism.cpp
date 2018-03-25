#include "LiftMechanism.h"
#include <Spark.h>

LiftMechanism::LiftMechanism(int LiftID, int IntakeID, int ClimbID) {
    intake = new frc::Spark(IntakeID);
    lift = new frc::Spark(LiftID);
    climb = new frc::Spark(ClimbID);
}

void LiftMechanism::Intake(double speed) {
    intake->Set(speed);
}

void LiftMechanism::Lift(double speed) {
    lift->Set(speed);
}

void LiftMechanism::Climb(double speed) {
    climb->Set(speed);
}


LiftMechanism::~LiftMechanism() {
    // TODO Auto-generated destructor stub
}

