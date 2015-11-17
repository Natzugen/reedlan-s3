//======================================
// Season 3 
// Coder : MaMoHT
// Custom : ResetSystem
// Start Date : 16.07.2012
//======================================
#include "ResetSystem.h"
#include "SMDToken.h"
#include "User.h"
#include "Utils.h"
#include "MSSQL.h"


void ResetSystem(int aIndex)
{
	

	char ResetSystemFile[27] = ".//Config//ResetSystem.cfg";
	int Switch		 =         GetPrivateProfileInt("Reset","SwitchCommand",1,ResetSystemFile);
	int MaxResets 	 =         GetPrivateProfileInt("Reset","MaxResets",99,ResetSystemFile);
	int ZenFormula   =         GetPrivateProfileInt("Reset","ZenForumla",1,ResetSystemFile);
	int StatsResets  =         GetPrivateProfileInt("Reset","StatsResets",1,ResetSystemFile);
	int ResetPoints  =         GetPrivateProfileInt("Reset","ResetPoints",1,ResetSystemFile);

	int LevelToResetSM    =      GetPrivateProfileInt("SM","LevelToReset",400,ResetSystemFile);
	int PointsPerResetSM	=    GetPrivateProfileInt("SM","PointsReset",1000,ResetSystemFile);
	int RequiredZenSM  =         GetPrivateProfileInt("SM","RequiredZen",1000000,ResetSystemFile);
    unsigned int ResetItemSM   = GetPrivateProfileInt("SM","ItemID",7182,ResetSystemFile);
	int ExLevelSM      =         GetPrivateProfileInt("SM","ExLevel",1,ResetSystemFile);
	int PointStrSM     =         GetPrivateProfileInt("SM","PointStr",1,ResetSystemFile);
    int PointAgiSM     =         GetPrivateProfileInt("SM","PointAgi",1,ResetSystemFile);
    int PointVitSM     =         GetPrivateProfileInt("SM","PointVit",1,ResetSystemFile);
    int PointEneSM     =         GetPrivateProfileInt("SM","PointEne",1,ResetSystemFile);

	int LevelToResetBK    =      GetPrivateProfileInt("BK","LevelToReset",400,ResetSystemFile);
	int PointsPerResetBK	=    GetPrivateProfileInt("BK","PointsReset",1000,ResetSystemFile);
	int RequiredZenBK  =         GetPrivateProfileInt("BK","RequiredZen",1000000,ResetSystemFile);
    unsigned int ResetItemBK   = GetPrivateProfileInt("BK","ItemID",7182,ResetSystemFile);
	int ExLevelBK      =         GetPrivateProfileInt("BK","ExLevel",1,ResetSystemFile);
	int PointStrBK     =         GetPrivateProfileInt("BK","PointStr",1,ResetSystemFile);
    int PointAgiBK     =         GetPrivateProfileInt("BK","PointAgi",1,ResetSystemFile);
    int PointVitBK     =         GetPrivateProfileInt("BK","PointVit",1,ResetSystemFile);
    int PointEneBK     =         GetPrivateProfileInt("BK","PointEne",1,ResetSystemFile);

	int LevelToResetElf    =      GetPrivateProfileInt("Elf","LevelToReset",400,ResetSystemFile);
	int PointsPerResetElf	=     GetPrivateProfileInt("Elf","PointsReset",1000,ResetSystemFile);
	int RequiredZenElf  =         GetPrivateProfileInt("Elf","RequiredZen",1000000,ResetSystemFile);
    unsigned int ResetItemElf   = GetPrivateProfileInt("Elf","ItemID",7182,ResetSystemFile);
	int ExLevelElf      =         GetPrivateProfileInt("Elf","ExLevel",1,ResetSystemFile);
	int PointStrElf     =         GetPrivateProfileInt("Elf","PointStr",1,ResetSystemFile);
    int PointAgiElf     =         GetPrivateProfileInt("Elf","PointAgi",1,ResetSystemFile);
    int PointVitElf     =         GetPrivateProfileInt("Elf","PointVit",1,ResetSystemFile);
    int PointEneElf     =         GetPrivateProfileInt("Elf","PointEne",1,ResetSystemFile);

	int LevelToResetMG    =      GetPrivateProfileInt("MG","LevelToReset",400,ResetSystemFile);
	int PointsPerResetMG	=    GetPrivateProfileInt("MG","PointsReset",1000,ResetSystemFile);
	int RequiredZenMG  =         GetPrivateProfileInt("MG","RequiredZen",1000000,ResetSystemFile);
    unsigned int ResetItemMG   = GetPrivateProfileInt("MG","ItemID",7182,ResetSystemFile);
	int ExLevelMG      =         GetPrivateProfileInt("MG","ExLevel",1,ResetSystemFile);
	int PointStrMG     =         GetPrivateProfileInt("MG","PointStr",1,ResetSystemFile);
    int PointAgiMG     =         GetPrivateProfileInt("MG","PointAgi",1,ResetSystemFile);
    int PointVitMG     =         GetPrivateProfileInt("MG","PointVit",1,ResetSystemFile);
    int PointEneMG     =         GetPrivateProfileInt("MG","PointEne",1,ResetSystemFile);

	int LevelToResetDL    =      GetPrivateProfileInt("DL","LevelToReset",400,ResetSystemFile);
	int PointsPerResetDL	=    GetPrivateProfileInt("DL","PointsReset",1000,ResetSystemFile);
	int RequiredZenDL  =         GetPrivateProfileInt("DL","RequiredZen",1000000,ResetSystemFile);
    unsigned int ResetItemDL   = GetPrivateProfileInt("DL","ItemID",7182,ResetSystemFile);
	int ExLevelDL      =         GetPrivateProfileInt("DL","ExLevel",1,ResetSystemFile);
	int PointStrDL     =         GetPrivateProfileInt("DL","PointStr",1,ResetSystemFile);
    int PointAgiDL     =         GetPrivateProfileInt("DL","PointAgi",1,ResetSystemFile);
    int PointVitDL     =         GetPrivateProfileInt("DL","PointVit",1,ResetSystemFile);
    int PointEneDL     =         GetPrivateProfileInt("DL","PointEne",1,ResetSystemFile);
    int PointComDL     =         GetPrivateProfileInt("DL","PointCom",1,ResetSystemFile);


	GetPrivateProfileString("ResetMessage","ItemResetMSG1","[Reset] You need item for reset.",GLOBAL.MSGRes1,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG2","[Reset]: You need %ld zen to Reset your Character.",GLOBAL.MSGRes2,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG3","[Reset]: You must be Level %d to Reset your Character.",GLOBAL.MSGRes3,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG4","[Reset]: You Exceeded Maximum Resets Number, Contact Administrator.",GLOBAL.MSGRes4,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG5","[Reset]: You are Successfully Reseted, You have [%d] Resets Now!",GLOBAL.MSGRes5,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG6","[Reset]: Sorry,System is Desabled!",GLOBAL.MSGRes6,256,ResetSystemFile);
	GetPrivateProfileString("ResetMessage","ItemResetMSG7","[Reset]: Please use Swith Character!",GLOBAL.MSGRes7,256,ResetSystemFile);

	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);


	int ResetGivN = SQL.ResetS+1;
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	if(Switch == 0)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes6);
		return;
	}
	if(SQL.ResetS >= MaxResets)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes4);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------SM------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	if 	 ((int)GetPlayerClass(aIndex) == DB_DARK_WIZARD || (int)GetPlayerClass(aIndex) == DB_SOUL_MASTER || (int)GetPlayerClass(aIndex) == DB_GRAND_MASTER )
	{
	//--------------------------------------------------------------------------------------------------------------------
    int ExPoints = PointsPerResetSM*ResetGivN;
	int ExMoney = RequiredZenSM+ZenFormula*SQL.ResetS;
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < LevelToResetSM)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes3,LevelToResetSM);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Money < RequiredZenSM)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes2,RequiredZenSM);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(ResetItemSM !=0 )
	{
	if (gObjGetItemCountInInventory(aIndex,ResetItemSM,0) < 1)
	{
	MsgNormal(aIndex,GLOBAL.MSGRes1);
	return;
	}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if (StatsResets == 1)
	{
	gObj->Strength =   PointStrSM;
	gObj->Dexterity =  PointAgiSM;
	gObj->Vitality =   PointVitSM;
	gObj->Energy =     PointEneSM;
	}
	gObj->Experience = 0;
	gObj->Level = ExLevelSM;
	if (ResetPoints == 1)
	{
	gObj->LevelUpPoint = 0;
	}
	gObj->LevelUpPoint += ExPoints;
	gObj->Money	-= ExMoney;
	gObj->Resets++;

	//--------------------------------------------------------------------------------------------------------------------
    GCMoneySend(aIndex, gObj->Money);
	GCLevelUpMsgSend(aIndex, ExLevelSM);
	if(ResetItemSM !=0 )
	{
	gObjDeleteItemsCount(aIndex,ResetItemSM,0,1);
	}
	//--------------------------------------------------------------------------------------------------------------------
	SQL.UpdateResetSystem(gObj->Name,SQL.ResetS);
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(aIndex,GLOBAL.MSGRes5,SQL.ResetS);
	MsgNormal(aIndex,GLOBAL.MSGRes7,SQL.ResetS);
	//--------------------------------------------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------BK------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	if 	 ((int)GetPlayerClass(aIndex) == DB_DARK_KNIGHT || (int)GetPlayerClass(aIndex) == DB_BLADE_KNIGHT || (int)GetPlayerClass(aIndex) == DB_BLADE_MASTER )
	{
	//--------------------------------------------------------------------------------------------------------------------
    int ExPoints = PointsPerResetBK*ResetGivN;
	int ExMoney = RequiredZenBK+ZenFormula*SQL.ResetS;
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < LevelToResetBK)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes3,LevelToResetBK);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Money < RequiredZenBK)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes2,RequiredZenBK);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(ResetItemBK !=0 )
	{
	if (gObjGetItemCountInInventory(aIndex,ResetItemBK,0) < 1)
	{
	MsgNormal(aIndex,GLOBAL.MSGRes1);
	return;
	}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if (StatsResets == 1)
	{
	gObj->Strength =   PointStrBK;
	gObj->Dexterity =  PointAgiBK;
	gObj->Vitality =   PointVitBK;
	gObj->Energy =     PointEneBK;
	}
	gObj->Experience = 0;
	gObj->Level = ExLevelBK;
	if (ResetPoints == 1)
	{
	gObj->LevelUpPoint = 0;
	}
	gObj->LevelUpPoint += ExPoints;
	gObj->Money	-= ExMoney;
	gObj->Resets++;

	//--------------------------------------------------------------------------------------------------------------------
    GCMoneySend(aIndex, gObj->Money);
	GCLevelUpMsgSend(aIndex, ExLevelBK);
	if(ResetItemBK !=0 )
	{
	gObjDeleteItemsCount(aIndex,ResetItemBK,0,1);
	}
	//--------------------------------------------------------------------------------------------------------------------
	SQL.UpdateResetSystem(gObj->Name,SQL.ResetS);
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(aIndex,GLOBAL.MSGRes5,SQL.ResetS);
	MsgNormal(aIndex,GLOBAL.MSGRes7,SQL.ResetS);
	//--------------------------------------------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------Elf-----------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	if 	 ((int)GetPlayerClass(aIndex) == DB_FAIRY_ELF || (int)GetPlayerClass(aIndex) == DB_MUSE_ELF || (int)GetPlayerClass(aIndex) == DB_HIGH_ELF )
	{
	//--------------------------------------------------------------------------------------------------------------------
    int ExPoints = PointsPerResetElf*ResetGivN;
	int ExMoney = RequiredZenElf+ZenFormula*SQL.ResetS;
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < LevelToResetElf)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes3,LevelToResetElf);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Money < RequiredZenBK)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes2,RequiredZenElf);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(ResetItemElf !=0 )
	{
	if (gObjGetItemCountInInventory(aIndex,ResetItemElf,0) < 1)
	{
	MsgNormal(aIndex,GLOBAL.MSGRes1);
	return;
	}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if (StatsResets == 1)
	{
	gObj->Strength =   PointStrElf;
	gObj->Dexterity =  PointAgiElf;
	gObj->Vitality =   PointVitElf;
	gObj->Energy =     PointEneElf;
	}
	gObj->Experience = 0;
	gObj->Level = ExLevelElf;
	if (ResetPoints == 1)
	{
	gObj->LevelUpPoint = 0;
	}
	gObj->LevelUpPoint += ExPoints;
	gObj->Money	-= ExMoney;
	gObj->Resets++;

	//--------------------------------------------------------------------------------------------------------------------
    GCMoneySend(aIndex, gObj->Money);
	GCLevelUpMsgSend(aIndex, ExLevelElf);
	if(ResetItemElf !=0 )
	{
	gObjDeleteItemsCount(aIndex,ResetItemElf,0,1);
	}
	//--------------------------------------------------------------------------------------------------------------------
	SQL.UpdateResetSystem(gObj->Name,SQL.ResetS);
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(aIndex,GLOBAL.MSGRes5,SQL.ResetS);
	MsgNormal(aIndex,GLOBAL.MSGRes7,SQL.ResetS);
	//--------------------------------------------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------MG------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	if 	 ((int)GetPlayerClass(aIndex) == DB_MAGIC_GLADIATOR || (int)GetPlayerClass(aIndex) == DB_DUEL_MASTER  )
	{
	//--------------------------------------------------------------------------------------------------------------------
    int ExPoints = PointsPerResetMG*ResetGivN;
	int ExMoney = RequiredZenMG+ZenFormula*SQL.ResetS;
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < LevelToResetMG)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes3,LevelToResetMG);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Money < RequiredZenBK)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes2,RequiredZenMG);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(ResetItemMG !=0 )
	{
	if (gObjGetItemCountInInventory(aIndex,ResetItemMG,0) < 1)
	{
	MsgNormal(aIndex,GLOBAL.MSGRes1);
	return;
	}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if (StatsResets == 1)
	{
	gObj->Strength =   PointStrMG;
	gObj->Dexterity =  PointAgiMG;
	gObj->Vitality =   PointVitMG;
	gObj->Energy =     PointEneMG;
	}
	gObj->Experience = 0;
	gObj->Level = ExLevelMG;
	if (ResetPoints == 1)
	{
	gObj->LevelUpPoint = 0;
	}
	gObj->LevelUpPoint += ExPoints;
	gObj->Money	-= ExMoney;
	gObj->Resets++;

	//--------------------------------------------------------------------------------------------------------------------
    GCMoneySend(aIndex, gObj->Money);
	GCLevelUpMsgSend(aIndex, ExLevelMG);
	if(ResetItemMG !=0 )
	{
	gObjDeleteItemsCount(aIndex,ResetItemMG,0,1);
	}
	//--------------------------------------------------------------------------------------------------------------------
	SQL.UpdateResetSystem(gObj->Name,SQL.ResetS);
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(aIndex,GLOBAL.MSGRes5,SQL.ResetS);
	MsgNormal(aIndex,GLOBAL.MSGRes7,SQL.ResetS);
	//--------------------------------------------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------DL------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	if 	 ((int)GetPlayerClass(aIndex) == DB_DARK_LORD || (int)GetPlayerClass(aIndex) == DB_LORD_EMPEROR)
	{
	//--------------------------------------------------------------------------------------------------------------------
    int ExPoints = PointsPerResetDL*ResetGivN;
	int ExMoney = RequiredZenDL+ZenFormula*SQL.ResetS;
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < LevelToResetDL)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes3,LevelToResetDL);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Money < RequiredZenDL)
	{
		MsgNormal(aIndex,GLOBAL.MSGRes2,RequiredZenDL);
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	if(ResetItemDL !=0 )
	{
	if (gObjGetItemCountInInventory(aIndex,ResetItemDL,0) < 1)
	{
	MsgNormal(aIndex,GLOBAL.MSGRes1);
	return;
	}
	}
	//--------------------------------------------------------------------------------------------------------------------
	if (StatsResets == 1)
	{
	gObj->Strength =   PointStrDL;
	gObj->Dexterity =  PointAgiDL;
	gObj->Vitality =   PointVitDL;
	gObj->Energy =     PointEneDL;
	gObj->Leadership = PointComDL;
	}
	gObj->Experience = 0;
	gObj->Level = ExLevelDL;
	if (ResetPoints == 1)
	{
	gObj->LevelUpPoint = 0;
	}
	gObj->LevelUpPoint += ExPoints;
	gObj->Money	-= ExMoney;
	gObj->Resets++;

	//--------------------------------------------------------------------------------------------------------------------
    GCMoneySend(aIndex, gObj->Money);
	GCLevelUpMsgSend(aIndex, ExLevelDL);
	if(ResetItemDL !=0 )
	{
	gObjDeleteItemsCount(aIndex,ResetItemDL,0,1);
	}
	//--------------------------------------------------------------------------------------------------------------------
	SQL.UpdateResetSystem(gObj->Name,SQL.ResetS);
	SQL.GetResetCharacter(gObj->Name);
	//--------------------------------------------------------------------------------------------------------------------
	MsgNormal(aIndex,GLOBAL.MSGRes5,SQL.ResetS);
	MsgNormal(aIndex,GLOBAL.MSGRes7,SQL.ResetS);
	//--------------------------------------------------------------------------------------------------------------------
	}
}