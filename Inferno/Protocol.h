#include "Windows.h"

//========================================================================================================================
struct PBMSG_HEAD2	// Packet - Byte Type
{

public:
	BYTE c;
	BYTE size;
	BYTE headcode;
	BYTE subcode;
};
//========================================================================================================================
struct PMSG_DEFAULT2
{
	PBMSG_HEAD2 h;
	BYTE subcode;
};
struct PMSG_REQ_BUYITEM_FROM_PSHOP
{
	PBMSG_HEAD2 h;
	BYTE NumberH;	// 4
	BYTE NumberL;	// 5
	BYTE btName[10];	// 6
	BYTE btItemPos;	// 10
};
struct PMSG_DAMAGE
{
  PBMSG_HEAD2 h; // 0
  BYTE NumberH; // 3
  BYTE NumberL; // 4
  BYTE DamageH; // 5
  BYTE DamageL; // 6
  BYTE DamageType; // 7
  BYTE ShieldH; // 8
  BYTE ShieldL; // 9
  DWORD Life; // A
  DWORD MaxLife; // E
};
struct PMSG_DURATION_MAGIC_RECV
{

	PBMSG_HEAD2 h;
	BYTE MagicNumber;	// 3
	BYTE X;	// 4
	BYTE Y;	// 5
	BYTE Dir;	// 6
	BYTE Dis;	// 7
	BYTE TargetPos;	// 8
	BYTE NumberH;	// 9
	BYTE NumberL;	// A
	BYTE MagicKey;	// B
};

struct PMSG_MAGICATTACK_RESULT
{
	PBMSG_HEAD2 h;	// C3:19
	BYTE MagicNumber;	// 3
	BYTE SourceNumberH;	// 4
	BYTE SourceNumberL;	// 5
	BYTE TargetNumberH;	// 6
	BYTE TargetNumberL;	// 7
};
struct PMSG_BEATTACK_COUNT
{
	PBMSG_HEAD2 h;	// C1:D7
	BYTE MagicNumberH;	// 3
	BYTE MagicNumberL;	// 4
	BYTE X;	// 5
	BYTE Y;	// 6
	BYTE Serial;	// 7
	BYTE Count;	// 8
};

struct PMSG_TELEPORT_RESULT
{
	PBMSG_HEAD2 h;	// C3:1C
	WORD MoveNumber;	// 3 //BYTE -> WORD
	BYTE MapNumber;	// 4
	BYTE MapX;	// 5
	BYTE MapY;	// 6
	BYTE Dir;	// 7
};
struct PMSG_DURATION_MAGIC_SEND
{
	PBMSG_HEAD2 h;
	BYTE MagicNumberH;
	BYTE MagicNumberL;
	BYTE NumberH;
	BYTE NumberL;
	BYTE X;
	BYTE Y;
	BYTE Dir;
};
struct PMSG_MAGICATTACK
{
	PBMSG_HEAD2 h;
	BYTE MagicNumberH;	// 3
	BYTE MagicNumberL;	// 4
	BYTE NumberH;	// 5
	BYTE NumberL;	// 6
	BYTE Dis;	// 7
};

struct PMSG_GET_INFO // C1:F9:01
{
    PBMSG_HEAD2 h;
	int CtrCode;
	int Exp;
	int NextExp;
};
struct PMSG_CLIENTTIME
{
	PBMSG_HEAD2 h;
	DWORD Time;	// 4
	WORD AttackSpeed;	// 8
	WORD MagicSpeed;	// A
};
struct PMSG_ACTIONRESULT
{
	PBMSG_HEAD2 h;
	BYTE NumberH;
	BYTE NumberL;
	BYTE Dir;
	BYTE ActionNumber;
	BYTE TargetNumberH;
	BYTE TargetNumberL;
};
struct PMSG_SELLREQUEST 
{ 
PBMSG_HEAD2 h; 
BYTE Pos; // 3 
BYTE Info[4]; // reedlan 
}; 

struct PMSG_SELLRESULT 
{ 
PBMSG_HEAD2 h; // C1:33 
BYTE Result; // 3 
DWORD Money; // 4 
}; 
struct PMSG_ANS_PSHOP_TEXT_CHANGED
{
	PBMSG_HEAD2 h;
	BYTE NumberH;
	BYTE NumberL;
	BYTE btPShopText[36];
	BYTE btName[10];
};
struct PMSG_ANS_PSHOP_OPEN
{
	PBMSG_HEAD2 h;
	BYTE btResult;
};
struct PMSG_ANS_BUYITEM_FROM_PSHOP
{
	PBMSG_HEAD2 h;
	BYTE Result;
	BYTE NumberH;
	BYTE NumberL;
	BYTE cItemInfo[11];
	BYTE btItemPos;
};
struct PMSG_SEND_BUFF_ICON
{
	PBMSG_HEAD2 h;	// C1:2D
	WORD wOptionType;
	WORD wEffectType;
	BYTE byEffectOption;
	int iLeftTime;
	BYTE btEffectIndex;
};
struct PMSG_USEITEM
{
	PBMSG_HEAD2 h;
	BYTE inventoryPos;	// 3
	BYTE invenrotyTarget;	// 4
	BYTE btItemUseType;	// 5
};

//========================================================================================================================
bool ProtocolCore(BYTE protoNum,LPBYTE aRecv,DWORD aLen,DWORD aIndex,DWORD Encrypt,int Serial);
bool ProtocolCoreSend(int aIndex,unsigned char* aSend, int aLen);
void MsgNormal(int aIndex,char* szMsg,...);
void MsgAllNormal(int aIndex,char* szMsg,...);
void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
void BuxConvert(char* buf, int size);
void ItemClear(int aIndex,int pos);
void ItemClear1(int aIndex,int pos);
bool IsItem(int aIndex,int pos);
void SendBarMessage(DWORD PlayerID,int Color,LPCTSTR szText);
void CGLiveClient(PMSG_CLIENTTIME * lpClientTime, short aIndex);
void CGSellRequestRecv_Hook(PMSG_SELLREQUEST* lpMsg, int aIndex);
void CGPShopReqBuyItem_Hook(PMSG_REQ_BUYITEM_FROM_PSHOP * lpMsg, int aIndex);
bool CGUseItemRecv(PMSG_USEITEM* lpMsg, int aIndex);
//========================================================================================================================
