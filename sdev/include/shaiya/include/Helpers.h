#pragma once
#include <cstdint>
#include <shaiya/include/common.h>
#include <shaiya/include/common/ItemTypes.h>

namespace shaiya
{
    struct CItem;
    struct CUser;
    struct ItemInfo;
    struct SVector;

    struct Helpers
    {
        static bool ItemCreate(CUser* user, ItemInfo* itemInfo, int count, int& outBag, int& outSlot);
        static bool ItemRemove(CUser* user, int bag, int slot, int count);
        static bool ItemRemove(CUser* user, ItemId itemId, int count);
        static bool ItemRemove(CUser* user, ItemEffect effect, int count);

        static bool HasApplySkill(CUser* user, int skillId, int skillLv);

        static void SendMessageToServer(CUser* sender, const char* message);
        static void SendMessageToServer(const char* senderName, const char* message);
        static void SendNotice(const char* message);
        static void SendNoticeTo(CUser* user, const char* message);
        static void SendNoticeTo(ULONG charId, const char* message);
        static void SendNoticeTo(const char* charName, const char* message);

        static void Send(CUser* user, void* packet, int length);
        static void SendDBAgent(void* packet, int length);
        static void SendGameLog(void* packet, int length);
        static void SendSession(void* packet, int length);
        static void SendUserLog(void* packet, int length);

        static void SetMovePosition(CUser* user, int mapId, float x, float y, float z, int recallType, ULONG delay);
        static void SetMovePosition(CUser* user, int mapId, SVector* pos, int recallType, ULONG delay);
        static bool Teleport(CUser* user, int mapId, float x, float y, float z, int recallType, ULONG delay);
        static bool Teleport(CUser* user, int mapId, SVector* pos, int recallType, ULONG delay);

        static void SetItemCraftStrength(CItem* item, uint16_t value);
        static void SetItemCraftDexterity(CItem* item, uint16_t value);
        static void SetItemCraftReaction(CItem* item, uint16_t value);
        static void SetItemCraftIntelligence(CItem* item, uint16_t value);
        static void SetItemCraftWisdom(CItem* item, uint16_t value);
        static void SetItemCraftLuck(CItem* item, uint16_t value);
        static void SetItemCraftHealth(CItem* item, uint16_t value);
        static void SetItemCraftMana(CItem* item, uint16_t value);
        static void SetItemCraftStamina(CItem* item, uint16_t value);
        //static void SetItemCraftAttackPower(CItem* item, uint16_t value);
        //static void SetItemCraftAbsorption(CItem* item, uint16_t value);

        static void CopyItemCraftName(CItem* from, CItem* to);
        static void InitItemCraftName(CItem* item);
        static void SendDBAgentItemCraftName(CUser* user, CItem* item, int bag, int slot);
        static void SendDBAgentItemGems(CUser* user, CItem* item, int bag, int slot);
    };
}
