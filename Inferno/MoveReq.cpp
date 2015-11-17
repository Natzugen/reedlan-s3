//======================================
// LCTeam Season 5 Project GS 1.00.89/1.00.90 JPN
// Coder : SmallHabit
// Start Date : 16.08.2010
//======================================
#include "StdAfx.h"
#include <stdio.h>
#include <time.h>
#include "windows.h"
#include "MoveReq.h"
#include "Utils.h"
#include "User.h"
#include "SMDToken.h"
#include "MoveStadium.h"
#include "MSSQL.h"
CMoveSystem MoveReq;

void CMoveSystem::Init()
{
	for(int i=0;i<MAX_MOVES;i++)
	{
		this->m_MoveData[i].iIndex = 0;
		this->m_MoveData[i].iMoney = 0;
		this->m_MoveData[i].iLevel = 0;
		this->m_MoveData[i].iGate = 0;
	}
}

void CMoveSystem::InitGate()
{
	for(int i=0;i<MAX_GATES;i++)
	{
		this->m_GateData[i].iIndex = 0;
		this->m_GateData[i].iType = 0;
		this->m_GateData[i].iMapNum = 0;
		this->m_GateData[i].iX1 = 0;
		this->m_GateData[i].iY1 = 0;
		this->m_GateData[i].iX2 = 0;
		this->m_GateData[i].iY2 = 0;
		this->m_GateData[i].iTarget = 0;
		this->m_GateData[i].iDir = 0;
		this->m_GateData[i].iLevel = 0;
	}
}

void CMoveSystem::LoadFile(char *filename)
{
	this->Init();
	
	if((SMDFile = fopen(filename, "r")) == NULL)
	{
		MessageBoxA(0,"CMoveManager::LoadFile() error","CRITICAL ERROR",0);
		ExitProcess(1);
		return;
	}

	SMDToken Token;
	int iIndex;
	char szMoveKor[40] = {0};
	char szMoveEng[40] = {0};
	int iMoney = 0;
	int iLevel = 0;
	int iGate = 0;
	int MoveReqs = 0;

	while(true)
	{
		Token = GetToken();

		if(MoveReqs == 255)
			break;

		iIndex = TokenNumber;
		
		Token = GetToken();
		memcpy(szMoveKor,TokenString,sizeof(szMoveKor));

		Token = GetToken();
		memcpy(szMoveEng,TokenString,sizeof(szMoveEng));

		Token = GetToken();
		iMoney = TokenNumber;

		Token = GetToken();
		iLevel = TokenNumber;

		Token = GetToken();
		iGate = TokenNumber;

		this->Insert(iIndex,szMoveKor,szMoveEng,iMoney,iLevel,iGate);	
		MoveReqs++;
	}

	fclose(SMDFile);
	return;
}

void CMoveSystem::LoadGate(char *filename)
{
	this->InitGate();
	
	if((SMDFile = fopen(filename, "r")) == NULL)
	{
		MessageBoxA(0,"CMoveManager::LoadGate() error","CRITICAL ERROR",0);
		ExitProcess(1);
		return;
	}

	SMDToken Token;
	int iIndex;
	int iType = 0;
	int iMapNum = 0;
	int iX1 = 0;
	int iY1 = 0;
	int iX2 = 0;
	int iY2 = 0;
	int iTarget = 0;
	int iDir = 0;
	int iLevel = 0;
	int GateReqs = 0;

	while(true)
	{
		Token = GetToken();

		if(GateReqs == 333)
			break;

		iIndex = TokenNumber;

		Token = GetToken();
		iType = TokenNumber;

		Token = GetToken();
		iMapNum = TokenNumber;

		Token = GetToken();
		iX1 = TokenNumber;
		
		Token = GetToken();
		iY1 = TokenNumber;

		Token = GetToken();
		iX2 = TokenNumber;

		Token = GetToken();
		iY2 = TokenNumber;

		Token = GetToken();
		iTarget = TokenNumber;

		Token = GetToken();
		iDir = TokenNumber;

		Token = GetToken();
		iLevel = TokenNumber;

		this->InsertGate(iIndex,iType,iMapNum,iX1,iY1,iX2,iY2,iTarget,iDir,iLevel);	
		GateReqs++;
	}

	fclose(SMDFile);
	return;
}

void CMoveSystem::InsertGate(int iIndex,int iType,int iMapNum,int iX1,int iY1,int iX2,int iY2,int iTarget,int iDir,int iLevel)
{
	this->m_GateData[iIndex].iIndex = iIndex;
	this->m_GateData[iIndex].iType = iType;
	this->m_GateData[iIndex].iMapNum = iMapNum;
	this->m_GateData[iIndex].iX1 = iX1;
	this->m_GateData[iIndex].iY1 = iY1;
	this->m_GateData[iIndex].iX2 = iX2;
	this->m_GateData[iIndex].iY2 = iY2;
	this->m_GateData[iIndex].iTarget = iTarget;
	this->m_GateData[iIndex].iDir = iDir;
	this->m_GateData[iIndex].iLevel = iLevel;
}

void CMoveSystem::Insert(int iIndex,char *szMoveKor,char *szMoveEng, int iMoney,int iLevel,int iGate)
{
	this->m_MoveData[iIndex].iIndex = iIndex;
	strcpy(this->m_MoveData[iIndex].szMoveKor,szMoveKor);
	strcpy(this->m_MoveData[iIndex].szMoveEng,szMoveEng);
	this->m_MoveData[iIndex].iMoney = iMoney;
	this->m_MoveData[iIndex].iLevel = iLevel;
	this->m_MoveData[iIndex].iGate = iGate;
}

void CMoveSystem::MoveTeleport(int aIndex,char *MapName)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	for(int i=0;i<MAX_MOVES;i++)
	{
		if(!_strcmpi(MapName, this->m_MoveData[i].szMoveEng))
		{	
			int TeleportMap;
			int iError = 0;
			
			if(this->m_GateData[this->m_MoveData[i].iGate].iX1 == this->m_GateData[this->m_MoveData[i].iGate].iX2)
			this->m_GateData[this->m_MoveData[i].iGate].iX2++;
			if(this->m_GateData[this->m_MoveData[i].iGate].iY1 == this->m_GateData[this->m_MoveData[i].iGate].iY2)
			this->m_GateData[this->m_MoveData[i].iGate].iY2++;
			
			int randomizeR = rand()+gObj->m_Index+gObj->Money;
			int FinalX = min(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2)+randomizeR%(max(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2)-min(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2));
			int FinalY = min(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2)+randomizeR%(max(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2)-min(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2));
			
			if(IsExistWingItem(aIndex) == 65535 && this->m_GateData[this->m_MoveData[i].iGate].iMapNum == 10)
			{
				//return no wings
				gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
				iError = 1;
			}
			int CharResets = SQL.ResetCount;
			if(this->m_GateData[this->m_MoveData[i].iGate].iMapNum == 6)
			{
			MsgNormal(aIndex,"You need Resets");
		    gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
			return;
			}		
	
			if(iError == 1)
			{
				if(IsExistPetItem(aIndex) != 6659 && this->m_GateData[this->m_MoveData[i].iGate].iMapNum == 10)
				{
					//return no dinorant
					MsgNormal(aIndex,"You are currently not able to warp.");
					gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
					iError = 0;
					return;
				}
			}

	
			int NeedLevel = this->m_MoveData[this->m_MoveData[i].iGate].iLevel;

			if ( gObj->Class == 4 || gObj->Class == 3 || gObj->Class == 6 )
			{
				if ( NeedLevel > 0 )
				{
					NeedLevel = this->m_MoveData[this->m_MoveData[i].iGate].iLevel*2/3;
				}
			}

			if(gObj->Level < NeedLevel)
			{		
				//MsgNormal(aIndex,"You need %d level to warp. %d",this->m_MoveData[i].iLevel,gObj->Level);
				return;
			}
			
			//if(gObj->Money < this->m_MoveData[i].iMoney)
			//{
			//	MsgNormal(aIndex,"Not enought zen.");
			//	return;
			//}
		
			//gObj->Money -= this->m_MoveData[i].iMoney;
			//GCMoneySend(aIndex,gObj->Money);



			TeleportMap = this->m_GateData[this->m_MoveData[i].iGate].iMapNum;
			gObjTeleport(aIndex, TeleportMap, FinalX,FinalY);
		}
	}
}

void CMoveSystem::MoveNoChecks(int aIndex,char *MapName)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	for(int i=0;i<MAX_MOVES;i++)
	{
		if(!_strcmpi(MapName, this->m_MoveData[i].szMoveEng))
		{	
			int TeleportMap;
			
			if(this->m_GateData[this->m_MoveData[i].iGate].iX1 == this->m_GateData[this->m_MoveData[i].iGate].iX2)
			this->m_GateData[this->m_MoveData[i].iGate].iX2++;
			if(this->m_GateData[this->m_MoveData[i].iGate].iY1 == this->m_GateData[this->m_MoveData[i].iGate].iY2)
			this->m_GateData[this->m_MoveData[i].iGate].iY2++;
			
			int randomizeR = rand()+gObj->m_Index+gObj->Money;
			int FinalX = min(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2)+randomizeR%(max(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2)-min(this->m_GateData[this->m_MoveData[i].iGate].iX1,this->m_GateData[this->m_MoveData[i].iGate].iX2));
			int FinalY = min(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2)+randomizeR%(max(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2)-min(this->m_GateData[this->m_MoveData[i].iGate].iY1,this->m_GateData[this->m_MoveData[i].iGate].iY2));

			TeleportMap = this->m_GateData[this->m_MoveData[i].iGate].iMapNum;
			gObjTeleport(aIndex, TeleportMap, FinalX,FinalY);
		}
	}
}

void CMoveSystem::MoveTeleportGate(int aIndex, int GateNum)
{	
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	int TeleportMap;
	int iError = 0;

	if(this->m_GateData[GateNum].iX1 == this->m_GateData[GateNum].iX2)
		this->m_GateData[GateNum].iX2++;
	if(this->m_GateData[GateNum].iY1 == this->m_GateData[GateNum].iY2)
		this->m_GateData[GateNum].iY2++;
	
	int randomizeR = rand()+gObj->m_Index+gObj->Money;
	int FinalX = min(this->m_GateData[GateNum].iX1,this->m_GateData[GateNum].iX2)+randomizeR%(max(this->m_GateData[GateNum].iX1,this->m_GateData[GateNum].iX2)-min(this->m_GateData[GateNum].iX1,this->m_GateData[GateNum].iX2));
	int FinalY = min(this->m_GateData[GateNum].iY1,this->m_GateData[GateNum].iY2)+randomizeR%(max(this->m_GateData[GateNum].iY1,this->m_GateData[GateNum].iY2)-min(this->m_GateData[GateNum].iY1,this->m_GateData[GateNum].iY2));

	if(gObj->m_PK_Level > 5)
	{
		MsgNormal(aIndex,"PK can't use warp menu");
		return;
	}
	if(IsExistWingItem(aIndex) == 65535 && this->m_GateData[GateNum].iMapNum == 10)
	{
		//return no wings
		gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
		iError = 1;
	}
	
	if(iError == 1)
	{
		if(IsExistPetItem(aIndex) != 6659 && this->m_GateData[GateNum].iMapNum == 10)
		{
			//return no dinorant
			MsgNormal(aIndex,"You are currently not able to warp.");
			gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
			iError = 0;
			return;
		}
	}

	int NeedLevel = this->m_MoveData[GateNum].iLevel;

	if ( gObj->Class == 4 || gObj->Class == 3 || gObj->Class == 6 )
	{
		if ( NeedLevel > 0 )
		{
			NeedLevel = this->m_MoveData[GateNum].iLevel*2/3;
		}
	}

	if(gObj->Level < NeedLevel)
	{	
		//MsgNormal(aIndex,"You need %d level to warp. %d",this->m_GateData[GateNum].iLevel,gObj->Level);
		return;
	}


	TeleportMap = this->m_GateData[GateNum].iMapNum;
	gObjTeleport(aIndex, TeleportMap, FinalX,FinalY);
}

void CMoveSystem::Teleport(int aIndex, int MovNum)
{	
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	int TeleportMap;
	int iError = 0;

	if(this->m_GateData[this->m_MoveData[MovNum].iGate].iX1 == this->m_GateData[this->m_MoveData[MovNum].iGate].iX2)
		this->m_GateData[this->m_MoveData[MovNum].iGate].iX2++;
	if(this->m_GateData[this->m_MoveData[MovNum].iGate].iY1 == this->m_GateData[this->m_MoveData[MovNum].iGate].iY2)
		this->m_GateData[this->m_MoveData[MovNum].iGate].iY2++;
	
	int randomizeR = rand()+gObj->m_Index+gObj->Money;
	int FinalX = min(this->m_GateData[this->m_MoveData[MovNum].iGate].iX1,this->m_GateData[this->m_MoveData[MovNum].iGate].iX2)+randomizeR%(max(this->m_GateData[this->m_MoveData[MovNum].iGate].iX1,this->m_GateData[this->m_MoveData[MovNum].iGate].iX2)-min(this->m_GateData[this->m_MoveData[MovNum].iGate].iX1,this->m_GateData[this->m_MoveData[MovNum].iGate].iX2));
	int FinalY = min(this->m_GateData[this->m_MoveData[MovNum].iGate].iY1,this->m_GateData[this->m_MoveData[MovNum].iGate].iY2)+randomizeR%(max(this->m_GateData[this->m_MoveData[MovNum].iGate].iY1,this->m_GateData[this->m_MoveData[MovNum].iGate].iY2)-min(this->m_GateData[this->m_MoveData[MovNum].iGate].iY1,this->m_GateData[this->m_MoveData[MovNum].iGate].iY2));

	if(gObj->m_PK_Level > 5)
	{
		MsgNormal(aIndex,"PK can't use warp menu");
		return;
	}

	if(IsExistWingItem(aIndex) == 65535 && this->m_GateData[this->m_MoveData[MovNum].iGate].iMapNum == 10)
	{
		//return no wings
		gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
		iError = 1;
	}
	if(iError == 1)
	{
		if(IsExistPetItem(aIndex) != 6659 && this->m_GateData[this->m_MoveData[MovNum].iGate].iMapNum == 10)
		{
			//return no dinorant
			MsgNormal(aIndex,"You are currently not able to warp.");
			gObjTeleport(aIndex, gObj->MapNumber, gObj->X,gObj->Y);
			iError = 0;
			return;
		}
	}

	int NeedLevel = this->m_MoveData[MovNum].iLevel;

	if ( gObj->Class == 4 || gObj->Class == 3 || gObj->Class == 6 )
	{
		if ( NeedLevel > 0 )
		{
			NeedLevel = this->m_MoveData[MovNum].iLevel*2/3;
		}
	}

	if(gObj->Level < NeedLevel)
	{	
		//MsgNormal(aIndex,"You need %d level to warp. %d",this->m_MoveData[MovNum].iLevel,gObj->Level);
		return;
	}
	
	if(gObj->Money < this->m_MoveData[MovNum].iMoney)
	{
		MsgNormal(aIndex,"Not enought zen.");
		return;
	}

	gObj->Money -= this->m_MoveData[MovNum].iMoney;
	//GCMoneySend(aIndex,gObj->Money);



	TeleportMap = this->m_GateData[this->m_MoveData[MovNum].iGate].iMapNum;
	gObjTeleport(aIndex, TeleportMap, FinalX,FinalY);
}