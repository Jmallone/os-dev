#pragma once
#include "TypeDefs.h"
#include "TextPrint.h"

extern bool LeftShiftPressed;
extern uint_8 LastScanCode;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr);
void KeyBoardHandler0xE0(uint_8 scanCode);
void KeyBoardHandler(uint_8 scanCode, uint_8 chr);
