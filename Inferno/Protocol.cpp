#include "Windows.h"
#include "Protocol.h"
#include <stdio.h>
#include "USER.h"
#include "GMConf.h"
#include "g_Console.h"
#include "MSSQL.h"
#include <time.h>
#include "Utils.h"
#include "NewJewels.h"
#include "VIP.h"
#include "offTrade.h"
#include "Command.h"
#include "MoveStadium.h"
#include "ExpSystem.h"
#include "ChaosMaster.h"
#include "Wings.h"
//========================================================================================================================
OFFLINETRADELOGIN OfflineLogin[OBJECT_MAX];
//========================================================================================================================
//ProtocolCore
//========================================================================================================================
bool ProtocolCore(BYTE protoNum,LPBYTE aRecv,DWORD aLen,DWORD aIndex,DWORD Encrypt,int Serial)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
//========================================================================================================================
	switch(BYTE(protoNum))
	{
//========================================================================================================================
//Protocol Chat
//========================================================================================================================
	case 0x00:
    ChatDataSend(aIndex,aRecv);
		break;
//========================================================================================================================
//Protocol OffTrade
//========================================================================================================================
case 0xF1:
    OffTradeLogin(aIndex,aRecv);
  break;
//========================================================================================================================
//Protocol Npc Use
//========================================================================================================================
  case 0x30: //Click npc protocol
	if(ClickOnNPC(aIndex,aRecv))
			return true;
			break;
//========================================================================================================================
//Protocol Player Connect
//========================================================================================================================
		case 0x03: //Player Connected
		PlayerConnected(aIndex,aRecv);
	//	GetCustomInfoClient(aIndex,aRecv);
		break;
//========================================================================================================================
// ChaosBox Hook
//========================================================================================================================
	//  case 0x86: 
	//	ChaosBoxHook(aIndex,aRecv[3]);
	//	g_Console.ConsoleOutput(4,"[DEBUG] [%s][%s] ChaosMix Data Send",gObj->AccountID,gObj->Name);
	//	break;
//========================================================================================================================
//Protocol use Item(New Jewels)
//========================================================================================================================
		case 0x26:
			if(CGUseItemRecv((PMSG_USEITEM *)aRecv, aIndex))		
				return true;
		   CGUseItemRecv((PMSG_USE_ITEM_RECV*)aRecv,aIndex); //Item USE (New jewells)
		   break;
//========================================================================================================================

	}
//========================================================================================================================
if (DebugRecvPacket == 1)
{
LogNotice(2,"%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",aRecv[0],aRecv[1],aRecv[2],aRecv[3],aRecv[4],aRecv[5],aRecv[6],aRecv[7],aRecv[8],aRecv[9],aRecv[10],aRecv[11],aRecv[12],aRecv[13],aRecv[14],aRecv[15],aRecv[16],aRecv[17],aRecv[18],aRecv[19],aRecv[20],aRecv[21],aRecv[22],aRecv[23],aRecv[24],aRecv[25],aRecv[26],aRecv[27],aRecv[28],aRecv[29],aRecv[30]);
}
//========================================================================================================================
DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
//========================================================================================================================
	return true;
}
//========================================================================================================================
bool ProtocolCoreSend(int aIndex,unsigned char* aSend, int aLen)
{	
OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);	


	switch(aSend[0])
	{	
		case 0xC3:
			switch(aSend[2])
			{	
				case 0x24:
					GSEquiItem(aIndex,aSend);
					break;

			}
			break;
	}


//========================================================================================================================
	DataSend(aIndex,aSend,aLen);
	return true;
}
//========================================================================================================================
//CGLiveClient
//========================================================================================================================
void CGLiveClient(PMSG_CLIENTTIME * lpClientTime, short aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if ( gObj->Connected > PLAYER_CONNECTED )
	{
		gObj->ConnectCheckTime = GetTickCount();
	}

	if ( gObj->CheckSpeedHack != false )
	{
		int systemtick = GetTickCount() - gObj[aIndex].CheckTick2;
		int usertick = lpClientTime->Time - gObj[aIndex].CheckTick;
		int checktime = systemtick - usertick;

		/*if ( checktime < -7000 )
		{
			LogAddTD(lMsg.Get(MSGGET(1, 214)), gObj[aIndex].AccountID, gObj[aIndex].Name, checktime);
			CloseClient(aIndex);
		}*/

		gObj->CheckTickCount++;

		if ( gObj->CheckTickCount > 45 )
		{
			gObj->CheckTick = lpClientTime->Time;
			gObj->CheckTickCount = 0;
		}
	}
	

	if ( gObj->Connected == PLAYER_PLAYING )
	{
		int isFixSpeed = GetPrivateProfileInt("Fix","FixSpeed",1,".\\Custom.ini");
		if (isFixSpeed != 1)
		{
		if ( gObj->m_AttackSpeed < lpClientTime->AttackSpeed || gObj->m_MagicSpeed < lpClientTime->MagicSpeed )
		{
			LogNotice(2, "[%s][%s][%s] ClientHack Detected : Editing AttackSpeed [%d][%d] [%d][%d] ",
				gObj->AccountID, gObj->Name, gObj->Ip_addr,
				gObj->m_AttackSpeed, lpClientTime->AttackSpeed, gObj->m_MagicSpeed,
				lpClientTime->MagicSpeed);
			gObj->m_AttackSpeedHackDetectedCount++;


			if ( gObj->m_AttackSpeedHackDetectedCount > 3 )
			{
				CloseClient(aIndex);
			}
		}
		else
		{
			gObj->m_AttackSpeedHackDetectedCount = 0;
		}
		}
		else
		{
			gObj->m_AttackSpeedHackDetectedCount = 0;
		}
		

	}
	
}
//========================================================================================================================
//CGSellRequestRecv_Hook
//========================================================================================================================
void CGSellRequestRecv_Hook(PMSG_SELLREQUEST * lpMsg, int aIndex) 
{ 
OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex); 
if (OfflineShop[aIndex].IsOffTrade == 1)
{

PMSG_SELLRESULT pResult; 
PHeadSetB((LPBYTE)&pResult, 0x33, sizeof(pResult)); 
pResult.Result = false; 
pResult.Money = gObj->Money; 

int iAddSum = gObj->pInventory[lpMsg->Pos].m_SellMoney;


if ( gObj->CloseType != -1 ) 
{ 
DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
return; 
} 

if ( gObj->m_IfState.use > 0 && gObj->m_IfState.type != 3 ) 
{ 
DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
return; 
} 

if ( gObj->pTransaction == 1 ) 
{ 
return; 
} 

if ( lpMsg->Pos > MAIN_INVENTORY_SIZE-1 ) 
{ 
DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
return; 
} 

//unsigned short gems = iAddSum; 
unsigned short gems = 50; 
//SQL.UpdateCashOffExpSystem(gObj->AccountID,gems);
g_Console.ConsoleOutput(2,"[ DEBUG ]  Offline Trade Cash send");
gObjInventoryDeleteItem(aIndex, lpMsg->Pos); 
GCInventoryItemDeleteSend(aIndex, lpMsg->Pos, 1); 

pResult.Result = true; 
DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
return; 

}
CGSellRequestRecv(lpMsg, aIndex); 
}
//========================================================================================================================
//CGPShopReqBuyItem_Hook
//========================================================================================================================
void CGPShopReqBuyItem_Hook(PMSG_REQ_BUYITEM_FROM_PSHOP * lpMsg, int aIndex) 
{
	OBJECTSTRUCT *pObj = (OBJECTSTRUCT*)OBJECT_POINTER(MAKE_NUMBERW(lpMsg->NumberH, lpMsg->NumberL));
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	DWORD dwCost = 0;
    DWORD Coins = 0;
	DWORD Credits = 0;
	DWORD Procent = 0;
	float  OfftradeProcent = GetPrivateProfileInt("OffTrade","OfftradeProcent",0.3,".\\Config\\OffTrade.cfg");
	dwCost = pObj->pInventory1[lpMsg->btItemPos].m_iPShopValue;
    Coins = SQL.GetCoinsPlayer(gObj->AccountID);
	Credits = SQL.GetCreditsPlayer(gObj->AccountID);
	if (OfftradeProcent == 0.0)
	{
		Procent = 0;
	}
	else
	{
		Procent = dwCost*OfftradeProcent;
	}
	
	if (pObj->OffTradeCoin == 1)
	{
		if (Coins < pObj->pInventory1[lpMsg->btItemPos].m_iPShopValue)
		{
		MsgNormal(aIndex,"no required amount");
		return;
		}
	//	dwCost -= dwCost%5;
                SQL.UpdateCashOffExpSystemPlus(pObj->AccountID,dwCost-Procent);
				LogNotice(1,"[OffTradeCoin] Character %s succesful sell item for %d coins",pObj->Name,dwCost);
				SQL.UpdateCashOffExpSystemMinus(gObj->AccountID,dwCost);
				LogNotice(1,"[OffTradeCoin] Character %s succesful buy item for %d coins",gObj->Name,dwCost);
				 gObj->Money += dwCost;
			   	 pObj->Money -= dwCost;
			
				GCMoneySend(aIndex, gObj->Money);
				GCMoneySend(pObj->m_Index, pObj->Money);

	
	
	}

CGPShopReqBuyItem(lpMsg,aIndex);
}

