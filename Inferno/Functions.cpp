#include "Functions.h"
#include "windows.h"
// ---------------------------------------------------------------------------
Funtions g_Funtions;
// ---------------------------------------------------------------------------

Funtions::Funtions(void)
{
	// ----
}
// ---------------------------------------------------------------------------

Funtions::~Funtions(void)
{
	// -----
}
// ---------------------------------------------------------------------------

void __cdecl Funtions::SetJmp(DWORD Offset)
{
	*(BYTE*)(Offset) = 0xEB;
}

void __cdecl Funtions::SetNop(DWORD dwOffset,int Size)
{
	for(int n=0;n < Size;n++)
	{
		*(BYTE*)(dwOffset+n)=0x90;
	}
}
// ---------------------------------------------------------------------------