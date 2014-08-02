#include "ControllerEvent.h"  
#include "Controller.h"  
#include "Logger.h"  


using namespace std;
  
class MyController : public Controller {  
public:  
  void onInit(InitEvent &evt);  
  double onAction(ActionEvent&);  
  void onRecvMsg(RecvMsgEvent &evt); 
  void onCollision(CollisionEvent &evt); 
};  
  
void MyController::onInit(InitEvent &evt) {  
}  
  
double MyController::onAction(ActionEvent &evt) {  


  SimObj *tool  = getObj("ArrowStick");	
 

  // // BUG1 = The function setTorque works well, if the SIGServer from GitHub is installed and the type of JOINT1 is "free". 
  // If the SIGServer from Web is downloaded and installed setTorue is executed only once!  

  // // BUG 2 = The function setTorque does not work, when all the joint types are "fixed", or if any of the joint types are "rotate". 
  // // Only works if type of JOINT1 is "free".
  
  // // To confirm the above two, please uncomment the line below.

  // tool->setTorque(0, 100, 0);

 
  // // The function addTorque() works only if the SIGServer from GitHub is installed. 
  // // It shall work, even when all the the joint types are "fixed", or if any of the joint types are "rotate" (except JOINT1)

  // // BUG 1 = If the type of JOINT1 is "rotate", then a very slow rotation (and translation) of the tool is generated ( as compared to other cases). 

  // tool->addTorque(0, 1000, 0);

 
  // // To run the code below, please make sure that type of "JOINT1" is "rotate", else this shall give an error. 

  // BUG 1 = The "JOINT 1" shall rotate, but the movement of its corresponding segment (and  so the tool) is not the same as the Joint. 
  // This makes it impossible to write a PID torque control for controlling the orientation of tool, because I do not know how much torque should be applied to the JOINT1 in order to
  // rotate the tool for some spcific amount e.g 0.8 radians or -6 radians.


  tool->addJointTorque("JOINT1", 1500);
  cout << "The Joint1 angle =" << tool->getJointAngle("JOINT1") << endl;




  return 0.0001;      
}  
  
void MyController::onRecvMsg(RecvMsgEvent &evt) {  
}  

void MyController::onCollision(CollisionEvent &evt) { 
}
  
extern "C" Controller * createController() {  
  return new MyController;  
}  

