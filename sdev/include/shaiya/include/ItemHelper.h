#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/ItemTypes.h>

namespace shaiya
{
    struct CItem;

    class ItemHelper
    {
    public:

        static void SetCraftStrength(CItem* item, int value);
        static void SetCraftDexterity(CItem* item, int value);
        static void SetCraftReaction(CItem* item, int value);
        static void SetCraftIntelligence(CItem* item, int value);
        static void SetCraftWisdom(CItem* item, int value);
        static void SetCraftLuck(CItem* item, int value);
        static void SetCraftHealth(CItem* item, int value);
        static void SetCraftMana(CItem* item, int value);
        static void SetCraftStamina(CItem* item, int value);
        //static void SetCraftAttackPower(CItem* item, int value);
        //static void SetCraftAbsorption(CItem* item, int value);

        static void CopyCraftExpansion(CItem* src, CItem* dest);
        static void InitCraftExpansion(CItem* item);

        static void SendDBAgentCraftName(CUser* user, CItem* item, int bag, int slot);
        static void SendDBAgentGems(CUser* user, CItem* item, int bag, int slot);
        static void SendDBAgentCloakInfo(CUser* user, CItem* item, int bag, int slot);
    };
}
