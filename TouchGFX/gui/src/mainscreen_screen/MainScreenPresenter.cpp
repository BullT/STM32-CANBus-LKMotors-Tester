#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::receptionData(uint8_t *data)
{
	view.receptionData(data);
}

void MainScreenPresenter::sendData(uint8_t *data)
{
	model->sendData(data);
}
