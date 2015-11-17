#include "StdAfx.h"
#include "USER.h"
#include "MSSQL.h"
#include "Utils.h"
// -----------------------------------------------------------------------------------------------------------------------
       	char ExpFile[25] = ".\\Config\\ExpSystem.cfg";
		char CommFile[25] = "..\\Data\\Commonserver.cfg";
	    int ExpSystemEnabled	= GetPrivateProfileInt("ExpSystem", "Enable",1,ExpFile);
		int NormEXP = GetPrivateProfileInt("GameServerInfo","AddExperience",1,CommFile);
		int ExpSystempDel	= GetPrivateProfileInt("Config", "pDel",50,ExpFile);
// -----------------------------------------------------------------------------------------------------------------------
//int VIPEXP = Experience + VIPExp;
// -----------------------------------------------------------------------------------------------------------------------
void ExpSystem(int aIndex, int TargetIndex, int Exp, int AttackDamage, BOOL MSBFlag)		
{
	if (ExpSystemEnabled = 1)
	{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	unsigned int pNewExperience = Exp;
	unsigned int pBonusExp = 0;
	int ExpRes = 0;
	int ExpDel = (ExpSystempDel+1);
	int ExpS;
	if (SQL.ResetS > 30)
	{
	ExpS = 200;
	}
	if ((SQL.ResetS < 30)||(SQL.ResetS = 30))
	{
	ExpS = 100;
	}
	SQL.GetResetCharacter(gObj->Name);
	    ExpRes = (ExpDel-SQL.ResetS);
	    pBonusExp = ((Exp*ExpRes)/100);
		pNewExperience += pBonusExp;
		gObj->Experience += pBonusExp;
		GCKillPlayerExpSend(aIndex,TargetIndex,pNewExperience,AttackDamage,MSBFlag);
	}
	else
		{
	float * EXPERIENCE = (float *)(CGAddExperience); 
			(*EXPERIENCE) = NormEXP;
		}
	}
	
	
