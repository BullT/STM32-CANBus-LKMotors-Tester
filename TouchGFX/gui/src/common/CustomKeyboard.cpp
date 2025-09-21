#include <gui/common/CustomKeyboard.hpp>
#include <string.h>
#include <cstdlib>
#include <touchgfx/Color.hpp>

CustomKeyboard::CustomKeyboard() : keyboard(),
	okPressed(this, &CustomKeyboard::okPressedHandler),
    backspacePressed(this, &CustomKeyboard::backspacePressedHandler),
	closePressed(this, &CustomKeyboard::closePressedHandler),
    keyPressed(this, &CustomKeyboard::keyPressedhandler)
{
    //Set the callbacks for the callback areas of the keyboard and set its layout.
    layout.callbackAreaArray[0].callback = &okPressed;
	layout.callbackAreaArray[1].callback = &backspacePressed;
	layout.callbackAreaArray[2].callback = &closePressed;
    keyboard.setLayout(&layout);
    keyboard.setKeyListener(keyPressed);
    keyboard.setPosition(0, 0, 124, 284);
    keyboard.setTextIndentation();
    //Allocate the buffer associated with keyboard.
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);

    keyboard.setKeymappingList(&keyMappingListHexadecimal);

    add(keyboard);
}

void CustomKeyboard::backspacePressedHandler()
{
    uint16_t pos = keyboard.getBufferPosition();
    if(pos > 0)
    {
        //Delete the previous entry in the buffer and decrement the position.
        buffer[pos - 1] = 0;
        keyboard.setBufferPosition(pos - 1);
    }
}

void CustomKeyboard::setClosePressedCallback(touchgfx::GenericCallback<>& cb)
{
	closePressedCallback = &cb;
}

void CustomKeyboard::closePressedHandler()
{
    if(closePressedCallback && closePressedCallback->isValid())
    {
		closePressedCallback->execute();
		clearBuffer();
    }
}

void CustomKeyboard::setOkPressedCallback(touchgfx::GenericCallback<uint8_t>& cb)
{
    okPressedCallback = &cb;
}

void CustomKeyboard::okPressedHandler()
{
    if(okPressedCallback && okPressedCallback->isValid())
    {
        uint8_t asciiBuf[BUFFER_SIZE + 1] = {0};
        Unicode::toUTF8(buffer, asciiBuf, sizeof(asciiBuf));

        if(asciiBuf[0] != 0)
        {
			uint8_t value = static_cast<uint8_t>(strtoul(reinterpret_cast<char*>(asciiBuf), nullptr, 16));
			okPressedCallback->execute(value);
        }

        clearBuffer();
    }
}

void CustomKeyboard::setTouchable(bool touch)
{
    Container::setTouchable(touch);
    keyboard.setTouchable(touch);
}

void CustomKeyboard::keyPressedhandler(Unicode::UnicodeChar keyChar)
{

}

Unicode:: UnicodeChar* CustomKeyboard::getBuffer()
{
	return keyboard.getBuffer();
}

void CustomKeyboard::clearBuffer()
{
	memset(buffer, 0, BUFFER_SIZE+1);
	keyboard.setBufferPosition(0);
}
