#include <stdio.h>
#include "windows.h"
// ---
#include "g_Console.h"
#include "TEnum.h"
#include "StdAfx.h"
// -----------------------------------------------------------------------
Console g_Console;
// -----------------------------------------------------------------------
DWORD PiD;
// -----------------------------------------------------------------------

Console::Console()
{
	// ----
}
// -----------------------------------------------------------------------

Console::~Console()
{
	// ----
}
// -----------------------------------------------------------------------

void __stdcall LoggerCore(PVOID pVoid)
{
	char Temp[1024];
	// ----
	AllocConsole();
	SetConsoleTitleA(CONSOLETITLE);
	// ----
	while(true)
	{
		Sleep(100);
		g_Console.AddMessageToConsole(Temp);
		g_Console.LoadConsoleCommands(Temp);
	}
}
// -----------------------------------------------------------------------

void Console::InitCore()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LoggerCore, 0, 0, &PiD); 
	Sleep(100);
	// ----
	this->ConsoleOutput(1,"[ Developed ] GameServer Start");
	this->ConsoleOutput(1,"[ Developed ] Version 2.0.0.3");
	this->ConsoleOutput(1,"[ Developed ] Server Version : Season 3 ep 1");
}
// -----------------------------------------------------------------------

void Console::ConsoleOutput(int Color , const char* Format, ...)
{
	SYSTEMTIME Time;
	GetLocalTime(&Time);
	// ----
	char Message[1024];
	char MessageOutPut[2048];
	DWORD dwBytes;
	// ----
	HANDLE Handle		 = GetStdHandle(STD_OUTPUT_HANDLE);
	char CorrectDate[11] = {0};
	// ----
	va_list pArguments;
	va_start(pArguments, Format);
	vsprintf_s(Message , Format , pArguments);
	va_end(pArguments);
	// ----
	sprintf_s(CorrectDate , "[%02d:%02d:%02d]" , Time.wHour , Time.wMinute , Time.wSecond);
	// ----
	sprintf_s(MessageOutPut , "%s %s\n" , CorrectDate , Message);
	// ----
	switch(Color)
	{
		// Color Red Console.
		case CNSL_E::CONSOLE_RED:
		{
			SetConsoleTextAttribute(this->Handle(FALSE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		break;
		// Color Green Console.
		case CNSL_E::CONSOLE_GREEN:
		{
			SetConsoleTextAttribute(this->Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		break;
		// Color Blue Console.
		case CNSL_E::CONSOLE_BLUE:
		{
			SetConsoleTextAttribute(this->Handle(FALSE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		break;
		// Color Cyan Console.
		case CNSL_E::CONSOLE_CYAN:
		{
			SetConsoleTextAttribute(this->Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		break;
		// Color Yellow Console.
		case CNSL_E::CONSOLE_YELLOW:
		{
			SetConsoleTextAttribute(this->Handle(FALSE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		break;
	}
	// ----
	WriteFile(Handle , MessageOutPut , strlen(MessageOutPut) , &dwBytes , NULL);
}
// -----------------------------------------------------------------------

int Console::AddMessageToConsole(char* Buffer)
{
	char Text[1024];
	DWORD dwBytes;
	// ----
	memset(Text,   0x00, 1024);
	memset(Buffer, 0x00, 1024);
	// ----
	ReadFile(Handle(TRUE), Text, 1024, &dwBytes, NULL);
	// ----
	strncpy(Buffer, Text, strlen(Text) - 2);
	// ----
	return dwBytes;
}
// -----------------------------------------------------------------------

HANDLE Console::Handle(BOOL gImput)
{
	if(gImput == TRUE)
	{
		return GetStdHandle(STD_INPUT_HANDLE);
	}
	// ----
	else
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
}
// -----------------------------------------------------------------------

void Console::LoadConsoleCommands(char* gImput)
{
	char Temp[1024]		= {0};
	// ----
	if(!strncmp(gImput, "/clear" , 7))
	{
		system("cls");
		return;
	}
	// ----
	else if((!strncmp(gImput, "/exit", 5)) || 
			(!strncmp(gImput, "/quit", 5)) || 
			(!strncmp(gImput, "/close", 5)))
	{
		exit(1);
		return ;
	}
}

// -----------------------------------------------------------------------
extern Console g_Console;
// -----------------------------------------------------------------------