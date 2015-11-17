#pragma once
#include "Item.h"
void ChaosSendMixFail ( DWORD gObjID );
void ChaosBoxHook(DWORD gObjID , DWORD MixID);
int gObjGetItemCountInChaosbox(int aIndex, short type);
bool gObjGetItemInChaosbox(int aIndex, short type);
int gObjGetItemLevelInChaosbox(int aIndex, short type);
int gObjGetItemCountInInventory(int aIndex, short type);
void ChaosboxItemsRegardingEx();