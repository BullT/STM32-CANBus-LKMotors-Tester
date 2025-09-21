#ifndef TGFXKEYBOARD_HPP_
#define TGFXKEYBOARD_HPP_

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <gui/common/KeyboardLayout.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/KeyboardKeyMapping.hpp>

#include <touchgfx/Callback.hpp>

using namespace touchgfx;

class CustomKeyboard : public Container
{
public:
    CustomKeyboard();
    virtual ~CustomKeyboard() { }
    void setTouchable(bool touch);
	Unicode::UnicodeChar *getBuffer ();
    virtual void clearBuffer ();
    void setOkPressedCallback(touchgfx::GenericCallback<uint8_t>& cb);
    void setClosePressedCallback(touchgfx::GenericCallback<>& cb);

private:
    static const uint8_t BUFFER_SIZE = 3; //BullT -> Originalmente era 18
    Keyboard keyboard;
    Unicode::UnicodeChar buffer[BUFFER_SIZE];
    Callback<CustomKeyboard> okPressed;
    Callback<CustomKeyboard> backspacePressed;
    Callback<CustomKeyboard> closePressed;
    Callback<CustomKeyboard, Unicode::UnicodeChar> keyPressed;
    touchgfx::GenericCallback<uint8_t>* okPressedCallback = nullptr;
    touchgfx::GenericCallback<>* closePressedCallback = nullptr;

    void okPressedHandler();
    void backspacePressedHandler();
    void closePressedHandler();
    void keyPressedhandler(Unicode::UnicodeChar keyChar);
};

#endif /* TGFXKEYBOARD_HPP_ */
