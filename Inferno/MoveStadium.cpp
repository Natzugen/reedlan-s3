#include "StdAfx.h"
#include "MoveStadium.h"
#include "USER.h"
#include "Utils.h"
#include "MoveReq.h"
#include "MSSQL.h"
void MoveStad(int aIndex)
{   
	//--------------------------------------------------------------------------------------------------------------------
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	SQL.GetResetCharacter(gObj->Name);
	char MSG1[200];
	//--------------------------------------------------------------------------------------------------------------------
	int MoveSystemOn = GetPrivateProfileInt("MoveStadium","Active",1,".\\Custom.ini");
	int MoveSystemReset = GetPrivateProfileInt("MoveStadium","MaxReset",5,".\\Custom.ini");
	int MoveSystemMap = GetPrivateProfileInt("MoveStadium","MoveMap",5,".\\Custom.ini");
	int MoveSystemX = GetPrivateProfileInt("MoveStadium","MoveX",5,".\\Custom.ini");
	int MoveSystemY = GetPrivateProfileInt("MoveStadium","MoveY",5,".\\Custom.ini");
	GetPrivateProfileString("MoveStadium","ErrorMSG","Maxium Resets",MSG1,200,".\\Custom.ini");
	//--------------------------------------------------------------------------------------------------------------------
	if (MoveSystemOn == 0)
	{
	return;
	}
	if(gObj->MapNumber == 6)
	{
	           if(SQL.ResetS > MoveSystemReset)
					{	
						MsgNormal(aIndex,MSG1);
						gObjTeleport(aIndex, MoveSystemMap, MoveSystemX,MoveSystemY);

						return;
					}
					else
					{	


					}
	}
	//--------------------------------------------------------------------------------------------------------------------
	
}