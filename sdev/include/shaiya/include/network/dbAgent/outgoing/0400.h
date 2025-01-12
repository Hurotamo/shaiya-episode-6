#pragma once
#include <strsafe.h>
#include <shaiya/include/common.h>
#include <shaiya/include/common/Family.h>
#include <shaiya/include/common/Grow.h>
#include <shaiya/include/common/ItemTypes.h>
#include <shaiya/include/common/Job.h>
#include <shaiya/include/common/Sex.h>
#include <shaiya/include/common/UserTypes.h>

namespace shaiya
{
    #pragma pack(push, 1)
    // 8 items (5.4, 6.0)
    struct Character0403_EP5
    {
        ULONG id;                //0x00
        ULONG regDate;           //0x04
        bool nameChange;         //0x08
        UINT8 slot;              //0x09
        Family family;           //0x0A
        Grow grow;               //0x0B
        UINT8 hair;              //0x0C
        UINT8 face;              //0x0D
        UINT8 size;              //0x0E
        Job job;                 //0x0F
        Sex sex;                 //0x10
        UINT16 level;            //0x11
        UINT16 strength;         //0x13
        UINT16 dexterity;        //0x15
        UINT16 reaction;         //0x17
        UINT16 intelligence;     //0x19
        UINT16 wisdom;           //0x1B
        UINT16 luck;             //0x1D
        UINT16 health;           //0x1F
        UINT16 mana;             //0x21
        UINT16 stamina;          //0x23
        UINT16 mapId;            //0x25
        ULONG deleteDate;        //0x27
        ItemArray<8> equipment;  //0x2B
        CloakBadge cloakBadge;   //0x3B
        CharName charName;       //0x41
        // 0x56
    };
    #pragma pack(pop)

    static_assert(sizeof(Character0403_EP5) == 0x56);

    #pragma pack(push, 1)
    struct DBAgentCharListOutgoing_EP5
    {
        UINT16 opcode{ 0x403 };
        ULONG userId;
        bool sendCountry;
        UINT8 characterCount;
        Array<Character0403_EP5, 5> characterList;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // 17 items (6.4)
    struct Character0403_EP6_4
    {
        ULONG id;                 //0x00
        ULONG regDate;            //0x04
        bool nameChange;          //0x08
        UINT8 slot;               //0x09
        Family family;            //0x0A
        Grow grow;                //0x0B
        UINT8 hair;               //0x0C
        UINT8 face;               //0x0D
        UINT8 size;               //0x0E
        Job job;                  //0x0F
        Sex sex;                  //0x10
        UINT16 level;             //0x11
        UINT16 strength;          //0x13
        UINT16 dexterity;         //0x15
        UINT16 reaction;          //0x17
        UINT16 intelligence;      //0x19
        UINT16 wisdom;            //0x1B
        UINT16 luck;              //0x1D
        UINT16 health;            //0x1F
        UINT16 mana;              //0x21
        UINT16 stamina;           //0x23
        UINT16 mapId;             //0x25
        ULONG deleteDate;         //0x27
        ItemArray<17> equipment;  //0x2B
        CloakBadge cloakBadge;    //0x4D
        CharName charName;        //0x53
        // 0x68
    };
    #pragma pack(pop)

    static_assert(sizeof(Character0403_EP6_4) == 0x68);

    #pragma pack(push, 1)
    struct DBAgentCharListOutgoing_EP6_4
    {
        UINT16 opcode{ 0x403 };
        ULONG userId;
        bool sendCountry;
        UINT8 characterCount;
        Array<Character0403_EP6_4, 5> characterList;
    };
    #pragma pack(pop)

    enum struct DBAgentCharCreateResult : UINT8
    {
        Success,
        Failure,
        NullUser = 3
    };

    #pragma pack(push, 1)
    struct DBAgentCharCreateResultOutgoing
    {
        UINT16 opcode{ 0x404 };
        ULONG userId;
        DBAgentCharCreateResult result;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentCharNameChangeOutgoing
    {
        UINT16 opcode{ 0x409 };
        ULONG userId;
        bool success;
        ULONG charId;
        CharName oldCharName;
        CharName newCharName;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentCharDeleteOutgoing
    {
        UINT16 opcode{ 0x40A };
        ULONG userId;
        ULONG charId;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentCharRestoreOutgoing
    {
        UINT16 opcode{ 0x40B };
        ULONG userId;
        ULONG charId;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // custom
    struct DBAgentCharNameAvailableOutgoing
    {
        UINT16 opcode{ 0x40D };
        ULONG userId;
        bool available;
    };
    #pragma pack(pop)
}
