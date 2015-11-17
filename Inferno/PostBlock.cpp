#include "PostBlock.h"
#include "User.h"
#include "Utils.h"
#include "StdAfx.h"
#include "MSSQL.h"
#include <time.h>
#pragma warning(disable: 4244)



void OffExp(void * lpParam)
{

	while(true)
	{ 
	Sleep(60000); 
	for(int i=OBJECT_MIN;i<OBJECT_MAX;i++)
	{

		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
	
	int  PostBlockD;
	int BlockPost = SQL.GetBlockPCharacter(gObj->Name);
   if(OfflineShop[i].IsOffTrade == 1)
   {
		if(gObj->Connected == 3)
		{	
			
	
			SYSTEMTIME t;
			GetLocalTime(&t);
		//	SQL.UpdatePostBCharacter2(gObj->Name,PostBlockD);
					GCMagicAttackNew(gObj,46,gObj->m_Index,1);
	GCLevelUpMsgSend(gObj->m_Index,0);
	//Sleep(120000);
		}
	
	
   }
	}
	}
	_endthread();
}
