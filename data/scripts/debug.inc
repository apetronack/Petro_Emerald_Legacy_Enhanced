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
@ Debug_Script_1 - Roxanne Quest: QUEST ACTIVE
@ -----------------------------------------------------------------------------
@ World state: Badges 1-3 obtained, Wattson just defeated, Roxanne quest
@ activated. Roxanne NPC appears outside Rustboro Gym, blocking entry.
@
@ Automatically warps to Rusturf Tunnel (Route 116 entrance side).
@ Gives a level 45 Sceptile for immediate combat testing.
@ =============================================================================
Debug_Script_1::
	lockall

	@ --- Badges ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET

	@ --- Gym defeat flags ---
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM

	@ --- TM receipt flags ---
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	setflag FLAG_RECEIVED_TM_BULK_UP            @ Brawly's TM

	@ --- Match Call / PokéNav registration ---
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_REMATCH_READY_ROXANNE
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV

	@ --- Story-critical vars ---
	@ VAR_RUSTBORO_CITY_STATE 1: Devon goods quest resolved, city normal
	setvar VAR_RUSTBORO_CITY_STATE, 1
	@ VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE 3: Set by Wattson defeat
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	@ VAR_PETALBURG_GYM_STATE: 0 base + 1 (Wally intro) + 1 (Wally leaves)
	@   + 1 (Roxanne badge) + 1 (Wattson badge) = 4
	@   Value 6 triggers Norman unlock; 4 is safe.
	setvar VAR_PETALBURG_GYM_STATE, 4
	@ VAR_0x8008 3: Gym trainer difficulty tier after Badge 3
	setvar VAR_0x8008, 3

	@ --- Slateport / Devon goods chain resolved ---
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_MET_DEVON_EMPLOYEE

	@ --- Briney / sailing resolved so player can access Dewford/Slateport ---
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY

	@ --- Player progression essentials ---
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_B_DASH                     @ Running shoes
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_SYS_POKEMON_GET

	@ --- Give HM Rock Smash so tunnel puzzle is immediately usable ---
	additem ITEM_HM_ROCK_SMASH

	@ --- Give a usable party if one is not already present ---
	@ (Use Debug Menu > Pokemon Creator to set a proper party if needed)

	@ --- Roxanne Quest activation ---
	setflag FLAG_ROXANNE_QUEST_ACTIVE
	setvar VAR_ROXANNE_QUEST_STATE, 1
	@ Roxanne NPC visible outside gym; cleared when quest completes
	clearflag FLAG_HIDE_ROXANNE_OUTSIDE_GYM

	@ --- Rusturf Tunnel grunt guard visible (set by Wattson gym defeat in-game) ---
	setflag FLAG_RUSTURF_MAGMA_GRUNT_VISIBLE
	@ FLAG_RUSTURF_MAGMA_GRUNT_PAID intentionally NOT set here; tester must pay

	@ --- Skip Briney/Peeko/Aqua Grunt encounter in Rusturf Tunnel ---
	@ Devon goods quest resolved at state 1; ensure encounter NPCs are hidden
	setvar VAR_RUSTURF_TUNNEL_STATE, 0
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_BRINEY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	@ Wanda and her boyfriend are hidden at new game; reveal them for the side quest
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA

	@ --- Give enough money to pay the Magma Grunt guard (¥5,000 required) ---
	addmoney 5000, 0

	@ --- Give a high-level starter for combat testing ---
	givemon SPECIES_SCEPTILE, 45, ITEM_NONE

	@ --- Warp directly into Rusturf Tunnel (Route 116 entrance side) ---
	warp MAP_RUSTURF_TUNNEL, 5, 10
	waitstate
	end

@ =============================================================================
@ Debug_Script_2 - Roxanne Quest: GRUNTS CLEARED
@ -----------------------------------------------------------------------------
@ World state: Both Magma Grunts in the cave have been defeated. Player is
@ ready to enter Rusturf_MagmaCave_Final and face the admin double battle.
@
@ Automatically warps to Rusturf_MagmaCave_Main entrance.
@ Gives a level 45 Sceptile for immediate combat testing.
@ =============================================================================
Debug_Script_2::
	lockall

	@ --- All flags from Script 1 ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	setflag FLAG_RECEIVED_TM_BULK_UP
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_REMATCH_READY_ROXANNE
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_GYM_STATE, 4
	setvar VAR_0x8008, 3
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
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_STRENGTH
	setflag FLAG_ROXANNE_QUEST_ACTIVE
	clearflag FLAG_HIDE_ROXANNE_OUTSIDE_GYM

	@ --- Rusturf Tunnel grunt guard visible (set by Wattson gym defeat in-game) ---
	setflag FLAG_RUSTURF_MAGMA_GRUNT_VISIBLE
	@ Player is past the grunt; mark as paid so OnTransition repositions him
	setflag FLAG_RUSTURF_MAGMA_GRUNT_PAID

	@ --- Quest progression: all 3 grunts defeated ---
	setvar VAR_ROXANNE_QUEST_STATE, 3
	setflag FLAG_MAGMA_GRUNT_RUSTURF_1_DEFEATED
	settrainerflag TRAINER_GRUNT_RUSTURF_MAGMA_CAVE_2
	settrainerflag TRAINER_GRUNT_RUSTURF_MAGMA_CAVE_3

	@ --- Skip Briney/Peeko/Aqua Grunt encounter in Rusturf Tunnel ---
	setvar VAR_RUSTURF_TUNNEL_STATE, 0
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_BRINEY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	@ Wanda and her boyfriend are hidden at new game; reveal them for the side quest
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA

	@ --- Give a high-level starter for combat testing ---
	givemon SPECIES_SCEPTILE, 45, ITEM_NONE

	@ --- Warp into Rusturf_MagmaCave_Main (past the Entry tunnel) ---
	warp MAP_RUSTURF_MAGMA_CAVE_MAIN, 5, 25
	waitstate
	end

@ =============================================================================
@ Debug_Script_3 - Roxanne Quest: QUEST COMPLETE (Reward Pending)
@ -----------------------------------------------------------------------------
@ World state: Admin double battle done, fossil stolen, player has returned
@ to Rustboro City. Roxanne is back inside the gym. Quest complete flag set,
@ reward not yet given - triggers Roxanne's Relicanth gift dialogue on contact.
@
@ Automatically warps to Rustboro City Gym (near Roxanne).
@ Gives a level 45 Sceptile for immediate combat testing.
@ =============================================================================
Debug_Script_3::
	lockall

	@ --- All flags from Script 1 ---
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	setflag FLAG_RECEIVED_TM_BULK_UP
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setflag FLAG_REMATCH_READY_ROXANNE
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setvar VAR_RUSTBORO_CITY_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_GYM_STATE, 4
	setvar VAR_0x8008, 3
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
	setflag FLAG_ROXANNE_QUEST_ACTIVE
	@ Player is long past the grunt; mark as paid so OnTransition repositions him
	setflag FLAG_RUSTURF_MAGMA_GRUNT_PAID

	@ --- Quest complete state ---
	setvar VAR_ROXANNE_QUEST_STATE, 5
	setflag FLAG_MAGMA_GRUNT_RUSTURF_1_DEFEATED
	setflag FLAG_MAGMA_ADMINS_RUSTURF_DEFEATED
	setflag FLAG_ROXANNE_QUEST_COMPLETE

	@ --- Fossil tracking (Helix chosen by default for testing) ---
	@ To test Dome instead: swap setflag/clearflag below
	setflag FLAG_CHOSE_HELIX_FOSSIL
	clearflag FLAG_CHOSE_DOME_FOSSIL
	setflag FLAG_FOSSIL_STOLEN_BY_GRUNT

	@ --- Roxanne back inside gym; overworld NPC hidden ---
	setflag FLAG_HIDE_ROXANNE_OUTSIDE_GYM

	@ --- Reward not yet given; speaking to Roxanne will trigger gift ---
	clearflag FLAG_ROXANNE_QUEST_REWARD_GIVEN

	@ --- Skip Briney/Peeko/Aqua Grunt encounter in Rusturf Tunnel ---
	setvar VAR_RUSTURF_TUNNEL_STATE, 0
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_BRINEY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	@ Wanda and her boyfriend are hidden at new game; reveal them for the side quest
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA

	@ --- Give a high-level starter for combat testing ---
	givemon SPECIES_SCEPTILE, 45, ITEM_NONE

	@ --- Warp to Rustboro City Gym (near Roxanne for reward dialogue) ---
	warp MAP_RUSTBORO_CITY_GYM, 5, 5
	waitstate
	end

@ --- Scripts 4-8 reserved for future quest checkpoints ---

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end
