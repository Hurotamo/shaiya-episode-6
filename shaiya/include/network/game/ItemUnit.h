#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/ItemTypes.h>

namespace shaiya
{
    #pragma pack(push, 1)
    // TP_ITEM_UNIT
    struct ItemUnit
    {
        uint8_t bag;
        uint8_t slot;
        uint8_t type;
        uint8_t typeId;
        uint16_t quality;
        Gems gems;
        uint8_t count;
        CraftName craftName;
    };
    #pragma pack(pop)
}
