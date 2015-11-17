#include "StdAfx.h"
#include "DropZen.h"
#include "SMDToken.h"
#include "Utils.h"
#include "User.h"

int MygEventMonsterItemDrop(BYTE *b_MonsterDataAddr,BYTE *a_gObjAddr)
	// 2Class = 1, 17, 33, 49, 65
	// 3Class = 2, 18, 34, 50, 66
{
	PBYTE a_aIndex = 0;
	PBYTE b_mIndex = 0;

	a_aIndex = (PBYTE)a_gObjAddr;
	b_mIndex = (PBYTE)b_MonsterDataAddr;

	WORD mIndex = 0;
	WORD aIndex = 0;
	int vActive = GetPrivateProfileInt("DropZen","Active",1,".\\Config\\DropZen.cfg");
	int vDropZenPlus = GetPrivateProfileInt("DropZen","DropZenPlus",1,".\\Config\\DropZen.cfg");
	int vZenMoney = GetPrivateProfileInt("DropZen","ZenMoney",1,".\\Config\\DropZen.cfg");
	int vZenDrop = GetPrivateProfileInt("DropZen","ZenDrop",1,".\\Config\\DropZen.cfg");

	memcpy(&mIndex, b_mIndex+0x00,sizeof(WORD));
	memcpy(&aIndex, a_aIndex+0x00,sizeof(WORD));
	int Randomer = rand()%100+1;
	OBJECTSTRUCT *mObj = (OBJECTSTRUCT*) OBJECT_POINTER (mIndex);
	OBJECTSTRUCT *pObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	int MoneyMob = mObj->Money/Randomer;
	int Default = gEventMonsterItemDrop(b_MonsterDataAddr, a_gObjAddr);


	int StateMoney = vZenMoney;

	if (vActive == 1)
	{
		/*if (vDropZenPlus == 1)
		{
        if(Randomer < vZenDrop)
				{
		mObj->Money += StateMoney;
		return Default;
		}
		else
		{
		return Default;
		}
		}
		else
		{
		mObj->Money -= StateMoney;
		return Default;
		}*/

		mObj->Money =MoneyMob;
	}
	else
	{
		return Default;
	}
	return 1;
}
