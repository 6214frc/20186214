#include <LiftMechanism.h>

LiftMechanism::LiftMechanism() {
	// TODO Auto-generated constructor stub

}

void LiftMechanism::SetIntake(int number) {
	intake = new frc::Spark(number);
}

void LiftMechanism::Intake(double speed) {
	LiftMechanism::intake->Set(speed);
}

void LiftMechanism::SetLift(int number) {
	lift = new frc::Spark(number);
}

void LiftMechanism::Lift(double speed) {
	lift->Set(speed);
}

LiftMechanism::~LiftMechanism() {
	// TODO Auto-generated destructor stub
	delete intake;
}

