#include <Windows.h>
#include "Protocol.h"
#include <stdio.h>
#include "USER.h"
#include "GMConf.h"
#include "g_Console.h"
#include "MSSQL.h"
#include <time.h>
void OnStartConfig()
{	
	//Version
	//sprintf(GLOBAL.Version,"1.1.1.8");
	//Configs Summon System
	// [30] Summon Command

	//Configs File Names
	char FileGlobal[25] = ".//Custom.ini";



	//Customs
	//if((strcmp(GLOBAL.Serial,"276798215") == 0) || (strcmp(GLOBAL.Serial,"60391424") == 0))
	//{	
		GetPrivateProfileString("GameServer","WelcomeMsg","Welcome to RebellionMu",CNMS.Custom1,200,FileGlobal);
		GetPrivateProfileString("GameServer","ServerName","RebellionMu",CNMS.Custom2,200,FileGlobal);
		GetPrivateProfileString("GameServer","HomePage","www.Rebellion-Mu.ru",CNMS.Custom3,200,FileGlobal);
	//}

}