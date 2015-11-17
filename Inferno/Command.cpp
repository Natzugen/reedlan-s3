#include "StdAfx.h"
#include "Command.h"
#include "USER.h"
#include "Utils.h"
#include "GMConf.h"
#include "offTrade.h"
#include "MoveReq.h"
#include "MSSQL.h"
#include "Protocol.h"
#include "ResetSystem.h"
#include "PostBlock.h"
#include "PackSystem.h"
//========================================================================================================================
// Trace Character Command
//========================================================================================================================
void ChatTrace(int aIndex,char* msg)
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
     char TPlayer[16]	= {0};
//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[Trace] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,1))
	{	
		MsgNormal(aIndex,"[Trace] Only GM from list can use this command.");
		return;
	}

//========================================================================================================================

	int isFind = 0;
	sscanf(msg,"%s",TPlayer);
	DWORD PlayerID = SQL.GetaIndexPlayer(TPlayer);
	for(PlayerID=OBJECT_MIN;PlayerID<OBJECT_MAX;PlayerID++)
	{
		OBJECTSTRUCT * sObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);

		if(strcmp(msg,sObj->Name) == 0)
		{
			gObjTeleport(aIndex,sObj->MapNumber,sObj->X,sObj->Y);
			isFind = 1;
		}
	}

	if(isFind == 1)
	{
	MsgNormal(aIndex,"You have trace to [%s]",TPlayer);
	}
	else
	{
	MsgNormal(aIndex,"[Trace] Player: %s  is offline",TPlayer);
	}
}
//========================================================================================================================
// Gmove Command
//========================================================================================================================
void ChatGmove(int aIndex,char* msg)
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
     char Player[16]	= {0};
	 int Map = 0;
	 int MapX = 100;
	 int MapY = 100;
	 int isFind = 0;
//========================================================================================================================
    if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[Gmove] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,11))
	{	
		MsgNormal(aIndex,"[Gmove] Only GM from list can use this command.");
		return;
	}
//========================================================================================================================
	 sscanf(msg,"%s %d %d %d",&Player,&Map,&MapX,&MapY);
	 DWORD PlayerID = SQL.GetaIndexPlayer(Player);
//========================================================================================================================
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
	OBJECTSTRUCT * sObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
	
			gObjTeleport(PlayerID,Map,MapX,MapY);
			isFind = 1;
	}
//========================================================================================================================
	if(isFind == 1)
	{
	MsgNormal(aIndex,"[Gmove] %s moved to %d %d %d " ,Player,Map,MapX,MapY);
	}
	else
	{
	MsgNormal(aIndex,"[Gmove] Player: %s  is offline",Player);
	}
}
//========================================================================================================================
// Drop Item Command
//========================================================================================================================
void ChatDrop(DWORD gObjId,char* msg)
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(gObjId,"[Item] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,0))
	{	
		MsgNormal(gObjId,"[Item] Only GM from list can use this command.");
		return;
	}

//========================================================================================================================

	int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
	sscanf_s(msg,"%d %d %d %d %d %d %d %d",&ItemType,&ItemNr,&ItemLevel,&ItemDur,&ItemSkill,&ItemLuck,&ItemOpt,&ItemExc);

	DWORD Item = ItemType*512+ItemNr;

	ItemSerialCreateSend(gObjId,gObj->MapNumber,gObj->X,gObj->Y,Item,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
	MsgNormal(gObjId,"[Item] : Created %d %d %d %d %d %d %d %d", ItemType, ItemNr, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, ItemExc);
}
//========================================================================================================================
// Online Show Command
//========================================================================================================================
void ChatOnline(int aIndex)
{
	int online=0,gm = 0;
	int isOnline = GetPrivateProfileInt("Online","IsOnline",1,".\\Config\\Command.cfg");
	int Level = GetPrivateProfileInt("Online","MinLevel",1,".\\Config\\Command.cfg");
	int OnlinePlus = GetPrivateProfileInt("Online","OnlinePlus",0,".\\Config\\Command.cfg");
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if (isOnline == 0)
	{
	             
	MsgNormal(aIndex,"[Online] : Command disabled.");
		return;
	}


	if(gObj->Level < Level)
	{
		MsgNormal(aIndex,"[Online] : You need %d level to use command.",Level);
		return;
	}

	for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
	{
		OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);

		if(gObj->Connected == 3)
		{	
			if(gObj->Type == OBJECT_USER)
			{
				if((gObj->Authority != 32)||(gObj->Authority != 8))
				{
				online++;
				}
				if(gObj->Authority == 32)
				{
					gm++;
				}
			}
		}
	}
			
	MsgNormal(aIndex,"[Online] Players : %d, GMs: %d",online+OnlinePlus,gm);
}
//========================================================================================================================
// Global GM Command
//========================================================================================================================
void ChatGMmsg(int aIndex,char* msg)
	
{
   //--------------------------------------------------------------------------------------------------------------------
	if(aIndex <= OBJECT_MIN && aIndex >= OBJECT_MAX)
		return;
	//--------------------------------------------------------------------------------------------------------------------
	if(aIndex > OBJECT_MAX)
		return;
	//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	//--------------------------------------------------------------------------------------------------------------------
	//========================================================================================================================
    if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[GG] : Command only for GM's");
		return;
	}	
     //========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,4))
	{	
		MsgNormal(aIndex,"[GG] Only GM from list can use this command.");
		return;
	}

//========================================================================================================================  

	//--------------------------------------------------------------------------------------------------------------------
		MsgAll("[%s]: %s",gObj->Name,msg);

}
//========================================================================================================================
// Test Box Command
//========================================================================================================================
void ChatT(DWORD gObjId)
	
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
 BYTE Packet[7] = {0xC1, 0x07, 0xF3, 0x40, 0x01, 0x15, 0x00};
 DataSend(gObj->m_Index, (BYTE*)&Packet, sizeof(Packet));

 //return;

}
//========================================================================================================================
// OffTradeZen Command
//========================================================================================================================
void ChatOffTradeZen(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int OffTradeActive = GetPrivateProfileInt("OffTrade","OffTradeActive",1,".\\Config\\OffTrade.cfg");
	int OffTradeZen = GetPrivateProfileInt("OffTrade","OffTradeZen",1,".\\Config\\OffTrade.cfg");
	if (OffTradeActive == 1)
	{
	if (OffTradeZen == 1)
	{
	gObj->OffTradeZen = 1;
	OFFTrade.CreateOfflineTrade(aIndex);
	}
	else
	{
	MsgNormal(aIndex,"~[System] : OffTrade sell for zen disabled.");
	}
	}
	else
	{
	MsgNormal(aIndex,"~[System] : OffTrade System is disabled.");
	}
}
//========================================================================================================================
// OffTradeCoins Command
//========================================================================================================================
void ChatOffTradeCoins(int aIndex)
{
		OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int OffTradeActive = GetPrivateProfileInt("OffTrade","OffTradeActive",1,".\\Config\\OffTrade.cfg");
	int OffTradeCoins = GetPrivateProfileInt("OffTrade","OffTradeCoins",1,".\\Config\\OffTrade.cfg");
	if (OffTradeActive == 1)
	{
    if (OffTradeCoins == 1)
	{
	gObj->OffTradeCoin = 1;
	OFFTrade.CreateOfflineTrade(aIndex);
	}
	else
	{
	MsgNormal(aIndex,"~[System] : OffTrade sell for coins disabled.");
	}
	}
	else
	{
	MsgNormal(aIndex,"~[System] : OffTrade System is disabled.");
	}
}
//========================================================================================================================
// Skin Character Command
//========================================================================================================================
void SkinCommand(DWORD aIndex,char* msg)
{
int	 SkinMob	= -1;
char Player[16]	= {0};
int  isFind = 0;
int  online = 0;
OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[Skin] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,7))
	{	
		MsgNormal(aIndex,"[Skin] Only GM from list can use this command.");
		return;
	}
//========================================================================================================================
    sscanf(msg,"%s %d",&Player,&SkinMob);
	DWORD PlayerID = SQL.GetaIndexPlayer(Player);
//========================================================================================================================
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
	OBJECTSTRUCT* lObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
	lObj->m_Change = SkinMob;
	gObjViewProtocolListCreateHook(lObj);
	isFind = 1;
	}
//========================================================================================================================
	if(isFind == 1)
	{
	MsgNormal(aIndex,"[Skin]: [%s] is transformed to - Monster ID [%d]",Player,SkinMob);
	}
	else
	{
	MsgNormal(aIndex,"[Skin] Player: %s  is offline",Player);
	}
}
//========================================================================================================================
// Summon System
//========================================================================================================================
void SummonCommand(DWORD ChatID)
{
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)OBJECT_POINTER(ChatID);
	short FinalPosX = gObj->X+1;
	short FinalPosY = gObj->Y+1;
   //--------------------------------------------------------------------------------------------------------------------
	int isActive = GetPrivateProfileInt("SummonSystem","Active",1,".\\Common.ini");
	int Level = GetPrivateProfileInt("SummonSystem","Level",100,".\\Common.ini");
	int vCost = GetPrivateProfileInt("SummonSystem","Cost",10000,".\\Common.ini");
   //--------------------------------------------------------------------------------------------------------------------
	
	if(vCost > 0)
	{
		if(gObj->Money < vCost)
		{
			if(vCost > 0)
			{
				MsgNormal(ChatID,"[Summon]: You Don't Have Enough Zen %d",vCost);
				return;
			}
			else
			{
				MsgNormal(ChatID,"[Summon] : Config error");
				return;
			}
		}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(isActive==0)
	{
		MsgNormal(ChatID,"~[Summon] : Command disabled.");
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < Level)
	{
		MsgNormal(ChatID,"~[Summon] : You need %d level to use command.",Level);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	//Summon(ChatID);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(ChatID,"~[Summon]: Monster has been summoned!");
	//--------------------------------------------------------------------------------------------------------------------
}
//========================================================================================================================
// JewelUP Command
//========================================================================================================================
void JewelUP (DWORD gObjId)
{
	//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
	//--------------------------------------------------------------------------------------------------------------------

	if((gObjGetItemCountInInventory(gObjId,0x1C63,0) < 1)||(gObjGetItemCountInInventory(gObjId,0x1C64,0) < 1)||(gObjGetItemCountInInventory(gObjId,0x1C65,0) < 1)||(gObjGetItemCountInInventory(gObjId,0x1C66,0) < 1))
	{
	MsgNormal(gObjId,"[JewelUP] You dont hawe need item!");
	return;
	}

	gObjDeleteItemsCount(gObjId,0x1C63,0,1);
	gObjDeleteItemsCount(gObjId,0x1C64,0,1);
    gObjDeleteItemsCount(gObjId,0x1C65,0,1);
	gObjDeleteItemsCount(gObjId,0x1C66,0,1);
	
	int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

	DWORD Item = ItemType*512+ItemNr;

	ItemSerialCreateSend(gObjId,gObj->MapNumber,gObj->X,gObj->Y,Item,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
	
}
//========================================================================================================================
// ClearPK Command
//========================================================================================================================
void ClearPK (DWORD gObjId)
{
	int isFind = 0;
//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
//========================================================================================================================
	int isClearPK = GetPrivateProfileInt("ClearPK","IsActive",1,".\\Config\\Command.cfg");
	int  MinLevel = GetPrivateProfileInt("ClearPK","MinLevel",1,".\\Config\\Command.cfg");
	int  MaxLevel = GetPrivateProfileInt("ClearPK","MaxLevel",400,".\\Config\\Command.cfg");
	int     vCost = GetPrivateProfileInt("ClearPK","Cost",10000,".\\Config\\Command.cfg");
//========================================================================================================================
	if(isClearPK==0)
	{
		MsgNormal(gObjId,"[PkClear] : Command disabled.");
		return;
	}
	if (gObj->m_PK_Level < 4)
		{												
	MsgNormal(gObjId,"[PkClear] %s is not pk!", gObj->Name);			
			return;
	}

	if(gObj->Level < MinLevel)
	{
		MsgNormal(gObjId,"[PkClear] : You need %d level to use command.",MinLevel);
		return;
	}

	if(gObj->Level > MaxLevel)
	{
		MsgNormal(gObjId,"[PkClear] : You need %d level to use command.",MaxLevel);
		return;
	}

	if(vCost > 0)
	{
		if(gObj->Money < vCost)
		{
			if(vCost > 0)
			{
				MsgNormal(gObjId,"[PkClear] : To use post command you need %d",vCost);
				return;
			}
			else
			{
				MsgNormal(gObjId,"[PkClear] : Config error");
				return;
			}
		}
	}




	if((gObjId>=OBJECT_MIN) && (gObjId<=OBJECT_MAX))
	{
	 OBJECTSTRUCT* lObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
	lObj->m_PK_Level = 3;
	lObj->m_PK_Count = 0;
	//GCPkLevelSend (gObjId,gObj_GetPKStatus(gObjId));

	gObj_Write(gObjId, 0x101, 3);    
	//GCPkLevelSend (gObjId,3);
	isFind = 1;

	if(vCost > 0)
	{
		if(gObj->Money >= vCost)
		{
			if(vCost > 0)
			{
				gObj->Money -= vCost;
				GCMoneySend(gObjId,gObj->Money);
			}
		}
	}


	}
	if(isFind == 1)
	{
	}
	else
	{
	MsgNormal(gObjId,"[PkClear] Error");
	}

}
//========================================================================================================================
// PKClear Command
//========================================================================================================================
void PKClear (DWORD gObjId, char *Msg)
{
	int isFind = 0;
	char Player[16]	= {0};
	//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
	//========================================================================================================================
    if(gObj->Authority != 32)
	{	
		MsgNormal(gObjId,"[PkClear] : Command only for GM's");
		return;
	}	
    //========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,3))
	{	
		MsgNormal(gObjId,"[PkClear] Only GM from list can use this command.");
		return;
	}
    //========================================================================================================================
	if (gObj->m_PK_Level < 4 )
		{												
			MsgNormal(gObjId,"[PkClear] %s is not pk!", gObj->Name);			
			return;
		}
	sscanf(Msg,"%s",Player);
	DWORD PlayerID = SQL.GetaIndexPlayer(Player);
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
	 OBJECTSTRUCT* lObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
	lObj->m_PK_Level = 3;
	lObj->m_PK_Count = 0;
	//gObj_Write(gObjId, gObjPk, 3);
	//GCPkLevelSend (gObjId,gObj_GetPKStatus(PlayerID));

	gObj_Write(gObjId, 0x101, 3);    
	//GCPkLevelSend (gObjId,3);
	isFind = 1;


	}
	if(isFind == 1)
	{
	MsgNormal(gObjId,"[PkClear] Now player: %s  is not pk",Player);
	}
	else
	{
	MsgNormal(gObjId,"[PkClear] Player: %s  is offline",Player);
	}

}
//========================================================================================================================
// SetPK Command
//========================================================================================================================
void SetPK (DWORD gObjId, char *Msg)
{
	int isFind = 0;
	char Player[16]	= {0};
	//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
    //========================================================================================================================
    if(gObj->Authority != 32)
	{	
		MsgNormal(gObjId,"[SetPK] : Command only for GM's");
		return;
	}	
    //========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,7))
	{	
		MsgNormal(gObjId,"[SetPK] Only GM from list can use this command.");
		return;
	}
   //========================================================================================================================
	sscanf(Msg,"%s",Player);
	DWORD PlayerID = SQL.GetaIndexPlayer(Player);
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
	 OBJECTSTRUCT* lObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
	lObj->m_PK_Level = 6;
	//lObj->m_PK_Count = 3;
	//GCPkLevelSend (gObjId,gObj_GetPKStatus(PlayerID));

	gObj_Write(gObjId, 0x101, 6);    
//	GCPkLevelSend (gObjId,6);
	isFind = 1;
	}
	if(isFind == 1)
	{
	MsgNormal(gObjId,"[SetPK] Player: %s PK",Player);
	}
	else
	{
	MsgNormal(gObjId,"[SetPK] Player: %s  is offline",Player);
	}

}
//========================================================================================================================
// Reload MonsterSetBase
//========================================================================================================================
void ReloadM(DWORD gObjId)
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(gObjId,"[Reload] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,6))
	{	
		MsgNormal(gObjId,"[Reload] Only GM from list can use this command.");
		return;
	}

//========================================================================================================================
	ReloadMonsterSetBase();
	MsgNormal(gObjId,"[Reload] Monsters Reloaded.");
}
//========================================================================================================================
// Status Command
//========================================================================================================================
void StatusC(DWORD ChatID,char*  msg)
{	
	char Player[16]	= {0};
	int isFind = 0;
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)OBJECT_POINTER(ChatID);
	//--------------------------------------------------------------------------------------------------------------------
	if(strlen(msg) <= 0)
	{
		return;
	}
//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(ChatID,"[Status] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,8))
	{	
		MsgNormal(ChatID,"[Status] Only GM from list can use this command.");
		return;
	}
//========================================================================================================================
	sscanf(msg,"%s",Player);
    DWORD PlayerID = SQL.GetaIndexPlayer(Player);
	//--------------------------------------------------------------------------------------------------------------------
	if((PlayerID>=MIN_PLAYERID) && (PlayerID<=MAX_PLAYERID))
	{
		OBJECTSTRUCT * pObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
			
	MsgNormal(ChatID, "[Status]IP Address: %s",pObj->Ip_addr);
	MsgNormal(ChatID, "[Status]Account: %s | Character: %s",pObj->AccountID,pObj->Name);
	MsgNormal(ChatID, "[Status]Level: %d | Zen: %d |",pObj->Level,pObj->Money);
	MsgNormal(ChatID, "[Status]Map: %d X %d Y %d",pObj->MapNumber,pObj->X,pObj->Y); 
	isFind = 1;
	

	}
	if(isFind == 1)
	{
	}
	else
	{
	MsgNormal(ChatID,"[Status] Player: %s  is offline",Player);
	}
}
//========================================================================================================================
// Global Voice
//========================================================================================================================
void ChatGlobalVmsg(int aIndex,char* msg)
	
{
	if(aIndex <= OBJECT_MIN && aIndex >= OBJECT_MAX)
  return;
	if(aIndex > OBJECT_MAX)
  return;
	if(gObjGetItemCountInInventory(aIndex,0x1C67,0) < 1)
	{
	MsgNormal(aIndex,"~[System] You do not have the right stuff!");
	return;
	}
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
  MsgAll("[%s]: %s",gObj->Name,msg);
       gObjDeleteItemsCount(aIndex,0x1C67,0,1);
}
//========================================================================================================================
// Trans Character Command
//========================================================================================================================
void ChatTrans(int aIndex,char* msg)
{	
	int isFind = 0;
	char Player[16]	= {0};
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[Trans] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,9))
	{	
		MsgNormal(aIndex,"[Trans] Only GM from list can use this command.");
		return;
	}
//========================================================================================================================
	sscanf(msg,"%s",Player);
    DWORD PlayerID = SQL.GetaIndexPlayer(Player);
//========================================================================================================================
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
		OBJECTSTRUCT * pObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
		
			gObjTeleport(PlayerID,gObj->MapNumber,gObj->X,gObj->Y);
			isFind = 1;
	
	}

	if(isFind == 1)
	{
	}
	else
	{
	MsgNormal(aIndex,"[Status] Player: %s  is offline",Player);
	}
}
//========================================================================================================================
// SetZen Command
//========================================================================================================================
void SetZenCommand(DWORD ChatID,char *ChatMSG)
{
	char Player[16]	= {0};
	int SetZen	= 0;
	int isFind = 0;
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)OBJECT_POINTER(ChatID);

//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(ChatID,"[Setzen] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,10))
	{	
		MsgNormal(ChatID,"[Setzen] Only GM from list can use this command.");
		return;
	}

//========================================================================================================================
	sscanf(ChatMSG,"%s %d",Player,&SetZen);
	DWORD PlayerID = SQL.GetaIndexPlayer(Player);
//========================================================================================================================
	if((PlayerID>=OBJECT_MIN) && (PlayerID<=OBJECT_MAX))
	{
		int SET_MONEY = SetZen;
		SQL.UpdateZenPlayer(Player,SET_MONEY);
		gObj_Write(PlayerID, gObjZen, SET_MONEY);
		GCMoneySend(PlayerID, gObj_GetInt(ChatID,gObjZen));
		isFind = 1;
	}
	if(isFind == 1)
	{
	MsgNormal(ChatID,"[Setzen] Player: %s have now %d zen",Player,SetZen);
	}
	else
	{
	MsgNormal(ChatID,"[Setzen] Player: %s  is offline",Player);
	}

}


//========================================================================================================================
void ChatDataSend(DWORD gObjId,LPBYTE Protocol)
{
char PostBlockCom[200];
char CommandOffTrCoins[50];
char CommandOffTrZen[50];

   
	char CommandItem[] = "/item";
	char CommandOnli[] = "/online";
	char CommandTrace[] = "/trace ";
	char CommandTrans[] = "/trans ";
	char MSGCommand[] = "/chat ";
	char MSGGMCommand[] = "/gg ";
	char ChatTX[] = "/test";
	//char CommandOffTrZen[] = "/offzen";
	//char CommandOffTrCoins[] = "/offcoin";
	GetPrivateProfileString("OffTrade","OffTradeZenCommand","/offzen",CommandOffTrZen,50,".\\Config\\OffTrade.cfg");
	GetPrivateProfileString("OffTrade","OffTradeCoinCommand","/offcoin",CommandOffTrCoins,50,".\\Config\\OffTrade.cfg");

	char CommandOffExp[] = "/offexp";
	char CommandSkin[] = "/skin ";
	char CommandClearP[] = "/clearpk";
	char CommandPKClear[] = "/pkclear ";
	char CommandSetP[] = "/setpk ";
	char CommmandStatus[] = "/status";
	char CommandPost[] = "/Post ";
	char CommandSetZen[] = "/setzen ";
	char CommandPost1[]  = "/post ";
	char CommandGVoice[] = "/chat ";
	char CommandReset[]  = "/reset";
	GetPrivateProfileString("PostSystem","PostCommand","/post",CommandPost1,15,".\\Config\\Command.cfg");
	char CommandPostB[] = "/blockpost ";
	char SummonSystem[] = "/mob";
	char CommandGmove[] = "/gmove ";
	char CommandQuest[] = "/question";

	char CommandPackLife[] = "/packlife";
	char CommandUnPackLife[] = "/unpacklife";
	char CommandPackChaos[] = "/packchaos";
	char CommandUnPackChaos[] = "/unpackchaos";
	char CommandPackCreation[] = "/packcreation";
	char CommandUnPackCreation[] = "/unpackcreation";
	char CommandPackHarmony[] = "/packharmony";
	char CommandUnPackHarmony[] = "/unpackharmony";
	char CommandPackGuardian[] = "/packguardian";
	char CommandUnPackGuardian[] = "/unpackguardian";
	//char CommandAddBuff[] = "/AddBuff ";
	//char JewelUPC[] = "/jewelup";
	//========================================================================================================================
	//Post Block Command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandPostB,strlen(CommandPostB)))
	{
		PostBlock(gObjId,(char*)Protocol+13+strlen(CommandPostB));
	}
	//========================================================================================================================
	//Post command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandPost,strlen(CommandPost)))
	{
		ChatGlobal(gObjId,(char*)Protocol+13+strlen(CommandPost));
	}
	//========================================================================================================================
	//Gmove command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandGmove,strlen(CommandGmove)))
	{
		ChatGmove(gObjId,(char*)Protocol+13+strlen(CommandGmove));
	}
	//========================================================================================================================
	//Post command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandPost1,strlen(CommandPost1)))
	{
		ChatGlobal(gObjId,(char*)Protocol+13+strlen(CommandPost1));
	}
	//========================================================================================================================
	//Item command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandItem,strlen(CommandItem)))
	{
		ChatDrop(gObjId,(char*)Protocol+13+strlen(CommandItem));
	}
	
	//========================================================================================================================
	//Setzen command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandSetZen,strlen(CommandSetZen)))
	{
		SetZenCommand(gObjId,(char*)Protocol+13+strlen(CommandSetZen));
	}
	//========================================================================================================================
	//Skin command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandSkin,strlen(CommandSkin)))
	{
		SkinCommand(gObjId,(char*)Protocol+13+strlen(CommandSkin));
	}
	//========================================================================================================================
	//Status command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommmandStatus,strlen(CommmandStatus)))
	{
		StatusC(gObjId,(char*)Protocol+13+strlen(CommmandStatus));
	}	
	//========================================================================================================================
	//ClearPK command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandClearP,strlen(CommandClearP)))
	{
		ClearPK(gObjId);
	}

	//========================================================================================================================
	//PKClear command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandPKClear,strlen(CommandPKClear)))
	{
		PKClear(gObjId,(char*)Protocol+13+strlen(CommandPKClear));
	}
	//========================================================================================================================
	//SetPK command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandSetP,strlen(CommandSetP)))
	{
		SetPK(gObjId,(char*)Protocol+13+strlen(CommandSetP));
	}
	//========================================================================================================================
	//Off Trade Zen
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandOffTrZen,strlen(CommandOffTrZen)))
	{
		ChatOffTradeZen(gObjId);
	}
	//========================================================================================================================
	//Off Trade Coins
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandOffTrCoins,strlen(CommandOffTrCoins)))
	{
		ChatOffTradeCoins(gObjId);
	}
    //========================================================================================================================
	//Trace command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandTrace,strlen(CommandTrace)))
	{
		ChatTrace(gObjId,(char*)Protocol+13+strlen(CommandTrace));
	}
	 //========================================================================================================================
	//Trans command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandTrans,strlen(CommandTrans)))
	{
		ChatTrans(gObjId,(char*)Protocol+13+strlen(CommandTrans));
	}

	//========================================================================================================================
	//Online command
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandOnli,strlen(CommandOnli)))
	{
		ChatOnline(gObjId);
	}
	//========================================================================================================================
	//GG Command
	//========================================================================================================================
    if(!memcmp(&Protocol[13],MSGGMCommand,strlen(MSGGMCommand)))
	{
		ChatGMmsg(gObjId,(char*)Protocol+13+strlen(MSGGMCommand));
	}
	//========================================================================================================================
	//Global Voice Command
	//========================================================================================================================
    if(!memcmp(&Protocol[13],CommandGVoice,strlen(CommandGVoice)))
	{
		ChatGlobalVmsg(gObjId,(char*)Protocol+13+strlen(CommandGVoice));
	}
	//========================================================================================================================
	//ChatT MSG Private
	//========================================================================================================================
    if(!memcmp(&Protocol[13],ChatTX,strlen(ChatTX)))
	{
		ChatT(gObjId);
	}
    //========================================================================================================================
	//ChatT MSG Private
	//========================================================================================================================
	 if(!memcmp(&Protocol[13],SummonSystem,strlen(SummonSystem)))
	{
		SummonCommand(gObjId);
	}
	
	//========================================================================================================================
	//Reset System
	//========================================================================================================================
	if(!memcmp(&Protocol[13],CommandReset,strlen(CommandReset)))
	{
		ResetSystem(gObjId);
	}
	//========================================================================================================================
	//Question Event
	//========================================================================================================================
	//if(!memcmp(&Protocol[13],CommandQuest,strlen(CommandQuest)))
	//{
		//g_QSNConfig.Question(gObjId);
	//}

	 
//--------------------------------------------------------------------------------------------------
     // Life Pack & UnPack
	if(!memcmp(&Protocol[13], CommandPackLife,strlen(CommandPackLife)))
	{
		PackLife(gObjId);
	}

	if(!memcmp(&Protocol[13],CommandUnPackLife,strlen(CommandUnPackLife)))
	{
		UnPackLife(gObjId);
	}
//--------------------------------------------------------------------------------------------------
// Chaos Pack & UnPack
	if(!memcmp(&Protocol[13],CommandPackChaos,strlen(CommandPackChaos)))
	{
		PackChaos(gObjId);
	}

	if(!memcmp(&Protocol[13],CommandUnPackChaos,strlen(CommandUnPackChaos)))
	{
		UnPackChaos(gObjId);
	}
//--------------------------------------------------------------------------------------------------
// Harmony Pack & UnPack
	if(!memcmp(&Protocol[13],CommandPackHarmony,strlen(CommandPackHarmony)))
	{
		PackHarmony(gObjId);
	}

	if(!memcmp(&Protocol[13],CommandUnPackHarmony,strlen(CommandUnPackHarmony)))
	{
		UnPackHarmony(gObjId);
	}
//--------------------------------------------------------------------------------------------------
// Guardian Pack & UnPack
	if(!memcmp(&Protocol[13],CommandPackGuardian,strlen(CommandPackGuardian)))
	{
		PackGuardian(gObjId);
	}

	if(!memcmp(&Protocol[13],CommandUnPackGuardian,strlen(CommandUnPackGuardian)))
	{
		UnPackGuardian(gObjId);
	}

//--------------------------------------------------------------------------------------------------
// Creation Pack & UnPack
	if(!memcmp(&Protocol[13],CommandPackCreation,strlen(CommandPackCreation)))
	{
		PackCreation(gObjId);
	}

	if(!memcmp(&Protocol[13],CommandUnPackCreation,strlen(CommandUnPackCreation)))
	{
		UnPackCreation(gObjId);
	}
}