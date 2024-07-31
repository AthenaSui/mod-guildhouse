#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Configuration/Config.h"
#include "Creature.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Define.h"
#include "GossipDef.h"
#include "DataMap.h"
#include "GameObject.h"
#include "Transport.h"
#include "CreatureAI.h"
#include "guildhouse.h"

int cost, GuildHouseInnKeeper, GuildHouseBank, GuildHouseMailBox, GuildHouseAuctioneer, GuildHouseTrainer, GuildHouseVendor, GuildHouseObject, GuildHousePortal, GuildHouseSpirit, GuildHouseProf, GuildHouseBuyRank;

class GuildHouseSpawner : public CreatureScript
{

public:
    GuildHouseSpawner() : CreatureScript("GuildHouseSpawner") {}

    struct GuildHouseSpawnerAI : public ScriptedAI
    {
        GuildHouseSpawnerAI(Creature* creature) : ScriptedAI(creature) {}

        void UpdateAI(uint32 /*diff*/) override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
    };

    CreatureAI* GetAI(Creature *creature) const override
    {
        return new GuildHouseSpawnerAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetGuild())
        {
            Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId());
            Guild::Member const* memberMe = guild->GetMember(player->GetGUID());

            if (!memberMe->IsRankNotLower(GuildHouseBuyRank))
            {
                ChatHandler(player->GetSession()).PSendSysMessage("您无权购买公会驻地。");
                return false;
            }
        }
        else
        {
            ChatHandler(player->GetSession()).PSendSysMessage("你未加入一个公会。");
            return false;
        }

        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "招募旅店老板", GOSSIP_SENDER_MAIN, GetCreatureEntry(2), "你确定要招募一名旅店老板？", GuildHouseInnKeeper, false);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "购买邮箱", GOSSIP_SENDER_MAIN, 184137, "你确定要购买一个邮箱？", GuildHouseMailBox, false);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "招募兽栏管理员", GOSSIP_SENDER_MAIN, 28690, "你确定要招募一名兽栏管理员？", GuildHouseVendor, false);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "招募职业训练师", GOSSIP_SENDER_MAIN, 2);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "招募供应商", GOSSIP_SENDER_MAIN, 3);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "购买传送门和装置", GOSSIP_SENDER_MAIN, 4);
        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "招募银行职员", GOSSIP_SENDER_MAIN, 30605, "你确定要招募一名银行职员？", GuildHouseBank, false);
        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "招募联盟拍卖师", GOSSIP_SENDER_MAIN, 8719, "你确定要招募一名联盟拍卖师", GuildHouseAuctioneer, false);
        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "招募部落拍卖师", GOSSIP_SENDER_MAIN, 9856, "你确定要招募一名部落拍卖师", GuildHouseAuctioneer, false);
        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "招募中立拍卖师", GOSSIP_SENDER_MAIN, 9858, "你确定要招募一名中立拍卖师？", GuildHouseAuctioneer, false);
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "招募主专业技能训练师", GOSSIP_SENDER_MAIN, 7);
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "招募副专业技能训练师", GOSSIP_SENDER_MAIN, 8);
        AddGossipItemFor(player, GOSSIP_ICON_TALK, "招募灵魂医者", GOSSIP_SENDER_MAIN, 6491, "你确定要招募一名灵魂医者？", GuildHouseSpirit, false);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {

        switch (action)
        {
        case 2: // Spawn Class Trainer
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "死亡骑士训练师", GOSSIP_SENDER_MAIN, 29195, "你确定要招募一名死亡骑士训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "德鲁伊训练师", GOSSIP_SENDER_MAIN, 26324, "你确定要招募一名德鲁伊训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "猎人训练师", GOSSIP_SENDER_MAIN, 26325, "你确定要招募一名猎人训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "法师训练师", GOSSIP_SENDER_MAIN, 26326, "你确定要招募一名法师训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "圣骑士训练师", GOSSIP_SENDER_MAIN, 26327, "你确定要招募一名圣骑士训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "牧师训练师", GOSSIP_SENDER_MAIN, 26328, "你确定要招募一名牧师训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "盗贼训练师", GOSSIP_SENDER_MAIN, 26329, "你确定要招募一名盗贼训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "萨满祭司训练师", GOSSIP_SENDER_MAIN, 26330, "你确定要招募一名萨满祭司训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "术士训练师", GOSSIP_SENDER_MAIN, 26331, "你确定要招募一名术士训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "战士训练师", GOSSIP_SENDER_MAIN, 26332, "你确定要招募一名战士训练师？", GuildHouseTrainer, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "返回上一级！", GOSSIP_SENDER_MAIN, 9);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 3: // Vendors
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "商人", GOSSIP_SENDER_MAIN, 28692, "你确定要招募一名商人？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "战袍商人", GOSSIP_SENDER_MAIN, 28776, "你确定要招募一名战袍商人？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "联盟食物和饮料商人", GOSSIP_SENDER_MAIN, 4255, "你确定要招募一名食物和饮料商人？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "部落食物和饮料商人", GOSSIP_SENDER_MAIN, 10367, "你确定要招募一名食物和饮料商人？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "材料商", GOSSIP_SENDER_MAIN, 29636, "你确定要招募一名材料商？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "弹药和修理商人", GOSSIP_SENDER_MAIN, 29493, "你确定要招募一名弹药和修理商人？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "毒药商", GOSSIP_SENDER_MAIN, 2622, "你确定要招募一名毒药商？", GuildHouseVendor, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "返回上一级！", GOSSIP_SENDER_MAIN, 9);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 4: // Objects & Portals
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "熔炉", GOSSIP_SENDER_MAIN, 1685, "你确定要购买一个熔炉？", GuildHouseObject, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "铁砧", GOSSIP_SENDER_MAIN, 4087, "你确定要购买一个铁砧？", GuildHouseObject, false);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "炉子", GOSSIP_SENDER_MAIN, 59853, "你确定要购买一个炉子？", GuildHouseObject, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "公会银行", GOSSIP_SENDER_MAIN, 187293, "你确定要购买一个公会银行？", GuildHouseObject, false);
            AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "理发椅", GOSSIP_SENDER_MAIN, 191028, "你确定要购买一个理发椅？", GuildHouseObject, false);

//            if (player->GetTeamId() == TEAM_ALLIANCE)
//            {
                // ALLIANCE players get these options
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 铁炉堡", GOSSIP_SENDER_MAIN, GetGameObjectEntry(3), "你确定要购买一个到铁炉堡的传送门？", GuildHousePortal, false);
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 达纳苏斯", GOSSIP_SENDER_MAIN, GetGameObjectEntry(1), "你确定要购买一个到达纳苏斯的传送门？", GuildHousePortal, false);
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 埃索达", GOSSIP_SENDER_MAIN, GetGameObjectEntry(2), "你确定要购买一个到埃索达的传送门？", GuildHousePortal, false);
//            }
//            else
//            {
                // HORDE players get these options
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 幽暗城", GOSSIP_SENDER_MAIN, GetGameObjectEntry(7), "你确定要购买一个到幽暗城的传送门？", GuildHousePortal, false);
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 雷霆崖", GOSSIP_SENDER_MAIN, GetGameObjectEntry(6), "你确定要购买一个到雷霆崖的传送门？", GuildHousePortal, false);
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 银月城", GOSSIP_SENDER_MAIN, GetGameObjectEntry(5), "你确定要购买一个到银月城的传送门？", GuildHousePortal, false);
//            }

            // These two portals work for either Team
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 沙塔斯城", GOSSIP_SENDER_MAIN, GetGameObjectEntry(8), "你确定要购买一个到沙塔斯城的传送门？", GuildHousePortal, false);
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "传送门: 达拉然", GOSSIP_SENDER_MAIN, GetGameObjectEntry(9), "你确定要购买一个到达拉然的传送门？", GuildHousePortal, false);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "返回上一级！", GOSSIP_SENDER_MAIN, 9);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
		case 8719: // Alliance Auctioneer
		case 9856: // Horde Auctioneer
        case 9858: // Neutral Auctioneer
            cost = GuildHouseAuctioneer;
            SpawnNPC(action, player);
            break;
        case 7: // Spawn Profession Trainers
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "炼金术训练师", GOSSIP_SENDER_MAIN, 28703, "你确定要招募一名炼金术训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "锻造训练师", GOSSIP_SENDER_MAIN, 28694, "你确定要招募一名锻造训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "工程学训练师", GOSSIP_SENDER_MAIN, 28697, "你确定要招募一名工程学训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "裁缝训练师", GOSSIP_SENDER_MAIN, 28699, "你确定要招募一名裁缝训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "制皮训练师", GOSSIP_SENDER_MAIN, 28700, "你确定要招募一名制皮训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "剥皮训练师", GOSSIP_SENDER_MAIN, 28696, "你确定要招募一名剥皮训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "采矿训练师", GOSSIP_SENDER_MAIN, 28698, "你确定要招募一名采矿训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "草药学训练师", GOSSIP_SENDER_MAIN, 28704, "你确定要招募一名草药学训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "附魔训练师", GOSSIP_SENDER_MAIN, 28693, "你确定要招募一名附魔训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "珠宝加工训练师", GOSSIP_SENDER_MAIN, 28701, "你确定要招募一名珠宝加工训练师？", GuildHouseProf, false);
        	AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "铭文训练师", GOSSIP_SENDER_MAIN, 28702, "你确定要招募一名铭文训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "武器训练师", GOSSIP_SENDER_MAIN, 190013, "你确定要招募一名武器训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "返回上一级！", GOSSIP_SENDER_MAIN, 9);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 8: // Secondary Profession Trainers
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "急救训练师", GOSSIP_SENDER_MAIN, 28706, "你确定要招募一名急救训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "钓鱼训练师", GOSSIP_SENDER_MAIN, 28742, "你确定要招募一名钓鱼训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "烹饪训练师", GOSSIP_SENDER_MAIN, 33587, "你确定要招募一名烹饪训练师？", GuildHouseProf, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "返回上一级！", GOSSIP_SENDER_MAIN, 9);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 9: // Go back!
            OnGossipHello(player, creature);
            break;
        case 10: // PVP toggle
            break;
        case 30605: // Banker
            cost = GuildHouseBank;
            SpawnNPC(action, player);
            break;
        case GetCreatureEntry(2): // Innkeeper
            cost = GuildHouseInnKeeper;
            SpawnNPC(action, player);
            break;
        case 26327: // Paladin
        case 26324: // Druid
        case 26325: // Hunter
        case 26326: // Mage
        case 26328: // Priest
        case 26329: // Rogue
        case 26330: // Shaman
        case 26331: // Warlock
        case 26332: // Warrior
        case 29195: // Death Knight
            cost = GuildHouseTrainer;
            SpawnNPC(action, player);
            break;
        case 28694: // Blacksmithing
        case 28698: // Mining
        case 28697: // Engineering
        case 28701: // Jewelcrafting
        case 28693: // Enchanting
        case 28702: // Inscription
        case 28700: // Leatherworking
        case 28696: // Skinning
        case 28703: // Alchemy
        case 28704: // Herbalism
        case 28699: // Tailoring
        case 190013: // Arms Trainer
        case 33587: // Cooking
        case 28742: // Fishing
        case 28706: // First Aid
            cost = GuildHouseProf;
            SpawnNPC(action, player);
            break;
        case 28692: // Trade Supplies
        case 28776: // Tabard Vendor
        case 4255:  // Food & Drink Vendor
        case 10367:  // Food & Drink Vendor
        case 29636: // Reagent Vendor
        case 29493: // Ammo & Repair Vendor
        case 28690: // Stable Master
        case 2622:  // Poisons Vendor
            cost = GuildHouseVendor;
            SpawnNPC(action, player);
            break;
        //
        // Objects
        //
        case 184137: // Mailbox
            cost = GuildHouseMailBox;
            SpawnObject(action, player);
            break;
        case 6491: // Spirit Healer
            cost = GuildHouseSpirit;
            SpawnNPC(action, player);
            break;
        case 1685:   // Forge
        case 4087:   // Anvil
        case 59853:  // Stove
        case 187293: // Guild Vault
        case 191028: // Barber Chair
            cost = GuildHouseObject;
            SpawnObject(action, player);
            break;
        case GetGameObjectEntry(1): // Darnassus Portal
        case GetGameObjectEntry(2): // Exodar Portal
        case GetGameObjectEntry(3): // Ironforge Portal
        case GetGameObjectEntry(5): // Silvermoon Portal
        case GetGameObjectEntry(6): // Thunder Bluff Portal
        case GetGameObjectEntry(7): // Undercity Portal
        case GetGameObjectEntry(8): // Shattrath Portal
        case GetGameObjectEntry(9): // Dalaran Portal
            cost = GuildHousePortal;
            SpawnObject(action, player);
            break;
        }
        return true;
    }

    uint32 GetGuildPhase(Player* player)
    {
        return player->GetGuildId() + 10;
    }

    void SpawnNPC(uint32 entry, Player* player)
    {
        if (player->FindNearestCreature(entry, VISIBILITY_RANGE, true))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("你已经拥有该职责NPC！");
            CloseGossipMenuFor(player);
            return;
        }

        float posX;
        float posY;
        float posZ;
        float ori;

        QueryResult result = WorldDatabase.Query("SELECT `posX`, `posY`, `posZ`, `orientation` FROM `guild_house_spawns` WHERE `entry`={}", entry);

        if (!result)
            return;

        do
        {
            Field* fields = result->Fetch();
            posX = fields[0].Get<float>();
            posY = fields[1].Get<float>();
            posZ = fields[2].Get<float>();
            ori = fields[3].Get<float>();

        } while (result->NextRow());

        Creature* creature = new Creature();

        if (!creature->Create(player->GetMap()->GenerateLowGuid<HighGuid::Unit>(), player->GetMap(), GetGuildPhase(player), entry, 0, posX, posY, posZ, ori))
        {
            delete creature;
            return;
        }
        creature->SaveToDB(player->GetMapId(), (1 << player->GetMap()->GetSpawnMode()), GetGuildPhase(player));
        uint32 db_guid = creature->GetSpawnId();

        creature->CleanupsBeforeDelete();
        delete creature;
        creature = new Creature();
        if (!creature->LoadCreatureFromDB(db_guid, player->GetMap()))
        {
            delete creature;
            return;
        }

        sObjectMgr->AddCreatureToGrid(db_guid, sObjectMgr->GetCreatureData(db_guid));
        player->ModifyMoney(-cost);
        CloseGossipMenuFor(player);
    }

    void SpawnObject(uint32 entry, Player* player)
    {
        if (player->FindNearestGameObject(entry, VISIBLE_RANGE))
        {
            ChatHandler(player->GetSession()).PSendSysMessage("你已经拥有该功能装置！");
            CloseGossipMenuFor(player);
            return;
        }

        float posX;
        float posY;
        float posZ;
        float ori;

        QueryResult result = WorldDatabase.Query("SELECT `posX`, `posY`, `posZ`, `orientation` FROM `guild_house_spawns` WHERE `entry`={}", entry);

        if (!result)
            return;

        do
        {
            Field* fields = result->Fetch();
            posX = fields[0].Get<float>();
            posY = fields[1].Get<float>();
            posZ = fields[2].Get<float>();
            ori = fields[3].Get<float>();

        } while (result->NextRow());

        uint32 objectId = entry;
        if (!objectId)
            return;

        const GameObjectTemplate* objectInfo = sObjectMgr->GetGameObjectTemplate(objectId);

        if (!objectInfo)
            return;

        if (objectInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(objectInfo->displayId))
            return;

        GameObject* object = sObjectMgr->IsGameObjectStaticTransport(objectInfo->entry) ? new StaticTransport() : new GameObject();
        ObjectGuid::LowType guidLow = player->GetMap()->GenerateLowGuid<HighGuid::GameObject>();

        if (!object->Create(guidLow, objectInfo->entry, player->GetMap(), GetGuildPhase(player), posX, posY, posZ, ori, G3D::Quat(), 0, GO_STATE_READY))
        {
            delete object;
            return;
        }

        // fill the gameobject data and save to the db
        object->SaveToDB(player->GetMapId(), (1 << player->GetMap()->GetSpawnMode()), GetGuildPhase(player));
        guidLow = object->GetSpawnId();
        // delete the old object and do a clean load from DB with a fresh new GameObject instance.
        // this is required to avoid weird behavior and memory leaks
        delete object;

        object = sObjectMgr->IsGameObjectStaticTransport(objectInfo->entry) ? new StaticTransport() : new GameObject();
        // this will generate a new guid if the object is in an instance
        if (!object->LoadGameObjectFromDB(guidLow, player->GetMap(), true))
        {
            delete object;
            return;
        }

        // TODO: is it really necessary to add both the real and DB table guid here ?
        sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGameObjectData(guidLow));
        player->ModifyMoney(-cost);
        CloseGossipMenuFor(player);
    }
};

class GuildHouseButlerConf : public WorldScript
{
public:
    GuildHouseButlerConf() : WorldScript("GuildHouseButlerConf") {}

    void OnBeforeConfigLoad(bool /*reload*/) override
    {
        GuildHouseInnKeeper = sConfigMgr->GetOption<int32>("GuildHouseInnKeeper", 1000000);
        GuildHouseBank = sConfigMgr->GetOption<int32>("GuildHouseBank", 1000000);
        GuildHouseMailBox = sConfigMgr->GetOption<int32>("GuildHouseMailbox", 500000);
        GuildHouseAuctioneer = sConfigMgr->GetOption<int32>("GuildHouseAuctioneer", 500000);
        GuildHouseTrainer = sConfigMgr->GetOption<int32>("GuildHouseTrainerCost", 1000000);
        GuildHouseVendor = sConfigMgr->GetOption<int32>("GuildHouseVendor", 500000);
        GuildHouseObject = sConfigMgr->GetOption<int32>("GuildHouseObject", 500000);
        GuildHousePortal = sConfigMgr->GetOption<int32>("GuildHousePortal", 500000);
        GuildHouseProf = sConfigMgr->GetOption<int32>("GuildHouseProf", 500000);
        GuildHouseSpirit = sConfigMgr->GetOption<int32>("GuildHouseSpirit", 100000);
        GuildHouseBuyRank = sConfigMgr->GetOption<int32>("GuildHouseBuyRank", 4);
    }
};

void AddGuildHouseButlerScripts()
{
    new GuildHouseSpawner();
    new GuildHouseButlerConf();
}
