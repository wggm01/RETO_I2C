#include <AccelStepper.h>
#define HALFSTEP 8
 
// Motor pin definitions
#define motorPin1  8
#define motorPin2  9
#define motorPin3  10
#define motorPin4  11
 
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
 
void setup() {
  stepper1.setMaxSpeed(1000);
  //stepper1.setAcceleration(100.0);
  stepper1.setSpeed(800);
  stepper1.moveTo(10000);
 
}//--(end setup )---
 
void loop() {
 
  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
}
