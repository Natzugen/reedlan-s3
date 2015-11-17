#include "PostSystem.h"
#include "User.h"
#include "Utils.h"
#include "StdAfx.h"
#include "MSSQL.h"
#include "GMConf.h"
#include <time.h>
//========================================================================================================================
//Команда отправки сообщения
//========================================================================================================================
void ChatGlobal(int aIndex,char* msg)
{	
	if(aIndex <= OBJECT_MIN && aIndex >= OBJECT_MAX)
		return;
	char PostPrefix[20];
	char PostBlockS[100];
	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int isPost = GetPrivateProfileInt("PostSystem","IsPost",1,".\\Config\\Command.cfg");
	int Level = GetPrivateProfileInt("PostSystem","PostLevel",50,".\\Config\\Command.cfg");
	int BlockPostSystem = GetPrivateProfileInt("PostSystem","PostBlock",1,".\\Config\\Command.cfg");
	int vCost = GetPrivateProfileInt("PostSystem","PostCost",10000,".\\Config\\Command.cfg");
	int vPostColor = GetPrivateProfileInt("PostSystem","PostCost",10000,".\\Config\\Command.cfg");
	GetPrivateProfileString("PostSystem","PrefixPost","[Post]",PostPrefix,15,".\\Config\\Command.cfg");
	GetPrivateProfileString("PostSystem","PostBlockS","[Post]",PostBlockS,15,".\\Config\\Command.cfg");
	int BlockPost = SQL.GetBlockPCharacter(gObj->Name);
	if(aIndex > OBJECT_MAX)
		return;


	if (BlockPostSystem == 1)
	{
	if (BlockPost > 0)
	{              
		MsgNormal(aIndex,PostBlockS);
		return;
	}
	}
	if(isPost==0)
	{
		MsgNormal(aIndex,"[Post] : Command disabled.");
		return;
	}

	if(!strcmpi("/post",msg))
	{
		MsgNormal(aIndex,"[Post] : Write /post <msg>");
		return;
	}

	if(strlen(msg)<1)
	{
		MsgNormal(aIndex,"[Post] : Write /post <msg>");
		return;
	}

	if(gObj->Level < Level)
	{
		MsgNormal(aIndex,"[Post] : You need %d level to use command.",Level);
		return;
	}


	if(vCost > 0)
	{
		if(gObj->Money < vCost)
		{
			if(vCost > 0)
			{
				MsgNormal(aIndex,"[Post] : To use post command you need %d",vCost);
				return;
			}
			else
			{
				MsgNormal(aIndex,"[Post] : Config error");
				return;
			}
		}
	}




	for(int i = OBJECT_MIN; i<OBJECT_MAX; i++)
	{
		if (gObj->Connected == 3)
			MsgYellow(i,"%s%s: %s",PostPrefix,gObj->Name,msg);
	
		
	}

	if(vCost > 0)
	{
		if(gObj->Money >= vCost)
		{
			if(vCost > 0)
			{
				gObj->Money -= vCost;
				GCMoneySend(aIndex,gObj->Money);
			}
		}
	}
}
//========================================================================================================================
// Команда блокировки сообщения для админов
//========================================================================================================================
void PostBlock(int aIndex,char* msg)
{
OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
//========================================================================================================================
 int  PostBlock	= 0;
 char Player[16]	= {0};
 int  PostBlockC;
 int GMCode = 0;
 int isFind = 0;
//========================================================================================================================
if(gObj->Authority != 32)
	{	
		MsgNormal(aIndex,"[PostBlock] : Command only for GM's");
		return;
	}	
//========================================================================================================================
	if(!g_GMConfig.CheckIsGM(gObj->Name,2))
	{	
		MsgNormal(aIndex,"[PostBlock] Only GM from list can use this command.");
		return;
	}
//========================================================================================================================
	sscanf(msg,"%s %d",Player,&PostBlock);
    DWORD PlayerID = SQL.GetaIndexPlayer(Player);
	PostBlockC = PostBlock * 60;
//========================================================================================================================
	if((PlayerID>=MIN_PLAYERID) && (PlayerID<=MAX_PLAYERID))
	{
	OBJECTSTRUCT * pObj = (OBJECTSTRUCT*)OBJECT_POINTER(PlayerID);
		
    SQL.UpdatePostBCharacter(Player,PostBlockC);
	isFind = 1;
	}

	if(isFind == 1)
	{
	MsgNormal(aIndex,"[PostBlock]: [%s] You are blocked on %d minutes",Player, PostBlockC);
	}
	else
	{
	MsgNormal(aIndex,"[PostBlock] Player: %s  is offline",Player);
	}
}
//========================================================================================================================
// Таймер блокировки чата
//========================================================================================================================
void PostBlockTimer(void * lpParam)
{

	while(true)
	{ 
	Sleep(60000); 
	for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
	{

		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
	
	int  PostBlockD;
	int BlockPost = SQL.GetBlockPCharacter(gObj->Name);
		if (BlockPost > 0)
	{   
		if(gObj->Connected == 3)
		{	
			
	
			SYSTEMTIME t;
			GetLocalTime(&t);
			SQL.UpdatePostBCharacter2(gObj->Name,PostBlockD);
		}
	}

	

	}
	}
	_endthread();
}