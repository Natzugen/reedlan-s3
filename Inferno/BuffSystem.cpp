#include "User.h"
#include "Utils.h"
#include "BuffSystem.h"
//========================================================================================================================
// Buff System 1 npc
//========================================================================================================================
void BuffSystem1(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
   	int isActive = GetPrivateProfileInt("BuffSystem1","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem1","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin1 = GetPrivateProfileInt("BuffSystem1","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem1","BuffTime",20,".\\Config\\BuffSystem.cfg");
//=======================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// CHECK BUFF
//========================================================================================================================
if ( gObj->GreatFBuff == 1)
{
		return;
}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin1)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Great Fortitude Buff              Black Knight
//========================================================================================================================
				gObj->m_SkillAddLife	= (gObj->AddEnergy + gObj->Energy) /20 + (gObj->Vitality + gObj->AddVitality) /100 + 13;
				gObj->MaxLife += (gObj->AddEnergy + gObj->Energy) /20 + (gObj->Vitality + gObj->AddVitality) /100 + 13;
				GCMagicAttackNew(gObj,48,aIndex,1);
				MaxLifeReFillSend(aIndex);	
				gObj->GreatFBuff = 1;
	            MsgNormal(aIndex,"[AddBuff]: Great Fortitude Buff Added");
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}
//========================================================================================================================
// Buff System 2 npc
//========================================================================================================================
void BuffSystem2(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
	int isActive = GetPrivateProfileInt("BuffSystem2","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem2","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin = GetPrivateProfileInt("BuffSystem2","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem2","BuffTime",20,".\\Config\\BuffSystem.cfg");
//========================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Soul Barier              Soul Master
//========================================================================================================================
		        gObj->m_WizardSkillDefenseTime = BuffTime;
		        gObj->m_WizardSkillDefense = (4000) / 40 + 60;
				GCMagicAttackNew(gObj,16,aIndex,1);
                MsgNormal(aIndex,"[AddBuff]: Soul Barrier Buff Added");
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}
//========================================================================================================================
// Buff System 3 npc
//========================================================================================================================
void BuffSystem3(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
	int isActive = GetPrivateProfileInt("BuffSystem2","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem2","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin = GetPrivateProfileInt("BuffSystem2","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem2","BuffTime",20,".\\Config\\BuffSystem.cfg");
//========================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// CHECK BUFF
//========================================================================================================================
if (gObj->CriticDmBuff == 1)
{
			return;
}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Increase Critical Damage Buff Added              Dark Lord
//========================================================================================================================
				int addcriticaldamagevalue = (gObj->AddDexterity + gObj->Dexterity)/30 + (gObj->Energy + gObj->AddEnergy)/30;
	            int SkillTime = (gObj->Energy + gObj->AddEnergy)/10 + 60;
				gObj->SetOpAddCriticalDamage += addcriticaldamagevalue;
	            gObj->m_JewelOfHarmonyEffect.HJOpAddCriticalDamage+= addcriticaldamagevalue;
				GCMagicAttackNew(gObj,64,aIndex,1);
				gObj->CriticDmBuff = 1;
			    MsgNormal(aIndex,"[AddBuff]: Increase Critical Damage Buff Added",aIndex);
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}
//========================================================================================================================
// Buff System 4 npc
//========================================================================================================================
void BuffSystem4(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
	int isActive = GetPrivateProfileInt("BuffSystem4","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem4","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin = GetPrivateProfileInt("BuffSystem4","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem4","BuffTime",20,".\\Config\\BuffSystem.cfg");
//========================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// CHECK BUFF
//========================================================================================================================
if (gObj->HealBuff == 1)
{
	return;
}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Heal             Fairy Elf
//========================================================================================================================
                gObj->HealBuff= 1;
				GCMagicAttackNew(gObj,26,aIndex,1);
			    MsgNormal(aIndex,"[AddBuff]: Heal Buff Added",aIndex);
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}
//========================================================================================================================
// Buff System 5 npc
//========================================================================================================================
void BuffSystem5(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
	int isActive = GetPrivateProfileInt("BuffSystem5","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem5","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin = GetPrivateProfileInt("BuffSystem5","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem5","BuffTime",20,".\\Config\\BuffSystem.cfg");
//========================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// CHECK BUFF
//========================================================================================================================
if(gObj->GreatDefBuff == 1 )
{
	return;
}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Greater Defense   Fairy Elf
//========================================================================================================================
gObj->GreatDefBuff = 1;
				GCMagicAttackNew(gObj,27,aIndex,1);
			    MsgNormal(aIndex,"[AddBuff]: Greater Defense Buff Added",aIndex);
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}
//========================================================================================================================
// Buff System 5 npc
//========================================================================================================================
void BuffSystem6(DWORD aIndex)
{
   OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
   int BuffNumber = rand()%8+1;
//========================================================================================================================
// Buff System Config
//========================================================================================================================
	int isActive = GetPrivateProfileInt("BuffSystem5","IsActive",1,".\\Config\\BuffSystem.cfg");
	int ZenNeed = GetPrivateProfileInt("BuffSystem5","ZenNeed",100000,".\\Config\\BuffSystem.cfg");
	int LevelMin = GetPrivateProfileInt("BuffSystem5","MaximumLevel",20,".\\Config\\BuffSystem.cfg");
	int BuffTime    = GetPrivateProfileInt("BuffSystem5","BuffTime",20,".\\Config\\BuffSystem.cfg");
//========================================================================================================================
// Buff System Active
//========================================================================================================================
if(isActive==0)
	{
		MsgNormal(aIndex,"[BuffSystem] : System is disabled.");
		return;
	}
//========================================================================================================================
// CHECK BUFF
//========================================================================================================================
if(gObj->GreatDamBuff == 1)
{
	return;
}
//========================================================================================================================
// Buff System Maximum Level
//========================================================================================================================
if (gObj->Level > LevelMin)
{
		MsgNormal(aIndex,"[BuffSystem] : You have a maximum level");
		return;
}
//========================================================================================================================
// Buff System Zen Need
//========================================================================================================================
if(gObj->Money < ZenNeed)
    {
		MsgNormal(aIndex,"[BuffSystem] : To use System you need %d zen.",ZenNeed);
		return;
	}
//========================================================================================================================
// Greater Damage   Fairy Elf
//========================================================================================================================
                gObj->GreatDamBuff = 1;
				GCMagicAttackNew(gObj,28,aIndex,1);
			    MsgNormal(aIndex,"[AddBuff]: Greater Damage Buff Added",aIndex);
//========================================================================================================================
// BuffSystem Give Zen
//========================================================================================================================
		gObj->Money -= ZenNeed;
		GCMoneySend(aIndex,gObj->Money);
}