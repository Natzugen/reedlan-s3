//======================================
// Reedlan Customs
// Coder : MaMoHT
// Start Date : 16.07.2011
//======================================
#include "NewJewels.h"
#include "stdafx.h"
#include "Utils.h"
#include "User.h"
#include "Item.h"
#include "Protocol.h"
//========================================================================================================================
//Delete Item Func
//========================================================================================================================
void DeleteItem(int aIndex, int Slot)
{		
		gObjInventoryDeleteItem(aIndex, Slot);
		GCInventoryItemDeleteSend(aIndex, Slot, 1);
}
//========================================================================================================================
//Use Item Func
//========================================================================================================================
void CGUseItemRecv(PMSG_USE_ITEM_RECV* lpMsg,int aIndex)
{	


	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	
	ITEMSTRUCT* lpItem = &gObj->pInventory[lpMsg->inventoryPos];
	ITEMSTRUCT* ProtochItem = &gObj->pInventory[lpMsg->invenrotyTarget];
//========================================================================================================================
// [14:101] Jewel Of Luck [Add Luck on Item]
//========================================================================================================================
	if (gObj->pInventory[lpMsg->inventoryPos].m_Type == ITEMGET(14,101)) // Jewel Of Luck
	{	
		srand ( time(NULL) );

		int iRate = rand()%100+1;
		int LuckJewelRate = GetPrivateProfileInt("Jewels","JewelOfLuckRate",100,".\\Custom.ini");

		if(iRate < LuckJewelRate)
		{
			if(gObj->pInventory[lpMsg->invenrotyTarget].m_Option2 < 1)
			{	
				gObj->pInventory[lpMsg->invenrotyTarget].m_Option2 = 1;

				gObjInventoryItemSet(aIndex,lpMsg->inventoryPos, -1);
				ItemClear(aIndex,lpMsg->inventoryPos);
				GCInventoryItemOneSend(aIndex, lpMsg->invenrotyTarget);
				GCInventoryItemDeleteSend(aIndex, lpMsg->inventoryPos, 1);	
			}
		}
	}
//========================================================================================================================
// [14:102] Jewel Of Everest [Make excellent from normal]
//========================================================================================================================
 if (gObj->pInventory[lpMsg->inventoryPos].m_Type == ITEMGET(14,102))
 { 
  srand ( time(NULL) );

  int iRate = rand()%100+1;
  int ElemJewelRate = GetPrivateProfileInt("Jewels","JewelOfEverestRate",100,".\\Custom.ini");
  if (gObj->pInventory[lpMsg->invenrotyTarget].m_NewOption != 0) {
			MsgNormal(aIndex,"Already excelent item!");
			return;
}

		else {
  if(iRate < ElemJewelRate)
  {
   if(gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,0) || gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,1)  || 
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,2) || gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,3)  || 
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,4) || gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,5)  ||
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,6) || gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,36) ||
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,37)|| gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,38) ||
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,39)|| gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(12,40) ||
      gObj->pInventory[lpMsg->invenrotyTarget].m_Type == ITEMGET(13,30))
   { 
           MsgNormal(aIndex,"This Jewel not use to this item");
        return;
   }
   else
   {
			(gObj->pInventory[lpMsg->invenrotyTarget].m_NewOption = 4);
			gObjInventoryItemSet(aIndex,lpMsg->inventoryPos, -1);
			ItemClear(aIndex,lpMsg->inventoryPos);
			GCInventoryItemOneSend(aIndex, lpMsg->invenrotyTarget);
			GCInventoryItemDeleteSend(aIndex, lpMsg->inventoryPos, 1); 
   }}
  }
 }
//========================================================================================================================
// [14:107] Symbol off Buff [Add Divine Buff]
//========================================================================================================================
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
		}
//========================================================================================================================
}
//========================================================================================================================