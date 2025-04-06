#include "include/shaiya/include/CNpc.h"
#include "include/shaiya/include/CUser.h"
using namespace shaiya;

void CNpc::SetTarget(CNpc* npc/*eax*/, CUser* user/*esi*/)
{
    unsigned u0x4D4550 = 0x4D4550;

    __asm
    {
        mov esi,user
        mov eax,npc
        call u0x4D4550
    }
}

void CNpc::StatusChange(CNpc* npc/*eax*/, int nextStatus/*ecx*/)
{
    unsigned u0x4D4600 = 0x4D4600;

    __asm
    {
        mov ecx,nextStatus
        mov eax,npc
        call u0x4D4600
    }
}

void CNpc::StatusAttackStop(CNpc* npc/*eax*/)
{
    unsigned u0x4D4610 = 0x4D4610;

    __asm
    {
        mov eax,npc
        call u0x4D4610
    }
}
