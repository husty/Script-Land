DELETE FROM `npc_gossip_textid` WHERE `creatureid` IN(19169,19171,19148,19178,19172,20102,18927,19173,19175,19176,19177);
DELETE FROM `creature_quest_starter` WHERE `id` IN(19169,19171,19148,19178,19172,20102,18927,19173,19175,19176,19177);
DELETE FROM `creature_waypoints` WHERE `spawnid` IN (420084,420027);
DELETE FROM `creature_timed_emotes` WHERE `spawnid` IN (420111,420037);
DELETE FROM `gameobject_spawns` WHERE `id` BETWEEN '510000' AND '512011';
DELETE FROM `creature_spawns` WHERE `id` BETWEEN '420000' AND '420393';
UPDATE `creature_proto` SET `auras`=' ' WHERE `entry` IN (18927,19148,19169,19171,19172,19173,19175,19176,19177,19178,20102,23872,28067);
