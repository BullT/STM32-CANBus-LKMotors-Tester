#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void flexButtonsCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    virtual void sendClicked();
    virtual void keyboardOK(uint8_t value);
    virtual void keyboardClose();

    virtual void receptionData(uint8_t *data);

protected:
    touchgfx::Callback<MainScreenView, uint8_t> okCallback;
    touchgfx::Callback<MainScreenView> closeCallback;

    touchgfx::BoxWithBorderButtonStyle<touchgfx::ClickButtonTrigger>* flexButtons[9];
    const touchgfx::AbstractButtonContainer* flexButton;
    touchgfx::Callback<MainScreenView, const touchgfx::AbstractButtonContainer&> flexButtonsCallback;

    CustomKeyboard keyboard;
    //uint8_t sendBuffer[9] = {0xA8, 0x00, 0x00, 0x01, 0x28, 0x23, 0x00, 0x00, 0x01};
    uint8_t sendBuffer[9] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
};

#endif // MAINSCREENVIEW_HPP
