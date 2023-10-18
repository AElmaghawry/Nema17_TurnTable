#!/usr/bin/env python

import rospy
from std_srvs.srv import Empty, EmptyResponse

def rotate_motor_callback(req):
    # Implement your motor control logic here
    rospy.loginfo("Rotating motor 360 degrees")
    # Your motor control code goes here
    
    # Print a success message
    rospy.loginfo("Success: Motor rotation completed!")
    
    # Return an EmptyResponse object to indicate a successful service execution
    return EmptyResponse()

if __name__ == '__main__':
    rospy.init_node('stepper_motor_node')
    rospy.loginfo("Stepper motor node is ready to rotate!")
    service = rospy.Service('rotate_motor', Empty, rotate_motor_callback)
    rospy.spin()
