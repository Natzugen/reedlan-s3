#include "NewJewels.h"
#include "stdafx.h"
#include "Utils.h"
#include "User.h"
#include "Item.h"
#include "Protocol.h"
#include "ChaosBox.h"
#include "g_Console.h"
void ChaosSendMixFail ( DWORD gObjID )
{
 ChaosBoxInit ( gObjOffset + ( gObjSize * gObjID ) );
 ChaosBoxSend ( gObjOffset + ( gObjSize * gObjID ) , 0 );

 char buff[11] = { 0xC1 , 0x0B , 0x86 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
 DataSend ( gObjID , (PBYTE)buff , buff[1] );
}
void ChaosBoxHook(DWORD gObjID , DWORD MixID) 
{
 OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjID);

 bool CheckChaosCard = gObjGetItemInChaosbox(gObjID,0x1C36); //Chaos Card
 DWORD Level=DWORD(gObjGetItemLevelInChaosbox(gObjID,0x1C36)); 

 int Mix1P1  = gObjGetItemInChaosbox(gObjID,0x1C33);
 int Mix1P2  = gObjGetItemInChaosbox(gObjID,0x180F);
 int iExc[13] = { 0, 1, 2, 3, 4, 5, 8, 10, 16, 18, 24, 32, 48 };
 int iOpt =  rand()%4+0;
 int iLuck = rand()%2+0;
 int Mix1Sum = Mix1P1+Mix1P2;
 DWORD Level2=DWORD(gObjGetItemLevelInChaosbox(gObjID,0x1C33)); 

 if (Mix1P1)
 {
 if(gObj->Money<=5000000)
 {
 MsgNormal(gObjID,"[SYSTEM] You need more zen to mix");
 }
 else 
 {
 ItemSerialCreateSend (gObjID,0xFF,0,0,0x1829,0,0,0,iLuck,iOpt,-1,iExc[rand()% 12],0);
 //UserItem,ItemLevel,ItemDurability,ItemSkill,ItemLuck,ItemOpc,-1,ItemExc,AncientItem
 gObj->Money-=5000000;
 GCMoneySend(gObjID, gObj->Money);
 LevelUpEffect(gObjID,0);
 g_Console.ConsoleOutput(4,"[Debug] Mix1 Success Mixed");
 }
 }

 else if (CheckChaosCard && Level>=0 && Level<=13)
 {
 g_Console.ConsoleOutput(4,"[Debug] ChaosCard Mixed");
 }

 else
 {
 ChaosSendMixFail(gObjID);  
 }
}