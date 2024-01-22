-- !!! NOTE: set these before running the queries in order to avoid conflicts !!!
SET @C_TEMPLATE = 500030;

DELETE FROM `creature_template` WHERE `entry` IN (
	@C_TEMPLATE + 0,
	@C_TEMPLATE + 1,
	@C_TEMPLATE + 2
);

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `speed_swim`, `speed_flight`, `detection_range`, `scale`, `rank`, `dmgschool`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
	(@C_TEMPLATE + 0, 0, 0, 0, 0, 0, 25901, 0, 0, 0, '沈万三', '公会驻地商人', '',   0, 35, 35, 0, 35, 0, 1, 1.14286, 1, 1, 20, 1, 0, 0, 1, 2000, 2000, 1, 1, 1, 33536, 2048, 0, 0, 0, 0, 0, 0, 7, 4096, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 'GuildHouseSeller', 12340),
	(@C_TEMPLATE + 1, 0, 0, 0, 0, 0, 25901, 0, 0, 0, '轩辕无敌', '公会驻地管理员',   '',   0, 35, 35, 0, 35, 0, 1, 1.14286, 1, 1, 20, 1, 0, 0, 1, 2000, 2000, 1, 1, 1, 33536, 2048, 0, 0, 0, 0, 0, 0, 7, 4096, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 'GuildHouseSpawner', 12340),
	(@C_TEMPLATE + 2, 0, 0, 0, 0, 0, 18234, 0, 0, 0, '金镶玉','老板娘', '', 0, 70, 70, 0, 35, 65747, 0.8, 0.28571, 1, 1, 20, 1, 1, 0, 4.6, 2000, 1900, 1, 1, 1, 0, 2048, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 1, 1, 1, 1, 1, 0, 70, 1, 0, 0, 2, 'npc_innkeeper', 12340),
	(@C_TEMPLATE + 3, 0, 0, 0, 0, 0, 31833, 0, 0, 0, '镇星','武器大师', '', 61032, 70, 70, 0, 35, 115, 1, 1.14286, 0, 0, 0, 1, 1, 0, 0, 2000, 1900, 1, 1, 1, 0, 0, 0, 0, 2, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 16777216, '', 12340);

-- !!! NOTE: set these before running the queries in order to avoid conflicts !!!
SET @GO_TEMPLATE = 500000;

DELETE FROM `gameobject_template` WHERE `entry` IN (
    @GO_TEMPLATE + 0,
    @GO_TEMPLATE + 1,
    @GO_TEMPLATE + 2,
    @GO_TEMPLATE + 3,
    @GO_TEMPLATE + 4,
    @GO_TEMPLATE + 5,
    @GO_TEMPLATE + 6,
    @GO_TEMPLATE + 7,
    @GO_TEMPLATE + 8,
    @GO_TEMPLATE + 9
);

INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
	(@GO_TEMPLATE + 0, 22, 4396, '传送门：暴风城', '', '', '', 1, 17334, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 1, 22, 4393, '传送门：达纳苏斯', '', '', '', 1, 17608, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 2, 22, 6955, '传送门：埃索达', '', '', '', 1, 32268, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 3, 22, 4394, '传送门：铁炉堡', '', '', '', 1, 17607, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 4, 22, 4395, '传送门：奥格瑞玛', '', '', '', 1, 17609, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 5, 22, 6956, '传送门：银月城', '', '', '', 1, 32270, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 6, 22, 4397, '传送门：雷霆崖', '', '', '', 1, 17610, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 7, 22, 4398, '传送门：幽暗城', '', '', '', 1, 17611, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 8, 22, 7146, '传送门：沙塔斯城', '', '', '', 1, 35718, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
	(@GO_TEMPLATE + 9, 22, 8111, '传送门：达拉然', '', '', '', 1, 53141, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0);
	
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `artkit0`, `artkit1`, `artkit2`, `artkit3`) VALUES
	(@GO_TEMPLATE + 0, 1732, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 1, 1732, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 2, 1732, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 3, 1732, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 4, 1735, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 5, 1735, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 6, 1735, 0, 0, 0, 0, 0, 0, 0),
	(@GO_TEMPLATE + 7, 1735, 0, 0, 0, 0, 0, 0, 0);