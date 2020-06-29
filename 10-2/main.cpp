#ifndef RR8cube_H
#define RR8cube_H
#include "vex.h"
#include "automove.h"
#include "move.h"

int PR8M = 0;

int PushmoveR8() {
    //release the tray:

    //place cubes:
    RotateMotor.resetRotation();
    while (true) {
        if (PR8M == 1) {
            RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
            if(fabs(RotateMotor.rotation(vex::rotationUnits::deg)) < 200) {
                RotateMotor.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
            } else if(fabs(RotateMotor.rotation(vex::rotationUnits::deg)) >= 200 && fabs(RotateMotor.rotation(vex::rotationUnits::deg)) < 600) {
                RotateMotor.spin(vex::directionType::fwd,60,vex::percentUnits::pct);
            } else if(fabs(RotateMotor.rotation(vex::rotationUnits::deg)) >= 600 && fabs(RotateMotor.rotation(vex::rotationUnits::deg)) < 900) {
                RotateMotor.spin(vex::directionType::fwd,60,vex::percentUnits::pct);
            } else if(fabs(RotateMotor.rotation(vex::rotationUnits::deg)) >= 900 && fabs(RotateMotor.rotation(vex::rotationUnits::deg)) < 1500) {
                RotateMotor.spin(vex::directionType::fwd,20,vex::percentUnits::pct);
            } else {
                RotateMotor.spin(vex::directionType::fwd,5,vex::percentUnits::pct);
            }
        }
    }
}

void RReightcube(){
    double time;
    /*RotateMotor.stop();
    RotateMotor.setStopping(brakeType ::coast);
    automove(400,400,300,10000);
    automove(-350,-350,400,5000);
    //将方块顶到前面
    LiftMotor.setMaxTorque(0.2,vex::currentUnits::amp);
    LiftMotor.spin(vex::directionType::fwd,20,vex::percentUnits::pct);
    LeftRollerMotor.setMaxTorque(2.4,currentUnits::amp);
    RightRollerMotor.setMaxTorque(2.4,currentUnits::amp);
    LeftRollerMotor.spin(vex::directionType::rev,-100,vex::percentUnits::pct);
    RightRollerMotor.spin(vex::directionType::fwd,-100,vex::percentUnits::pct);
    //往后顶墙壁

    vex::task::sleep(100);
    RotateMotor.stop();
    RotateMotor.setStopping(brakeType ::coast);
    RotateMotor.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
    vex::task::sleep(280);*/
    RotateMotor.spin(vex::directionType::rev,50,vex::percentUnits::pct);
    LeftRollerMotor.spin(vex::directionType::rev,100,vex::percentUnits::pct);
    RightRollerMotor.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
    LiftMotor.setMaxTorque(1.0,vex::currentUnits::amp);
    LiftMotor.startRotateFor(10,vex::rotationUnits::deg,5,vex::velocityUnits::pct);
    automove(1100,1100,3000,6000);

    RotateMotor.setStopping(brakeType ::coast);
    LiftMotor.setMaxTorque(0.2,vex::currentUnits::amp);
    LiftMotor.spin(vex::directionType::fwd,20,vex::percentUnits::pct);
    stopbot();
    vex::task::sleep(50);
    automove(-400,-400,400,10000);
    task::sleep(50);
    gyroturn(-25,6000,1000);
    vex::task::sleep(50);
    automove(-800,-800,800,10000);
    vex::task::sleep(50);
    gyroturn(25,6000,1000);

    time = Brain.timer(vex::timeUnits::msec);
    while (Brain.timer(vex::timeUnits::msec) - time < 400){
        mmove(-12000,-12000);
    }
    stopbot();
    vex::task::sleep(50);
    LeftRollerMotor.spin(vex::directionType::rev,-50,vex::percentUnits::pct);
    RightRollerMotor.spin(vex::directionType::fwd,-50,vex::percentUnits::pct);
    automove(400,400,400,11000);

    LeftRollerMotor.spin(vex::directionType::rev,100,vex::percentUnits::pct);
    RightRollerMotor.spin(vex::directionType::fwd,100,vex::percentUnits::pct);
    automove(1150,1150,3000,5000);
    stopbot();
    task::sleep(200);
    automove(-750,-750,550,11000);
    RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
    LeftRollerMotor.spin(vex::directionType::rev,-60,vex::percentUnits::pct);
    RightRollerMotor.spin(vex::directionType::fwd,-60,vex::percentUnits::pct);
    automove(-350,-350,550,11000);
    RotateMotor.resetRotation();
    RotateMotor.startRotateFor(1100,vex::rotationUnits::deg,30+0.022*(1400-RotateMotor.rotation(vex::rotationUnits::deg)),vex::velocityUnits::pct);
    LeftRollerMotor.stop(vex::brakeType::hold);
    RightRollerMotor.stop(vex::brakeType::hold);
    vex::task::sleep(50);
    gyroturn(120,6000,3500);
    vex::task::sleep(50000);
    automove(600,600,1500,4500);

    LeftRollerMotor.stop(vex::brakeType::coast);
    RightRollerMotor.stop(vex::brakeType::coast);
    time = Brain.timer(vex::timeUnits::msec);
    while (Brain.timer(vex::timeUnits::msec) - time < 500){
        RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
        RotateMotor.spin(vex::directionType::fwd,30,vex::percentUnits::pct);
        LeftMotor1.spin(vex::directionType::fwd,-1,vex::velocityUnits::pct);
        LeftMotor2.spin(vex::directionType::fwd,-1,vex::velocityUnits::pct);
        RightMotor1.spin(vex::directionType::fwd,-1,vex::velocityUnits::pct);
        RightMotor2.spin(vex::directionType::fwd,-1,vex::velocityUnits::pct);
    }
    time = Brain.timer(vex::timeUnits::msec);
    while (Brain.timer(vex::timeUnits::msec) - time < 700){
        RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
        RotateMotor.spin(vex::directionType::fwd,30,vex::percentUnits::pct);
        LeftMotor1.spin(vex::directionType::fwd,4,vex::velocityUnits::pct);
        LeftMotor2.spin(vex::directionType::fwd,4,vex::velocityUnits::pct);
        RightMotor1.spin(vex::directionType::fwd,4,vex::velocityUnits::pct);
        RightMotor2.spin(vex::directionType::fwd,4,vex::velocityUnits::pct);
    }
    /*while (Brain.timer(vex::timeUnits::msec) - time < 200){
      RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
      RotateMotor.spin(vex::directionType::fwd,35,vex::percentUnits::pct);
      LeftMotor1.stop(vex::brakeType::hold);
      LeftMotor2.stop(vex::brakeType::hold);
      RightMotor1.stop(vex::brakeType::hold);
      RightMotor2.stop(vex::brakeType::hold);
    } */
    RotateMotor.setMaxTorque(0.2,vex::currentUnits::amp);
    RotateMotor.stop();
    RotateMotor.setStopping(brakeType ::hold);
    time = Brain.timer(vex::timeUnits::msec);
    while (Brain.timer(vex::timeUnits::msec) - time < 600){
        RotateMotor.setMaxTorque(2.4,vex::currentUnits::amp);
        RotateMotor.spin(vex::directionType::fwd,20,vex::percentUnits::pct);
        mmove(-4000,-4000);
    }
    autostop(1,50);
    RotateMotor.spin(vex::directionType::rev,100,vex::percentUnits::pct);
}

#endif