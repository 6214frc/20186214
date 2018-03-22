#include <math.h>
#include <WPIlib.h>
#include <Spark.h>
#include <Systems/MyMecanumDrive.h>

void MyMecanumDrive::setWheels(int fl, int fr, int bl, int br) {
    FL = new frc::Spark(fl);
    FR = new frc::Spark(fr);
    BL = new frc::Spark(bl);
    BR = new frc::Spark(br);

}

void MyMecanumDrive::setPolarity(int flp, int frp, int blp, int brp) {
    FLP = flp;
    FRP = frp;
    BLP = blp;
    BRP = brp;
}

void MyMecanumDrive::drive(float x, float y, float z) {
    enum caseswitch {cx, cy, cz};
    int sw = 0;

    if(std::fabs(x) > std::fabs(y) && std::fabs(x) > std::fabs(z)) {
        sw = cx;
    } else if (std::fabs(y) > std::fabs(x) && std::fabs(y) > std::fabs(z)) {
        sw = cy;
    } else if (std::fabs(z) > std::fabs(y) && std::fabs(z) > std::fabs(x)) {
        sw = cz;
    }

    //Making sure that the speed is zero unless it is above a certain value
    if (std::fabs(x) < threshold) {
        x = 0;
    }
    if (std::fabs(y) < threshold) {
        y = 0;
    }
    if (std::fabs(z) < threshold) {
        z = 0;
    }


    //Each drive type is determined by the largest float
    switch(sw) {
    case cy:
        MyMecanumDrive::FL->Set(y * MyMecanumDrive::FLP);
        MyMecanumDrive::FR->Set(y * MyMecanumDrive::FRP);
        MyMecanumDrive::BL->Set(y * MyMecanumDrive::BLP);
        MyMecanumDrive::BR->Set(y * MyMecanumDrive::BRP);
        break;
    case cx:
        MyMecanumDrive::FL->Set(x * MyMecanumDrive::FLP);
        MyMecanumDrive::FR->Set(x * MyMecanumDrive::FRP * -1);
        MyMecanumDrive::BL->Set(x * MyMecanumDrive::BLP);
        MyMecanumDrive::BR->Set(x * MyMecanumDrive::BRP * -1);
        break;
    case cz:
        MyMecanumDrive::FL->Set(z * MyMecanumDrive::FLP);
        MyMecanumDrive::FR->Set(z * MyMecanumDrive::FRP);
        MyMecanumDrive::BL->Set(z * MyMecanumDrive::BLP * -1);
        MyMecanumDrive::BR->Set(z * MyMecanumDrive::BRP * -1);
        break;
    default:
        MyMecanumDrive::FL->Set(0);
        MyMecanumDrive::FR->Set(0);
        MyMecanumDrive::BL->Set(0);
        MyMecanumDrive::BR->Set(0);
    }
    Wait(0.005);
}
