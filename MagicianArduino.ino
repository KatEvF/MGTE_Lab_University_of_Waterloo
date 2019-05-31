

/****************************************Copyright(c)*****************************************************
**                            Shenzhen Yuejiang Technology Co., LTD.
**
**                                 http://www.dobot.cc
**--------------------------------------------------------------------------------------------------------
** Modify by:           
** Modified date:     
** Version:          
** Descriptions:        
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <Magician.h>
bool flag = false;

void setup()
{
  Serial.begin(115200);
  Dobot_Init();                                       //Initial Dobot
  SetHomeCmd();
  Serial.println("start...");
  Dobot_SetPTPCommonParams(50,50);
  Dobot_SetPTPCmd(MOVJ_XYZ, 230, 0, 40, 0);
}

void loop()
{
  
  if(!flag)
  {                                                  
     //flag = true;
     Dobot_SetPTPCmd(MOVJ_XYZ, 212, 9, 0, 0);                                                           //Move to point A
     Dobot_SetEndEffectorGripper(true,false);                                                           //Turn on gripper to pick up puck
     Dobot_SetPTPCmd(JUMP_XYZ, 212, 9, 90, 0);                                                          //Lift a certain height                                            
     Dobot_SetPTPCmd(MOVJ_XYZ, 139, -160, 90, 0);                                                       //Move to point B
     Dobot_SetPTPCmd(JUMP_XYZ, 139, -160, -0, 0);                                                       //drop a certain height
     delay(500);
     Dobot_SetEndEffectorGripper(true, true);                                                           //Turn off air pump   
     delay(500);
     Dobot_SetPTPCmd(MOVJ_XYZ, 230, 0, -5, 0);                                                          //Move back to the initial position
  }
  
}
