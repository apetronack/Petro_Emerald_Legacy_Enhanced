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
	closemessage
	release
	end

@ =============================================================================
@ Debug_Script_1 - Steven Champion Rematch Battle Test
@ -----------------------------------------------------------------------------
@ World state: postgame champion flow with both rematch gates satisfied.
@ - FLAG_DEFEATED_WALLACE_AS_CHAMPION set
@ - FLAG_DEFEATED_WALLY_VR5_REMATCH set
@ Forces next champion = Steven and warps into Champions Room.
@ Expected result: Steven battle should use TRAINER_STEVEN_CHAMPION_REMATCH.
@ =============================================================================
Debug_Script_1::
	lockall
	call Debug_SetupChampionTestBase
	@ Ensure Champions Room OnFrame entry script always runs on warp.
	setvar VAR_TEMP_1, 0
	setflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	setflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 0
	@ Champion object visibility for next run.
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	setflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	clearflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for selected next champion = Steven.
	setflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	clearflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM, 6, 12
	waitstate
	end

@ =============================================================================
@ Debug_Script_2 - Brawly Quest: QUEST START
@ -----------------------------------------------------------------------------
@ World state: Badges 1-5 obtained, all relevant gyms defeated. Brawly NPC
@ appears outside Dewford Gym, ready to begin the Brawly quest.
@
@ Automatically warps to Dewford Town at X11, Y9.
@ Gives a high-level Pokemon and Star Pieces for combat testing.
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

	@ --- TM receipt flags ---
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_BULK_UP
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	setflag FLAG_RECEIVED_TM_OVERHEAT
	setflag FLAG_RECEIVED_TM_FACADE

	@ --- Give TM items ---
	additem ITEM_TM_ROCK_TOMB
	additem ITEM_TM_BULK_UP
	additem ITEM_TM_SHOCK_WAVE
	additem ITEM_TM_OVERHEAT
	additem ITEM_TM_FACADE

	@ --- Match Call / PokéNav registration ---
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
	setflag FLAG_REMATCH_READY_ROXANNE
	setflag FLAG_REMATCH_READY_BRAWLY
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV

	@ --- Story-critical vars ---
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_GYM_STATE, 6
	setvar VAR_0x8008, 5

	@ --- Storyline flags ---
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Give HMs ---
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_CUT
	additem ITEM_HM_SURF

	@ --- Brawly Quest: make Brawly visible outside gym to begin the quest ---
	clearflag FLAG_HIDE_BRAWLY_OUTSIDE_GYM
	clearflag FLAG_HIDE_BRAWLY_QUEST_AQUAS
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	clearflag FLAG_HIDE_BRAWLY_QUEST_ROUTE_107_AQUA_GRUNT

	@ --- Give a high-level starter for combat testing ---
	givemon SPECIES_BLAZIKEN, 50, ITEM_NONE
	givemon SPECIES_WAILORD, 50, ITEM_NONE
	givemon SPECIES_LINOONE, 50, ITEM_NONE

	@ --- Give Star Pieces for testing ---
	additem ITEM_STAR_PIECE, 5

	@ --- Give money for any vendor/NPC interactions ---
	addmoney 50000, 0

	@ --- Give healing items for combat testing ---
	additem ITEM_FULL_RESTORE, 10

	@ --- Warp to Dewford Town ---
	warp MAP_DEWFORD_TOWN, 11, 9
	waitstate
	end

@ --- Debug_Script_3: New Mauville Wattson Quest ---
@ Warps to New Mauville, gives a high-level Pokemon for combat testing, and sets the Wattson quest state to active.

Debug_Script_3::
	lockall
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_BULK_UP
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	setflag FLAG_RECEIVED_TM_OVERHEAT
	setflag FLAG_RECEIVED_TM_FACADE
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
	setflag FLAG_REMATCH_READY_ROXANNE
	setflag FLAG_REMATCH_READY_BRAWLY
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_GYM_STATE, 6
	setvar VAR_0x8008, 5
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON 
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	givemon SPECIES_PARASECT, 50, ITEM_NONE
	warp MAP_NEW_MAUVILLE_INSIDE, 32, 34
	waitstate

	end

@ =============================================================================
@ Champion Rotation Test Suite (Scripts 4-10)
@ -----------------------------------------------------------------------------
@ Script 4: Baseline/Initial route. Forces next champion = Steven and warps to
@           Champions Room for a direct battle flow check.
@ Script 5: Post-Steven fixed phase. Forces next champion = Wallace and warps
@           to Champions Room for Wallace battle flow check.
@ Script 6: Random-phase setup (gates met), force next champion = Steven.
@           Warps to Steven's Cave to validate clue visibility.
@ Script 7: Random-phase setup (gates met), force next champion = Wallace.
@           Warps to Sootopolis to validate Wallace visiting clue visibility.
@ Script 8: Random-phase setup (gates met), force next champion = Wally.
@           Warps to Victory Road 1F to validate Exit Wally clue visibility.
@ Script 9: Mixed gate case A. Wallace defeated as champion, but Wally VR5 not done.
@           Force next champion = Wallace and verify Wallace remains the only option.
@ Script 10: Mixed gate case B. Wally VR5 done, but Wallace not defeated as champion.
@            Force next champion = Steven and verify Steven uses INITIAL team path.
@ =============================================================================

Debug_Script_4::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Champions Room: Steven present, Wallace/Wally hidden.
	@ - Meteor Falls Steven clue: hidden (Steven absent).
	@ - Sootopolis Wallace visiting: visible.
	@ - Victory Road Exit Wally: visible.
	@ Gate state: Wallace not yet defeated as champion and Wally VR5 flag not set.
	clearflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	clearflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 0
	@ Champion object visibility for next run.
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	setflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	clearflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for next champion = Steven.
	setflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	clearflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM, 6, 12
	waitstate
	end

Debug_Script_5::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Champions Room: Wallace present, Steven/Wally hidden.
	@ - Meteor Falls Steven clue: visible.
	@ - Sootopolis Wallace visiting: hidden.
	@ - Victory Road Exit Wally: visible.
	@ Gate state: fixed Wallace phase.
	clearflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	clearflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 1
	@ Champion object visibility for next run.
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	clearflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for next champion = Wallace.
	clearflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM, 6, 12
	waitstate
	end

Debug_Script_6::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Random pool unlocked, forced next champion = Steven.
	@ - Champions Room: Steven present, Wallace/Wally hidden.
	@ - Meteor Falls Steven clue: hidden (validate immediately at warp target).
	@ - Sootopolis Wallace visiting: visible.
	@ - Victory Road Exit Wally: visible.
	@ Gate state: random pool unlocked.
	setflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	setflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 0
	@ Champion object visibility for next run.
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	setflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	clearflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for selected next champion = Steven.
	setflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	clearflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_METEOR_FALLS_STEVENS_CAVE, 10, 28
	waitstate
	end

Debug_Script_7::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Random pool unlocked, forced next champion = Wallace.
	@ - Champions Room: Wallace present, Steven/Wally hidden.
	@ - Sootopolis Wallace visiting: hidden (validate immediately at warp target).
	@ - Meteor Falls Steven clue: visible.
	@ - Victory Road Exit Wally: visible.
	@ Gate state: random pool unlocked.
	setflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	setflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 1
	@ Champion object visibility for next run.
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	clearflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for selected next champion = Wallace.
	clearflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_SOOTOPOLIS_CITY, 29, 34
	waitstate
	end

Debug_Script_8::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Random pool unlocked, forced next champion = Wally.
	@ - Champions Room: Wally present, Steven/Wallace hidden.
	@ - Victory Road Exit Wally: hidden (validate immediately at warp target).
	@ - Meteor Falls Steven clue: visible.
	@ - Sootopolis Wallace visiting: visible.
	@ Gate state: random pool unlocked.
	setflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	setflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 2
	@ Champion object visibility for next run.
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	setflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	clearflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for selected next champion = Wally.
	clearflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	setflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	clearflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_VICTORY_ROAD_1F, 31, 10
	waitstate
	end

Debug_Script_9::
	lockall
	call Debug_SetupChampionTestBase
	@ Expected outcome:
	@ - Mixed gate case A: Wallace champion flag set, Wally VR5 not cleared.
	@ - Champions Room: Wallace present, Steven/Wally hidden.
	@ - Wallace battle should start (fixed Wallace phase persists).
	setflag FLAG_DEFEATED_WALLACE_AS_CHAMPION
	clearflag FLAG_DEFEATED_WALLY_VR5_REMATCH
	setvar VAR_NEXT_CHAMPION, 1
	@ Champion object visibility for next run.
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_WALLACE
	clearflag FLAG_HIDE_HALL_OF_FAME_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_STEVEN
	setflag FLAG_HIDE_HALL_OF_FAME_STEVEN
	setflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	setflag FLAG_HIDE_HALL_OF_FAME_WALLY
	@ Clues for selected next champion = Wallace.
	clearflag FLAG_HIDE_STEVEN_CHAMPION_CLUE
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_WALLACE_VISITING_SOOTOPOLIS
	call Debug_GrantChampionTestTeam
	warp MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM, 6, 12
	waitstate
	end

Debug_SetupChampionTestBase::
	@ Core progression and postgame assumptions used by all champion tests.
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_IS_CHAMPION
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 0
	setvar VAR_SKY_PILLAR_STATE, 2
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	return

Debug_GrantChampionTestTeam::
	@ Battle-capable team for champion and rematch testing.
	givemon SPECIES_SWAMPERT, 80, ITEM_LEFTOVERS
	givemon SPECIES_METAGROSS, 80, ITEM_CHOICE_BAND
	givemon SPECIES_SALAMENCE, 80, ITEM_LUM_BERRY
	givemon SPECIES_GARDEVOIR, 80, ITEM_TWISTED_SPOON
	givemon SPECIES_MANECTRIC, 80, ITEM_MAGNET
	givemon SPECIES_BRELOOM, 80, ITEM_BLACK_BELT
	additem ITEM_FULL_RESTORE, 30
	additem ITEM_MAX_REVIVE, 20
	additem ITEM_MAX_ETHER, 20
	additem ITEM_TM_EARTHQUAKE, 3
	additem ITEM_TM_FLAMETHROWER, 1
	additem ITEM_TM_THUNDERBOLT, 1
	additem ITEM_TM_ICE_BEAM, 1
	additem ITEM_TM_CALM_MIND, 1
	additem ITEM_TM_GIGA_DRAIN, 1
	additem ITEM_TM_SHADOW_BALL, 1
	additem ITEM_TM_FIRE_BLAST, 1
	additem ITEM_TM_DRAGON_CLAW, 1
	additem ITEM_TM_BULK_UP, 1
	additem ITEM_TM_BLIZZARD, 2
	additem ITEM_TM_BRICK_BREAK, 2
	additem ITEM_TM_SLUDGE_BOMB, 1
	additem ITEM_TM_AERIAL_ACE, 1
	additem ITEM_HM_SURF, 1
	additem ITEM_HM_FLY, 1
	additem ITEM_HM_CUT, 1
	additem ITEM_HM_STRENGTH, 1
	additem ITEM_HM_ROCK_SMASH, 1
	additem ITEM_HM_DIVE, 1
	additem ITEM_HM_FLASH, 1
	addmoney 99999, 0
	return
