//==================================================================================================
//=====================================AROTH GAMESERVER PROJECT=====================================
//==================================================================================================
// File:          PackSystem.cpp
// Description:   Custom Jewels Pack System
// Last Edit:     15.10.2011
//==================================================================================================
// Code: DarkSim, MaMoHT
//==================================================================================================
#include "User.h"
#include "Protocol.h"
#include "ChaosMaster.h"
#include "Item.h"
#include "USER.h"
#include "g_Console.h"
//==================================================================================================
// Jewels Pack System
//==================================================================================================
int repeat2;
int PackPrice = GetPrivateProfileInt("Common","PackPrice",2000000,".\\Config\\PackSystem.cfg");
int UnPackPrice = GetPrivateProfileInt("Common","UnPackPrice",2000000,".\\Config\\PackSystem.cfg");

int LifeCount = GetPrivateProfileInt("LifePack","GemCount",10,".\\Config\\PackSystem.cfg");
unsigned int LifePack = GetPrivateProfileInt("LifePack","PackItem",7275,".\\Config\\PackSystem.cfg");

int ChaosCount = GetPrivateProfileInt("ChaosPack","GemCount",10,".\\Config\\PackSystem.cfg");
unsigned int ChaosPack = GetPrivateProfileInt("ChaosPack","PackItem",7275,".\\Config\\PackSystem.cfg");

int CreationCount = GetPrivateProfileInt("CreationPack","GemCount",10,".\\Config\\PackSystem.cfg");
unsigned int CreationPack = GetPrivateProfileInt("CreationPack","PackItem",7275,".\\Config\\PackSystem.cfg");

int HarmonyCount = GetPrivateProfileInt("HarmonyPack","GemCount",10,".\\Config\\PackSystem.cfg");
unsigned int HarmonyPack = GetPrivateProfileInt("HarmonyPack","PackItem",7275,".\\Config\\PackSystem.cfg");

int GuardianCount = GetPrivateProfileInt("GuardianPack","GemCount",10,".\\Config\\PackSystem.cfg");
unsigned int GuardianPack = GetPrivateProfileInt("GuardianPack","PackItem",7275,".\\Config\\PackSystem.cfg");

//==========================
// Jewel Of Life
//==========================
 void PackLife (DWORD gObjId)
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,0x1C10,0) < LifeCount))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to pack");
 return;
 }
 gObjDeleteItemsCount(gObjId,0x1C10,0,LifeCount);
 
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

 DWORD Item = ItemType*512+ItemNr;

 ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,LifePack,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
 (gObj->Money -= PackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels packed");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Pack Bounch Of Life",gObj->AccountID,gObj->Name);
 return;
 }
//==========================
// UnPack
//==========================
void UnPackLife (DWORD gObjId)
{ 
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,LifePack,0) < 1))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to unpack");
 return;
 }
 int iEmptyCount = 0;

 for ( int x=0;x<64;x++)
 {
  if ( gObj->pInventoryMap[x] == 0xFF )
  {
   iEmptyCount++;
  }
 }

 if ( iEmptyCount < LifeCount )
 {
  MsgNormal(gObjId,"[SYSTEM] You dont have inventory space");
 }
 else 
 {
 gObjDeleteItemsCount(gObjId,LifePack,0,1);
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
 DWORD Item = ItemType*512+ItemNr;
do
{
ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,0x1C10,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
repeat2++;
} while (repeat2 < LifeCount);
 (gObj->Money -= UnPackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels unpacked");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Unpack Bounch Of Life",gObj->AccountID,gObj->Name);
 repeat2=0;
 return;
 }
}

//==========================
// Jewel Of Chaos
//==========================
 void PackChaos (DWORD gObjId)
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,0x180F,0) < ChaosCount))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to pack");
 return;
 }
 gObjDeleteItemsCount(gObjId,0x180F,0,ChaosCount);
 
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

 DWORD Item = ItemType*512+ItemNr;

 ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,ChaosPack,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
 (gObj->Money -= PackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels packed");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Pack Bounch Of Chaos",gObj->AccountID,gObj->Name);
 return;
 }
//==========================
// UnPack Chaos
//==========================
void UnPackChaos (DWORD gObjId)
{ 
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,ChaosPack,0) < 1))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to unpack");
 return;
 }
 int iEmptyCount = 0;

 for ( int x=0;x<64;x++)
 {
  if ( gObj->pInventoryMap[x] == 0xFF )
  {
   iEmptyCount++;
  }
 }

 if ( iEmptyCount < ChaosCount )
 {
  MsgNormal(gObjId,"[SYSTEM] You dont have inventory space");
 }
 else 
 {
 gObjDeleteItemsCount(gObjId,ChaosPack,0,1);
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
 DWORD Item = ItemType*512+ItemNr;
do
{
ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,0x180F,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
repeat2++;
} while (repeat2 < ChaosCount);
 (gObj->Money -= UnPackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);

 MsgNormal(gObjId,"[SYSTEM] Jewels unpacked"); 
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Unpack Bounch Of Chaos",gObj->AccountID,gObj->Name);
 repeat2=0;
 return;
 }
}


//==========================
// Jewel Of Creation
//==========================
 void PackCreation (DWORD gObjId)
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,0x1C16,0) < CreationCount))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to pack");
 return;
 }
 gObjDeleteItemsCount(gObjId,0x1C16,0,CreationCount);
 
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

 DWORD Item = ItemType*512+ItemNr;

 ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,CreationPack,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
 (gObj->Money -= PackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels packed");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Pack Bounch Of Creation",gObj->AccountID,gObj->Name);
 return;
 }
//==========================
// UnPack  Creation
//==========================
void UnPackCreation (DWORD gObjId)
{ 
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,CreationPack,0) < 1))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to unpack");
 return;
 }
 int iEmptyCount = 0;

 for ( int x=0;x<64;x++)
 {
  if ( gObj->pInventoryMap[x] == 0xFF )
  {
   iEmptyCount++;
  }
 }

 if ( iEmptyCount < CreationCount )
 {
  MsgNormal(gObjId,"[SYSTEM] You dont have inventory space");
 }
 else 
 {
 gObjDeleteItemsCount(gObjId,CreationPack,0,1);
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
 DWORD Item = ItemType*512+ItemNr;
do
{
ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,0x1C16,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
repeat2++;
} while (repeat2 < CreationCount);
 (gObj->Money -= UnPackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);

 MsgNormal(gObjId,"[SYSTEM] Jewels unpacked"); 
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Unpack Bounch Of Creation",gObj->AccountID,gObj->Name);
 repeat2=0;
 return;
 }
}

//==========================
// Jewel Of Harmony
//==========================
 void PackHarmony (DWORD gObjId)
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,0x1C2A,0) < HarmonyCount))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to pack");
 return;
 }
 gObjDeleteItemsCount(gObjId,0x1C2A,0,HarmonyCount);
 
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

 DWORD Item = ItemType*512+ItemNr;

 ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,HarmonyPack,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
 (gObj->Money -= PackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels packed");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Pack Bounch Of Harmony",gObj->AccountID,gObj->Name);
 return;
 }
//==========================
// UnPack Harmony
//==========================
void UnPackHarmony (DWORD gObjId)
{ 
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,HarmonyPack,0) < 1))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to unpack");
 return;
 }
 int iEmptyCount = 0;

 for ( int x=0;x<64;x++)
 {
  if ( gObj->pInventoryMap[x] == 0xFF )
  {
   iEmptyCount++;
  }
 }

 if ( iEmptyCount < HarmonyCount )
 {
  MsgNormal(gObjId,"[SYSTEM] You dont have inventory space");
 }
 else 
 {
 gObjDeleteItemsCount(gObjId,HarmonyPack,0,1);
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
 DWORD Item = ItemType*512+ItemNr;
do
{
ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,0x1C2A,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
repeat2++;
} while (repeat2 < HarmonyCount);
 (gObj->Money -= UnPackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);

 MsgNormal(gObjId,"[SYSTEM] Jewels unpacked"); 
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Unpack Bounch Of Harmony",gObj->AccountID,gObj->Name);
 repeat2=0;
 return;
 }
}


//==========================
// Jewel Of Guardian
//==========================
 void PackGuardian (DWORD gObjId)
{
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,0x1C1F,0) < GuardianCount))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to pack");
 return;
 }
 gObjDeleteItemsCount(gObjId,0x1C1F,0,GuardianCount);
 
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;

 DWORD Item = ItemType*512+ItemNr;

 ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,GuardianPack,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
 (gObj->Money -= PackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);
 MsgNormal(gObjId,"[SYSTEM] Jewels packed");
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Pack Bounch Of Guardian",gObj->AccountID,gObj->Name);
 return;
 }
//==========================
// UnPack Guardian
//==========================
void UnPackGuardian (DWORD gObjId)
{ 
 OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

 if((gObjGetItemCountInInventory(gObjId,GuardianPack,0) < 1))
 {
 MsgNormal(gObjId,"[SYSTEM] You dont have jewels to unpack");
 return;
 }
 int iEmptyCount = 0;

 for ( int x=0;x<64;x++)
 {
  if ( gObj->pInventoryMap[x] == 0xFF )
  {
   iEmptyCount++;
  }
 }

 if ( iEmptyCount < GuardianCount )
 {
  MsgNormal(gObjId,"[SYSTEM] You dont have inventory space");
 }
 else 
 {
 gObjDeleteItemsCount(gObjId,GuardianPack,0,1);
 int ItemType=0,ItemNr=0,ItemLevel=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
 DWORD Item = ItemType*512+ItemNr;
do
{
ItemSerialCreateSend(gObjId,235,gObj->X,gObj->Y,0x1C1F,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
repeat2++;
} while (repeat2 < GuardianCount);
 (gObj->Money -= UnPackPrice);
 GCMoneySend(gObj->m_Index, gObj->Money);

 MsgNormal(gObjId,"[SYSTEM] Jewels unpacked"); 
 g_Console.ConsoleOutput(4,"[JEWELS][%s][%s] Unpack Bounch Of Guardian",gObj->AccountID,gObj->Name);
 repeat2=0;
 return;
 }
}