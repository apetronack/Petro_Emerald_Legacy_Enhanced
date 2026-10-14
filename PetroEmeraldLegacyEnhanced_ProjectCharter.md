# Pokemon Emerald Legacy Enhanced Petro Version

## Starting Basis

* Pokemon Emerald Legacy Enhanced includes:
    * Additional QoL features
    * Expanded starter selection
    * Reduced grinding

## Petro Version Features
* Additional gym leader interaction in overworld with new, optional rewards
* Add new small map segments to overworld
* Add limited, focused additions to the Hoenn Pokédex to support story progression
* Potential graphic changes to enhance the player experience
    * Tile palettes
    * Mugshots
    * Limited sprite changes

## Out of Scope
* Physical/Special Split
* Pokémon beyond Gen 3 games
* Significant gym/trainer team updates
    * Minor single-member or moveset changes are acceptable
* Move power / accuracy changes
* Pokémon stat, type, or ability changes

# Planned Development Goals
1. Environment setup
    1. Fork repository
    2. Clone to local environment
    3. Set up Poryscript
    4. Set up Porymap
    5. Set up Porymoves
    6. Set up Tilemap Studio
    7. Set up build pipeline
    8. Confirm baseline build success
2. Iteratively add gym leader interactions and associated maps, rewards, and events
    1. Roxanne
        1. Area Addition: Entry point in Rusturf tunnel blocked by rock smash rocks
        2. Roxanne appears outside of gym after beating Wattson, blocks gym entry
        3. Task: Send player to stop Team Magma, who are excavating in tunnel
            1. Worldbuilding: Tunnel excavation crew members express having been intimidated away from the tunnel
            2. Worldbuilding: A boyfriend trying to flee Team Magma to rejoin his girlfriend adds urgency to the quest
            3. Worldbuilding: After completing quest, have excavation crew thank player
        4. Area details: Excavation equipment, warm cave aesthetic, lava, rock smash rocks
        5. 2-3 rooms/paths to access
            1. Main entry point, fight 3 grunts
            2. Second area, find Helix/Dome Fossils behind a Rock Smash rock
                1. After picking a fossil, the player is ambushed by 2 admins
                2. Admins fight the player; a grunt takes the unselected fossil (player loses access temporarily, with retrieval tracked for later)
                * Note: Remove fossil encounters from postgame to enforce weight of quest completion
            3. Third area: Make optional rock smash/strength puzzle
                1. Reward: Shiny Lairon with high IVs
                    * Moves: Iron Tail, Rock Blast, Take Down, Iron Defense
                    * Nature: Jolly (+Speed / -SpAtk)
                    * Ability: Rock Head
        6. Speak with Roxanne. Reward: Gift Relicanth with above-average IVs, no custom moves, holding a Hard Stone
    2. Brawly
        1. Area addition: Expand Dewford Island to the south, accessible by Surf
        2. Brawly appears outside of gym after beating Norman, blocks gym entry
        3. Task: Send player to stop Team Aqua, who are intimidating town locals and setting up hideout in area south of Dewford
            1. Worldbuilding: Make townspeople comment on Aqua team members being in town. After quest completion, have them thank the player for help
            2. Worldbuilding: Add Team Aqua members to standard Dewford. Remove after quest completion
            3. Worldbuilding: Make shop fronts in the area south of Dewford populated only by Aqua members, with no townspeople
        4. Area details: Beachfront with abandoned storefronts. Include industrial-looking assets on the beach.
        5. Only one area; 2–3 grunts followed by a double battle with admins
        6. Rewards: After beating Team Aqua and talking to Brawly, add move tutors for elemental punches, rock slide, body slam, counter, mega kick, mega punch, mud slap, seismic toss, dynamic punch, endure, swords dance. Give the player one Star Piece as a reward and incentive to use the tutor
        * Currency: Star Piece
        * Make Staryu a Super Rod encounter in the water surrounding the beach/surf area, as Star Pieces are a 5% hold item drop chance
    3. Wattson
        1. Unchanged quest; add a static shiny Pikachu encounter next to the generator in New Mauville with above-average IVs. It knows the event moves Surf and Fly.
            * Ability: Static
            * Moves: Thunderbolt, Surf, Fly, Slam
            * Nature: Rash
    4. Flannery
        1. Find Flannery outside her gym after Groudon is released. Lavaridge's hot springs have begun noticeably cooling, and Flannery wants to solve this problem rather than ask Steven or Devon Corp for help. Sends the player (and herself) to the Scorched Slab, where she has heard has gotten remarkably hotter as Lavaridge gets cooler.
        2. Area: Add a new vent system branching from the Scorched Slab entrance, eventually connecting underground to a cave mouth that will appear by Lavaridge's hot springs path
            1. Antechamber and hazard passage: environmental hazards (new lava flows, steam vents) 
            2. Player and Flannery rescue two stranded survey workers along the way
            3. Vent chamber: Flannery identifies redirected magma flow as the cause of the cooling springs; player helps reopen a secondary channel (Rock Smash / Strength puzzle) to partially restore flow immediately
        4. Flannery has idea to cultivate a Slugma / Torkoal colony in the old flow vent under Lavaridge to restore heat and partially restore lava flow under area
        5. Underground tunnel connects the vent chamber to Lavaridge's hot springs path. Only appears after player has worked through vent chamber from Scorched Slab and opens entrance with Rock Smash scripted event
        6. Rewards: 
            1. Rescued survey workers set up renewable shard mining node in the stabilized vent chamber and a small White Herb shop from a fire-type herbalist among them
            2. Chamber with Sun Stone item. Once player has obtained National Pokedex, can find wild Sunkern who have been attracted by stable conditions
            3. Player can find shiny Houndour in side chamber with above-average IVs, a Hasty nature (+Speed / -Def) knowing Flamethrower, Torment, and egg moves Beat Up and Will-O-Wisp.
    5. Norman
        1. Find Norman in Littleroot after the player's first gym battle
            * Norman makes a comment after losing, reflecting that he needs to get to know his family better and acknowledging that his career focus has caused him to miss out on family connection
        2. New area: south of Littleroot, requiring Cut, Rock Smash, and Surf to access. Has an ancient forest aesthetic.
        * Add Johto encounters: Heracross, Jumpluff, Ariados, Misdreavus, Pineco, Teddiursa
        3. Chase a disappearing Stantler through the forest with Norman
        4. Eventually catch a static encounter shiny Stantler with above-average IVs
            * Ability: Intimidate
            * Nature: Adamant
            * Moves: Hypnosis, Secret Power, Bite (egg move), Earthquake (TM)
        5. Worldbuilding: Make Norman appear at home with mom between each rematch
            * After second rematch, give player an egg for Aipom
            * After third rematch (postgame), give player an egg for Snubbull
            * After fourth rematch (postgame), give player an egg for Girafarig
            * After fifth and final rematch (postgame), give player an egg for Miltank
    6. Winona
        1. Find Winona outside her gym after Kyogre and Groudon are released
        2. Winona explains that the seasonal migratory bird Pokemon flocks that nest on the Sootopolis caldera's exterior cliffs have vanished, and asks the player to help her investigate
        3. Winona flies the player to a new small platform on Route 126, built into the exterior caldera cliff face, with an entrance leading to a new cliff interior area
        4. New areas:
            1. Short transition cave from Route 126. Uses existing cave tilesets
            2. Sootopolis exterior cliff face. Uses Sootopolis tilesets if possible
            3. New cave at upper portion of cliff face
        5. Partway up, the player and Winona find a newly opened cave, created from shifting after Groudon's awakening
            1. A group of Loudred and Exploud have gathered outside the cave entrance and are causing a continuous Uproar, which has driven off the nesting birds
            2. Approaching the group triggers an escalating two-stage warning/rockslide sequence. If the player gets too close, a rockslide sends the player back to a position lower on the cliff face.
        6. Once the player makes their way past the Loudred and Exploud, they find a Whismur trapped by a Strength/Rock Smash obstacle
            1. Clearing the obstacle and freeing the Whismur allows it to return to the group
            2. The Whismur returned, the Loudred/Exploud group calms the uproar and returns to the cave
        7. Winona and the player observe some Pelipper returning to the cliff face, resolving the quest.
        8. Reward: Winona gifts the player a Scope Lens
        9. After quest completion, non-Hoenn migratory bird encounters become available on this new area after receiving the National Dex
        10. After quest completion, the player can enter the Exploud cave to find a shiny Loudred
    7. Tate and Liza
        1. Find them in the postgame at Altering Cave
        2. Worldbuilding: They talk about meditating and ask to see specific Pokémon to attune their powers, rewarding the player in return
            1. Ask to see Alakazam
                * After the player shows Alakazam, add Drowzee and Abra to Altering Cave encounters
            2. Ask to see Unown
                * After the player shows Unown, add Mr. Mime and Misdreavus encounters to Altering Cave
            3. Ask to see Chimecho
                * After the player shows Chimecho, add Psyduck and Jynx encounters to Altering Cave
        3. After all Pokémon are shown, Tate and Liza say they have unlocked their potential and gained the ability to help the player unlock theirs
            * Create shop to enable IV editing
                * 1 Heart Scale per IV point of choice
    8. Wallace
		1. After the initial E4 defeat, find Wallace in the Battle Frontier
		2. Ask the player for help investigating a rumor of a group of Aqua grunts seen near the Battle Frontier
		3. New area: Surf north of the Battle Frontier to find a group of islands and a fishing village
		4. Worldbuilding: Aqua Grunts are visible as the player explores the islands. When the player approaches, they run away.
		5. Worldbuilding: Eventually find Archie, who explains that after seeing the error of his ways, he wants to make amends for the problems Team Aqua caused and live in peace, at one with nature
		6. Wallace arrives, wants to fight, but is talked out of it
		7. Wallace and Archie realize they have common ground, set up fishing village and pal around together
		8. Tasks:
			1. Catch and show Archie an extra-large Chinchou
				* Reward: 50x Net Balls
			2. Show Archie either Kabuto/Kabutops or Omanyte/Omastar
				* Reward: Gives the player the other fossil they didn't select during the Roxanne quest
			3. Show Archie a Sharpedo with max toughness
				* Reward: Give the player a shiny Huntail with max IVs
					* Level: 50
					* Moves: Dragon Dance, Crunch, Hydro Pump, Earthquake (exclusive move!)
                    * Nature: Brave (+Attack / -Speed)
			4. Show Archie a Luvdisc with Max Cuteness
				* Reward: Give the player a shiny Gorebyss with max IVs
					* Level: 50
					* Moves: Calm Mind (exclusive move!), Psychic, Hydro Pump, Ice Beam
                    * Nature: Quiet (+SpAtk / -Speed)
		9. Immediately add a vendor that trades Deep Sea Tooth and Deep Sea Scale for each other
3. Other changes
    1. Make dynamic team selection for Brawly, Wattson, and Flannery
        1. When the player fights Brawly first, keep Wattson and Flannery as-is
        2. When the player skips Brawly and fights Wattson first, then Brawly, then Flannery
        3. When the player skips Brawly and fights Wattson first, then Flannery, then Brawly
	2. After all 5 Wally rematches and the player has beaten both Wallace and Steven as champion
		1. Introduce Wally's champion team
		2. Randomly alternate between Wally, Wallace, and Steven as champions when rematching the E4
	3. Add an intermediate Wally fight before fighting Tate and Liza, scaled appropriately and showing his trainer progression
	4. After completing rival quests in the postgame, make the rival re-battleable
		1. Create region-specific teams for Kanto, Hoenn, and Johto, each with 3 starters from that region and the other 3 as rare encounters
		2. Randomize which team the rival uses
    5. Implement Enhanced Starters changes described by ReadMe. Reference branch: https://github.com/Exclsior/Pokemon_Emerald_Legacy_Enhanced/tree/enhanced-starters
4. Summarization Report
    1. Create a report to display differences from the base Emerald version
    2. Automate:
        * Changes to gym leaders, rivals, and team leaders/admins from base Emerald to modified Emerald
        * Changes in pokemon stats from base Emerald to modified Emerald
        * Changes in move characteristics from base Emerald to modified Emerald
        * Changes in battle frontier teams from base Emerald to modified Emerald
        * Changes in encounter pokemon, locations, or rates from base Emerald to modified Emerald
        * Pokemon evolution changes (method, level, etc.)
        * Pokemon ability changes
    3. Manual:
        * Describe new quest additions
        * Describe new shop / tutor options
        * Berry mechanic changes
        * Contest mechanic changes
        * Postgame encounter changes
        * Postgame legendary pokemon quests
        * Item location changes
        * Reusable TM locations
        * Ability mechanic changes
        * Prize, trade, static, gift pokemon changes from base Emerald
# Workstream Goals
* Add an in-game debug menu covering up through the Battle Frontier
	* Enumerate the flags that need to be set for each gym leader and main story point
	* Prioritize writing debug menu scripts that start the player at specific story points to speed up testing
* Make each improvement a specific branch, then merge into main after successful implementation and game testing
	* Have very specific, planned goals for each improvement
	* If an increase in scope is desired, be prudent about whether to include it in the current branch or make it its own branch
* Keep copious notes about changes in commits/PRs to make ending summary more straightforward
* Review encounter changes and item accessibility holistically when pushing a branch back to main
* Restraint is valuable. Make rewards feel genuinely rewarding and purposeful to enhance the gameplay loop