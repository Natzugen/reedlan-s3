//==================================================================================================
//=====================================AROTH GAMESERVER PROJECT=====================================
//==================================================================================================
// File:          ChaosMaster.cpp
// Description:   ChaosMaster Mix Adder
// Last Edit:     15.10.2011
//==================================================================================================
// Code: DarkSim, Killbrum
//==================================================================================================
#include "User.h"
#include "Protocol.h"
#include "ChaosMaster.h"
#include "Item.h"
#include "USER.h"
#include "Utils.h"
#include "g_Console.h"
#pragma warning(disable:4309)
#pragma warning(disable:4244)
//==================================================================================================
// ChaosMaster Mix Adder
//==================================================================================================
int gObjGetItemCountInChaosbox(int aIndex, short type) {
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	int count = 0;

	for(unsigned i = 0; i < 32; i++)
	{
		if(gObj->pChaosBox[i].m_Type == type)
			count++;
	}

	return count;
}


bool gObjGetItemInChaosbox(int aIndex, short type) {
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	int count = 0;

	for(unsigned i = 0; i < 32; i++)
	{
		if(gObj->pChaosBox[i].m_Type == type)
			return true;
	}

	return false;
}

int gObjGetItemLevelInChaosbox(int aIndex, short type) {
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	int count = 0;

	for(unsigned i = 0; i < 32; i++)
	{
		if(gObj->pChaosBox[i].m_Type == type)
			return gObj->pChaosBox[i].m_Level;
	}

	return 1;
}


void ChaosSendMixFail ( DWORD gObjID)
{
	ChaosBoxInit ( gObjOffset + ( gObjSize * gObjID ) );
	ChaosBoxSend ( gObjOffset + ( gObjSize * gObjID ) , 0 );
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjID);
	char buff[11] = { 0xC1 , 0x0B , 0x86 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	DataSend ( gObjID , (PBYTE)buff , buff[1] );

}
	//GCInventoryItemDeleteSend(gObjID, lpMsg->inventoryPos, 1);	


	//PMSG_CHAOSBOX_RESULT Msg = {0xC1, 0x0A, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	//DataSend(gObjID, (unsigned char*)&Msg, 10);


//==========================
// Chaos Box Hook
//==========================
void ChaosBoxHook(DWORD gObjID , DWORD MixID) 
{
OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjID);
    int Randomer = rand()%99+1;
	
	
	
	
	if( MixID == 40)
	{

	DWORD Level=DWORD(gObjGetItemLevelInChaosbox(gObjID,0x1C36)); 
	int iExc[23] = { 0,0,0,0,0,0,0,0,0,0,0,1, 2, 3, 4, 5, 8, 10, 16, 18, 24, 32, 48 };
	int Wings1[3] = { 0x1800,0x1801,0x1802};
	int iOpt =  rand()%4+0;
	int iLuck = rand()%2+0;
	DWORD Level2=DWORD(gObjGetItemLevelInChaosbox(gObjID,0x1C33)); 
	int WingsOfDivine = GetPrivateProfileInt("NewWings","WingsOfDivine",1,".\\Config\\Mix.cfg");
	int WingsOfWhite = GetPrivateProfileInt("NewWings","WingsOfWhite",1,".\\Config\\Mix.cfg");
	int PriceMix = GetPrivateProfileInt("NewWings","PriceMix",1,".\\Config\\Mix.cfg");

	if(gObj->Money<=PriceMix)
	{
	MsgNormal(gObjID,"[SYSTEM] You need more zen to mix");
	return;
	}
	      if(Randomer > 50) //Wings of Wihte
				{
					if(Role(100) <= WingsOfWhite)
					{
	gObj->Money-=PriceMix;
	ItemSerialCreateSend (gObjID,0xFF,0,0,0x1829,0,0,0,iLuck,iOpt,-1,iExc[rand()% 23],0);
	GCMoneySend(gObjID, gObj->Money);
	LevelUpEffect(gObjID,0);
	g_Console.ConsoleOutput(4,"[Mix] [%s][%s] Mixed - Wings of White [0] OK",gObj->AccountID,gObj->Name);
	}

					else
					    {   
						gObj->Money-=PriceMix;
	                    GCMoneySend(gObjID, gObj->Money);
						ItemSerialCreateSend (gObjID,0xFF,0,0,Wings1[rand()% 3],0,0,0,0,0,-1,0,0);
						ChaosSendMixFail(gObjID);

					    }


				}
		          else //Wings of Divine
				       {

					 if(Role(100) <= WingsOfDivine)
					{
	//UserItem,ItemLevel,ItemDurability,ItemSkill,ItemLuck,ItemOpc,-1,ItemExc,AncientItem
	gObj->Money-=PriceMix;
	GCMoneySend(gObjID, gObj->Money);
	ItemSerialCreateSend (gObjID,0xFF,0,0,0x182A,0,0,0,iLuck,iOpt,-1,iExc[rand()% 23],0);

	LevelUpEffect(gObjID,0);
	g_Console.ConsoleOutput(4,"[Mix] [%s][%s] Mixed - Wings of Divine [0] OK",gObj->AccountID,gObj->Name);
					}
					 else
					 {
				gObj->Money-=PriceMix;
	            GCMoneySend(gObjID, gObj->Money);
					ItemSerialCreateSend (gObjID,0xFF,0,0,Wings1[rand()% 3],0,0,0,0,0,-1,0,0);
					 ChaosSendMixFail(gObjID);	
					 }
					
	}
		}








}

		
