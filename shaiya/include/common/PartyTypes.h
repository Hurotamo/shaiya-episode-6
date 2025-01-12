#pragma once
#include <cstdint>

namespace shaiya
{
    enum struct ItemDivType : uint32_t
    {
        Group = 1,
        Random,
        Unknown,
        Master
    };

    enum struct PartyType : uint8_t
    {
        None,
        Member,
        Leader
    };

    enum struct UnionType : uint32_t
    {
        Leader,
        SubLeader,
        Member,
        Default = UINT32_MAX
    };
}
