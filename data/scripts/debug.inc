Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_PETALBURG_WOODS_STATE, 1
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	setvar VAR_PETALBURG_CITY_STATE, 3
	closemessage
	release
	end

@ =============================================================================
@ Debug_Script_1 - Norman Quest: PRE-BATTLE
@ -----------------------------------------------------------------------------
@ World state: All 4 prerequisite badges obtained (Roxanne, Brawly, Wattson,
@ Flannery). VAR_PETALBURG_GYM_STATE = 6: Norman is at his battle position
@ (4, 2) and all gym doors are unlocked. FLAG_DEFEATED_PETALBURG_GYM not set.
@ HMs Rock Smash, Strength, Cut, and Flash in bag with received flags set.
@
@ Warps directly in front of Norman in Petalburg City Gym.
@ =============================================================================
Debug_Script_1::
	lockall

	@ --- Badges (all 4 prerequisites) ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET

	@ --- Gym defeat flags ---
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM

	@ --- Petalburg Gym: 4 prerequisites met, Norman ready to battle ---
	setvar VAR_PETALBURG_GYM_STATE, 6

	@ --- Match Call / PokéNav ---
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL

	@ --- Story-critical progression ---
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_0x8008, 4
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY

	@ --- Player essentials ---
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Littleroot intro complete ---
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4

	@ --- HMs ---
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_FLASH
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_CUT
	additem ITEM_HM_FLASH

	@ --- Party (levels 31-33) ---
	givemon SPECIES_MARSHTOMP, 32, ITEM_NONE
	givemon SPECIES_BRELOOM, 31, ITEM_NONE
	givemon SPECIES_PONYTA, 33, ITEM_NONE
	givemon SPECIES_SWELLOW, 31, ITEM_NONE
	givemon SPECIES_MACHOKE, 32, ITEM_NONE
	givemon SPECIES_GRAVELER, 33, ITEM_NONE
	additem ITEM_ULTRA_BALL, 10
	additem ITEM_FULL_RESTORE, 5

	@ --- Warp directly in front of Norman in Petalburg City Gym ---
	warp MAP_PETALBURG_CITY_GYM, 4, 6
	waitstate
	end

@ =============================================================================
@ Debug_Script_2 - Norman Quest: QUEST INITIATION
@ -----------------------------------------------------------------------------
@ World state: Norman just defeated for the first time. VAR_NORMAN_QUEST_STATE
@ = 0, FLAG_NORMAN_QUEST_STARTED not set: Norman is home in the player's house
@ waiting for the player to speak with him (DadIntroduceQuest dialogue).
@ FLAG_HIDE_PLAYERS_HOUSE_DAD is cleared; ManageNormanVisibility confirms Norman
@ visible on house entry. FLAG_HIDE_PETALBURG_GYM_NORMAN set.
@
@ Warps to Littleroot Town between the two player houses.
@ Brendan's house entrance at (5, 8), May's house entrance at (14, 8).
@ =============================================================================
Debug_Script_2::
	lockall

	@ --- Badges ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET

	@ --- Gym defeat flags ---
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM

	@ --- Norman defeated; quest not yet started ---
	setvar VAR_PETALBURG_GYM_STATE, 7
	setvar VAR_NORMAN_QUEST_STATE, 0
	@ FLAG_NORMAN_QUEST_STARTED intentionally not set: house intro not yet triggered
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN      @ Norman left the gym after defeat
	clearflag FLAG_HIDE_PLAYERS_HOUSE_DAD        @ Norman visible at home

	@ --- Match Call / PokéNav ---
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL

	@ --- Story-critical progression ---
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_0x8008, 4
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY

	@ --- Player essentials ---
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Littleroot intro complete ---
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4

	@ --- HMs ---
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_FLASH
	setflag FLAG_RECEIVED_HM_SURF
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_CUT
	additem ITEM_HM_FLASH
	additem ITEM_HM_SURF

	@ --- Party (levels 31-33) ---
	givemon SPECIES_MARSHTOMP, 32, ITEM_NONE
	givemon SPECIES_BRELOOM, 31, ITEM_NONE
	givemon SPECIES_PONYTA, 33, ITEM_NONE
	givemon SPECIES_SWELLOW, 31, ITEM_NONE
	givemon SPECIES_MACHOKE, 32, ITEM_NONE
	givemon SPECIES_GRAVELER, 33, ITEM_NONE
	additem ITEM_ULTRA_BALL, 10
	additem ITEM_FULL_RESTORE, 5

	@ --- Warp to Littleroot Town between the two player houses ---
	warp MAP_LITTLEROOT_TOWN, 9, 7
	waitstate
	end

@ =============================================================================
@ Debug_Script_3 - Norman Quest: PETALBURG WOODS ENCOUNTER
@ -----------------------------------------------------------------------------
@ World state: House intro has fired (DadIntroduceQuest). FLAG_NORMAN_QUEST_STARTED
@ set, VAR_NORMAN_QUEST_STATE = 0. The SanctuaryBlocker NPC at (3, 39) is hidden
@ by FLAG_NORMAN_QUEST_STARTED. Stepping on tile (4, 39) triggers
@ EventScript_NormanJoinPlayer: Norman flies in, greets the player, and state
@ advances to 1. FLAG_HIDE_PLAYERS_HOUSE_DAD set; Norman not in house.
@
@ Warps to Petalburg Woods north of the Norman coord event at (4, 39).
@ =============================================================================
Debug_Script_3::
	lockall

	@ --- Badges ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET

	@ --- Gym defeat flags ---
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM

	@ --- Norman quest: house intro done, player directed to Petalburg Woods ---
	setvar VAR_PETALBURG_GYM_STATE, 7
	setvar VAR_NORMAN_QUEST_STATE, 0
	setflag FLAG_NORMAN_QUEST_STARTED            @ house intro fired; Norman heading to woods
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD          @ Norman not at home

	@ --- Match Call / PokéNav ---
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL

	@ --- Story-critical progression ---
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_0x8008, 4
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY

	@ --- Player essentials ---
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Littleroot intro complete ---
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4

	@ --- HMs ---
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_FLASH
	setflag FLAG_RECEIVED_HM_SURF
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_CUT
	additem ITEM_HM_FLASH
	additem ITEM_HM_SURF

	@ --- Party (levels 31-33) ---
	givemon SPECIES_MARSHTOMP, 32, ITEM_NONE
	givemon SPECIES_BRELOOM, 31, ITEM_NONE
	givemon SPECIES_PONYTA, 33, ITEM_NONE
	givemon SPECIES_SWELLOW, 31, ITEM_NONE
	givemon SPECIES_MACHOKE, 32, ITEM_NONE
	givemon SPECIES_GRAVELER, 33, ITEM_NONE
	additem ITEM_ULTRA_BALL, 10
	additem ITEM_FULL_RESTORE, 5

	@ --- Warp to Petalburg Woods north of Norman coord event (4, 39) ---
	warp MAP_PETALBURG_WOODS, 4, 35
	waitstate
	end

@ =============================================================================
@ Debug_Script_4 - Norman Quest: JOHTO SANCTUARY ENTRANCE
@ -----------------------------------------------------------------------------
@ World state: Norman met the player in Petalburg Woods and introduced the Johto
@ Sanctuary (VAR_NORMAN_QUEST_STATE = 1). Stepping on tile (9, 10) triggers
@ StantlerAppearance_NorthernTrigger: Stantler walks in from (11, 17), cries,
@ leaves, then Norman runs in for the first re-encounter dialogue. State advances
@ to 2. Cut trees at (10, 13) and (11, 14) can be cleared to test deeper access.
@
@ Warps to Johto Sanctuary Entrance north of the Stantler coord events (9, 10)/(9, 11).
@ =============================================================================
Debug_Script_4::
	lockall

	@ --- Badges ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET

	@ --- Gym defeat flags ---
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM

	@ --- Norman quest: woods scene complete, player heading to sanctuary ---
	setvar VAR_PETALBURG_GYM_STATE, 7
	setvar VAR_NORMAN_QUEST_STATE, 1
	setflag FLAG_NORMAN_QUEST_STARTED
	setflag FLAG_HIDE_PETALBURG_GYM_NORMAN
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD

	@ --- Match Call / PokéNav ---
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL

	@ --- Story-critical progression ---
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_0x8008, 4
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY

	@ --- Player essentials ---
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Littleroot intro complete ---
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4

	@ --- HMs ---
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_FLASH
	setflag FLAG_RECEIVED_HM_SURF
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_CUT
	additem ITEM_HM_FLASH
	additem ITEM_HM_SURF

	@ --- Party (levels 31-33) ---
	givemon SPECIES_MARSHTOMP, 32, ITEM_NONE
	givemon SPECIES_BRELOOM, 31, ITEM_NONE
	givemon SPECIES_PONYTA, 33, ITEM_NONE
	givemon SPECIES_SWELLOW, 31, ITEM_NONE
	givemon SPECIES_MACHOKE, 32, ITEM_NONE
	givemon SPECIES_GRAVELER, 33, ITEM_NONE
	additem ITEM_ULTRA_BALL, 10
	additem ITEM_FULL_RESTORE, 5

	@ --- Warp to Johto Sanctuary Entrance north of Stantler coord events ---
	warp MAP_JOHTO_SANCTUARY_ENTRANCE, 9, 7
	waitstate
	end

@ --- Scripts 5-12 reserved ---

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end

Debug_Script_9::
	end

Debug_Script_10::
	end

Debug_Script_11::
	end

Debug_Script_12::
	end
