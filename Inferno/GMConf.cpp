//======================================
// LCTeam Season 5 Project GS 1.00.89/1.00.90 JPN
// Coder : SmallHabit
// Start Date : 16.08.2010
//======================================
#include "GMConf.h"
#include "Protocol.h"
#include "User.h"
#include "SMDToken.h"
//========================================================================================================================
CGMConfig g_GMConfig;
//========================================================================================================================
void CGMConfig::Init()
{
	for(int i=0;i<512;i++)
	{
		this->m_Data[i].isItem = 0;
		this->m_Data[i].isTrace = 0;
		this->m_Data[i].isBanPost = 0;
		this->m_Data[i].isClearPK = 0;
		this->m_Data[i].isGlobalGG = 0;
		this->m_Data[i].isSetPK = 0;
		this->m_Data[i].isReload = 0;
		this->m_Data[i].isSkin = 0;
		this->m_Data[i].isStatus = 0;
		this->m_Data[i].isTrans = 0;
		this->m_Data[i].isSetzen = 0;
		this->m_Data[i].isGmove = 0;
		this->iCount = 0;
	}
}
//========================================================================================================================
void CGMConfig::LoadFile(char *filename)
{
	this->Init();
	
	if((SMDFile = fopen(filename, "r")) == NULL)
	{
		MessageBoxA(0,"GMConfig::LoadFile() error","CRITICAL ERROR",0);
		ExitProcess(1);
		return;
	}

	SMDToken Token;
	int iIndex;
	char szName[40] = {0};
	int isItem;
	int isTrace;
	int isBanPost;
	int isClearPK;
	int isGlobalGG;
	int isSetPK;
	int isReload;
	int isSkin;
	int isStatus;
	int isTrans;
	int isSetzen;
	int isGmove;
	while(true)
	{
		Token = GetToken();
		
		if(Token == END)
			break;
	
		if(Token == NUMBER)
		{
			iIndex = TokenNumber;
			
			while(true)
			{	
				Token = GetToken();
				
				if(strcmp("end",TokenString) == 0)
					break;

				iIndex = TokenNumber;

				Token = GetToken();
				memcpy(szName,TokenString,sizeof(szName));

				Token = GetToken();
				isItem = TokenNumber;	

				Token = GetToken();
				isTrace = TokenNumber;

				Token = GetToken();
				isBanPost = TokenNumber;
				
				Token = GetToken();
				isClearPK = TokenNumber;

				Token = GetToken();
				isGlobalGG = TokenNumber;

				Token = GetToken();
				isSetPK = TokenNumber;

				Token = GetToken();
				isSkin = TokenNumber;

				Token = GetToken();
				isReload = TokenNumber;

				Token = GetToken();
				isStatus = TokenNumber;
			    
				Token = GetToken();
				isTrans = TokenNumber;

				Token = GetToken();
				isSetzen = TokenNumber;

				Token = GetToken();
				isGmove = TokenNumber;

				this->Insert(iIndex,szName,isItem,isTrace,isBanPost,isClearPK,isGlobalGG,isSetPK,isReload,isSkin,isStatus,isTrans,isSetzen,isGmove);	

				this->iCount++;
			}
		}
	}

	fclose(SMDFile);
	return;
}
//========================================================================================================================
void CGMConfig::Insert(int iIndex,char *szName,int isItem,int isTrace,int isBanPost,int isClearPK,int isGlobalGG,int isSetPK,int isReload,int isSkin,int isStatus,int isTrans,int isSetzen,int isGmove)
{
	this->m_Data[iIndex].isItem = isItem;
	this->m_Data[iIndex].isTrace = isTrace;
	this->m_Data[iIndex].isBanPost = isBanPost;
	this->m_Data[iIndex].isClearPK = isClearPK;
	this->m_Data[iIndex].isGlobalGG = isGlobalGG;
	this->m_Data[iIndex].isSetPK = isSetPK;
	this->m_Data[iIndex].isReload = isReload;
	this->m_Data[iIndex].isSkin = isSkin;
	this->m_Data[iIndex].isStatus = isStatus;
	this->m_Data[iIndex].isTrans = isTrans;
	this->m_Data[iIndex].isSetzen = isSetzen;
	this->m_Data[iIndex].isGmove = isGmove;
	strcpy(this->m_Data[iIndex].szName,szName);
}
//========================================================================================================================
bool CGMConfig::CheckIsGM(char *szName,int type)
{
	for(int i=0;i<this->iCount;i++)
	{	
		if( strcmp(szName,this->m_Data[i].szName) == 0)
		{	
			if(type == 0)
			{
				if(this->m_Data[i].isItem == 1)
					return true;
			}
			else if(type == 1)
			{
				if(this->m_Data[i].isTrace == 1)
					return true;
			}
			else if(type == 2)
			{
				if(this->m_Data[i].isBanPost == 1)
					return true;
			}
			else if(type == 3)
			{
				if(this->m_Data[i].isClearPK == 1)
					return true;
			}
			else if(type == 4)
			{
				if(this->m_Data[i].isGlobalGG == 1)
					return true;
			}
			else if(type == 5)
			{
				if(this->m_Data[i].isSetPK == 1)
					return true;
			}
			else if(type == 6)
			{
				if(this->m_Data[i].isReload == 1)
					return true;
			}

			else if(type == 7)
			{
				if(this->m_Data[i].isSkin == 1)
					return true;
			}
			else if(type == 8)
			{
				if(this->m_Data[i].isStatus == 1)
					return true;
			}
			else if(type == 9)
			{
				if(this->m_Data[i].isTrans == 1)
					return true;
			}

			else if(type == 10)
			{
				if(this->m_Data[i].isSetzen == 1)
					return true;
			}

			else if(type == 11)
			{
				if(this->m_Data[i].isGmove == 1)
					return true;
			}

			else
			{
				return false;
			}
		}
	}
	
	return false;
}
//========================================================================================================================