#pragma once

#include <Spark.h>
class LiftMechanism {
public:


	frc::Spark *intake;
	frc::Spark *lift;

	void SetIntake(int number);
	void Intake(double speed);

	void SetLift(int number);
	void Lift(double speed);

	LiftMechanism();
	virtual ~LiftMechanism();
};
