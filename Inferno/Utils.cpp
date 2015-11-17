#include "Windows.h"
#include "Protocol.h"
#include <stdio.h>
#include "USER.h"
#include "GMConf.h"
#include "g_Console.h"
#include "MSSQL.h"
#include <time.h>
#include "Config.h"
#include "Utils.h"
#include "MoveReq.h"
#include "BuffSystem.h"
#include "TvT.h"
#include "Coins.h"
#include "Wings.h"
#include "UltraEvent.h"
#include "ZenEvent.h"
#include "Fidery.h"
#include "ResetSystem.h"
#include "Question.h"
//========================================================================================================================
//Get PK Status
//========================================================================================================================
DWORD gObj_GetPKStatus ( DWORD gObjId )
{

	return *(DWORD*) ( gObjOffset + (gObjSize * gObjId) + gObjPk );

} 
//========================================================================================================================
//Player Connect
//========================================================================================================================
void PlayerConnected(int aIndex,LPBYTE aRecv)
{
	if(aIndex > OBJECT_MAX)
		return;
//========================================================================================================================
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	SYSTEMTIME t;
	GetLocalTime(&t);
	SQL.UpdateaIndexBCharacter(gObj->Name,aIndex);
	int online = 0;
	char Custom1[200];
	char Custom2[200];
	char Custom3[200];
	char Custom4[200];
	char Custom5[200];
	char Custom6[200];
//========================================================================================================================
	for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
	{
      OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER (i);
		if(gObj->Connected == 3)
		online++;
		}
     

//========================================================================================================================
	GetPrivateProfileString("LoginMsg","NameServer","MuOnline",Custom4,200,".\\Config\\Login.cfg");
	GetPrivateProfileString("LoginMsg","NameServer2","MuOnline",Custom5,200,".\\Config\\Login.cfg");
	GetPrivateProfileString("LoginMsg","HomePage","www.muonline.ru",Custom6,200,".\\Config\\Login.cfg");
		int LoginConnect = GetPrivateProfileInt("LoginMsg","LoginConnectAct",1,".\\Config\\Login.cfg");
		int ConsoleOut = GetPrivateProfileInt("LoginMsg","ConsoleOut",1,".\\Config\\Login.cfg");
		int LoginMsgG = GetPrivateProfileInt("LoginMsg","LoginM",1,".\\Config\\Login.cfg");
		int onlinepl = GetPrivateProfileInt("LoginMsg","OnlinePlus",50,".\\Config\\Login.cfg");
		int onlinemax = GetPrivateProfileInt("LoginMsg","OnlineMax",50,".\\Config\\Login.cfg");
//========================================================================================================================
	    if (LoginMsgG == 1)
		{
     	MsgNormal(aIndex,"[%s] Wellcome to %s %s",Custom4,Custom5,gObj->Name);
		MsgNormal(aIndex,"[%s] Time : %d:%d:%d / %d.%d.%d",Custom4,t.wHour,t.wMinute,t.wSecond,t.wDay,t.wMonth,t.wYear);
		MsgNormal(aIndex,"[%s] Players Online: %d/500",Custom4,online+onlinepl);
		MsgNormal(aIndex,"[%s] Home Page: %s",Custom4,Custom6);
		}
//========================================================================================================================
		if (LoginConnect == 1)
		{
		MsgAllNormal(aIndex,"@[%s]%s Connected!",Custom4,gObj->Name);	
		}
//========================================================================================================================
		if (ConsoleOut == 1)
		{
		g_Console.ConsoleOutput(5,"[ Connect Info ] '%s' Connected The Game",gObj->Name);
		}
//========================================================================================================================	
		gObj->OffTradeCoin = 0;
		gObj->OffTradeZen = 0;
		gObj->GreatFBuff = 0;
		gObj->SoulBarBuff = 0;
		gObj->CriticDmBuff = 0;
		gObj->HealBuff = 0;
		gObj->GreatDefBuff = 0;
		gObj->GreatDamBuff = 0;


//========================================================================================================================	
		
	 }
//========================================================================================================================
//ClickOnNPC
//========================================================================================================================
bool ClickOnNPC(int aIndex,LPBYTE aRecv)
{
	if(aIndex > OBJECT_MAX)
		return true;

	if((aRecv[4] + aRecv[3] * 256) > OBJECT_MAX)
		return true;

	OBJECTSTRUCT *gObjNPC = (OBJECTSTRUCT*)OBJECT_POINTER((aRecv[4] + aRecv[3] * 256));




		int B1CordX = GetPrivateProfileInt("BuffSystem1","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B1CordY = GetPrivateProfileInt("BuffSystem1","CordY",100000,".\\Config\\BuffSystem.cfg");
		int B2CordX = GetPrivateProfileInt("BuffSystem2","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B2CordY = GetPrivateProfileInt("BuffSystem2","CordY",100000,".\\Config\\BuffSystem.cfg");
		int B3CordX = GetPrivateProfileInt("BuffSystem3","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B3CordY = GetPrivateProfileInt("BuffSystem3","CordY",100000,".\\Config\\BuffSystem.cfg");
		int B4CordX = GetPrivateProfileInt("BuffSystem4","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B4CordY = GetPrivateProfileInt("BuffSystem4","CordY",100000,".\\Config\\BuffSystem.cfg");
		int B5CordX = GetPrivateProfileInt("BuffSystem5","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B5CordY = GetPrivateProfileInt("BuffSystem5","CordY",100000,".\\Config\\BuffSystem.cfg");
		int B6CordX = GetPrivateProfileInt("BuffSystem6","CordX",100000,".\\Config\\BuffSystem.cfg");
		int B6CordY = GetPrivateProfileInt("BuffSystem6","CordY",100000,".\\Config\\BuffSystem.cfg");
        int C1CordX = GetPrivateProfileInt("Coin_1","CordX",100000,".\\Config\\Coins.cfg");
		int C1CordY = GetPrivateProfileInt("Coin_1","CordY",100000,".\\Config\\Coins.cfg");
		int C2CordX = GetPrivateProfileInt("Coin_2","CordX",100000,".\\Config\\Coins.cfg");
		int C2CordY = GetPrivateProfileInt("Coin_2","CordY",100000,".\\Config\\Coins.cfg");
		int C3CordX = GetPrivateProfileInt("Coin_3","CordX",100000,".\\Config\\Coins.cfg");
		int C3CordY = GetPrivateProfileInt("Coin_3","CordY",100000,".\\Config\\Coins.cfg");
		int ZECordX = GetPrivateProfileInt("ZenEvent","CordX",100,".\\Custom.ini");
		int ZECordY = GetPrivateProfileInt("ZenEvent","CordY",100,".\\Custom.ini");
		int ZEMapN  = GetPrivateProfileInt("ZenEvent","MaNumber",0,".\\Custom.ini");

		int ResetNPCX = GetPrivateProfileInt("ResetNPC","NpcX",145,".\\Config\\ResetSystem.cfg");
		int ResetNPCY = GetPrivateProfileInt("ResetNPC","NpcY",140,".\\Config\\ResetSystem.cfg");


	if(gObjNPC->Class == 247 && gObjNPC->X == B1CordX && gObjNPC->Y == B1CordY )
	{
		BuffSystem1(aIndex);
		GCMagicAttackNew(gObjNPC,48,gObjNPC->m_Index,1);
		
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == B2CordX && gObjNPC->Y == B2CordY )
	{
		BuffSystem2(aIndex);
		GCMagicAttackNew(gObjNPC,16,gObjNPC->m_Index,1);
		
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == B3CordX && gObjNPC->Y == B3CordY )
	{
		BuffSystem3(aIndex);
		GCMagicAttackNew(gObjNPC,64,gObjNPC->m_Index,1);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == B4CordX && gObjNPC->Y == B4CordY )
	{
		BuffSystem4(aIndex);
		GCMagicAttackNew(gObjNPC,26,gObjNPC->m_Index,1);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == B5CordX && gObjNPC->Y == B5CordY )
	{
		BuffSystem5(aIndex);
		GCMagicAttackNew(gObjNPC,27,gObjNPC->m_Index,1);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == B6CordX && gObjNPC->Y == B6CordY )
	{
		BuffSystem6(aIndex);
		GCMagicAttackNew(gObjNPC,28,gObjNPC->m_Index,1);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == ResetNPCX && gObjNPC->Y == ResetNPCY )
	{
		ResetSystem(aIndex);
	}
	
//	if(gObjNPC->Class == 247 && gObjNPC->X == ZECordX && gObjNPC->Y == ZECordY && gObjNPC->MapNumber == ZEMapN )
//	{
//		ZenDrop(aIndex);
//	}
	

/*	if(gObjNPC->Class == 247 && gObjNPC->X == C1CordX && gObjNPC->Y == C1CordY )
	{
		Coin1(aIndex);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == C2CordX && gObjNPC->Y == C2CordY )
	{
		Coin2(aIndex);
	}
	if(gObjNPC->Class == 247 && gObjNPC->X == C3CordX && gObjNPC->Y == C3CordY )
	{
		Coin3(aIndex);
	}

	*/

	if (gObjNPC->Class == 385) //Illusion Temple
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		gObj->TargetNumber = gObjNPC->Class;
	}

	return false;
}
//========================================================================================================================
//gObjViewProtocolListCreateHook
//========================================================================================================================
void gObjViewProtocolListCreateHook(OBJECTSTRUCT* gObj)
{	
	gObjViewportListProtocolCreate(gObj);
	
}

void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
	lpBuf[0] =0xC1; // Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC1;		// Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
}
//========================================================================================================================
//gObj_Write
//========================================================================================================================
void gObj_Write(int PlayerID,int gObjParam,long int Value)
{
	*(long int*)(PlayerID * OBJECT_SIZE + OBJECT_BASE + gObjParam)=Value;
}
//========================================================================================================================
//SetDrop
//========================================================================================================================
void SetDrop(DWORD Drop)
{
	__asm
	{
		MOV EAX,Drop
		MOV DWORD PTR DS:[0x0077FEFC],EAX
	}
}
//========================================================================================================================
//GobjByNick
//========================================================================================================================
//Retornar Char Index   
DWORD gObjByNick (char * nick)   
{   
    for (DWORD i = OBJECT_MIN ; i< OBJECT_MAX ; i++)   
    {   
        char * Name = (char*)(gObjOffset + (gObjSize * i)+ gObjNick);   
        if (memcmp (nick , Name, 10)== 0)   
        {   
            return i;   
        }   
    }   
   return 0xFFFF;   
} 

//========================================================================================================================
//MaxLifeReFillSend
//========================================================================================================================
void MaxLifeReFillSend(DWORD PlayerID)
{

		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);

		DWORD MaxLife = gObj->MaxLife + gObj->AddLife;
		DWORD MaxSh = gObj->iMaxShield + gObj->iAddShield;
		char buff[9]={0xC1,0x09,0x26,0xFE,HIBYTE(MaxLife),LOBYTE(MaxLife),0x03,HIBYTE(MaxSh),LOBYTE(MaxSh)};
		DataSend( PlayerID , (PBYTE)buff , buff[1] );
	
}
//========================================================================================================================
//LogNotice
//========================================================================================================================
void LogNotice(int type,char* szMsg,...)
{
	char szTemp[1024];

	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);

	LogAddFuncColor(type,szTemp);
}
void HookOffset(DWORD my, DWORD tohook, BYTE type)
{
 *(BYTE*)tohook = type;
 *(DWORD*)(tohook+1) = my - (tohook+5);
}
//========================================================================================================================
// GameServer Window 
//========================================================================================================================
void  TitleGS()
{
	char cTemp[30] = "[Developed Server]";
    DWORD *offsetGSTitle = (DWORD*)(GameServerTitle);
    memset(&offsetGSTitle[0],0,30);
    memcpy(&offsetGSTitle[0],cTemp,strlen(cTemp));
	
}
//========================================================================================================================
// GetPlayerAddress
//========================================================================================================================
void *GetPlayerAddress(unsigned int PlayerID)
{
	return(void*)(OBJECT_BASE + (PlayerID * OBJECT_SIZE));
}
//========================================================================================================================
// GetPlayerClass
//========================================================================================================================
WORD GetPlayerClass(DWORD PlayerID)
{
	BYTE *Player=(BYTE*)GetPlayerAddress(PlayerID);
	WORD Class=0;
	memcpy(&Class,Player+gObjClass,sizeof(WORD));
	return Class;
}
//========================================================================================================================
// gObj_GetInt
//========================================================================================================================
long int gObj_GetInt(int PlayerID, int gObjParam)
{
	return *(long int*)(PlayerID * OBJECT_SIZE + OBJECT_BASE + gObjParam);
}
//========================================================================================================================
//DataSendMap
//========================================================================================================================
void DataSendMap(int Map, unsigned char* Packet, int Len)
{
	OBJECTSTRUCT* gObj;
	for (int i=OBJECT_MIN; i<OBJECT_MAX; i++)

	if (gObj[i].Connected == PLAYER_PLAYING)
	{
		if (gObj[i].MapNumber == Map)
		{	
			DataSend(i, Packet, Len);
		}
	}
}
//========================================================================================================================
//DataSendAllNear
//========================================================================================================================
void DataSendAllNear(int PlayerID, PBYTE Protocol, DWORD ProtocolLen, int dist)
{
	BYTE *me_map  = (BYTE*) ((PlayerID * OBJECT_SIZE) + (OBJECT_BASE + gObjMapID));
	BYTE *me_posx = (BYTE*) ((PlayerID * OBJECT_SIZE) + (OBJECT_BASE + gObjPosX));
	BYTE *me_posy = (BYTE*) ((PlayerID * OBJECT_SIZE) + (OBJECT_BASE + gObjPosY));

	for ( int i = OBJECT_MIN ; i < OBJECT_MAX ; i ++ )
	{
		BYTE *map  = (BYTE*) ((i * OBJECT_SIZE) + (OBJECT_BASE + gObjMapID));
		BYTE *posx = (BYTE*) ((i * OBJECT_SIZE) + (OBJECT_BASE + gObjPosX));
		BYTE *posy = (BYTE*) ((i * OBJECT_SIZE) + (OBJECT_BASE + gObjPosY));
		
		if (*map == *me_map)
		{
			if (( *posx <= *me_posx + dist) && (*posx >= *me_posx - dist ))
			{
				if (( *posy <= *me_posy + dist) && (*posy >= *me_posy - dist ))
				{
					DataSend(i,(PBYTE)Protocol,ProtocolLen);
				}
			}
		}
	}
}
//========================================================================================================================
//CallSkillEffect
//========================================================================================================================
void CallSkillEffect(DWORD PlayerID,BYTE Skill, BYTE Status,DWORD MobID,int isSkill,int SendType)
{
	if(isSkill == 1)
	{
		BYTE pNewProtocol[7]={0xC1,0x07,0x07,Status,HIBYTE(MobID),LOBYTE(MobID),Skill};

		if(SendType == 0)
			DataSend(PlayerID,pNewProtocol,pNewProtocol[1]);
		if(SendType == 1)
			DataSendAllNear(PlayerID,pNewProtocol,pNewProtocol[1],16);
		if(SendType == 2)
			DataSendMap(PlayerID,pNewProtocol,pNewProtocol[1]);
		if(SendType == 3)
			DataSendAll(pNewProtocol,pNewProtocol[1]);
	}
	
	else if(isSkill == 2)
	{
		char sBuff[9] = {0xC1, 0x09, 0x2D, 0x00, 0x01, 0x00, Skill, 0x00, Status};
		DataSend(PlayerID,(PBYTE)sBuff,sBuff[1]);
	}
}

void GetCustomInfoClient(DWORD PlayerID,LPBYTE aRecv)
{
		OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);

		DWORD GMCode = gObj->Authority;
		DWORD Name = (DWORD)gObj->Name;
		DWORD Exp = gObj->Experience;
		DWORD NextExp = gObj->NextExp;
char sBuff[7] = {0xC1, 0xF9, 0x01,GMCode,Name,Exp,NextExp};
		DataSend(PlayerID,(PBYTE)sBuff,sBuff[1]);

}
//========================================================================================================================
//MsgNormal
//========================================================================================================================
void MsgNormal(int aIndex,char* szMsg,...)
{
	char szTemp[1024];

	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);
	
	GCServerMsgStringSend(szTemp, aIndex,1);


}
//========================================================================================================================
//MsgAllNormal
//========================================================================================================================
void MsgAllNormal(int aIndex,char* szMsg,...)
{
	char Message[1024];
	va_list pArguments;
    va_start(pArguments,szMsg);
	vsprintf_s(Message,sizeof(Message), szMsg, pArguments);
	va_end(pArguments);
	BYTE *Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	*(Packet+2) = 0x00;
	memcpy((Packet+13), Message, strlen(Message));
	int Len = (strlen(Message) + 0x13);
	*(Packet+1) = Len;
	DataSendAll(Packet, Len);
	free (Packet);
	}
//========================================================================================================================
//BuxConvert
//========================================================================================================================
void BuxConvert(char* buf, int size)
{
	int n;

	for (n=0;n<size;n++)
	{
		buf[n]^=bBuxCode[n%3] ;		// Nice trick from WebZen
	}
}
//========================================================================================================================
//MessageAll
//========================================================================================================================
void MessageAll(const char *Format, ...)
{
	char Message[1024];
	va_list pArguments;
	va_start(pArguments, Format);
	vsprintf(Message, Format, pArguments);
	va_end(pArguments);
	BYTE *Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	*(Packet+2) = 0x00;
	memcpy((Packet+13), Message, strlen(Message));
	int Len = (strlen(Message) + 0x13);
	*(Packet+1) = Len;
	DataSendAll(Packet, Len);
	free (Packet);
}
//========================================================================================================================
//SendBar Message
//========================================================================================================================
void SendBarMessage(DWORD PlayerID,int Color,LPCTSTR szText)
{
	#define	MAX_PACKET_LEN		0xFF

	BYTE buff[MAX_PACKET_LEN-0x0e];
	FillMemory(buff,(MAX_PACKET_LEN-0x0e),0x20);
	BYTE Len=(BYTE)strlen(szText);

	buff[0]=0xC1;
	buff[1]=Len+0x0E;
	buff[2]=0x0D;
	buff[3]=0x0A;
	buff[4]=0x01;
	buff[5]=0x01;
	buff[6]=0x00;
	buff[7]=0x00;

	switch(Color){
	case 1: // Vermelhor
		buff[8]		=	255; //R
		buff[9]		=	0;	 //G
		buff[10]	=	0;	 //B	
		break;
	case 2:
		buff[8]		=	0;	 //R
		buff[9]		=	255; //G
		buff[10]	=	0;   //B
		break;
	case 3:
		buff[8]		=	255; //R
		buff[9]		=	0;	 //G
		buff[10]	=	0;	 //B
		break;
	case 4:
		buff[8]		=	0;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;
	case 5:
		buff[8]		=	255;
		buff[9]		=	0;
		buff[10]	=	255;		
		break;
	case 6:
		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	0;		
		break;
	case 7:
		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;
	default:
		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;
	}

	buff[11]=0xFF;
	buff[12]=0x14;

	strncpy((char*)&buff[0x0d],szText,Len);

	buff[Len+0x0d]=0;

}
//========================================================================================================================
//AllServerMSg Send
//========================================================================================================================
void AllServerMsgSend(char *message)
{
	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
		if(gObj->Connected == 3)
			GCServerMsgStringSend(message, i, 0);
	}
}
//========================================================================================================================
//Msg All
//========================================================================================================================
void MsgAll(char* szMsg,...)
{
	char szTemp[1024];

	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);

	AllServerMsgSend(szTemp);
}
//========================================================================================================================
//Item Clear 
//========================================================================================================================
void ItemClear(int aIndex,int pos)	// Fine
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	gObj->pInventory[pos].m_Type =-1;
	gObj->pInventory[pos].m_Level =0;
	gObj->pInventory[pos].m_Part=0;
	gObj->pInventory[pos].m_Class=0;
	gObj->pInventory[pos].m_TwoHand=0;
	gObj->pInventory[pos].m_AttackSpeed=0;
	gObj->pInventory[pos].m_DamageMin=0;
	gObj->pInventory[pos].m_DamageMax=0;
	gObj->pInventory[pos].m_SuccessfulBlocking=0;
	gObj->pInventory[pos].m_Defense=0;
	gObj->pInventory[pos].m_MagicDefense =0;
	gObj->pInventory[pos].m_Durability=0;
	gObj->pInventory[pos].m_SpecialNum=0;
	gObj->pInventory[pos].m_Value=0;
	gObj->pInventory[pos].m_Option1 =0;
	gObj->pInventory[pos].m_Option2 =0;
	gObj->pInventory[pos].m_Option3 =0;
	gObj->pInventory[pos].m_NewOption =0;
	gObj->pInventory[pos].m_Number =0;
	gObj->pInventory[pos].m_DurabilitySmall =0;
	gObj->pInventory[pos].m_iPShopValue=-1;
	gObj->pInventory[pos].m_bItemExist=true;
	gObj->pInventory[pos].m_CurrentDurabilityState=-1;
	gObj->pInventory[pos].m_SetOption=0;
	gObj->pInventory[pos].m_QuestItem=false;

	memset(gObj->pInventory[pos].m_Special, 0, sizeof(gObj->pInventory[pos].m_Special));
	memset(gObj->pInventory[pos].m_SpecialValue, 0, sizeof(gObj->pInventory[pos].m_SpecialValue));
	memset(gObj->pInventory[pos].m_Resistance, 0, sizeof(gObj->pInventory[pos].m_Resistance));

	gObj->pInventory[pos].m_IsLoadPetItemInfo=0;
	gObj->pInventory[pos].m_PetItem_Level =1;
	gObj->pInventory[pos].m_PetItem_Exp =0;
	gObj->pInventory[pos].m_Leadership=0;
	gObj->pInventory[pos].m_JewelOfHarmonyOption = 0;
	gObj->pInventory[pos].m_ItemOptionEx = 0;
}
//========================================================================================================================
//Item Clear 1
//========================================================================================================================
void ItemClear1(int aIndex,int pos)	// Fine
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	gObj->pInventory1[pos].m_Type =-1;
	gObj->pInventory1[pos].m_Level =0;
	gObj->pInventory1[pos].m_Part=0;
	gObj->pInventory1[pos].m_Class=0;
	gObj->pInventory1[pos].m_TwoHand=0;
	gObj->pInventory1[pos].m_AttackSpeed=0;
	gObj->pInventory1[pos].m_DamageMin=0;
	gObj->pInventory1[pos].m_DamageMax=0;
	gObj->pInventory1[pos].m_SuccessfulBlocking=0;
	gObj->pInventory1[pos].m_Defense=0;
	gObj->pInventory1[pos].m_MagicDefense =0;
	gObj->pInventory1[pos].m_Durability=0;
	gObj->pInventory1[pos].m_SpecialNum=0;
	gObj->pInventory1[pos].m_Value=0;
	gObj->pInventory1[pos].m_Option1 =0;
	gObj->pInventory1[pos].m_Option2 =0;
	gObj->pInventory1[pos].m_Option3 =0;
	gObj->pInventory1[pos].m_NewOption =0;
	gObj->pInventory1[pos].m_Number =0;
	gObj->pInventory1[pos].m_DurabilitySmall =0;
	gObj->pInventory1[pos].m_iPShopValue=-1;
	gObj->pInventory1[pos].m_bItemExist=true;
	gObj->pInventory1[pos].m_CurrentDurabilityState=-1;
	gObj->pInventory1[pos].m_SetOption=0;
	gObj->pInventory1[pos].m_QuestItem=false;

	memset(gObj->pInventory1[pos].m_Special, 0, sizeof(gObj->pInventory1[pos].m_Special));
	memset(gObj->pInventory1[pos].m_SpecialValue, 0, sizeof(gObj->pInventory1[pos].m_SpecialValue));
	memset(gObj->pInventory1[pos].m_Resistance, 0, sizeof(gObj->pInventory1[pos].m_Resistance));

	gObj->pInventory1[pos].m_IsLoadPetItemInfo=0;
	gObj->pInventory1[pos].m_PetItem_Level =1;
	gObj->pInventory1[pos].m_PetItem_Exp =0;
	gObj->pInventory1[pos].m_Leadership=0;
	gObj->pInventory1[pos].m_JewelOfHarmonyOption = 0;
	gObj->pInventory1[pos].m_ItemOptionEx = 0;
}
//========================================================================================================================
//IsExistWingItem
//========================================================================================================================
int IsExistWingItem(int aIndex)
{
 DWORD pInvOffset = *LPDWORD((*(char**)OBJECT_BASE)+OBJECT_SIZE*aIndex+0xE7C);
 return *LPDWORD(pInvOffset + 0x52A);
}
//========================================================================================================================
//IsExistPetItem
//========================================================================================================================
int IsExistPetItem(int aIndex)
{
 DWORD pInvOffset = *LPDWORD((*(char**)OBJECT_BASE)+OBJECT_SIZE*aIndex+0xE7C);
 return *LPDWORD(pInvOffset + 0x5E6);
}
//========================================================================================================================
//Msg Yellow
//========================================================================================================================
void MsgYellow(int aIndex,char* szMsg,...)
{
	char szTemp[1024];
	BYTE *Packet;

	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);

	Packet = (BYTE*)malloc(200);
	memset(Packet,0x00,200);
	*Packet=0xC1;
	*(Packet+2)=0x02;

	memcpy((Packet+13),szTemp,strlen(szTemp));

	int Len=(strlen(szTemp)+0x13);
	*(Packet+1)=Len;

	DataSend(aIndex,Packet,Len);
	free(Packet);
}


//========================================================================================================================
//gObjCharacterWingsSetPreview
//========================================================================================================================
void gObjCharacterWingsSetPreview(short ItemType, unsigned char *CharSet) 
{
	switch(ItemType)
	{
	case 0x1824:
		CharSet[16] = WINGS_OF_STORM;
		break;
	case 0x1825:
		CharSet[16] = WINGS_OF_VORTEX;
		break;
	case 0x1826:
		CharSet[16] = WINGS_OF_ILLUSION;
		break;
	case 0x1827:
		CharSet[16] = WINGS_OF_HURRICANE;
		break;
	case 0x1828:
		CharSet[16] = MANTLE_OF_MONARCH;
		break;
	case 0x1829:
		CharSet[16] = WINGS_OF_MISERY;
		break;
	case 0x182A:
		CharSet[16] = WINGS_OF_DESPAIR;
		break;
	case 0x182B:
		CharSet[16] = WINGS_OF_DIMENSION;
		break;
	}
}
//========================================================================================================================
//gObjViewportExecute
//========================================================================================================================
void __stdcall gObjViewportExecute(OBJECTSTRUCT *lpObj) 
{
	if(lpObj->pInventory[WINGS].m_Type != SLOT_EMPTY)
	    gObjCharacterWingsSetPreview(lpObj->pInventory[WINGS].m_Type, lpObj->CharSet);
}
//========================================================================================================================
//Role
//========================================================================================================================
unsigned char Role(unsigned char range) {
	srand(static_cast<int>(time(NULL)));
	return (rand() % range);
}
//========================================================================================================================
//TakeExcNum
//========================================================================================================================
int TakeExcNum(int Exc)
{
	int Count = 0;
	for(int j = 0; j < 6; j++)
	{
		if((Exc>>j)&1)
			Count++;
	}
	return Count;
}
//========================================================================================================================
//MyObjCalCharacter
//========================================================================================================================
void MyObjCalCharacter(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	j_gObjCalCharacter(aIndex);

	if ( gObj->pInventory[7].m_Type == ITEMGET(12,41))
	{
		
		gObj->AddLife += 1000;	//Life +1000
	    gObj->Life +=1000;      //Life +1000 
		gObj->AddMana += 1000;	//Mana +1000
		gObj->Mana +=1000;      //Mana +1000
		//gObj->MaxMana +=1000;   //Mana +1000
		gObj->BP   +=1000; //SD +1000
	    gObj->AddBP +=1000;     //Stamina +1000
		gObj->iMaxShield +=1000;
	
		LifeReFill(gObj->m_Index,WORD(gObj->MaxLife + gObj->AddLife),0xFE,0,gObj->iMaxShield + gObj->iAddShield);


	}
	if ( gObj->pInventory[7].m_Type == ITEMGET(12,42))
	{
		
		gObj->AddMana += 1000;	//Mana +1000
		gObj->Mana +=1000;      //Mana +1000
		//gObj->MaxMana +=1000;   //Mana +1000
		gObj->BP   +=1000; //SD +1000
	    gObj->AddBP +=1000;     //Stamina +1000
		gObj->iMaxShield +=1000;
		gObj->m_AttackSpeed +=1000;

		LifeReFill(gObj->m_Index,WORD(gObj->MaxLife + gObj->AddLife),0xFE,0,gObj->iMaxShield + gObj->iAddShield);


	}
}
//========================================================================================================================
//GSEquiItem
//========================================================================================================================
void GSEquiItem(int aIndex,unsigned char* aSend)
{
	if(aIndex > OBJECT_MAX)
		return;

	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(aSend[4] == WINGS || aSend[4] == WINGS )
	{
		if(gObj->pInventory[WINGS].m_Type == 0x1A7A && gObj->m_Change != 548 || gObj->pInventory[WINGS].m_Type == 0x1A7A) //SKeleton Ring
		{
		gObj->AddLife += 1000;	//Life +1000
		gObj->AddMana += 1000;	//Mana +1000
		gObj->Life +=1000;      //Life +1000 
		gObj->Mana +=1000;      //Mana +1000
		//gObj->MaxMana +=1000;   //Mana +1000
		gObj->BP   +=1000; //SD +1000
	    gObj->AddBP +=1000;     //Stamina +1000
		gObj->iMaxShield +=1000;
	

		LifeReFill(gObj->m_Index,WORD(gObj->MaxLife + gObj->AddLife),0xFE,0,gObj->iMaxShield + gObj->iAddShield);
	
		}


	}



}
//========================================================================================================================
//GetRandomExcOption
//========================================================================================================================
unsigned char GetRandomExcOption(BYTE btMaxOptions, BOOL bAllowNoOpts)
{
	BYTE btRandOpt;
	BYTE btRandOpts;
	BYTE btItemOpts = 0x00;

	while (true)
	{
		btRandOpts = rand() % (btMaxOptions + 1);

		if (btRandOpts == 0 && bAllowNoOpts == FALSE)
		{
			continue;
		}

		break;
	}

	for (int i=0; i<btRandOpts; i++)
	{
		btRandOpt = rand() % 6;

		if (((btItemOpts >> btRandOpt) & 1) == 0)
		{
			btItemOpts |= (1 << btRandOpt);
		}
	}

	return btItemOpts;
}
//========================================================================================================================
//MobRelogDelete
//========================================================================================================================
void MobRelogDelete(int aIndex)
{
		if(aIndex > OBJECT_MAX)
		return;
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);


}


//========================================================================================================================
//Server_UpdateTimer
//========================================================================================================================
void Server_UpdateTimer(void * lpParam)
{
	while(true)
	{
		Sleep(10000); //1 Minute (60*1000)

		SYSTEMTIME t;
		GetLocalTime(&t);
		//UltraEventCheckTime(t.wHour,t.wMinute);
		//ZenCheck(t.wHour,t.wMinute);
	
	}
	_endthread();
}
//========================================================================================================================
//gObjLifeCheckHook
//========================================================================================================================
void gObjLifeCheckHook(OBJECTSTRUCT* mObj, OBJECTSTRUCT* pObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage)
{
	char FileName[] = ".\\Custom.ini";
	

	if(mObj->Life <= 0 && mObj->Live != 0)
	{	
		//If it is a mob, logic, yes :D
		if(mObj->Type == OBJECT_MONSTER)
		{	
			//
		

		}
	
	}


	gObjLifeCheck(mObj,pObj,AttackDamage,DamageSendType,MSBFlag,MSBDamage,Skill,iShieldDamage);
}
//========================================================================================================================
//gObjMissCheckHook
//========================================================================================================================
void gObjMissCheckHook(OBJECTSTRUCT* lpObj, OBJECTSTRUCT* lpTargetObj, int skill, int skillSuccess, int magicsend, BOOL& bAllMiss)
{
	gObjMissCheck(lpObj,lpTargetObj,skill,skillSuccess,magicsend,bAllMiss);
}

void PHeadSetBE( LPBYTE lpBuf, BYTE head,int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
}
void gObjAttackS(OBJECTSTRUCT* gObj,OBJECTSTRUCT* tObj,class CMagicInf * value1,int value2,unsigned char value3,int value4,int value5)
{	
gObjAttack(gObj,tObj,value1,value2,value3,value4,value5);

	
}
// -----------------------------------------------------------------------------------------------------------------------
void SendSrvData(int PosX, int PosY, unsigned char* Packet, int Len)
{
	OBJECTSTRUCT *gObj;
	OBJECTSTRUCT *ObjTab;
	for (int i=MIN_PLAYERID; i<MAX_PLAYERID; i++)
	{
		if (gObj[i].Connected == PLAYER_PLAYING)
		{
			if (gObj[i].X > (PosX - 20) && gObj[i].X < (PosX + 20))
			{
				if (ObjTab[i].Y > (PosY - 20) && ObjTab[i].Y < (PosY + 20))
				{
					DataSend(i, Packet, Len);
				}
			}
		}
	}
}
void MsgSendV2(OBJECTSTRUCT* gObj, unsigned char* Msg, int size)
{
	for ( int n=0;n<75;n++)
	{
		if ( gObj->VpPlayer2[n].type == OBJECT_USER )
		{
			if ( gObj->VpPlayer2[n].state != 0 )
			{
				DataSend(gObj->VpPlayer2[n].number, Msg, size);
			}
		}
	}
}
void  GCMagicAttackNumberSendH(OBJECTSTRUCT*  gObj, BYTE MagicNumber, int usernumber,  unsigned char skillsuccess)
{
	PMSG_MAGICATTACK_RESULT pAttack;
	
	PHeadSetBE((LPBYTE)&pAttack, 0x19, sizeof(pAttack));
	pAttack.MagicNumber = MagicNumber;
	pAttack.SourceNumberH = SET_NUMBERH(gObj->m_Index);
	pAttack.SourceNumberL = SET_NUMBERL(gObj->m_Index);
	pAttack.TargetNumberH = SET_NUMBERH(usernumber);
	pAttack.TargetNumberL = SET_NUMBERL(usernumber);
	pAttack.TargetNumberH &= 0x7F;

	if ( skillsuccess )
		pAttack.TargetNumberH |= 0x80;


	DataSend(gObj->m_Index, (LPBYTE)&pAttack, pAttack.h.size);
	MsgSendV2(gObj, (LPBYTE)&pAttack, pAttack.h.size);
}
void GCTeleportSend(OBJECTSTRUCT* gObj, int MoveNumber, BYTE MapNumber, BYTE MapX, BYTE MapY, BYTE Dir) 
{
	PMSG_TELEPORT_RESULT pMsg;



	if(MoveNumber > 0) //Season 2.5 add-on
	{
		MoveNumber = 1;
	}

	pMsg.h.c = 0xC3;
	pMsg.h.size = sizeof(pMsg);
	pMsg.h.headcode = 0x1C;
	pMsg.MoveNumber = MoveNumber;
	pMsg.MapNumber = MapNumber;
	pMsg.MapX = MapX;
	pMsg.MapY = MapY;
	pMsg.Dir = Dir;

	if ( MoveNumber == 0 )
	{
		DataSend(gObj->m_Index, (LPBYTE)&pMsg, pMsg.h.size);
	}
	else
	{
		DataSend(gObj->m_Index, (LPBYTE)&pMsg, pMsg.h.size);
	}
}
void gObjAttackRecv(OBJECTSTRUCT* gObj,OBJECTSTRUCT* tObj,class CMagicInf * value1,int value2,unsigned char value3,int value4,int value5)
{	


	gObjAttack(gObj,tObj,value1,value2,value3,value4,value5);

	
}
void gObjStateAttackProcHook(OBJECTSTRUCT *gObj, int aMsgCode, int aIndex, int SubCode, int SubCode2)
{
	if ( aIndex > OBJECT_MAX )
		return;

	if(aMsgCode == 54)
	{
		int DaDmg = (gObj->Energy/10)+50;
		int Strength = gObj->Strength + gObj->AddStrength;
		int Dexterity = gObj->Dexterity + gObj->AddDexterity;
		int Vitality = gObj->Vitality + gObj->AddVitality;

		gObj->m_AttackDamageMinRight = (Vitality / 15) + (Strength / 7) + (gObj->m_AttackDamageMinRight*DaDmg)/1000;
		gObj->m_AttackDamageMaxRight = (Vitality / 12) + (Strength / 5) +(gObj->m_AttackDamageMaxRight*DaDmg)/1000;
		gObj->m_AttackDamageMinLeft = (Vitality / 15) + (Strength / 7) + (gObj->m_AttackDamageMinLeft*DaDmg)/1000;
		gObj->m_AttackDamageMaxLeft = (Vitality / 12) + (Strength / 5) + (gObj->m_AttackDamageMaxLeft*DaDmg)/1000;

		gObj->m_MagicDamageMin = gObj->m_AttackDamageMinRight;
		gObj->m_MagicDamageMax = gObj->m_AttackDamageMaxRight;

		OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		gObjAttackRecv(gObj,tObj,gObj->Magic,0,1,0,0);

		BYTE sBuff2[10]={0xC3,0x09,0x19,0x01,0x08,0x24,0x0B,HIBYTE(tObj->m_Index),LOBYTE(tObj->m_Index)};
		DataSend(gObj->m_Index,(PBYTE)sBuff2,sBuff2[1]);
		MsgSendV2(gObj, (LPBYTE)&sBuff2,sBuff2[1]);

		
		return;
	}

	if(aMsgCode == 55)
	{
		int DaDmg = ((gObj->Dexterity-27)/8)+((gObj->Energy-20)/10)+105;
		int Strength = gObj->Strength + gObj->AddStrength;
		int Dexterity = gObj->Dexterity + gObj->AddDexterity;
		int Vitality = gObj->Vitality + gObj->AddVitality;

		gObj->m_AttackDamageMinRight = (Vitality / 15) + (Strength / 7) + (gObj->m_AttackDamageMinRight*DaDmg)/1000;
		gObj->m_AttackDamageMaxRight = (Vitality / 12) + (Strength / 5) +(gObj->m_AttackDamageMaxRight*DaDmg)/1000;
		gObj->m_AttackDamageMinLeft = (Vitality / 15) + (Strength / 7) + (gObj->m_AttackDamageMinLeft*DaDmg)/1000;
		gObj->m_AttackDamageMaxLeft = (Vitality / 12) + (Strength / 5) + (gObj->m_AttackDamageMaxLeft*DaDmg)/1000;

		gObj->m_MagicDamageMin = gObj->m_AttackDamageMinRight;
		gObj->m_MagicDamageMax = gObj->m_AttackDamageMaxRight;

		OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		gObjAttackRecv(gObj,tObj,gObj->Magic,0,1,0,0);

		BYTE sBuff2[10]={0xC3,0x09,0x19,0x01,0x07,0x24,0x0B,HIBYTE(tObj->m_Index),LOBYTE(tObj->m_Index)};

		
		return;
	}

	if(aMsgCode == 56)
	{
		BYTE sBuff[9]={0xC3,0x09,0x4A,0x01,0x05,HIBYTE(gObj->m_Index),LOBYTE(gObj->m_Index),HIBYTE(aIndex),LOBYTE(aIndex)};
		//DataSend(PlayerID,(PBYTE)sBuff,sBuff[1]);
		//MsgSendV2(gObj, (LPBYTE)&sBuff,sBuff[1]);
		return;
	}

	gObjStateAttackProc(gObj,aMsgCode,aIndex,SubCode,SubCode2);
}
void GCMagicAttackNewSkill4A(OBJECTSTRUCT* gObj,int Skill,int TargetNumber,int success)
{
	PMSG_MAGICATTACK_RESULT pMsg;

	pMsg.h.c = 0xC3;
	pMsg.h.headcode = 0x19;
	pMsg.h.size = sizeof(pMsg);
	pMsg.MagicNumber = Skill;
	pMsg.SourceNumberH = HIBYTE(gObj->m_Index);
	pMsg.SourceNumberL = LOBYTE(gObj->m_Index);
	pMsg.TargetNumberH = HIBYTE(TargetNumber);
	pMsg.TargetNumberL = LOBYTE(TargetNumber);
	pMsg.TargetNumberH &= 0x7F;

	if ( success )
		pMsg.TargetNumberH |= 0x80;

	if ( gObj->Type == OBJECT_USER )
		DataSend(gObj->m_Index, (LPBYTE)&pMsg, pMsg.h.size);

	MsgSendV2(gObj, (LPBYTE)&pMsg, pMsg.h.size);
}
char *GetMapName(int MapId)
{
	switch (MapId)
	{
		case 0:
			return "Lorencia";
		case 1:
			return "Dungeon";
		case 2:
			return "Devais";
		case 3:
			return "Noria";
		case 4:
			return "Lost Tower";
		case 5:
			return "Exile";
		case 6:
			return "Arena";
		case 7:
			return "Atlans";
		case 8:
			return "Tarkan";
		case 9:
			return "Devil Square";
		case 10:
			return "Icarus";
		case 30:
			return "Valley of Loren";
		case 31:
			return "Land of Trial";
		case 32:
			return "Devil Square";
		case 33:
			return "Aida";
		case 34:
			return "Crywolf";
		case 35:
			return "Null";
		case 36:
			return "Kalima";
		case 37:
			return "Kantru1";
		case 38:
			return "Kantru2";
		case 39:
			return "Kantru3";
		case 40:
			return "Silent";
		case 41:
			return "Barracks";
		case 42:
			return "Refuge";
		case 43:
			return "Null";
		case 44:
			return "Null";
		case 51:
			return "Elbeland";
		case 52:
			return "Blood Castle";
		case 53:
			return "Chaos Castle";
		case 56:
			return "Swamp of Calmness";
		case 57:
			return "Raklion";
		case 58:
			return "Raklion";
	}
	if (MapId >= 11 && MapId <= 17)
		return "Blood Castle";

	if (MapId >= 18 && MapId <= 23)
		return "Chaos Castle";

	if (MapId >= 24 && MapId <= 29)
		return "Kalima";

	if (MapId >= 45 && MapId <= 50)
		return "Illusion Temple";
	
	return "Unknown";
}
void GCUseBuffEffect(OBJECTSTRUCT* gObj, BYTE btEffectIndex, BYTE btEffectUseOption, WORD wOptionType, WORD wEffectType, int iLeftTime)
{
	PMSG_SEND_BUFF_ICON pMsg;

	PHeadSetB((LPBYTE)&pMsg, 0x2D, sizeof(PMSG_SEND_BUFF_ICON));

	pMsg.btEffectIndex = btEffectIndex;
	pMsg.byEffectOption = btEffectUseOption;
	pMsg.wOptionType = wOptionType;
	pMsg.wEffectType = wEffectType;
	pMsg.iLeftTime = iLeftTime;

	if ( gObj->Type == OBJECT_USER )
	{
		DataSend(gObj->m_Index, (LPBYTE)&pMsg, pMsg.h.size);
	}

	if(btEffectUseOption == 0)
	{
		GCStateInfoSend(gObj, 1, btEffectIndex);
	}
	else
	{
		GCStateInfoSend(gObj, 0, btEffectIndex);
	}
}
bool CGUseItemRecv(PMSG_USEITEM* lpMsg, int aIndex)
{
	if(aIndex > OBJECT_MAX)
		return true;

	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

		if(gObj->pInventory[lpMsg->inventoryPos].m_Type == ITEMGET(14,107))
		{
				int addcriticaldamagevalue = (gObj->AddDexterity + gObj->Dexterity)/30 + (gObj->Energy + gObj->AddEnergy)/30;
	            int SkillTime = (gObj->Energy + gObj->AddEnergy)/10 + 60;
				gObj->SetOpAddCriticalDamage += addcriticaldamagevalue;
	            gObj->m_JewelOfHarmonyEffect.HJOpAddCriticalDamage+= addcriticaldamagevalue;
				 gObj->m_WizardSkillDefenseTime = 500;
		        gObj->m_WizardSkillDefense = (4000) / 40 + 60;
				gObj->m_SkillAddLife	= (gObj->AddEnergy + gObj->Energy) /20 + (gObj->Vitality + gObj->AddVitality) /100 + 13;
				gObj->MaxLife += (gObj->AddEnergy + gObj->Energy) /20 + (gObj->Vitality + gObj->AddVitality) /100 + 13;
				GCMagicAttackNew(gObj,48,aIndex,1);
				GCMagicAttackNew(gObj,16,aIndex,1);
				GCMagicAttackNew(gObj,64,aIndex,1);
			    GCMagicAttackNew(gObj,26,aIndex,1);
			    GCMagicAttackNew(gObj,27,aIndex,1);
				GCMagicAttackNew(gObj,28,aIndex,1);
				MaxLifeReFillSend(aIndex);
				gObjDeleteItemsCount(aIndex,7275,0,1);
				LogNotice(1,"Divine Buff Used");
			
			return false;
		}
	return false;
}
