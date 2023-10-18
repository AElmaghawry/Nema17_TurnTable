#include <ros.h>
#include <std_srvs/Empty.h>
#include <AFMotor.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 200;
const float degreesPerStep = 360.0 / stepsPerRevolution;

// Calculate the number of steps for a 60-degree rotation
const int stepsFor60Degrees = int(60.0 / degreesPerStep);

// Create an instance of the Adafruit Motor Shield
AF_Stepper motor(stepsPerRevolution, 1);

ros::NodeHandle nh;

bool rotateCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res) {
  // Rotate 360 degrees in 60-degree increments
  for (int i = 0; i < 6; ++i) {
    motor.step(stepsFor60Degrees,FORWARD, SINGLE);
    delay(1000); // Wait for a second before the next rotation
  }
  nh.loginfo("Success: Motor rotation completed!");
  return true;
}

ros::ServiceServer<std_srvs::Empty::Request, std_srvs::Empty::Response> service("rotate_motor", &rotateCallback);

void setup() {
  motor.setSpeed(10); // Set the motor speed (RPM)
  
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertiseService(service);
}

void loop() {
  nh.spinOnce();
  delay(10);
}
