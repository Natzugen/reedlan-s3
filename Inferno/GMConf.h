//======================================
// LCTeam Season 5 Project GS 1.00.89/1.00.90 JPN
// Coder : SmallHabit
// Start Date : 16.08.2010
//======================================
#include "StdAfx.h"
#include "windows.h"

struct GMCONFDATA
{
	char szName[20];
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
};

class CGMConfig
{
public:
	void Init();
	void LoadFile(char *filename);

	bool CheckIsGM(char *szName,int type);
	void Insert(int iIndex,char *szName,int isItem,int isTrace,int isBanPost,int isClearPK,int isGlobalGG,int isSetPK,int isReload,int isSkin,int isStatus,int isTrans,int isSetzen,int isGmove);
	GMCONFDATA m_Data[512];

	int iCount;
}; extern CGMConfig g_GMConfig;
