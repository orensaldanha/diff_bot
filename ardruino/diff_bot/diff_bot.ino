#include <ros.h>
#include <geometry_msgs/Twist.h>

//motora
int in1 = 4;
int in2 = 5;
//motorb
int in3 = 7;
int in4 = 8;

void forward();
void backward();
void right();
void left();
void pause();

ros::NodeHandle  nh;

void messageCb( const geometry_msgs::Twist& twist_msg){
  if (twist_msg.linear.x == 1)
  {
    forward();
    nh.loginfo("Going Forward!");
  }
  else if (twist_msg.linear.x == -1)
  {
    backward();
    nh.loginfo("Going Backward!");
  }
  else if (twist_msg.angular.z == 1)
  {
    right();
    nh.loginfo("Turning Right!");
  }
  else if (twist_msg.angular.z == -1)
  {
    left();
    nh.loginfo("Turning Left!");
  }
  else
  {
    pause();
    nh.loginfo("Stopping!");
  }
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );

void setup()
{

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Set motors OFF
  pause();

  //Connect to ROS
  nh.initNode();
  nh.subscribe(sub);
}


void loop()
{
 nh.spinOnce();
 delay(1);

}

void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void pause()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
