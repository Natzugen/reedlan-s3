#include "SynFlood.h"
#include "User.h"
#include "Utils.h"
#include "MSSQL.h"

/*void SynFloodConnect(int aIndex)
{
OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
SQL.SynFloodProtect2(gObj->Ip_addr);
	 MsgNormal(aIndex,"[SynFlood] : SynFloodConnect");
}


void SynFlood(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	SQL.SynFloodProtect1(gObj->Ip_addr);
		 MsgNormal(aIndex,"[SynFlood] : SynFlood");
	if(SQL.CountIp > 0)
	{
	 CloseClient(aIndex);
	 MsgNormal(aIndex,"[SynFlood] : CloseClient");
	}
}
void gObjAdd(SOCKET aSocket, char* ip, int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
  	SynFloodConnect(aIndex);
	SynFlood(aIndex);
}*/



