#include "stdafx.h"
#define MAX_ITEM_INFO 12


struct PSBMSG_HEAD_Le
{
    BYTE type;
	BYTE size;
	BYTE head;
	BYTE subh;
};

struct PMSG_ITEM_MODIFY_SEND 
{
    PSBMSG_HEAD_Le header; //C1:F3:14
    BYTE slot;
    BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PBMSG_HEAD_it
{
    BYTE type;
	BYTE size;
	BYTE head;
};


struct PMSG_USE_ITEM_RECV
{
	PBMSG_HEAD_it h;
	BYTE inventoryPos;	// 3
	BYTE invenrotyTarget;	// 4
	BYTE btItemUseType;	// 5
};



void CGUseItemRecv(PMSG_USE_ITEM_RECV* lpMsg,int aIndex);