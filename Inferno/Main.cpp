#include "Fix.h"
#include "g_Console.h"
#include "Protocol.h"
#include "GMConf.h"
#include "MSSQL.h"
#include "offTrade.h"
#include "USER.h"
#include "Utils.h"
#include "MoveReq.h"
#include "MoveStadium.h"
#include <Windows.h>
#include "PostBlock.h"
#include "DropZen.h"
#include "BuffSystem.h"
UINT NumIps = 0;
char sql_server[256];
char sql_dbname[256];
char sql_access[256];
char sql_dbpass[255];

__declspec (dllexport) DWORD ProtocolClient(DWORD Type)
{
	if(Type == 0x1D)return 0x1D;
	if(Type == 0xD6)return 0xD6;
	if(Type == 0xDC)return 0xDC;
	return Type;
}

__declspec (dllexport) DWORD ProtocolServer(DWORD Type)
{
	if(Type == 0x1D)return 0x1D;
	if(Type == 0xD6)return 0xD6;
	if(Type == 0xDC)return 0xDC;
	return Type;
}

void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset-(dwJmpOffset+5);
}



extern "C" _declspec(dllexport) void Load()
{	
	DWORD dProtect;
	// ----
	if(VirtualProtect (LPVOID (0x401000) , 0x00746FFF, PAGE_EXECUTE_READWRITE , &dProtect))
	{
		_asm
		{
			MOV DWORD PTR DS:[00700000H],Offset ProtocolServer
			MOV DWORD PTR DS:[00700004H],Offset ProtocolClient
		}
//========================================================================================================================
// Config
//========================================================================================================================
		GetPrivateProfileStringA("SQL", "Account",	"sa"		,sql_access,sizeof(sql_access),	".\\Custom.ini");
		GetPrivateProfileStringA("SQL", "Password",	"sa"		,sql_dbpass,sizeof(sql_dbpass),	".\\Custom.ini");
		GetPrivateProfileStringA("SQL", "DataBase",	"MuOnline"	,sql_dbname,sizeof(sql_dbname),	".\\Custom.ini");
		GetPrivateProfileStringA("SQL", "Server",	"127.0.0.1"	,sql_server,sizeof(sql_server),	".\\Custom.ini");		
//========================================================================================================================
		if( SQL.Connect(3,(SQLCHAR*)sql_dbname,(SQLCHAR*)sql_access,(SQLCHAR*)sql_dbpass) == true )
		{
//========================================================================================================================
// Hooks
//========================================================================================================================
			HookThis((DWORD)&ProtocolCore,0x00403BA7);
			HookThis((DWORD)&gObjViewProtocolListCreateHook,0x00405D44);
		    HookThis((DWORD)&CloseClient2Hook,0x00405CA4); //rl Season 3 Reload ok
	  		HookThis((DWORD)&CGPShopAnsCloseHook,0x00404552); //rl Season 3 Reload ok
		    HookThis((DWORD)&ResponErrorCloseClientHook,0x00407E82); //rl Season 3 Reload ok
	 		HookThis((DWORD)&CloseClientHook,0x0040422D); //rl Season 3 Reload ok
			HookThis((DWORD)&MygEventMonsterItemDrop, 0x00405402); 
			HookThis((DWORD)&MyObjCalCharacter,0x004033C3);
            HookThis((DWORD)&gObjLifeCheckHook, 0x00402FFE); 
		    HookThis((DWORD)&gObjMissCheckHook, 0x004074C3); 
	        HookThis((DWORD)&CGLiveClient, 0x00405D94); 
			HookThis((DWORD)&CGSellRequestRecv_Hook,0x0040723E);
			HookThis((DWORD)&CGPShopReqBuyItem_Hook,0x00406DD9);
			
//========================================================================================================================
// Systems
//========================================================================================================================
			g_Console.InitCore();
			g_GMConfig.LoadFile("GMList.txt");
		  //CpuID();
			OFFTrade.Init();
			TitleGS();
			g_Fix.Load();
//========================================================================================================================
// Timers
//========================================================================================================================
			_beginthread(PostBlockTimer,0,NULL);
			_beginthread(Server_UpdateTimer,0,NULL);
//========================================================================================================================
// Console
//========================================================================================================================
			g_Console.ConsoleOutput(4,"[ Loading ] 'MSSQL Connect' loaded successfully.");
			g_Console.ConsoleOutput(4,"[ Loading ] 'GMList loaded' successfully.");
			g_Console.ConsoleOutput(4,"[ Loading ]  'Protocol' loaded successfully.");
			g_Console.ConsoleOutput(4,"[ Loading ]  'Configs' loaded successfully.");
			g_Console.ConsoleOutput(2,"[ ResetSystem ]  Reset System 2.0 loaded successfully!");
			g_Console.ConsoleOutput(2,"[ OffTrade ]  Offline Trade System 5.0 loaded successfully!");
//========================================================================================================================
// Events
//========================================================================================================================
//========================================================================================================================
		}
		else
		{
			MessageBoxA(NULL, "MSSQL Connect Fail, Check Custom.ini", "Error", MB_OK);
			ExitProcess(0);
		}
	}
	else
	{
		MessageBoxA(NULL, "DLL Lybrary not Loaded", "Error", MB_OK);
		// ----
		ExitProcess(0);
	}
}
