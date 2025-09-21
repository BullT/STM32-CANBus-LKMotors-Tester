#ifndef KEYBOARD_LAYOUT
#define KEYBOARD_LAYOUT

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/hal/Types.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include "BitmapDatabase.hpp"

using namespace touchgfx;

/**
 * Array specifying the keys used in the CustomKeyboard.
 */
static const Keyboard::Key keyArray[30] =
{
    { 1, Rect(7, 61, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 2, Rect(7 + 28, 61, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 3, Rect(7 + 28 * 2, 61, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 4, Rect(7 + 28 * 3, 61, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},

	{ 5, Rect(7, 105, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{ 6, Rect(7 + 28, 105, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{ 7, Rect(7 + 28 * 2, 105, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{ 8, Rect(7 + 28 * 3, 105, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},

	{ 9, Rect(7, 149, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{10, Rect(7 + 28, 149, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{11, Rect(7 + 28 * 2, 149, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{12, Rect(7 + 28 * 3, 149, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},

	{13, Rect(7, 193, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{14, Rect(7 + 28, 193, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{15, Rect(7 + 28 * 2, 193, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
	{16, Rect(7 + 28 * 3, 193, 26, 40), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
};

/**
 * Callback areas for the special buttons on the CustomKeyboard.
 */
static Keyboard::CallbackArea callbackAreas[3] =
{
    {Rect(7, 237, 56, 40), 0, BITMAP_KEYBOARD_KEY_OK_HIGHLIGHTED_ID},  		// ok
	{Rect(63, 237, 56, 40), 0, BITMAP_KEYBOARD_KEY_DELETE_HIGHLIGHTED_ID},  // backspace
    {Rect(90, 8, 28, 42), 0, BITMAP_KEYBOARD_KEY_CLOSE_HIGHLIGHTED_ID},  	// close
};

/**
 * The layout for the CustomKeyboard.
 */
static const Keyboard::Layout layout =
{
    BITMAP_KEYBOARD_BACKGROUND_ID,
    keyArray,
    16,
    callbackAreas,
    3,
    Rect(30, 15, 11 * 28, 40),
    TypedText(T_ENTEREDTEXT),
    0xFFFFFF,
    Typography::KEYBOARD,
    0
};

#endif
