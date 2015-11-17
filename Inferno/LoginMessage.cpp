#include <Windows.h>
#include "Protocol.h"
#include <stdio.h>
#include "USER.h"
#include "GMConf.h"
#include "g_Console.h"
#include "MSSQL.h"
#include <time.h>
void LoginMessage(int aIndex )

{

	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex); 
	//int totGMs = GetGMCount();
	int online = 0;
	if(aIndex > OBJECT_MAX)
		return;

	char Message4[200];
	char Message1[100];
	char Message2[100];
	char Message3[100];
	char Message5[100];
	int Hour;
	int Minute;
    SYSTEMTIME t;
	GetLocalTime(&t);
	t.wHour = Hour;
	t.wMinute = Minute;
	sprintf(Message1,"[MuOnline.com]Welcome to RebellionMu!",gObj->Name);	
	sprintf(Message5,"[MuOnline.com]Time : %d:%d:%d / %d.%d.%d",t.wHour,t.wMinute,t.wSecond,t.wDay,t.wMonth,t.wYear);
	sprintf(Message4,"[MuOnline.com]Players Online: %d/500",online); 
	sprintf(Message3,"[MuOnline.com]Home Page: http://www.webmu.ru");	
	GCServerMsgStringSend(Message1,aIndex,1); 
	GCServerMsgStringSend(Message2,aIndex,1);
	GCServerMsgStringSend(Message5,aIndex,1);
	GCServerMsgStringSend(Message4,aIndex,1);
	GCServerMsgStringSend(Message3,aIndex,1);
}