#include "Fix.h"
#include "Functions.h"
#include "Item.h"
#include "USER.h"
#include "Utils.h"
#include "MoveStadium.h"
//========================================================================================================================
Fix g_Fix;
//========================================================================================================================
Fix::Fix(void)
{
}
//========================================================================================================================
Fix::~Fix(void)
{
}


//========================================================================================================================
__inline __declspec(naked) void ItemPrice()
{   
    _asm
    {
        MOV EDX,DWORD PTR SS:[EBP-0x04]
        MOVSX EAX,WORD PTR DS:[EDX+0x06]
        CMP EAX,0x1C0E
        JNZ Item1
		MOV DWORD PTR SS:[EBP-0x14], 0x5B8D80
		MOV DWORD PTR SS:[EBP-0x10], 0x00
		JMP Exit
Item1:
        MOV EDX,DWORD PTR SS:[EBP-0x04]
        MOVSX EAX,WORD PTR DS:[EDX+0x06]
        CMP EAX,0x1C68 // [14:104]
        JNZ Item2
        MOV DWORD PTR SS:[EBP-0x14],0x5F5E100 // [100 000 000]
        MOV DWORD PTR SS:[EBP-0x10], 0x00
        JMP Exit
Item2:
        MOV EDX,DWORD PTR SS:[EBP-0x04]
        MOVSX EAX,WORD PTR DS:[EDX+0x06]
        CMP EAX,0x1C69 // [14:105]
        JNZ Item3
        MOV DWORD PTR SS:[EBP-0x14], 0xEE6B280 // [250 000 000]
        MOV DWORD PTR SS:[EBP-0x10], 0x00
        JMP Exit
Item3:
        MOV EDX,DWORD PTR SS:[EBP-0x04]
        MOVSX EAX,WORD PTR DS:[EDX+0x06]
        CMP EAX,0x1C6A // [14:106]
        JNZ Continue
        MOV DWORD PTR SS:[EBP-0x14], 0x1DCD6500 // [500 000 000]
        MOV DWORD PTR SS:[EBP-0x10], 0x00
        JMP Exit
Exit:
        mov esi,0x005F3B7F
        jmp esi
Continue:
		mov esi,0x005F2AD3
		jmp esi
    }
}
void FoldersChange()
{
char cTemp2[30] = "Logs\\Chat";
    DWORD *offsetChatFolder = (DWORD*)(FolderChatLog);
    memset(&offsetChatFolder[0],0,30);
    memcpy(&offsetChatFolder[0],cTemp2,strlen(cTemp2));

	char cTemp3[30] = "Logs\\CastleSiege";
    DWORD *offsetCSFolder = (DWORD*)(FolderCastleSiege);
    memset(&offsetCSFolder[0],0,30);
    memcpy(&offsetCSFolder[0],cTemp3,strlen(cTemp3));

	char cTemp4[30] = "Logs\\Kanturu";
    DWORD *offsetKanturuFolder = (DWORD*)(FolderKanturu);
    memset(&offsetKanturuFolder[0],0,30);
    memcpy(&offsetKanturuFolder[0],cTemp4,strlen(cTemp4));

	char cTemp5[30] = "Logs\\Kundun";
    DWORD *offsetKundunFolder = (DWORD*)(FolderKundunGM);
    memset(&offsetKundunFolder[0],0,30);
    memcpy(&offsetKundunFolder[0],cTemp5,strlen(cTemp5));

	char cTemp6[30] = "Logs\\Kundun";
    DWORD *offsetKundun2Folder = (DWORD*)(FolderKundunEvent);
    memset(&offsetKundun2Folder[0],0,30);
    memcpy(&offsetKundun2Folder[0],cTemp6,strlen(cTemp6));

	char cTemp7[30] = "Logs\\Connect";
    DWORD *offsetConnectFolder = (DWORD*)(FolderServerConnect);
    memset(&offsetConnectFolder[0],0,30);
    memcpy(&offsetConnectFolder[0],cTemp7,strlen(cTemp7)); 

	char cTemp8[27] = ".\\Logs\\%02d%02d%02d_%s.log";
    DWORD *offsetLogFolder = (DWORD*)(FolderLogs);
    memset(&offsetLogFolder[0],0,27);
    memcpy(&offsetLogFolder[0],cTemp8,strlen(cTemp8)); 

	char cTemp9[25] = "Data\\Server.dat";
    DWORD *offsetFileInfo = (DWORD*)(FileServerInfo);
    memset(&offsetFileInfo[0],0,25);
    memcpy(&offsetFileInfo[0],cTemp9,strlen(cTemp9));

}
void ItemTo15()
{
	/*//Fix Item Level Max to +15 TEST
	BYTE FixItemLevelMax1[] = { 0x83, 0xFA, 0x0F };
	memcpy((int*)0x00498D84,FixItemLevelMax1,sizeof(FixItemLevelMax1));

	BYTE FixItemLevelMax2[] = { 0x83, 0xF9, 0x0F };
	memcpy((int*)0x005AC5BE,FixItemLevelMax2,sizeof(FixItemLevelMax2));
	

	BYTE FixItemLevelMax3[] = { 0x83, 0x7D, 0xFC, 0x0F};
	memcpy((int*)0x005C9989,FixItemLevelMax3,sizeof(FixItemLevelMax3));

	BYTE FixItemLevelMax4[] = { 0x83, 0x7D, 0x08, 0x0F};
	memcpy((int*)0x005C9A29,FixItemLevelMax4,sizeof(FixItemLevelMax4));
	*/
}
//==============================================================================
void Fix::Load()
{		
//==============================================================================
// Folders Changer
//==============================================================================
	FoldersChange();
//==============================================================================
// Level Max to +15 TEST
//==============================================================================
	ItemTo15();
//==============================================================================
// Calculator
//==============================================================================
	*(unsigned int *) AttackDamageMin_Bow_StrDexDiv_Elf1	 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_Bow_StrDexDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_Bow_StrDexDiv_Elf2	 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_Bow_StrDexDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_Bow_StrDexDiv_Elf1	 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_Bow_StrDexDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_Bow_StrDexDiv_Elf2	 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_Bow_StrDexDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_NoBow_DexDiv_Elf1		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_NoBow_DexDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_NoBow_DexDiv_Elf2		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_NoBow_DexDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_NoBow_StrDiv_Elf1		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_NoBow_StrDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_NoBow_StrDiv_Elf2		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_NoBow_StrDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_NoBow_Elf1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_NoBow_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_NoBow_Elf2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_NoBow_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_DexStrDiv_Elf1		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_DexStrDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_DexStrDiv_Elf2		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_DexStrDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_DexStrDiv_Elf1		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_DexStrDiv_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_DexStrDiv_Elf2		 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_DexStrDiv_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_DK1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DK1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_DK2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DK2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_DK1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DK1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_DK2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DK2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_MG1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_MG1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_MG2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_MG2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_EneDiv_MG1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_EneDiv_MG1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_EneDiv_MG2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_EneDiv_MG2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_MG1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_MG1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_MG2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_MG2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_DL1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DL1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_StrDiv_DL2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DL2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_EneDiv_DL1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_EneDiv_DL1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMin_EneDiv_DL2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_EneDiv_DL2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMax_StrDiv_DL1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DL1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMax_StrDiv_DL2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DL2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMax_EneDiv_DL1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_EneDiv_DL1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackDamageMax_EneDiv_DL2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_EneDiv_DL2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMin_StrDiv_DW1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DW1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMin_StrDiv_DW2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_StrDiv_DW2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_DW1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DW1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_StrDiv_DW2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_StrDiv_DW2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMin_EneDiv_DW1			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMin_EneDiv_DW1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) AttackDamageMax_EneDiv_DW2			 = GetPrivateProfileInt("DamageCalculator", "AttackDamageMax_EneDiv_DW2",1,"..\\Data\\Custom\\Calculator.cfg");
	
	*(unsigned int *) AttackSpeed_Elf1						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_Elf1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackSpeed_Elf2						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_Elf2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackSpeed_DK_MG1					 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DK_MG1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackSpeed_DK_MG2					 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DK_MG2",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackSpeed_DL1						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DL1",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) AttackSpeed_DL2						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DL2",1,"..\\Data\\Custom\\Calculator.cfg");
	//*(unsigned int *) AttackSpeed_DW1						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DW1",1,"..\\Data\\Custom\\Calculator.cfg");
	//*(unsigned int *) AttackSpeed_DW2						 = GetPrivateProfileInt("AttackSpeedCalculator", "AttackSpeed_DW2",1,"..\\Data\\Custom\\Calculator.cfg");

	*(unsigned char *) SuccessfulBlocking_Elf				 = GetPrivateProfileInt("BlockAndDefense", "SuccessfulBlocking_Elf",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) SuccessfulBlocking_DW_DK_MG			 = GetPrivateProfileInt("BlockAndDefense", "SuccessfulBlocking_DW_DK_MG",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) SuccessfulBlocking_DL					 = GetPrivateProfileInt("BlockAndDefense", "SuccessfulBlocking_DL",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) Defense_Elf							 = GetPrivateProfileInt("BlockAndDefense", "Defense_Elf",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) Defense_DK							 = GetPrivateProfileInt("BlockAndDefense", "Defense_DK",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned int *) Defense_DL							 = GetPrivateProfileInt("BlockAndDefense", "Defense_DL",1,"..\\Data\\Custom\\Calculator.cfg");
	*(unsigned char *) Defense_DW_MG						 = GetPrivateProfileInt("BlockAndDefense", "Defense_DW_MG",1,"..\\Data\\Custom\\Calculator.cfg");
	
//==============================================================================
// Item Price
//==============================================================================
	//memcpy((int*)0x00710000,ItemPrice, 0xCA);
//	g_Funtions.SetNop(0x005F2A94,31);
//==============================================================================
// Price Load
//==============================================================================
	g_Funtions.SetNop(0x005F2AB3,31);
	HookOffset((DWORD)&ItemPrice, 0x005F2AB3, 0xE9);

	*(BYTE*)(0x005F3BEF+1) = 0x01; // Change % For Sell
//g_Funtions.SetNop(0x005F2AB3,31);
  //  HookOffset((DWORD)&ItemPrice, 0x005F2AB3, 0xE9);
	//g_Funtions.SetNop(0x00599AD2,32);
	//HookOffset((DWORD)&ItemPrice, 0x00599AD2, 0xE9); 
	//	SetNop(0x005F2AB3,31);
	//HookOffset((DWORD)&Price, 0x005F2AB3, 0xE9);
*(BYTE*)(0x005F3BEF+1) = 0x01; // Change % For Sell
//==============================================================================
// Ancient+Excellent Options Fix
//==============================================================================
g_Funtions.SetJmp(0x005F00C8); // Fix Ancient + Excelent;
//==============================================================================
}
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================
//========================================================================================================================