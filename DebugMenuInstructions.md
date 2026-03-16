Add a debug menu
From https://github.com/pret/pokeemerald/wiki/Add-a-debug-menu

TheXaman edited this page on Jun 12, 2021 · 10 revisions
During development it's common for your game to be partially complete; even if it isn't, you probably don't want to spend a whole bunch of time playing through the game to get to the bit you need to test. As such, it's useful to have a debug menu with a collection of tools defined in code to do useful things for you which you don't expose to the players. However, pokeemerald reproduces the commercial release of Pokémon Emerald, so there's no debug functionality at all. Fortunately we're programmers, so we can fix that.

I assume a reasonable familiarity with C, so I won't be explaining things like preprocessor directives, include guards, what a structure or its fields are, or the like. If you want or need to look these things up, you now know what to search for.

Step 0: Add a compile flag
There's no reason to expose the debug menu to the players, so it's a good idea to keep it behind a compile flag just like Game Freak did. This is technically optional, since you can just tell people not to hold R when pressing Start or whatever, but it's really easy to do. If you do choose to skip it, be sure when following the remainder of the tutorial to watch out for and ignore any #if DEBUGGING and #endif pairs.

Alter the Makefile like this.

ifeq ($(NODEP),1)
$(C_BUILDDIR)/%.o: c_dep :=
else
$(C_BUILDDIR)/%.o: c_dep = $(shell $(SCANINC) -I include $(C_SUBDIR)/$*.c)
endif

ifeq ($(DINFO),1)
override CFLAGS += -g
endif

+ifeq ($(DDEBUGGING),1)
+override ASFLAGS += --defsym DEBUGGING=1
+override CPPFLAGS += -D DEBUGGING=1
+endif

$(C_BUILDDIR)/%.o : $(C_SUBDIR)/%.c $$(c_dep)
	@$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/$*.i
	@$(PREPROC) $(C_BUILDDIR)/$*.i charmap.txt | $(CC1) $(CFLAGS) -o $(C_BUILDDIR)/$*.s
	@echo -e ".text\n\t.align\t2, 0\n" >> $(C_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/$*.s
From now on, when building your ROM hack for yourself, you'll want to run make DDEBUGGING=1 (note the double D!) rather than just make.

Step 1: Add a button combination
For this step we'll be working with the source file field_control_avatar.c and its associated header file field_control_avatar.h. Look in the header file for the definition of FieldInput; for me right now it looks like this.

struct FieldInput
{
    bool8 pressedAButton:1;
    bool8 checkStandardWildEncounter:1;
    bool8 pressedStartButton:1;
    bool8 pressedSelectButton:1;
    bool8 heldDirection:1;
    bool8 heldDirection2:1;
    bool8 tookStep:1;
    bool8 pressedBButton:1;
    bool8 input_field_1_0:1;
    bool8 input_field_1_1:1;
    bool8 input_field_1_2:1;
    bool8 input_field_1_3:1;
    bool8 input_field_1_4:1;
    bool8 input_field_1_5:1;
    bool8 input_field_1_6:1;
    bool8 input_field_1_7:1;
    u8 dpadDirection;
};
The fields whose names begin input_field_1_ are debug input flags; in Game Freak's debug builds these are switched on when the user inputs certain button combinations. I'll be using input_field_1_2 because it's what Game Freak used; it may be renamed in your copy of pokeemerald if you're reading this in the future, but it'll be in the same position in the structure so all you need to do is remember the name.

Switch to the source file and alter the end of the function FieldGetPlayerInput like this.

    if (heldKeys & DPAD_UP)
        input->dpadDirection = DIR_NORTH;
    else if (heldKeys & DPAD_DOWN)
        input->dpadDirection = DIR_SOUTH;
    else if (heldKeys & DPAD_LEFT)
        input->dpadDirection = DIR_WEST;
    else if (heldKeys & DPAD_RIGHT)
        input->dpadDirection = DIR_EAST;

+#if DEBUGGING
+    if ((heldKeys & R_BUTTON) && input->pressedStartButton)
+    {
+        input->input_field_1_2 = TRUE;
+        input->pressedStartButton = FALSE;
+    }
+#endif
}
This defines the button combination to access the debug menu: hold R, press Start. You can change it if you like, but the number of sensible combinations is pretty limited.

Now scroll down and alter the end of the function ProcessPlayerFieldInput like this.

    if (input->pressedSelectButton && UseRegisteredKeyItemOnField() == TRUE)
        return TRUE;

+#if DEBUGGING
+    if (input->input_field_1_2)
+    {
+        PlaySE(SE_WIN_OPEN);
+        Debug_ShowMainMenu();
+        return TRUE;
+    }
+#endif

    return FALSE;
}
This is the payoff; if the user has pressed the button combination, we get a sound effect and (eventually) a menu. If you want, you can comment out the line Debug_ShowMainMenu(); and test the code as it is now; the sound effect is the same as when you open the Start menu, but no menu opens. Finally, edit the very top of the file like this.

#include "global.h"
#include "battle_setup.h"
#include "bike.h"
#include "coord_event_weather.h"
#include "daycare.h"
+#include "debug.h"
#include "faraway_island.h"
If you search you'll find that there is no debug.h in the pokeemerald codebase; let's change that.

Step 2: Add the menu itself
You're done editing Game Freak code; now you get to write some of your own. Before we create the new files, we have to add them to the ld_script.txt, first one around line 102:

src/util.o(.text);
src/daycare.o(.text);
+src/debug.o(.text);
src/egg_hatch.o(.text);
src/battle_interface.o(.text);
Second one in ld_script.txt around line 486:

src/util.o(.rodata);
src/daycare.o(.rodata);
+src/debug.o(.rodata);
src/egg_hatch.o(.rodata);
src/battle_gfx_sfx_util.o(.rodata);
Now create a header file include/debug.h and populate it as follows.

#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H
#if DEBUGGING

void Debug_ShowMainMenu(void);

#endif
#endif // GUARD_DEBUG_H
Now create a source file src/debug.c and populate it as follows.

#if DEBUGGING

#include "global.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "constants/songs.h"

#define DEBUG_MAIN_MENU_HEIGHT 7
#define DEBUG_MAIN_MENU_WIDTH 11

void Debug_ShowMainMenu(void);
static void Debug_DestroyMainMenu(u8);
static void DebugAction_Cancel(u8);
static void DebugTask_HandleMainMenuInput(u8);

enum {
    DEBUG_MENU_ITEM_CANCEL,
};

static const u8 gDebugText_Cancel[] = _("Cancel");

static const struct ListMenuItem sDebugMenuItems[] =
{
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL}
};

static void (*const sDebugMenuActions[])(u8) =
{
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel
};

static const struct WindowTemplate sDebugMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MAIN_MENU_WIDTH,
    .height = 2 * DEBUG_MAIN_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sDebugMenuListTemplate =
{
    .items = sDebugMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenuItems),
    .maxShowed = DEBUG_MAIN_MENU_HEIGHT,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

void Debug_ShowMainMenu(void) {
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = sDebugMenuListTemplate;
    menuTemplate.windowId = windowId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(DebugTask_HandleMainMenuInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Debug_DestroyMainMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void DebugTask_HandleMainMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenuActions[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMainMenu(taskId);
    }
}

static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMainMenu(taskId);
}

#endif
That's a lot of code; let's go over it bit by bit.

static const u8 gDebugText_Cancel[] = _("Cancel");

enum {
    DEBUG_MENU_ITEM_CANCEL,
};

static const struct ListMenuItem sDebugMenuItems[] =
{
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL},
};

static void (*const sDebugMenuActions[])(u8) =
{
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel,
};
These define the list itself. sDebugMenuItems ties together the name and an ID number given by an enumeration, while sDebugMenuActions is a list of functions which are executed when the user presses A on that list item. It's important that the enumeration and arrays stay in the same order and have the same length, otherwise strange things will start happening. To add a new entry, follow this example.

static const u8 gDebugText_NewEntry[] = _("New Entry");
static const u8 gDebugText_Cancel[] = _("Cancel");

enum {
    DEBUG_MENU_ITEM_NEW_ENTRY,
    DEBUG_MENU_ITEM_CANCEL,
};

static const struct ListMenuItem sDebugMenuItems[] =
{
    [DEBUG_MENU_ITEM_NEW_ENTRY] = {gDebugText_NewEntry, DEBUG_MENU_ITEM_NEW_ENTRY},
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL},
};

static void (*const sDebugMenuActions[])(u8) =
{
    [DEBUG_MENU_ITEM_NEW_ENTRY] = DebugAction_NewEntry,
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel,
};
Make sure to create the function DebugAction_NewEntry; its signature is static void DebugAction_NewEntry(u8 taskId). If you want the menu item to do nothing when the user presses A, use NULL instead of writing a function that does nothing.

static const struct WindowTemplate sDebugMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MAIN_MENU_WIDTH,
    .height = 2 * DEBUG_MAIN_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};
This is a window template. A window is a box fringed by the border you chose in the options (the default is purple), and a window template determines the properties of that window. Most of these fields should be left alone, but the ones to know about are tilemapLeft and tilemapTop (the window's position relative to the left and top of the screen in tiles); width and height (unsurprisingly, the window's width and height in tiles) and baseBlock. baseBlock is used by the engine for placing the tiles for each window; since we know there are no other windows when the debug menu is opened its baseBlock is 1, but if you create a second window, its baseBlock needs to be at least equal to the product of the width and height fields of this one to avoid corruption.

static const struct ListMenuTemplate sDebugMenuListTemplate =
{
    .items = sDebugMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenuItems),
    .maxShowed = DEBUG_MAIN_MENU_HEIGHT,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};
This is a list menu template. A list menu is a sequence of items where the user scrolls up and down through the items and can pick one by pressing A; in much the same way that a window template determines the properties of a window, a list menu template determines the properties of a list menu. Most of these options look to me like sensible defaults; totalItems is the number of items on the list in total; maxShowed is the number of items you can see at any one time; scrollMultiple controls whether the user can scroll past multiple entries in the list at once, and how they do it (there are three possible values: LIST_NO_MULTIPLE_SCROLL for no fast-scrolling, LIST_MULTIPLE_SCROLL_DPAD for fast-scrolling by pressing left and right on the D-pad, and LIST_MULTIPLE_SCROLL_L_R for fast-scrolling by pressing the L and R buttons).

void Debug_ShowMainMenu(void) {
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = sDebugMenuListTemplate;
    menuTemplate.windowId = windowId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(DebugTask_HandleMainMenuInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}
This is the function that gets called in field_control_avatar.c. It first creates both a window and a list menu, which we've already discussed, and then creates a task to handle user input. A task is just a function which is invoked each frame. The task for this menu is the function DebugTask_HandleMainMenuInput, which checks for user input and delegates to the functions specified in sDebugMenuActions.

You should now be able to compile and run your game and open and close the debug menu. At this point my work is done; it's up to you now to decide what functionality to provide in your debug menu.