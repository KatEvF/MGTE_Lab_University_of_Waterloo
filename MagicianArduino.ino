

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
bool flag1 = false; //set off for now so I can not destroy the lab
bool flag2 = false; //see flag1
bool flag3 = false; //see flag1

//Note about moving:
//If youre looking from the back of the robot
//+y is to left
//-y is to right
//+x is away from you
//-x is towards you
//+z is up
//-z is down

void setup()
{
  Serial.begin(115200);
  Dobot_Init();                                       //Initial Dobot
  //SetHomeCmd();
  Serial.println("starting...");
  Dobot_SetPTPCommonParams(10,15);
}

//bool stopProcedure (){
//String a = Serial.readString();
//  if (a== "stop"){
//    flag = true;
//    return true;
//  }
//  else return false;
//}

void puckCollection() {
  Dobot_SetPTPCmd(MOVJ_XYZ, 264.0299, 83.9044, -40.4429, 52.3694); //Move above puck
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 279.3217, 93.0454, -103.1226, 0); //Move onto puck
  delay(500);
//  puckDelivery();
//  puckDropoff();
}

void puckDelivery() {
  Dobot_SetPTPCmd(MOVJ_XYZ, 264.0299, 83.9044, -40.4429, 52.3694); //Move above puck
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 206.2015, -46.3917, 60.7335, 24.0606); //Move away from puck
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 171.0816, -133.2117, 153.7598, -1.1659);//Move closer to Slide
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 89.0149, -198.8583, 160.9772, -29.1453); //Move even closer to Slide
  delay(500);
}

void puckDropoff() {
  Dobot_SetPTPCmd(MOVJ_XYZ, 117.8731, -245.7612, 148.3279, -27.6365);//On slide
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 89.0149, -198.8583, 160.9772, -29.1453); //Move even closer to Slide
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 171.0816, -133.2117, 153.7598, -1.1659);//Move closer to Slide
  delay(500);
  Dobot_SetPTPCmd(MOVJ_XYZ, 206.2015, -46.3917, 60.7335, 24.0606); //Move away from puck
  delay(500);
  flag1 = flag2 = flag3 = false;
}

void loop()
{
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    
    switch (inByte) {
    case '1': //   puck detected: start puck collection
      flag1 = true;   
      puckCollection();
      break;
    case '2': //   no obstruction detected: start puck delivery
      flag2 = true;   
      puckDelivery();
      break;
    case '3': //   no obstruction detected: start puck dropoff
      flag3 = true;   
      puckDropoff();
      break;
    case '9': // stop puck collection   
      flag1 = flag2 = flag3 = false;
      break;
    
      default: // turn off fading and shut all colors off
      flag1 = flag2 = flag3 = false;
      break;
    }
  }
}

//void checkSurroundings() {
//  if (
//}


//{{{{
//  
//  while(!flag && Serial.available())
//  {
//    Dobot_SetPTPCmd(MOVJ_XYZ, 264.0299, 83.9044, -40.4429, 52.3694); //Move above puck
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 279.3217, 93.0454, -103.1226, 0); //Move onto puck
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 264.0299, 83.9044, -40.4429, 52.3694); //Move above puck
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 206.2015, -46.3917, 60.7335, 24.0606); //Move away from puck
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 171.0816, -133.2117, 153.7598, -1.1659);//Move closer to Slide
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 89.0149, -198.8583, 160.9772, -29.1453); //Move even closer to Slide
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 117.8731, -245.7612, 148.3279, -27.6365);//On slide
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 89.0149, -198.8583, 160.9772, -29.1453); //Move even closer to Slide
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 171.0816, -133.2117, 153.7598, -1.1659);//Move closer to Slide
//    if (stopProcedure()) break;
//    delay(500);
//    Dobot_SetPTPCmd(MOVJ_XYZ, 206.2015, -46.3917, 60.7335, 24.0606); //Move away from puck
//    if (stopProcedure()) break;
//    delay(500);
//  }
//}}}}
//}
//  while(!flag && Serial.available())
//  {                                                  
//     if (stopProcedure()) break;
//     delay(500);
//     Dobot_SetPTPCmd(MOVJ_XYZ, -54.5824, 255.2436, 20.5242, 0);
//     if (stopProcedure()) break;
//     delay(500);
//     Dobot_SetPTPCmd(MOVJ_XYZ, -54.5824, 255.2436, -39.0827, 0);//Dobot_SetPTPCmd(MOVJ_XYZ, 212, 9, 0, 0);                                                           //Move to point A
//     Dobot_SetEndEffectorGripper(true,false);                                                           //Turn on gripper to pick up puck
//     Dobot_SetPTPCmd(JUMP_XYZ, 212, 9, 90, 0);                                                          //Lift a certain height                                            
//     Dobot_SetPTPCmd(MOVJ_XYZ, 139, -160, 90, 0);                                                       //Move to point B
//     Dobot_SetPTPCmd(JUMP_XYZ, 139, -160, -0, 0);                                                       //drop a certain height
//     delay(500);
//     Dobot_SetEndEffectorGripper(true, true);                                                           //Turn off air pump   
//     delay(500);
//     Dobot_SetPTPCmd(MOVJ_XYZ, 230, 0, -5, 0);                                                          //Move back to the initial position
//  }
  
//}
