#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

def callback(data):
    global t

    if data.buttons[3] == 1:
        #Forward
        t.linear.x  = 1
        t.angular.z = 0
        rospy.loginfo("Forward")
    elif data.buttons[0] == 1:
        #Backward
        t.linear.x  = -1
        t.angular.z = 0
        rospy.loginfo("Backward")
    elif data.buttons[1] == 1:
        #Right
        t.linear.x  = 0
        t.angular.z = 1
        rospy.loginfo("Right")
    elif data.buttons[2] == 1:
        #Left
        t.linear.x  = 0
        t.angular.z = -1
        rospy.loginfo("Left")
    elif data.buttons[4] == 1:
        #Pause
        t.linear.x  = 0
        t.angular.z = 0
        rospy.loginfo("Pause")
    else:
        return

    pub.publish(t)


rospy.init_node('joy_to_twist', anonymous=True)
rospy.Subscriber("joy", Joy, callback)
pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)

t = Twist()

# spin() simply keeps python from exiting until this node is stopped
rospy.spin()