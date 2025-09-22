#include <gui/mainscreen_screen/MainScreenView.hpp>

#ifndef SIMULATOR
#include <cstring>
#include <cstdlib>
#include <touchgfx/Unicode.hpp>
#endif

MainScreenView::MainScreenView() : okCallback(this, &MainScreenView::keyboardOK),
	closeCallback(this, &MainScreenView::keyboardClose),
	flexButtonsCallback(this, &MainScreenView::flexButtonsCallbackHandler)
{
	flexButtons[0]  = &flexButtonTX_0;
	flexButtons[1]  = &flexButtonTX_1;
	flexButtons[2]  = &flexButtonTX_2;
	flexButtons[3]  = &flexButtonTX_3;
	flexButtons[4]  = &flexButtonTX_4;
	flexButtons[5]  = &flexButtonTX_5;
	flexButtons[6]  = &flexButtonTX_6;
	flexButtons[7]  = &flexButtonTX_7;
	flexButtons[8]  = &flexButtonID;

    for (int i = 0; i < 9; i++)
    {
    	flexButtons[i]->setAction(flexButtonsCallback);
    }

    keyboard.setPosition(20, 20, 124, 284);
    keyboard.setOkPressedCallback(okCallback);
    keyboard.setClosePressedCallback(closeCallback);
    add(keyboard);
    keyboard.setVisible(false);
    keyboard.invalidate();
}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::sendClicked()
{
	uint8_t data[8] = {0};
	receptionData(data);
	presenter->sendData(sendBuffer);
}

void MainScreenView::keyboardClose()
{
    keyboard.setVisible(false);
    keyboard.invalidate();
}

void MainScreenView::keyboardOK(uint8_t value)
{
    keyboard.setVisible(false);
    keyboard.invalidate();

	if (flexButton == &flexButtonTX_0)
	{
		sendBuffer[0] = value;
		Unicode::snprintf(textAreaTX_0Buffer, TEXTAREATX_0_SIZE, "%X", value);
		textAreaTX_0.invalidate();
	}

	if (flexButton == &flexButtonTX_1)
	{
		sendBuffer[1] = value;
		Unicode::snprintf(textAreaTX_1Buffer, TEXTAREATX_1_SIZE, "%X", value);
		textAreaTX_1.invalidate();
	}

	if (flexButton == &flexButtonTX_2)
	{
		sendBuffer[2] = value;
		Unicode::snprintf(textAreaTX_2Buffer, TEXTAREATX_2_SIZE, "%X", value);
		textAreaTX_2.invalidate();
	}

	if (flexButton == &flexButtonTX_3)
	{
		sendBuffer[3] = value;
		Unicode::snprintf(textAreaTX_3Buffer, TEXTAREATX_3_SIZE, "%X", value);
		textAreaTX_3.invalidate();
	}

	if (flexButton == &flexButtonTX_4)
	{
		sendBuffer[4] = value;
		Unicode::snprintf(textAreaTX_4Buffer, TEXTAREATX_4_SIZE, "%X", value);
		textAreaTX_4.invalidate();
	}

	if (flexButton == &flexButtonTX_5)
	{
		sendBuffer[5] = value;
		Unicode::snprintf(textAreaTX_5Buffer, TEXTAREATX_5_SIZE, "%X", value);
		textAreaTX_5.invalidate();
	}

	if (flexButton == &flexButtonTX_6)
	{
		sendBuffer[6] = value;
		Unicode::snprintf(textAreaTX_6Buffer, TEXTAREATX_6_SIZE, "%X", value);
		textAreaTX_6.invalidate();
	}

	if (flexButton == &flexButtonTX_7)
	{
		sendBuffer[7] = value;
		Unicode::snprintf(textAreaTX_7Buffer, TEXTAREATX_7_SIZE, "%X", value);
		textAreaTX_7.invalidate();
	}

	if (flexButton == &flexButtonID)
	{
		sendBuffer[8] = value;
		Unicode::snprintf(textAreaIDBuffer, TEXTAREAID_SIZE, "%X", value);
		textAreaID.invalidate();
	}
}

void MainScreenView::flexButtonsCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    keyboard.setVisible(true);
    keyboard.invalidate();
	flexButton = &src;
}

void MainScreenView::receptionData(uint8_t *data)
{
    Unicode::snprintf(textAreaRX_0Buffer, TEXTAREARX_0_SIZE, "%X", data[0]);
    textAreaRX_0.invalidate();

    Unicode::snprintf(textAreaRX_1Buffer, TEXTAREARX_1_SIZE, "%X", data[1]);
    textAreaRX_1.invalidate();

    Unicode::snprintf(textAreaRX_2Buffer, TEXTAREARX_2_SIZE, "%X", data[2]);
    textAreaRX_2.invalidate();

    Unicode::snprintf(textAreaRX_3Buffer, TEXTAREARX_3_SIZE, "%X", data[3]);
    textAreaRX_3.invalidate();

    Unicode::snprintf(textAreaRX_4Buffer, TEXTAREARX_4_SIZE, "%X", data[4]);
    textAreaRX_4.invalidate();

    Unicode::snprintf(textAreaRX_5Buffer, TEXTAREARX_5_SIZE, "%X", data[5]);
    textAreaRX_5.invalidate();

    Unicode::snprintf(textAreaRX_6Buffer, TEXTAREARX_6_SIZE, "%X", data[6]);
    textAreaRX_6.invalidate();

    Unicode::snprintf(textAreaRX_7Buffer, TEXTAREARX_7_SIZE, "%X", data[7]);
    textAreaRX_7.invalidate();
}
