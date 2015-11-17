#include "stdafx.h"
#include "ZenEvent.h"
#include "User.h"
#include "Utils.h"

int zn = 0;
void ZenCheck(int Hour,int Minute)
{
	int iHourStart = GetPrivateProfileInt("ZenEvent","Hour",100,".\\Custom.ini");
	int iMinuteStart = GetPrivateProfileInt("ZenEvent","Minute",100,".\\Custom.ini");
	int iHourEnd = GetPrivateProfileInt("ZenEvent","HourEnd",1,".\\Custom.ini");
	int iMinuteEnd = GetPrivateProfileInt("ZenEvent","MinuteEnd",1,".\\Custom.ini");


	if(Hour == iHourStart)
	{
		if(Minute == iMinuteStart-5)
		{
	    MsgAll("Zen Event Start after 5 minuts");
		}
		if(Minute == iMinuteStart-4)
		{
	    MsgAll("Zen Event Start after 4 minuts");
		}
		if(Minute == iMinuteStart-3)
		{
	    MsgAll("Zen Event Start after 3 minuts");
		}
		if(Minute == iMinuteStart-2)
		{
	    MsgAll("Zen Event Start after 2 minuts");
		}
		if(Minute == iMinuteStart-1)
		{
	    MsgAll("Zen Event Start after 1 minuts");
		}
	}
	
	if(Hour == iHourStart)
	{
		if(Minute == iMinuteStart)
		{
		MsgAll("Zen Event start!");

			
			zn = 1;
		}
	}
   if(Hour == iHourEnd)
	{
		if(Minute == iMinuteEnd)
		{

		zn = 0;
      MsgAll("Zen Event end.");
		}
	
	}

}
void ZenDrop(DWORD gObjId)
{	
//--------------------------------------------------------------------------------------------------------------------
	int isActive = GetPrivateProfileInt("ZenEvent","Active",1,".\\Custom.ini");
	int Level = GetPrivateProfileInt("ZenEvent","Level",100,".\\Custom.ini");
    int Hour = GetPrivateProfileInt("ZenEvent","Hour",100,".\\Custom.ini");
	int Minute = GetPrivateProfileInt("ZenEvent","Minute",100,".\\Custom.ini");
	int Duration = GetPrivateProfileInt("ZenEvent","Duration",5,".\\Custom.ini");
	int LastMinute = Minute+Duration+1;
//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
	SYSTEMTIME t;
	GetLocalTime(&t);
//--------------------------------------------------------------------------------------------------------------------

	if(isActive==0)
	{
		MsgNormal(gObjId,"~[ZenEvent] : System is Disabled.");
		return;
	}
//--------------------------------------------------------------------------------------------------------------------
	if (zn ==1)
	{
//--------------------------------------------------------------------------------------------------------------------
	if(gObj->Level < Level)
	{
		MsgNormal(gObjId,"~[ZenEvent] : You need %d level to event.",Level);
		return;
	}

//--------------------------------------------------------------------------------------------------------------------

	int ItemType=0,ItemNr=0,ItemSkill=0,ItemLuck=0,ItemOpt=0,ItemExc=0,ItemDur=0;
	int ItemLevel =  rand()%15+1;
	DWORD Item = 14*512+15;
	Sleep(700);
    ItemSerialCreateSend(gObjId,gObj->MapNumber,gObj->X,gObj->Y,Item,ItemLevel,ItemDur,ItemSkill,ItemLuck,ItemOpt,gObjId,ItemExc,0);
	//MsgNormal(gObjId,"[Zen Event] : Created zen");
	}
	else
	{
	MsgNormal(gObjId,"[Zen Event] : Event is Closed");
	}
}




