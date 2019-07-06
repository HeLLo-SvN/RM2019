#include "main.h"

/**********底盘值返回**********/

void V_Back(int16_t FTL,int16_t FTR,int16_t FDL,int16_t FDR)
{
  CanTxMsg tx_message;
  tx_message.StdId=0x200;
  tx_message.IDE=CAN_Id_Standard;
  tx_message.RTR=CAN_RTR_Data;
  tx_message.DLC=0x08;
  tx_message.Data[0]=(unsigned char)(FTL>>8);
  tx_message.Data[1]=(unsigned char)FTL;
  tx_message.Data[2]=(unsigned char)(FTR>>8);
  tx_message.Data[3]=(unsigned char)FTR;
  tx_message.Data[4]=(unsigned char)(FDL>>8);
  tx_message.Data[5]=(unsigned char)FDL;
  tx_message.Data[6]=(unsigned char)(FDR>>8);
  tx_message.Data[7]=(unsigned char)FDR;
  CAN_Transmit(CAN1,&tx_message);
}

void VR_Back(int16_t FML,int16_t FMR,int16_t UNKNOWN1,int16_t UNKNOWN2)
{
  CanTxMsg tx_message;
  tx_message.StdId=0x1FF;
  tx_message.IDE=CAN_Id_Standard;
  tx_message.RTR=CAN_RTR_Data;
  tx_message.DLC=0x08;
  tx_message.Data[0]=(unsigned char)(FML>>8);
  tx_message.Data[1]=(unsigned char)FML;
  tx_message.Data[2]=(unsigned char)(FMR>>8);
  tx_message.Data[3]=(unsigned char)FMR;
  tx_message.Data[4]=(unsigned char)(UNKNOWN1>>8);
  tx_message.Data[5]=(unsigned char)UNKNOWN1;
  tx_message.Data[6]=(unsigned char)(UNKNOWN2>>8);
  tx_message.Data[7]=(unsigned char)UNKNOWN2;
  CAN_Transmit(CAN1,&tx_message);
}

/**********升降值返回**********/
/**********抓取值返回**********/
/**********翻转值返回**********/

void Action_Back(int16_t FliftL,int16_t FliftR,int16_t FGrab,int16_t FRotate)
{
  CanTxMsg tx_message;
  tx_message.StdId=0x200;
  tx_message.IDE=CAN_Id_Standard;
  tx_message.RTR=CAN_RTR_Data;
  tx_message.DLC=0x08;
  tx_message.Data[0]=(unsigned char)(FliftL>>8);
  tx_message.Data[1]=(unsigned char)FliftL;
  tx_message.Data[2]=(unsigned char)(FliftR>>8);
  tx_message.Data[3]=(unsigned char)FliftR;
  tx_message.Data[4]=(unsigned char)(FGrab>>8);
  tx_message.Data[5]=(unsigned char)FGrab;
  tx_message.Data[6]=(unsigned char)(FRotate>>8);
  tx_message.Data[7]=(unsigned char)FRotate;
  CAN_Transmit(CAN2,&tx_message);
}
