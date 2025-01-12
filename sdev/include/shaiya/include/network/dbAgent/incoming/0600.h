#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/Grow.h>

// CUser::PacketUserSetStatus

namespace shaiya
{
    #pragma pack(push, 1)
    struct DBAgentStatusIncoming
    {
        UINT16 opcode{ 0x601 };
        ULONG userId;
        UINT16 level;
        UINT32 exp;
        UINT16 statPoint;
        UINT16 skillPoint;
        UINT16 strength;
        UINT16 dexterity;
        UINT16 intelligence;
        UINT16 wisdom;
        UINT16 reaction;
        UINT16 luck;
        UINT16 health;
        UINT16 mana;
        UINT16 stamina;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBExp
    struct DBAgentExpIncoming
    {
        UINT16 opcode{ 0x602 };
        ULONG userId;
        UINT32 exp;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBMoney
    struct DBAgentMoneyIncoming
    {
        UINT16 opcode{ 0x603 };
        ULONG userId;
        UINT32 money;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBStatusUp
    struct DBAgentStatusUpIncoming
    {
        UINT16 opcode{ 0x604 };
        ULONG userId;
        UINT16 statPoint;
        UINT16 strength;
        UINT16 dexterity;
        UINT16 recovery;
        UINT16 intelligence;
        UINT16 wisdom;
        UINT16 luck;
    };
    #pragma pack(pop)

    enum struct DBAgentStatusGroupType : UINT8
    {
        Honor = 1,
        Vg, Cg, Og, Ig
    };

    #pragma pack(push, 1)
    struct DBAgentStatusGroupIncoming
    {
        UINT16 opcode{ 0x605 };
        ULONG userId;
        // Set command logic wrongly assigns 2 for cg, og, and ig. 
        // See dbAgent address 0x4066E2.
        DBAgentStatusGroupType groupType;
        UINT16 value;

        DBAgentStatusGroupIncoming() = default;

        DBAgentStatusGroupIncoming(ULONG userId, DBAgentStatusGroupType groupType, UINT16 value)
            : userId(userId), groupType(groupType), value(value)
        {
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentHpMpSpIncoming
    {
        UINT16 opcode{ 0x606 };
        ULONG userId;
        UINT16 health;
        UINT16 mana;
        UINT16 stamina;

        DBAgentHpMpSpIncoming() = default;

        DBAgentHpMpSpIncoming(ULONG userId, UINT16 health, UINT16 mana, UINT16 stamina)
            : userId(userId), health(health), mana(mana), stamina(stamina)
        {
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentLocationIncoming
    {
        UINT16 opcode{ 0x607 };
        ULONG userId;
        UINT16 mapId;
        UINT16 direction;
        float x;
        float y;
        float z;

        DBAgentLocationIncoming() = default;

        DBAgentLocationIncoming(ULONG userId, UINT16 mapId, UINT16 direction, float x, float y, float z)
            : userId(userId), mapId(mapId), direction(direction), x(x), y(y), z(z)
        {
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct DBAgentQuickSlot
    {
        UINT8 bag;
        UINT8 slot;
        UINT8 srcBag;
        UINT16 srcSlot;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBAgentQuickSlot
    struct DBAgentQuickSlotIncoming
    {
        UINT16 opcode{ 0x609 };
        ULONG userId;
        UINT8 quickSlotCount;
        Array<DBAgentQuickSlot, 128> quickSlots;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBLevel
    struct DBAgentLevelIncoming
    {
        UINT16 opcode{ 0x60A };
        ULONG userId;
        UINT32 level;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // not implemented
    // see CUser::SendDBBankMoney
    struct DBAgentBankMoneyIncoming
    {
        UINT16 opcode{ 0x60B };
        ULONG userId;
        UINT32 bankMoney;
    };
    #pragma pack(pop)

    enum struct DBAgentPvPStatusType : UINT8
    {
        Kill,
        Death,
        Win,
        Loss
    };

    #pragma pack(push, 1)
    struct DBAgentPvPStatusIncoming
    {
        UINT16 opcode{ 0x60C };
        ULONG userId;
        DBAgentPvPStatusType statusType;
        UINT32 value;

        DBAgentPvPStatusIncoming() = default;

        DBAgentPvPStatusIncoming(ULONG userId, DBAgentPvPStatusType statusType, UINT32 value)
            : userId(userId), statusType(statusType), value(value)
        {
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBGrow
    struct DBAgentGrowIncoming
    {
        UINT16 opcode{ 0x60D };
        ULONG userId;
        UINT32 grow;

        DBAgentGrowIncoming() = default;

        DBAgentGrowIncoming(ULONG userId, Grow grow)
            : userId(userId), grow(UINT32(grow))
        {
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBSkillPoint
    struct DBAgentSkillPointIncoming
    {
        UINT16 opcode{ 0x60E };
        ULONG userId;
        UINT32 skillPoint;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    // see CUser::SendDBStatPoint
    struct DBAgentStatPointIncoming
    {
        UINT16 opcode{ 0x60F };
        ULONG userId;
        UINT32 statPoint;
    };
    #pragma pack(pop)
}
