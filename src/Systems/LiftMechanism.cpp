#include "LiftMechanism.h"
#include <Spark.h>

LiftMechanism::LiftMechanism(int LiftID, int IntakeID) {
    intake = new frc::Spark(IntakeID);
    lift = new frc::Spark(LiftID);
}

void LiftMechanism::Intake(double speed) {
    LiftMechanism::intake->Set(speed);
}

void LiftMechanism::Lift(double speed) {
    lift->Set(speed);
}

LiftMechanism::~LiftMechanism() {
    // TODO Auto-generated destructor stub
}

