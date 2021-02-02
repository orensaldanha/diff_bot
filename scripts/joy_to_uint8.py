#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from std_msgs.msg import UInt8

def callback(data):
    global ui
    
    if data.axes[7] == 1: # full speed (d-pad up)
        ui.data = 255
        rospy.loginfo("Full Speed")
    elif data.axes[6] != 0: # medium speed (d-pad left or right)
        ui.data = 172
        rospy.loginfo("Medium Speed")
    elif data.axes[7] == -1: # low speed (d-pad down)
        ui.data = 86
        rospy.loginfo("Low Speed")
    else:
        return
    
    pub.publish(ui)


rospy.init_node('joy_to_uint8', anonymous=True)
rospy.Subscriber("joy", Joy, callback)
pub = rospy.Publisher('speed', UInt8, queue_size=10)

ui = UInt8()

# spin() simply keeps python from exiting until this node is stopped
rospy.spin()