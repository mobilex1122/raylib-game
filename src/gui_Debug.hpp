/*******************************************************************************************
*
*   Debug v1.0.0 - Custom Debug UI
*
*   MODULE USAGE:
*       #define GUI_DEBUG_IMPLEMENTATION
*       #include "gui_Debug.h"
*
*       INIT: GuiDebugState state = InitGuiDebug();
*       DRAW: GuiDebug(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 Jan Palma. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_DEBUG_H
#define GUI_DEBUG_H

typedef struct {
    Vector2 anchor03;
    
    bool Scene_NameEditMode;
    char Scene_NameText[128];
    bool FpsEditMode;
    char FpsText[128];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiDebugState;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiDebugState InitGuiDebug(void);
void GuiDebug(GuiDebugState *state);

#ifdef __cplusplus
}
#endif

#endif // GUI_DEBUG_H

/***********************************************************************************
*
*   GUI_DEBUG IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_DEBUG_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiDebugState InitGuiDebug(void)
{
    GuiDebugState state = { 0 };

    state.anchor03 = (Vector2){ 24, 24 };
    
    state.Scene_NameEditMode = false;
    strcpy(state.Scene_NameText, "SAMPLE TEXT");
    state.FpsEditMode = false;
    strcpy(state.FpsText, "SAMPLE TEXT");

    // Custom variables initialization

    return state;
}

void GuiDebug(GuiDebugState *state)
{
    GuiPanel((Rectangle){ state->anchor03.x + 0, state->anchor03.y + 0, 208, 104 }, NULL);
    if (GuiTextBox((Rectangle){ state->anchor03.x + 80, state->anchor03.y + 32, 120, 24 }, state->Scene_NameText, 128, state->Scene_NameEditMode)) state->Scene_NameEditMode = !state->Scene_NameEditMode;
    GuiLabel((Rectangle){ state->anchor03.x + 8, state->anchor03.y + 32, 72, 24 }, "SCENE:");
    GuiLabel((Rectangle){ state->anchor03.x + 8, state->anchor03.y + 64, 72, 24 }, "FPS:");
    if (GuiTextBox((Rectangle){ state->anchor03.x + 80, state->anchor03.y + 64, 120, 24 }, state->FpsText, 128, state->FpsEditMode)) state->FpsEditMode = !state->FpsEditMode;
    GuiLabel((Rectangle){ state->anchor03.x + 8, state->anchor03.y + 0, 192, 24 }, "DEBUG");
    GuiLine((Rectangle){ state->anchor03.x + 0, state->anchor03.y + 16, 208, 16 }, NULL);
}

#endif // GUI_DEBUG_IMPLEMENTATION
